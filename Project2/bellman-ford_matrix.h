#pragma once
#include "vertex_edge.h"
#include "graph_matrix.h"

/*
funkcja realizujaca algorymt Bellmana-Forda dla reprezentacji grafu w formie macierzy sasiedztwa
*/
Vertex* bellman_ford_matrix(GraphMatrix*,int starting_vertex_id);