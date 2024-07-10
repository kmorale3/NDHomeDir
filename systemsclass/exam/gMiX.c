/* 07-memory-management.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */

char *DATA[] = {"GNU", "is", "not", "Unix", NULL};

/* Structure */

typedef struct Node Node;
struct Node {
    char *  data;
    Node *  next;
};

/* Functions */

Node *	node_create(char *data, Node *next) {
    Node *n = malloc(sizeof(Node));
    if (n) {
    	n->data = data;
    	n->next = next;
    }
    return n;
}

void	node_delete(Node *n) {
    if (n) {
    	if (n->next) {
    	    free(n->next);
	}
	free(n->data);
	free(n);
    }
}

void	node_print(Node *n) {
    if (n) {
        node_print(n->next);
    	puts(n->data);
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    Node *head = NULL;
    for (char **s = DATA; *s; s++) {
    	head = node_create(*s, head);
    }

    node_print(head);
    node_delete(head);
    return EXIT_SUCCESS;
}
