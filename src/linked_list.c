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
	while (list->next != NULL) {
		list = list->next; //  go to last list item
	}
	if (list->data == NULL){ // It is the first element of the list
		list->data = element;
	} else {
		linked_list *new_list = init_linked_list(); // init new list
		new_list->data = element; // Add data to item
		new_list->previous = list; // Link item to list
		new_list->next = NULL; // Set next item to null
		list->next = new_list; // Link list to item
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
	while (list->previous != NULL){
		list = list->previous; // Find start of list
	}
	void *element;
	if (list->next == NULL){ // Only one item
		// printf("Data is null\n");
		element = list->data; // Get data
		list->data = NULL;
		return element; // Return data
	} else { // If more than one item
		// We move item n+1 into n
		list->data = list->next->data; // Move n+1 data into n
		if (list->next->next != NULL){ // Check if n+2 is null
			list->next = list->next->next; // Skip n+1
			list->next->previous = list; // Asign n+2 previous to n
		} else {
			list->next = NULL;
		}
	}
	return element; // Return element
}


int remove_element(linked_list *list, void *element) {
	while (list->previous != NULL){
		list=list->previous; // Go to first list item
	}
	while (1==1){ // Keep looping
		if (list->data == element){ // Found data
			printf("Found data\n");
			if (list->next != NULL){ // if list only contains 1 item
				printf("First if\n");
				list->next->previous = list->previous; // Replace next item previous
													  // with current items previous
				list->previous->next = list->next; // Replace current item with next item
			} else { // If it is last item
				if (list->previous != NULL) {
					list->previous->next = list->next;
				}
			}
			if (list->next == NULL && list->next == NULL) {
				free(list);
			}
			printf("Returning 0\n");
			return 0; // return found item
		}
		if (list->next != NULL){
			printf("Looped\n");
			list = list->next; // Didn't find item, go to next item
		} else {
			break; // There are no more items
		}
	}
	return -1; // Didn't find element
}
