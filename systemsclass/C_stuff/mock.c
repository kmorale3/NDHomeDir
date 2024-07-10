/* mock.c */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *mock(const char *s) {
   char *t = strdup(s);
   
   for (char *c = t; *c; c++) {
      *c = ((size_t)c % 2) ? toupper(*c) : tolower(*c);
   }

   return t;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
	    char *t = mock(argv[i]);
	    puts(t);
	    free(t);    // BUG: free
    }
    return EXIT_SUCCESS;
}
