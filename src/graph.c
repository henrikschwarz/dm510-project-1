#include <stdlib.h>
#include "graph.h"
#include <stdio.h>


graph *read_graph(char *filename) {

	FILE* graph_file = fopen(filename, "r"); // Open filename in read mode

	char string[60];

	if (fgets(string, 60, graph_file) != NULL){
		printf("%s", string);
 	}

	return NULL;
}

void print_graph(graph *g) {

}
