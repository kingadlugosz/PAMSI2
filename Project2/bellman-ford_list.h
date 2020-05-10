#pragma once
#include "vertex_edge.h"
#include "graph_list.h"

/*
funkcja realizujaca algorymt Bellmana-Forda dla reprezentacji grafu w formie listy sasiedztwa
*/
Vertex* bellman_ford_list(GraphList*, int starting_vertex_id);