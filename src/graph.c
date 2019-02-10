#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


graph *read_graph(char *filename) {

	graph *new_graph = malloc(sizeof(graph));
	FILE* graph_file = fopen(filename, "r"); // Open filename in read mode

	char n_vertice[200]; // String buffer for vertice number
	fgets(n_vertice, 200, graph_file); // Load buffer

	size_t length_str = strlen(n_vertice)-1; // Remove null character from length

	for (size_t i = 0; i < length_str; i++) {
		int new_char = (int) (n_vertice[i]-48)*pow(10,(length_str-i)-1); // Convert int to char with right weigth
		new_graph->number_vertices += new_char;
	}
	new_graph->vertices = malloc(sizeof(vertex)*new_graph->number_vertices); // Allocate memory for vertices
	printf("Size of vertices is %lu \n", sizeof(vertex)*new_graph->number_vertices);
	for (size_t vert = 0; vert < new_graph->number_vertices; vert++) { // Init each vertices
		new_graph->vertices[vert].id =(int) vert;
		new_graph->vertices[vert].in_neighbours = init_linked_list();
		new_graph->vertices[vert].out_neighbours = init_linked_list();
	}
	printf("Vertice id of vetice #1 is %d\n", new_graph->vertices[0].id);

	char list_buffer[200]; // String buffer for adjencency matrix

	for (size_t i = 0; i < new_graph->number_vertices; i++) {
		fgets(list_buffer, 200, graph_file); // Load buffer
		for (size_t j = 0; j < strlen(list_buffer); j++) {
			if (list_buffer[j] == 1){ // If connected, populate vertices
				add_element(new_graph->vertices[i].out_neighbours, &new_graph->vertices[j]);
				add_element(new_graph->vertices[j].in_neighbours, &new_graph->vertices[i]);
			}
		}
	}
	return new_graph; // Return the graph
}

void print_graph(graph *g) {
		for (size_t i = 0; i < g->number_vertices; i++) {
			linked_list *list_item = g->vertices[i].out_neighbours; // pointer to first out neighbors list item
			printf("trying to print vetex id\n");
			printf("vertex id is %d\n", *(int*) (*(vertex) list_item->data)->id);
			// for (int j = 0; j < linked_list_size(list_item); j++) {
			// 	if (list_item->next != NULL){
			// 		// printf("%d\n", (*(vertex*) list_item->data).id);
			// 	}
			// }
			printf("Doen with iteration number %lu", i);
		}
}
