#include "bellman-ford_matrix.h"


Vertex* bellman_ford_matrix(GraphMatrix *graph ,int source_id) {
	graph->vertex[source_id].distance = 0;
	for (int i = 1; i <= graph->size - 1; i++) {
		for (int w = source_id; w < graph->size; w++) {
			for (int k = 0; k < w; k++) {
				//if (vertex[k]->distance == INF);
				if (graph->vertex[k].distance > graph->adjacent_matrix[w][k].weight + graph->vertex[w].distance) {
					graph->vertex[k].distance = graph->adjacent_matrix[w][k].weight + graph->vertex[w].distance;
					graph->vertex[k].origin = w;
				}
				else if (graph->vertex[w].distance > graph->adjacent_matrix[w][k].weight + graph->vertex[k].distance) {
					graph->vertex[w].distance = graph->adjacent_matrix[w][k].weight + graph->vertex[k].distance;
					graph->vertex[w].origin = k;
				}
			}
		}
		for (int w = 0; w < source_id; w++) {
			for (int k = 0; k < w; k++) {
				//if (graph->vertex[k].distance == INF);
				if (graph->vertex[k].distance > graph->adjacent_matrix[w][k].weight + graph->vertex[w].distance) {
					graph->vertex[k].distance = graph->adjacent_matrix[w][k].weight + graph->vertex[w].distance;
					graph->vertex[k].origin = w;
				}
				else if (graph->vertex[w].distance > graph->adjacent_matrix[w][k].weight + graph->vertex[k].distance) {
					graph->vertex[w].distance = graph->adjacent_matrix[w][k].weight + graph->vertex[k].distance;
					graph->vertex[w].origin = k;
				}
			}
		}
	}

	return graph->vertex;
}

