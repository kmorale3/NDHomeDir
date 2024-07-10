/* duplicates.c */

#include "hash.h"
#include "macros.h"
#include "table.h"

#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>

/* Globals */

char * PROGRAM_NAME = NULL;

/* Structures */

typedef struct {
    bool count;
    bool quiet;
} Options;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s paths...\n", PROGRAM_NAME);
    fprintf(stderr, "    -c     Only display total number of duplicates\n");
    fprintf(stderr, "    -q     Do not write anything (exit with 0 if duplicate found)\n");
    exit(status);
}

/**
 * Check if path is a directory.
 * @param       path        Path to check.
 * @return      true if Path is a directory, otherwise false.
 */
bool is_directory(const char *path) {
    //create the struct stat, gives us information 
    struct stat s;
    if (stat(path, &s) < 0) {
        fprintf(stderr, "%s", strerror(errno));
    }
    //see if it is a directory now that the struct stat object made
    if (S_ISDIR(s.st_mode))
        return true;
    else    
        return false;
}

/**
 * Check if file is in table of checksums.
 *
 *  If quiet is true, then exit if file is in checksums table.
 *
 *  If count is false, then print duplicate association if file is in
 *  checksums table.
 *
 * @param       path        Path to file to check.
 * @param       checksums   Table of checksums.
 * @param       options     Options.
 * @return      0 if Path is not in checksums, otherwise 1.
 */
size_t check_file(const char *path, Table *checksums, Options *options) {
    //this will store the md5 sum for the file
    char hexdigest[HEX_DIGEST_LENGTH];
    //first you need to HASH
    hash_from_file(path, hexdigest);

    //quiet true
    //exit if file is in checksums table
    if (options->quiet) {
        //search the table by the md5 sum
        if (table_search(checksums, hexdigest))
            return 1;
        else {
            //insert the value if it is not in the table
            //first the value object must be created
            //since it is a union, it can be the pointer or the int
            Value v = {(uint64_t)path};
            table_insert(checksums, hexdigest, v, STRING );     
        }
        //return 0 if there were not any matches
        return 0;
    }

    //we want to print out the matches
    if (!(options->count)) {
            //a null value will be returned if it is not in the table
            Value *v = table_search(checksums, hexdigest);
            //check if it is not null aka there is a match  
            if (v) {
                //print out the match
                printf("%s is duplicate of %s\n", path, v->string );
                //return 1 to signify a match
                return 1;
            }
            else {
                //insert the value if it is not in the table
                //first the value object must be created
                //since it is a union, it can be the pointer or the int
                Value v = {(uint64_t)path};
                table_insert(checksums, hexdigest, v, STRING );
            }
    }
    //only print the count, so check for matches
    //this will only be true if quiet is false and count is false
    else {
        //check for match
        Value *v = table_search(checksums, hexdigest);
        if (v) {
            return 1;
        }
        else {
            //insert if there is not a match
            Value v = {(uint64_t)path};
            table_insert(checksums, hexdigest, v, STRING );
        }
    }
    return 0;
}

/**
 * Check all entries in directory (recursively).
 * @param       root        Path to directory to check.
 * @param       checksums   Table of checksums.
 * @param       options     Options.
 * @return      Number of duplicate entries in directory.
 */
size_t check_directory(const char *root, Table *checksums, Options *options) {
    //count the duplicates, this functions returns a size_t
    size_t duplicates = 0;

    //check to see if it is a directory
    if (is_directory(root)) {
        //open the directory
        DIR *d = opendir(root);
        if (!d) {
    	    fprintf(stderr, "%s\n", strerror(errno));
    	    return EXIT_FAILURE;
        }
        //create the object
        for (struct dirent *e = readdir(d); e; e = readdir(d)) {
            //we want to skip the . and .. directories
            if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0) 
                continue;

            //create the full path name of the file
            char path[BUFSIZ];
            sprintf(path, "%s/%s", root, e->d_name);

            //call check_directory recursively on the full path that was created
            //then increment the duplicates on the result (if it is a duplicate)
            duplicates += check_directory(path, checksums, options);
        }
        //close the directory
        closedir(d);
    }
    else {
        //check the file for a match
        if (check_file(root, checksums,options)) {
            //increment duplicates if the result of the function call is true
            duplicates ++;
        }
    }
    //returnt he number of duplicates
    return duplicates;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    //used to index the arg arguments 
    int argind = 1; 

    //initialize the options object to fall
    Options o = {false};

    //program name
    PROGRAM_NAME = argv[0];

    /* Parse command line arguments */
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];
        //arg[0] is '-'
        //arg[1] is the letter
        //make sure to break after each case,
        // so it doesn't roll to the default case
        switch (arg[1]) {
            case 'h': //usage
                usage(0);
                break;
            case 'c': //only display final count of duplicates
                o.count = true;
                break;
            case 'q': //exit with 0 as soon as duplicate detected
                o.quiet = true;
                break;
            default:
                usage(1);
                break;
        }
    }

    //create the table
    Table *checksums = table_create(0);
    //initialize duplicates
    size_t duplicates = 0;
    //if there are no files or directories inputted, it fails
    if (argind >= argc)
        return EXIT_FAILURE;

    //parse through the rest of the command line arguments 
    while ((argind < argc && strlen(argv[argind]) > 1)) {
        char *arg = argv[argind++];

        //call check directory to return the matches for the directory or file
        //need to pass the argument, the table, and the parsed options
        size_t num = check_directory(arg, checksums, &o);
        
        //increse the count of the duplicates
        duplicates += num;

    }

    //display count if the flag was given 
    if (o.count)
        printf("%zu\n", duplicates);

    //you must free the table!!
    table_delete(checksums);

    //if the quiet flag was passed
    //and there were no matches
    //then the program should return a failure
    if (o.quiet)
        if (duplicates == 0)
            return EXIT_FAILURE;

    //elsewise return success!!!
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
