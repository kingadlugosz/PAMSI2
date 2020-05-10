#include "graph_list.h"



GraphList::GraphList(int size) {
	this->size = size;
	this->arr = new Edge * [size]();
	for (int i = 0; i < size; i++) {
		this->arr[i] = nullptr;
	}
}

GraphList::~GraphList() {
	delete[]arr;
}

Edge* GraphList::get_edge_list(int destination, Edge* arr, int weight) {
	Edge* new_edge = new Edge;
	new_edge->destination_id = destination;
	new_edge->weight = weight;
	new_edge->destination_ptr = arr;

	return new_edge;
}

void GraphList::addEdge(int destination, int source,  int weight) {
	Edge* new_edge = get_edge_list(destination, arr[source], weight);
	arr[source] = new_edge;
	new_edge = get_edge_list(source, arr[destination], weight);
	arr[destination] = new_edge;
	current_number_of_edges++;
}

void GraphList::print_list(Edge*ptr) {
	while (ptr != nullptr){
		std::cout << "->" << ptr->destination_id << " ";
		ptr = ptr->destination_ptr;
	}
	std::cout << "\n";
}

void GraphList::make_random(int weight_max, int weight_min,int density) {
	srand((unsigned int)time(NULL));
	if (density == 100) {
		for (int source = 0; source < size; source++) {
			for (int destination = 0; destination < source; destination++) {
				if (source == destination);
				else {
					int weight = std::rand() % (weight_max - weight_min + 1) + weight_min;
					addEdge(destination, source, weight);
				}
			}
		}
	}
	else {
		bool** tab;		//tablica pomocnicza typu bool w celu unikniecia dodania wielokrotnie tej samej krawedzi
		tab = new bool * [size]();
		for (int w = 0; w < size; w++) {
			tab[w] = new bool[size];
			for (int k = 0; k < size; k++) {
				tab[w][k] = false;
			}
		}
		int number_of_edge = (density * size * (size - 1)) / 200;
		while (current_number_of_edges < number_of_edge) {
			int source_id = std::rand() % size;
			int destination_id = std::rand() % size;
			if (source_id == destination_id);
			else if (tab[source_id][destination_id] == true);
			else if (tab[source_id][destination_id] == false) {
				int weight = std::rand() % (weight_max - weight_min + 1) + weight_min;
				addEdge(destination_id, source_id, weight);
				tab[source_id][destination_id] = true;
				tab[destination_id][source_id] = true;
			}
		}
		for (int i = 0; i < size; i++) {
			delete[] tab[i];
		}
		delete[] tab;
	}
}



GraphList::GraphList(const char* filename) {
	ifstream file;
	file.open(filename);
	if (!file.is_open())cout << "failed to open a file\n";
	else {
		int word;
		file >> word;
		int number_of_edges = word;
		file >> word;
		this->size = word;
		file >> word;
		starting_vertex_id = word;
		int control_number_of_edges_in_file = 0;
		this->arr = new Edge * [size]();
		for (int i = 0; i < size; i++) {
			this->arr[i] = nullptr;
		}
		while (file.good()) {
			file >> word;
			int source_id = word;
			file >> word;
			int destination_id = word;
			file >> word;
			int weight = word;
			control_number_of_edges_in_file++;

			if (control_number_of_edges_in_file > number_of_edges) {
				cout << "You are trying to add more edges than You declared";
				break;
			}
			else {
				addEdge(destination_id, source_id, weight);
			}
		}
		file.close();
	}
}