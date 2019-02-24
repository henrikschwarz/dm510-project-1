#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


graph *read_graph(char *filename) {

	graph* new_graph = malloc(sizeof(graph));

	FILE* graph_file = fopen(filename, "r"); // Open filename in read mode

	char n_vertices[100];
	fgets(n_vertices, 100, graph_file); // Get first line containing number of verices
	int n_vertice_len = (int) strlen(n_vertices)-1; // Remove NULL char
	int sum = 0;
	for (int i = 0; i < n_vertice_len; i++) {
		int char_to_int =(int) n_vertices[i]-48; // Convert single
		 										 // char from char array to int
		int expontent = (n_vertice_len-i)-1; // Exponent for pow function
		sum += char_to_int * (int) pow(10, expontent); // Summize number
	}

	new_graph->number_vertices = sum;

	new_graph->vertices = malloc(sizeof(vertex)*new_graph->number_vertices);
	// printf("number of vertice is %d \n", new_graph->number_vertices);
	// printf("Vertices %p\n", &new_graph->vertices);

	for (size_t i = 0; i < new_graph->number_vertices; i++) {

			linked_list* in = init_linked_list();
			linked_list* out = init_linked_list();

			new_graph->vertices[i].id = (int) i;
			new_graph->vertices[i].in_neighbours = in;
			new_graph->vertices[i].out_neighbours = out;
	}

	char strBuffer[256];

	for (size_t i = 0; i < new_graph->number_vertices; i++) {
		// printf("Starting vertex %lu\n", i);
		fgets(strBuffer, 256, graph_file);
		for (size_t j = 0; j < strlen(strBuffer); j++) {
			if ((int) strBuffer[j]-48 == 1) {
				// printf("Adding to %lu vertex %lu\n", j, i);
				// printf("Vertex %lu list item: prev %p, next %p\n", i, new_graph->vertices[i].out_neighbours->previous, new_graph->vertices[i].out_neighbours->next);
				// printf("Adding to vertex %lu\n", i);
				add_element(new_graph->vertices[i].out_neighbours,  &new_graph->vertices[j]);
				add_element(new_graph->vertices[j].in_neighbours, &new_graph->vertices[i]);
			}
		}
	}
	return new_graph;
}

void print_graph(graph *g) {
	for (size_t i = 0; i < g->number_vertices; i++) {
		linked_list *l_list = g->vertices[i].out_neighbours;
		int vertices_length = linked_list_size(l_list);
		 while (vertices_length != 0){
			int vert = (*(vertex*) l_list->data).id;
			printf("vertex %lu is connected to vertex %d\n", i, vert);
			if (l_list->next != NULL){
				l_list = l_list->next;
			} else {
				break;
			}
		}
	}
}
