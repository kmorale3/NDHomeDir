/* treecopy.c
   OS Project 1
   Anna Koziol and Katie Morales */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int copy_file(const char *source_path, const char *target_path, size_t *total_bytes) {
  // open the source file as read only, creates a file descriptor
  int source_fd = open(source_path, O_RDONLY);

  // check for successful open, value less than 0 means unsuccessful
  if (source_fd < 0) {
    printf("treecopy: Unable to open %s: %s\n", source_path, strerror(errno));
    return EXIT_FAILURE;
  }

  // create the target file and give the user read, write, execute permissions,
  // creates a file descriptor
  int target_fd = creat(target_path, S_IRWXU);

  // check for successful open
  if (target_fd < 0) {
    printf("treecopy: Unable to open %s: %s\n", target_path, strerror(errno));
    return EXIT_FAILURE;
  }

  // create the buffer to read into of size 4 KB
  size_t read_size = 4096;
  char buffer[read_size];

  // total number of bytes read
  // bytes just read
  size_t bytes_read;
  // bytes written
  ssize_t bytes_written;

  // read the first chunk
  bytes_read = read(source_fd, buffer, read_size);

  // returns 0 at EOF
  while (bytes_read > 0) {
    // write the bytes just read
    bytes_written = write(target_fd, buffer, bytes_read);
    // check for an error
    if (bytes_written < 0) {
      printf("treecopy: Unsuccessful write of %s: %s\n", target_path,
             strerror(errno));
      return EXIT_FAILURE;
    }
    // check that the number of bytes written was the number requested
    if (bytes_written != bytes_read) {
      printf(
          "treecopy: Error: %ld bytes just read, but %ld bytes just written\n",
          bytes_read, bytes_written);
      return EXIT_FAILURE;
    }
    // increment the total number of bytes copied
    (*total_bytes) += bytes_read;
    // get the next read
    bytes_read = read(source_fd, buffer, read_size);
  }

  // returns less than 0 for an error
  if (bytes_read < 0) {
    printf("treecopy: Unsuccessful read of %s: %s\n", source_path,
           strerror(errno));
    return EXIT_FAILURE;
  }

  // close source file
  int source_close = close(source_fd);
  // check for errors
  if (source_close < 0) {
    printf("treecopy: Unsuccessful close of %s: %s\n", source_path,
           strerror(errno));
    return EXIT_FAILURE;
  }

  // close source file
  int target_close = close(target_fd);
  // check for errors
  if (target_close < 0) {
    printf("treecopy: Unsuccessful close of %s: %s\n", target_path,
           strerror(errno));
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int copy_directory(struct dirent *dir, const char *source_path, const char *target_path, size_t *num_dir, size_t *num_files, size_t *num_bytes){
  // get the full path of the directory / file
  char original_path[BUFSIZ];  
  char copy_path[BUFSIZ]; 

  // path of the directory / file to be opened
  strcpy(original_path, source_path);
  strcat(original_path, "/");
  strcat(original_path, dir->d_name);

  // path of the directory / file to be copied 
  strcpy(copy_path, target_path);
  strcat(copy_path, "/");
  strcat(copy_path, dir->d_name);

  struct stat sb;
  stat(original_path, &sb);
  
  // base case: it is a file
  if ((sb.st_mode & S_IFMT) == S_IFREG) {
    (*num_files) ++;
    // 0 is exit_success
    if (copy_file(original_path, copy_path, num_bytes)){
      return EXIT_FAILURE;
    }
    printf("%s -> %s\n", original_path, copy_path);
    return EXIT_SUCCESS;
  } 
  // recursive case: it is a directory 
  (*num_dir) ++;
  // Open directory for reading 
  DIR *original_dir = opendir(original_path);
  if (!original_dir) {
    fprintf(stderr, "treecopy: Unable to opendir on %s: %s\n", original_path, strerror(errno));
    return EXIT_FAILURE;
  }  

  // make the target directory 
  if (mkdir(copy_path,S_IRWXU) < 0){
    fprintf(stderr, "treecopy: Unable to mkdir on %s: %s\n", copy_path, strerror(errno));
    return EXIT_FAILURE;
  }

  // open the target directory
  DIR *copy_dir = opendir(target_path);
  if (!copy_dir) {
    fprintf(stderr, "treecopy: Unable to opendir on %s: %s\n", copy_path, strerror(errno));
    return EXIT_FAILURE;
  }

  printf("%s -> %s\n", original_path, copy_path);
  
  /* Iterate through directory entries */
  for (struct dirent *e = readdir(original_dir); e; e = readdir(original_dir)) {
    if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0) {
      continue;
    }
    // 0 is exit_success, 1 is exit failure
    if (copy_directory(e, original_path,copy_path,num_dir, num_files, num_bytes)){
      return EXIT_FAILURE;
    }      
  }

  // close original directory
  if (closedir(original_dir) < 0){
    printf("treecopy: Unsuccessful close of %s: %s\n", original_path, strerror(errno));
    return EXIT_FAILURE;
  }
  // close copied directory
  if (closedir(copy_dir) < 0){
    printf("treecopy: Unsuccessful close of %s: %s\n", copy_path, strerror(errno));
    return EXIT_FAILURE;
  }
  // success
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {

  // check that the correct number of arguments were given, otherwise return
  // failure treecopy SourceFile TargetFile
  if (argc != 3) {
    printf("treecopy: 3 arguments needed, %d provided.\nCommand should be "
           "formatted:\treecopy SourcePath TargetPath\n",
           argc);
    return EXIT_FAILURE;
  }

  // Command line arguments
  const char *source_path = argv[1];
  const char *target_path = argv[2];

  // number of directories, files, and bytes
  size_t num_dir = 0;
  size_t num_files = 0;
  size_t num_bytes = 0;

  struct stat sb;
  stat(source_path, &sb);
  
  // it is a file
  if ((sb.st_mode & S_IFMT) == S_IFREG) {
    num_files ++;
    // 0 is exit_success
    if (copy_file(source_path, target_path, &num_bytes)){
      return EXIT_FAILURE;
    }
    printf("%s -> %s\n", source_path, target_path);
    printf("treecopy: copied %ld directories, %ld files, and %ld bytes from %s to %s\n",num_dir, num_files, num_bytes, source_path, target_path);      
    return EXIT_SUCCESS;
    
  } 

  // Open directory for reading 
  DIR *source_dir = opendir(source_path);
  if (!source_dir) {
    fprintf(stderr, "treecopy: Unable to opendir on %s: %s\n", source_path, strerror(errno));
    return EXIT_FAILURE;
  }  

  // make the target directory 
  if (mkdir(target_path,S_IRWXU) < 0){
    fprintf(stderr, "treecopy: Unable to mkdir on %s: %s\n", target_path, strerror(errno));
    return EXIT_FAILURE;
  }

  // open the target directory
  DIR *target_dir = opendir(target_path);
  if (!target_dir) {
    fprintf(stderr, "treecopy: Unable to opendir on %s: %s\n", target_path, strerror(errno));
    return EXIT_FAILURE;
  }

  printf("%s -> %s", source_path, target_path);

  /* Iterate through directory entries */
  for (struct dirent *e = readdir(source_dir); e; e = readdir(source_dir)) {
    if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0) {
      continue;
    }
    // 0 is exit_success, 1 is exit failure
    if (copy_directory(e, source_path,target_path,&num_dir, &num_files, &num_bytes)){
      return EXIT_FAILURE;
    }      
  }

  // close source directory
  if (closedir(source_dir) < 0){
    printf("treecopy: Unsuccessful close of %s: %s\n", source_path, strerror(errno));
    return EXIT_FAILURE;
  }
  // close target directory
  if (closedir(target_dir) < 0){
    printf("treecopy: Unsuccessful close of %s: %s\n", target_path, strerror(errno));
    return EXIT_FAILURE;
  }

  printf("treecopy: copied %ld directories, %ld files, and %ld bytes from %s to %s\n",num_dir, num_files, num_bytes, source_path, target_path);      
  return EXIT_SUCCESS;
}