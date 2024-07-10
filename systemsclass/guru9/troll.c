/* troll.c */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

void kill_sig(int signum) {
    printf("\nnot today loser\n");
}


int main(int argc, char *argv[]) {
    signal(SIGTERM, kill_sig);
    signal(SIGINT, kill_sig);
    signal(SIGTSTP, kill_sig);
    char buffer[BUFSIZ];
    FILE *fp = fopen("AllTooWell.txt", "r");
    while (fgets(buffer, BUFSIZ, fp)) {
        char command[BUFSIZ];
        sprintf(command, "cowsay -f stegosaurus \"%s\" ", buffer); 
        FILE *stream = popen(command, "w");
        if (!stream) {
	        fprintf(stderr, "Unable to popen: %s\n", strerror(errno));
	        fclose(stream);
            return EXIT_FAILURE;
        }
        fclose(stream);
        sleep(3);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}