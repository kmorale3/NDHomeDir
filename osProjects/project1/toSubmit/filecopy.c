/* filecopy.c
   OS Project 1
   Anna Koziol and Katie Morales */

/* This program duplicates a file from one place to another
   formatted: filecopy SourceFile TargetFile
   It then outputs how many bytes were copied over if successful */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  // check that the correct number of arguments were given, otherwise return
  // failure filecopy SourceFile TargetFile
  if (argc != 3) {
    printf("filecopy: 3 arguments needed, %d provided.\nCommand should be "
           "formatted:\nfilecopy SourceFile TargetFile\n",
           argc);
    return EXIT_FAILURE;
  }

  // Command line arguments, get the paths
  const char *source_path = argv[1];
  const char *target_path = argv[2];

  // open the source file as read only, creates a file descriptor
  int source_fd = open(source_path, O_RDONLY);

  // check for successful open, value less than 0 means unsuccessful
  if (source_fd < 0) {
    printf("filecopy: Unable to open %s: %s\n", source_path, strerror(errno));
    return EXIT_FAILURE;
  }

  // create the target file and give the user read, write, execute permissions,
  // creates a file descriptor
  int target_fd = creat(target_path, S_IRWXU);

  // check for successful open
  if (target_fd < 0) {
    printf("filecopy: Unable to open %s: %s\n", target_path, strerror(errno));
    return EXIT_FAILURE;
  }

  // create the buffer to read into of size 4 KB
  size_t read_size = 4096;
  char buffer[read_size];

  // total number of bytes read
  size_t total_bytes = 0;
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
      printf("filecopy: Unsuccessful write of %s: %s\n", target_path,
             strerror(errno));
      return EXIT_FAILURE;
    }
    // check that the number of bytes written was the number requested
    if (bytes_written != bytes_read) {
      printf(
          "filecopy: Error: %ld bytes just read, but %ld bytes just written\n",
          bytes_read, bytes_written);
      return EXIT_FAILURE;
    }
    // increment the total number of bytes copied
    total_bytes += bytes_read;
    // get the next read
    bytes_read = read(source_fd, buffer, read_size);
  }

  // returns less than 0 for an error
  if (bytes_read < 0) {
    printf("filecopy: Unsuccessful read of %s: %s\n", source_path,
           strerror(errno));
    return EXIT_FAILURE;
  }

  // close source file
  int source_close = close(source_fd);
  // check for errors
  if (source_close < 0) {
    printf("filecopy: Unsuccessful close of %s: %s\n", source_path,
           strerror(errno));
    return EXIT_FAILURE;
  }

  // close source file
  int target_close = close(target_fd);
  // check for errors
  if (target_close < 0) {
    printf("filecopy: Unsuccessful close of %s: %s\n", target_path,
           strerror(errno));
    return EXIT_FAILURE;
  }

  // successful file copy
  printf("filecopy success: copied %ld bytes from %s to %s\n", total_bytes,
         source_path, target_path);
  return EXIT_SUCCESS;
}