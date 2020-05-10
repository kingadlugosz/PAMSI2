#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "vertex_edge.h"
using namespace std;

/*
funkcja zapisujaca wynik algorytmu w formie listy wierzcholkow do pliku
*/
void save_results_to_file(Vertex *vertex,int start_id,int size, const char* filename) {
	ofstream file;
	file.open(filename);
	for (int source_id = 0; source_id < size; source_id++) {
		file << "wierzcholek " << source_id << ": waga-" << vertex[source_id].distance << " droga: ";
		int road = source_id;
		if (start_id == source_id)file << "wierzcholek poczatkowy";
		else {
			while (true) {
				file << "->" << vertex[road].origin;
				road = vertex[road].origin;
				if (road == start_id)break;
			}
		}
		file << "\n";
	}

}