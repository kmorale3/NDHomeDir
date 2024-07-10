#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;	
	
}sll_node;

// Step 3 - Create the struct for sllist
typedef struct sllist{

	// Make the private sll_node member called head_node
	struct sll_node* head_node;
	
}sllist;

// Step 6 - Create the constructor method for sllist 
void insert( sll_node* head_node, int data) {
	
	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof9sll_node));
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = data;
	insert_node->next_node = NULL;
	
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if (head_node == NULL) {
		
		// Set the head node equal to insert_node 
		head_node = insert_node;
		
		// And return
		return;
	}
	
	// Otherwise, create a curr_ptr equal to the head_node 
	sll_node* curr_ptr = head_node;
	
	// Iterate until the next_node is NULL
	while( curr_ptr->next != NULL){
	
		curr_ptr= curr_ptr->next;
	}		
	
	
	// Set curr_ptr's next_node equal to insert_node
	curr_ptr->next= insert_node;
	
}

// Step 8 - Print the Singly Linked List 

	
	// We can just copy and paste from sllist_part2.c
	
	// Just change node_0 to head_node

	
	
		
		
		
				
		
		

		// Iterate through the next node
		

	
	




// Step 10 - Free all the elements 

	
	// Dr. Morrison's Golden Rule of Pointers 
	
		
	

	// Recursively call destructor on the next node  
	
		
	// Free the current pointer 
	
	



int main( void ){
	
	// Step 4 - Dynamically allocate a sllist 
	sllist* the_list = (sllist*)malloc(sizeof(sllist));
	
	// Step 4-1 - Set the head_node to NULL 
	the_list->head_node = NULL;
	
	
	// Step 7 - Call insert with 10, -20, 15, and 4
	insert( the_list->head_node, 10);
	insert( the_list->head_node, -20);
	insert( the_list->head_node, 15);
	insert( the_list->head_node, 4);
	
	
	
	// Step 9 - Call in main
	

	
	// Step 11 - Call the destructor
	

	
	// Step 5 - Free the sllist 
	free(the_list);
	
	return EXIT_SUCCESS;
}