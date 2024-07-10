/* http_client.c: simple HTTP client */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

//WRITE FUNCTIONS 
FILE *socket_dial(const char *host, const char *port) {
        /* Lookup server address information */
    struct addrinfo *results;
        //initial suggestion to the function 
    struct addrinfo  hints = {
        //AF_UNSPEC says i dont care, use ipv4 or ipv6
        .ai_family   = AF_UNSPEC,   //either one, unspecified /* Return IPv4 and IPv6 choices */
        .ai_socktype = SOCK_STREAM, /* Use TCP */
    };
    int status;
    //make sure to check if it fails 
    //results is a linked list 
    if ((status = getaddrinfo(host, port, &hints, &results)) != 0) {
    	fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(status));
	return NULL;
    }
    //results is a list because there can be multiple ip addresses for each machine 

    /* For each server entry, allocate socket and try to connect */
    //talking to the dns server can give me multiple results because 
    //each machine may have multiple ip addresses
    //you will get back a sequence of ip addrresses

    //linked list 
    int client_fd = -1;
    for (struct addrinfo *p = results; p != NULL && client_fd < 0; p = p->ai_next) {
	/* Allocate socket */
    //check for failure 
	if ((client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0) {
	    fprintf(stderr, "Unable to make socket: %s\n", strerror(errno));
	    continue;
	}

	/* Connect to host */
	if (connect(client_fd, p->ai_addr, p->ai_addrlen) < 0) {
	    //if i allocate a socket but the connection fails, 
            //i should close the socket
            //i should reset the file descriptor 
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
    FILE *client_file = fdopen(client_fd, "w+"); //read and write... r+ would also be acceptable 
    if (!client_file) {
        fprintf(stderr, "Unable to fdopen: %s\n", strerror(errno));
        close(client_fd);
        return NULL;
    }

    return client_file;
}

int main(int argc, char *argv[]) {
    char *host = "example.com";
    char *port = "80";

    /* Parse command line arguments */
    if (argc > 1) host = argv[1];
    if (argc > 2) port = argv[2];

    /* Connect to remote machine */
    FILE *client_file = socket_dial(host, port);
    if (!client_file) {
        return EXIT_FAILURE;
    }

    /* Send HTTP Request */
    fprintf(client_file, "GET / HTTP/1.0\r\n"); //speak the protocol 
    fprintf(client_file, "Host: %s\r\n", host);
    fprintf(client_file, "\r\n");                   // Must end Request with empty line

    /* Read HTTP Response */
    //this will makes sure to not print the header 
    //a blank line indicates the end of the headers
    //a blank line will be "\r\n", which has a string length of 2 
    char buffer[BUFSIZ];
    size_t content_length = 0;

    //use sscanf to get the content length 
    while (fgets(buffer, BUFSIZ, client_file) && strlen(buffer) > 2) {
        sscanf(buffer, "Content-Length: %ld", &content_length);
    }

    while (fgets(buffer, BUFSIZ, client_file)) {
        fputs(buffer, stdout);
    }

    fprintf(stdout, "content length was %ld\n", content_length);

    /* Close socket */
    fclose(client_file);
    return EXIT_SUCCESS;
}

/* vim: set expandtab sts=4 sw=4 ts=8 ft=c: */