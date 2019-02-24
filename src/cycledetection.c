#include "graph.h"
#include <stdio.h>

void cycle_detection(graph *g) {
    linked_list* sorted_list = init_linked_list(); // Sorted listed
    linked_list* no_edges = init_linked_list(); // List with no edges

    for (int i = 0; i < g->number_vertices; i++) {
        int list_size = linked_list_size(g->vertices[i].in_neighbours);
        // printf("Vertex %d has size %d\n", i, list_size);
        if (list_size == 0) { // If no edges add it to no_egdes list
            // printf("added vertex %d to no_egdes\n", i);
            add_element(no_edges, &g->vertices[i]);
        }
    }
    int edges_size = linked_list_size(no_edges);

    while (edges_size != 0) {
        vertex *node_n = remove_first(no_edges); // Get node n
        edges_size = linked_list_size(no_edges); // Decrease size of edges list

        add_element(sorted_list, node_n); // Add node n to sorted list

        int size_out = linked_list_size(node_n->out_neighbours);

        for (size_t i = 0; i < size_out; i++) {
            int size_e = linked_list_size(node_n->out_neighbours);
            printf("E size before: %d\n", size_e);
            vertex *edge_e_out = remove_first(node_n->out_neighbours); // Edge e
            int e_id = (*(vertex*) edge_e_out).id; // Id that edge e connect to
            printf("E size after : %d\n", size_e);
            printf("E id: %d\n", e_id);


            // printf("Id of edge is %d\n", id_of_e);
            printf("In-going size before: %d\n", linked_list_size(g->vertices[e_id].in_neighbours));
            if (remove_element(g->vertices[e_id].in_neighbours, node_n) == 0){
                printf("Removed element %d, size is now %d\n", e_id, linked_list_size(g->vertices[e_id].in_neighbours));
            } else {
                printf("Could not find element %d\n", e_id);
            }
            printf("In-going size after: %d\n", linked_list_size(g->vertices[e_id].in_neighbours));
            printf("\n");
        }
    }

}
