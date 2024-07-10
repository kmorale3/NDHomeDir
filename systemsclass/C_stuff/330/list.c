/* list.c */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Constants */

const int DATA[] = {4, 6, 6, 3, 7, 0};

/* Node Structure */

typedef struct Node Node;
struct Node {
    int   data;
    Node *next;
};

Node * node_create(int data, Node *next) {
    //allocate on the heap
    Node *n = malloc(sizeof(Node));
    //check if it fails
    //if n is not 0, then the conditional will evaluate true 
    if (n) {
    	n->data = data;
    	n->next = next;
    }
    //if it fails it just returns null
    return n;
}

/* List Structure */
//lists consists of series of nodes
//all the list needs is a head

typedef struct List List;
struct List {
    Node *head;
};

void	list_insert(List *l, int value) {
    //Head -> NULL
    //isnert 0
    //Head -> [0] -> NULL
    //insert 1
    //Head -> [1] -> [0] -> NULL
    //this is insert front
    //good for stack (the abstract data type)
    l->head = node_create(value, l->head);
}

bool    list_search(List *l, int value) {
    for (Node *curr = l->head; curr; curr = curr->next) {
    	if (curr->data == value) {
    	    return true;
	}
    }

    return false;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    List l = {0};

    // Insert each item in DATA into set
    for (const int *p = DATA; *p > 0; p++) {
        //pass in a pointer by taking the address aka &
    	list_insert(&l, *p);
    }

    // Search for numbers 1 - 9 in set
    for (int i = 1; i < 10; i++) {
        //this uses the ternary
    	printf("%d ? %s\n", i, list_search(&l, i) ? "YES" : "NO");
    }

    return EXIT_SUCCESS;
}