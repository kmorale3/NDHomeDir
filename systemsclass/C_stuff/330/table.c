/* table.c */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Constants */

#define NBUCKETS (1<<8) //2^8 is 256... number of buckets

const int DATA[]= {4, 6, 6, 3, 7, 0};

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

/* Table Structure */
//THIS IS THE ORIGINAL HASH TABLE

typedef struct Table Table;
struct Table {
    int buckets[NBUCKETS];
};

void	table_insert(Table *t, int value) {
    //THE FIRST STEP IS TO HASH
    //THE INTEGER IS THE INDEX
    //locate what am i doing... where am i going
    int bucket = value % NBUCKETS; //know which bucket to use
    //put the value INTO the bucket
    t->buckets[bucket] = value;
}

bool    table_search(Table *t, int value) {
    //LOCATE THE BUCKET HOMIE
    int bucket = value % NBUCKETS;
    return t->buckets[bucket] == value;
}

/* Table Structure */
//THIS IS THE SEPARATE CHAINING METHOD

typedef struct Table Table;
struct Table {
    Node *bucket[NBUCKETS];
};

void	table_insert(Table *t, int value) {
    int bucket = value & NBUCKETS;
    for (Node *curr = t->buckets[bucket]; curr; curr = curr->next) {
        if (curr->data == value) {
            return;
        }
    }
}

bool    table_search(Table *t, int value) {
    //LOCATE THE BUCKET HOMIE
    int bucket = value % NBUCKETS;
    for (Node *curr = t->buckets[bucket]; curr; curr = curr->next) {
        if (curr->data == value) {
            return true;
        }
    }
    return false;

}

/* Main Execution */

int main(int argc, char *argv[]) {
    //2 curly braces because it is an array??
    Table t = {{0}};

    // Insert each item in DATA into set
    for (const int *p = DATA; *p > 0; p++) {
    	table_insert(&t, *p);
    }

    // Search for numbers 1 - 9 in set
    for (int i = 1; i < 10; i++) {
    	printf("%d ? %s\n", i, table_search(&t, i) ? "YES" : "NO");
    }

    return EXIT_SUCCESS;
}