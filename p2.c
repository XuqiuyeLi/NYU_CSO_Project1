#include <stdlib.h> 
#include <stdio.h> 
#include "p2.h"

/*
 * Implementation file for functions
 * declared in p2.h
 *
 * Summer Li
 * Methods for cicularly double linked list
 */ 




int add_to_front ( char to_add, node ** head_pointer ){
    
    	node *tail = (*head_pointer)->prev;
    	// Create a new item and set its value
    	node * new_node = (node *) malloc(sizeof(node));
    	new_node->value = to_add;
    	new_node->next = new_node;
    	new_node->prev = new_node;

    	// Add if the list is empty
    	if((*head_pointer) == NULL){
    		*head_pointer = new_node;
    	}

	// Link the new item to point to the head_pointer of the list
	else{
    		new_node->next = *head_pointer;
    		new_node->prev = tail;
    		// Set the head_pointer of the list to be our new item
    		tail->next = new_node;
    		(*head_pointer)-> prev = new_node;
    		*head_pointer = new_node;
	}
    	return 1; 

}


int add_to_back ( char to_add, node ** head_pointer ) {
	node* new_node = (node *) malloc(sizeof(node));
	new_node->value = to_add;
	new_node->next = new_node;
    	new_node->prev = new_node;
    	node *tail = (*head_pointer)->prev;
	// Add as first element if on an empty list
	if ((*head_pointer) == NULL)
    	{
       		*head_pointer = new_node;
    	}
    	// now add a new variable if nonempty list
    	else{
    		new_node->next = *head_pointer;
    		tail->next = new_node;
    		new_node->prev = tail;
    		tail = new_node;
    		(*head_pointer)-> prev = tail;
	}
    	return 1; 
	
}

char remove_first ( node ** head_pointer) { 
	char return_value = '\0';
    	node * next_node = (*head_pointer)->next;
    	node * prev_node = (*head_pointer)->prev;
    	// If the list is empty
    	if (* head_pointer == NULL) {
        	return return_value;
    	}
    	// Free the head item
    	return_value = (* head_pointer)->value;
    	node *temp = *head_pointer;
  
    	// Set the head to be the next item that we've stored on the side
    	*head_pointer = next_node;
    	prev_node->next = *head_pointer;
    	(*head_pointer)->prev = prev_node;
    	free(temp);
    	return return_value;

}

char remove_tail ( node ** head_pointer ){
	char return_value = '\0';
	node *current = *head_pointer;
	node *tail = (*head_pointer)->prev;
	node *temp = NULL;
	// Set prev_node to the one before tail
	node *prev_node = (*head_pointer)->prev->prev;

	// If the list is empty
	if (*head_pointer == NULL) {
        	return return_value;
    	}

    	// If there is only one item in the list, remove it
    	if ((*head_pointer)->next == current) {
        	return_value = current->value;
        	free(current);
        	*head_pointer = NULL;
        	return return_value;
   	}

    	else{
    		// get to the second to tail node in the list 
    		temp = tail->prev;
    		current = tail;
    		return_value = tail->value;
    		temp->next = *head_pointer;
    		tail = temp;
    		(*head_pointer)->prev = tail;
    		free(current);
    		return return_value;

    }
}


int index_of ( char to_locate, node * head_pointer ) {
    	if (head_pointer == NULL) {
        	return -1;
    	}
    	int index =0;
    	node *current = head_pointer;
    	do{
    		if((current->value) == to-locate){
    			return index;
    		}
    		current = current->next;
    		index++;
   	} while(current != head_pointer);

    	// didn't find the element after loop through the list
    	return -1;
}


int num_of_nodes ( node * head_pointer ) {
	if (head_pointer == NULL) {
        	return 0;
    	}
	int count = 0;
	node *current = head_pointer;
	// count the nodes until back to head
	do{
        	count++;
        	current = current->next;
    	}while(current != head_pointer);

    	return count; 
}

void empty ( node ** head_pointer ) {
	//Deference head to get to read head
    	node *current = *head_pointer;
    	// loop back until the head pointer
    	while (current != NULL){
       		free(current);
       		current = current->next;
    	}
    	*head_pointer = NULL;
}

void print_list ( node * head_pointer ) { 
	node *temp = head_pointer;
 	// print in forward direction
 	// If the list is empyty print []
 	if (*head_pointer == NULL) {
        	printf("[\n]");
    	}
    	else{
    		printf("[\n");
    		while (temp->next != head_pointer){
        		printf("temp: %c", temp->value);
        		printf(",\n");
        		temp = temp->next;
    		}
    		// print the tail node individually
   		printf("temp: %c", temp->value);
   		printf("\n]");
	}    
}

