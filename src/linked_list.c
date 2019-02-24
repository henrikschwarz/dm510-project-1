/*
 * linked_list.c
 *
 *  Created on: Dec 24, 2013
 *      Author: jacob
 */
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

linked_list *init_linked_list() {
	linked_list *list = malloc(sizeof(linked_list)); // Allocate space for list
	// printf("Init list: next is %p, previous is %p\n", list->next, list->previous);
	return list; // List pointer
}

void add_element( linked_list *list, void *element) {
	if (list->data == NULL){ // If the list is empty
		list->data = element;
	} else {
		while (list->next != NULL) {
			list = list->next; //  go to last node
		}
		linked_list *new_list = init_linked_list(); // init new list
		new_list->data = element; // Add data to node
		new_list->previous = list; // Link current node to list
		new_list->next = NULL; // Set next item to null
		list->next = new_list; // Link list to current node
	}
}

int linked_list_size(linked_list *list) {
	int count = 0; // Counter
	while (list->previous != NULL) { // Go to start
		list = list->previous;
	}
	if (list->data == NULL){
		return 0;
	}
	while (list->data != NULL){ // If data is not null, count
		count++; // Count items.
		if (list->next != NULL){ // If there is no next item then break
			list=list->next; // Go to next item
		} else {
			break;
		}
	}
	return count;
}

void *remove_first(linked_list *list) {
	while (list->previous != NULL) {
		list = list->previous; // Make sure we are at the start of the list
	}
	if (list->data != NULL) { // Check that we have data
		void* element = list->data; // Save our data
		if (list->next != NULL) { // check that we have more than one element
			list->data = list->next->data; // Insert data from next node into head of list
			if (list->next->next != NULL) { // If list was size of 3
				list->next->next->previous = list; // Linked node 3 to new head
			}
			free(list->next);
		}
		return element; // Return element
	}
	return NULL;
}


int remove_element(linked_list *list, void *element) {
	/*
	* Has 3 different cases: Head of list, between two nodes or end of list
	*/
	while (list->previous != NULL) {
		list = list->previous; // Find start of list
	}
	while (1==1) {
		if (list->data == element) {
			if (list->previous == NULL) {
				// First node
				list->data = NULL; // Remove node data if it is the first item
				if (list->next != NULL) {
					remove_first(list); // If there are more than one node in the list, use our function
				}
			} else if (list->next == NULL && list->previous != NULL) {
				// Tail of the list
				list->previous->next = NULL; // Remove link list to node
				free(list); // Free the memory
			} else if (list->next != NULL && list->previous != NULL) {
				// Between two nodes
				list->previous->next = list->next; // Link node n-1 to node n+1
				list->next->previous = list->previous; // Link node n+1 to node n-1
				free(list);
			}
			return 0;
		} else if (list->next != NULL) { // If not at the end of list, go to next node
			list = list->next;
		} else { // Couldn't find the element in the list
			return -1;
		}
	}
}
