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
	return list; // List pointer
}

void add_element( linked_list *list, void *element) {
	while (list->next != NULL) {
		list = list->next; //  go to last list item
	}
	linked_list *n_list = init_linked_list(); // init new list
	n_list->data = element;
	n_list->previous = list;
	list->next = n_list;
}

int linked_list_size(linked_list *list) {
	int count; // Counter
	while (list->previous != NULL) { // Go to start
		list=list->previous;
	}
	while (list->next != NULL){ // Go to end of list
		count++; // Count items.
	}
	return count;
}

void *remove_first(linked_list *list) {
	while (list->previous != NULL){
		list = list->previous; // Find start of list
	}
	list->next->previous = NULL; // Remove reference to the first item
	return list;
}

int remove_element(linked_list *list, void *element) {
	while (list->previous != NULL){
		list=list->previous; // Go to first list item
	}
	while (list->next !=  NULL){ // Go to start of list
		if (list->data == element){ // Find data
			list->next->previous = list->previous; //previous item->next = item->next
			list->previous->next= list->next; // next item->previous = item->previous
			free(list); // Free space
			return 0; // return found integer
		}
		list=list->next; // Didn't match element, go to next item
	}
	return -1; // Didn't find element
}
