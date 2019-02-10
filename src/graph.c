#include <stdlib.h>
#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


graph *read_graph(char *filename) {

	graph *new_graph = malloc(sizeof(graph));

	FILE* graph_file = fopen(filename, "r"); // Open filename in read mode

	char n_vertice[200];
	fgets(n_vertice, 200, graph_file);

	size_t length_str = strlen(n_vertice)-1;

	for (size_t i = 0; i < length_str; i++) {
		int new_char = (int) (n_vertice[i]-48)*pow(10,(length_str-i)-1);
		new_graph->number_vertices += new_char;
	}
	vertex *vertice = malloc(sizeof(vertex)*new_graph->number_vertices);
	for (size_t vert = 0; vert < new_graph->number_vertices; vert++) {
		vertice[vert].id =(int) vert;
		vertice[vert].in_neighbours = init_linked_list();
		vertice[vert].out_neighbours = init_linked_list();
	}

	char list_buffer[200];

	for (size_t i = 0; i < new_graph->number_vertices; i++) {
		fgets(list_buffer, 200, graph_file);
		for (size_t j = 0; j < strlen(list_buffer); j++) {
			if (list_buffer[j] == 1){
				add_element(vertice[i].out_neighbours, &vertice[j]);
				add_element(vertice[j].in_neighbours, &vertice[i]);
			}
		}
	}
	return &new_graph;
}

void print_graph(graph *g) {

}
