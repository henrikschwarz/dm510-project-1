#include <stdlib.h>
#include "graph.h"
#include <stdio.h>


graph *read_graph(char *filename) {

	graph new_graph;

	FILE* graph_file = fopen(filename, "r"); // Open filename in read mode

	char n_vertices[1]; // Number of vertices
	fscanf(graph_file, "%s", n_vertices); // Get num
	new_graph.number_vertices = (int)* n_vertices - 48; // Save it in graph

	vertex *vertice  = malloc(sizeof(vertex)*new_graph.number_vertices);

	for (size_t i = 0; i < new_graph.number_vertices; i++) {
			vertex vert;
			linked_list in;
			linked_list out;

			vert.id = (int) i;
			vert.in_neighbours = &in;
			vert.out_neighbours = &out;

			vertice[i] = vert;
	}

	printf("%d\n", vertice);
	return NULL;
}

void print_graph(graph *g) {

}
