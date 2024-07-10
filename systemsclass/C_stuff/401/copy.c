/* copy.c */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>

void usage(const char *program) {
    fprintf(stderr, "Usage: %s source target\n", program);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
    	usage(argv[0]);
    	return EXIT_FAILURE;
    }

    // Command line arguments
    const char *source_path = argv[1];
    const char *target_path = argv[2];

    // Open file for reading

    //get a file descriptor
    //read only
    int source_fd = open(source_path, O_RDONLY);    // Discuss: open
    
    //always check if the system call fails
    // -1 is typically the number we get if it fails
    if (source_fd < 0) {			    // Discuss: errno
        //looks up errno aka error number that is 
        //associated to whatever the error is
    	fprintf(stderr, "open: %s\n", strerror(errno));
    	return EXIT_FAILURE;
    }

    //file descriptors is how things work internally
    //we are lazy af... optimization
    //we are familiar with streams FILE *

    // fdopen convert a file descriptor into a FILE *
    //allows us to use fgets and fputs
    // "r" is read mode 
    FILE *source_file = fdopen(source_fd, "r");	    // Discuss: fdopen
    //check for failure (if it is null)
    if (!source_file) {
    	fprintf(stderr, "fopen: %s\n", strerror(errno));
    	return EXIT_FAILURE;
    }

    // Open file for writing
    //now we have changed it to a file stream so we can fopen
    // "w" is write mode
    FILE *target_file = fopen(target_path, "w");    // Discuss: fopen
    if (!target_file) {
    	fprintf(stderr, "fopen: %s\n", strerror(errno));
    	return EXIT_FAILURE;
    }

    // Copy from source file to target file
    char   buffer[BUFSIZ];			    // Review: buffer
    size_t nread;				    // Discuss: fread

    //fread(where to store the stuff (buffer), 
        //size of element in the buffer (1 a char), 
        //length of the buffer (BUFSIZ), 
        //stream where I want to read (source_file))
    //parentheses matter
    while ((nread = fread(buffer, 1, BUFSIZ, source_file)) > 0) {
        //fwrite(location (buffer),
            //size of element in the buffer (1 a char),
            //nread is the number of things YOU ACTUALLY HAVE (write what you have),
            //file to store the writing)
    	fwrite(buffer, 1, nread, target_file);	    // Discuss: fwrite
    }

    // Close files
    fclose(source_file);			    // Review: fclose
    fclose(target_file);

    return EXIT_SUCCESS;
}