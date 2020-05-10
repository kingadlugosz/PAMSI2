#include "bellman-ford_list.h"


Vertex* bellman_ford_list(GraphList*graph, int source_id) {
	Vertex* vertex = new Vertex[graph->size];
	vertex[source_id].distance = 0;

	for (int i = 0; i <= graph->size - 1; i++) {
		for (int id = source_id; id < graph->size; id++) {
			Edge* ptr = graph->arr[id];
			while (ptr != nullptr) {
				if (vertex[ptr->destination_id].distance> vertex[id].distance + ptr->weight) {
					vertex[ptr->destination_id].distance = vertex[id].distance + ptr->weight;
					vertex[ptr->destination_id].origin = id;
				}
				ptr = ptr->destination_ptr;
			}
		}
		for (int id = 0; id < source_id; id++) {
			Edge* ptr = graph->arr[id];
			while (ptr != nullptr) {
				if (vertex[ptr->destination_id].distance > vertex[id].distance + ptr->weight) {
					vertex[ptr->destination_id].distance = vertex[id].distance + ptr->weight;
					vertex[ptr->destination_id].origin = id;
				}
				ptr = ptr->destination_ptr;
			}
		}
	}

	
	return vertex;
	
}