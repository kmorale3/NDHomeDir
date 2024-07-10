/* http_client.c: simple HTTP client */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


FILE *socket_dial(const char *host, const char *port) {
    /* Lookup server address information */
    struct addrinfo *results;
    struct addrinfo  hints = {
        .ai_family   = AF_UNSPEC,   /* Return IPv4 and IPv6 choices */
        .ai_socktype = SOCK_STREAM, /* Use TCP */
    };
    int status;
    if ((status = getaddrinfo(host, port, &hints, &results)) != 0) {
    	fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(status));
	return NULL;
    }

    /* For each server entry, allocate socket and try to connect */
    int client_fd = -1;
    for (struct addrinfo *p = results; p != NULL && client_fd < 0; p = p->ai_next) {
	/* Allocate socket */
	if ((client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
	    fprintf(stderr, "Unable to make socket: %s\n", strerror(errno));
	    continue;
	}

	/* Connect to host */
	if (connect(client_fd, p->ai_addr, p->ai_addrlen) < 0) {
	    close(client_fd);
	    client_fd = -1;
	    continue;
	}
    }

    /* Release allocate address information */
    freeaddrinfo(results);

    if (client_fd < 0) {
	    fprintf(stderr, "Unable to connect to %s:%s: %s\n", host, port, strerror(errno));
    	return NULL;
    }

    /* Open file stream from socket file descriptor */
    FILE *client_file = fdopen(client_fd, "w+");
    if (!client_file) {
        fprintf(stderr, "Unable to fdopen: %s\n", strerror(errno));
        close(client_fd);
        return NULL;
    }

    return client_file;
}

int main(int argc, char *argv[]) {
    char *host = "example.com";
    char *port1 = "80";
    char *delim = "-";
    char *port2 = NULL;

    /* Parse command line arguments */
    if (argc > 1) host = argv[1];
    if (argc > 2) {
        port1 = argv[2]; 
        port2 = strstr(port1, delim);
        if (port2) {
            *port2 = 0;
            port2++;
        }
    }
    
    int port1int = atoi(port1);
    int port2int = port1int;
    if (port2) port2int = atoi(port2);
    char port[BUFSIZ];
    int status = EXIT_FAILURE;
    for (int i =port1int; i <=port2int; i++) {
        sprintf(port, "%d", i);

    /* Connect to remote machine */
        FILE *client_file = socket_dial(host, port);
        if (!client_file) {
            continue;
        }
    printf("Port %d is open\n", i);
    status = EXIT_SUCCESS;
    /* Close socket */
    fclose(client_file);
    }
    return status;
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */