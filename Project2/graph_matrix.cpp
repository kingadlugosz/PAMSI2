#include "graph_matrix.h"

GraphMatrix::GraphMatrix(const char* filename) {
	current_number_of_edge = 0;
	ifstream file;
	file.open(filename);
	if (!file.is_open())cout << "failed to open a file\n";
	else {
		int word;
		file >> word;
		this->number_of_edge = word;
		file >> word;
		this->size = word;
		file >> word;
		this->starting_vertex_id=word;
		this->density = 1 + (200 * number_of_edge / (size * (size - 1)));
		int control_number_of_edges_in_file = 0;

		this->vertex = new Vertex[size];
		this->edge = new Edge[number_of_edge];

		this->adjacent_matrix = new Edge * [size];
		for (int i = 0; i < size; i++) {
			adjacent_matrix[i] = new Edge[size];
			for (int j = 0; j < size; j++) {
				if (j == i)adjacent_matrix[i][j].weight = 0;
				else adjacent_matrix[i][j].weight = INF;
			}
		}
		for (int i = 0; i < size; i++) {
			vertex[i].id = i;
		}

		// wczytanie z pliku krawedzi
		while (file.good()) {
			file >> word;
			int source_id = word;
			file >> word;
			int destination_id = word;
			file >> word;
			int weight = word;
			control_number_of_edges_in_file++;
			if (control_number_of_edges_in_file > number_of_edge) {
				cout << "You are trying to add more edges than You declared";
				break;
			}
			else {
				addEdge(source_id, destination_id, weight);
			}
		}
		file.close();
	}
}



GraphMatrix::GraphMatrix(int number_of_vertex, int density) {
	current_number_of_edge = 0;
	this->size = number_of_vertex;
	this->density = density;
	this->number_of_edge = (density * number_of_vertex * (number_of_vertex - 1)) / 200;
	this->vertex = new Vertex[number_of_vertex];
	this->edge = new Edge[number_of_edge];

	this->adjacent_matrix = new Edge * [size];
	for (int i = 0; i < size; i++) {
		adjacent_matrix[i] = new Edge[size];
		for (int j = 0; j < size; j++) {
			if (j == i)adjacent_matrix[i][j].weight = 0;
			else adjacent_matrix[i][j].weight = INF;
		}
	}
	for (int i=0; i < size; i++) {
		vertex[i].id = i;
	}

}

GraphMatrix::~GraphMatrix() {
	for (int i = 0; i < size; i++) {
		delete[] adjacent_matrix[i];
	}
	delete[] adjacent_matrix;
	delete[] vertex;
	delete[] edge;
}


void GraphMatrix::addEdge(int source_id, int destination_id, int weight) {
	if (current_number_of_edge >= number_of_edge)cout << "!!! ERROR !!!\n You are trying add too many edges\n\n";
	else {
		edge[current_number_of_edge].destination_id = destination_id;
		edge[current_number_of_edge].source_id = source_id;
		edge[current_number_of_edge].weight = weight;
		adjacent_matrix[source_id][destination_id] = edge[current_number_of_edge];
		adjacent_matrix[destination_id][source_id] = edge[current_number_of_edge];
	}
	current_number_of_edge++;
}

void GraphMatrix::print_adjacent_matrix() {
	cout << "graf zawiera " << size << " wierzcholkow i " << number_of_edge << " krawedzi- czyli " << density << "% gestosci\n";
	for (int w = 0; w < size; w++) {
		for (int k = 0; k < size; k++) {
			cout<<adjacent_matrix[w][k].weight<<"\t";
		}
		cout << "\n";
	}
}

void GraphMatrix::make_random(int weight_max, int weight_min) {
	srand((unsigned int)time(NULL));
	if (density == 100) {
		for (int source_id = 0; source_id < size; source_id++) {
			for (int destination_id = 0; destination_id < source_id; destination_id++) {
				if (destination_id == source_id);
				else {
					int weight = std::rand() % (weight_max-weight_min+1) + weight_min;
					addEdge(source_id, destination_id, weight);
				}
			}
		}
	}
	else {
		srand((unsigned int)time(NULL));
		int licznik = 0;
		while (licznik<number_of_edge) {
			int source_id = std::rand()%size;
			int destination_id = std::rand()%size;
			if (adjacent_matrix[source_id][destination_id].weight != INF || adjacent_matrix[source_id][destination_id].weight == 0);
			else {
				int weight = std::rand() % (weight_max - weight_min + 1) + weight_min;
				addEdge(source_id, destination_id, weight);
				licznik++;
			}
		}
	};
}

/*
void GraphMatrix::save_results(int start_id,const char* filename) {
	ofstream file;
	file.open(filename);
	for (int source_id = 0; source_id < size; source_id++) {
		file << "wierzcholek " << vertex[source_id].id<<": waga-"<< vertex[source_id].distance<<" droga: ";
		int road = source_id;
		if (start_id == source_id)file<< "wierzcholek poczatkowy";
		else {
			while (true) {
				file << "->" << vertex[road].origin ;
				road = vertex[road].origin;
				if (road == start_id)break;

			}
		}
		file << "\n";
	}
	
}
*/










































// #######################
/*
void Graph::bellman_ford(int source_id) {
	vertex[source_id].distance = 0;
	for (int i = 1; i <= size - 1; i++) {
		for (int w = source_id; w < size; w++) {
			for (int k = 0; k < w; k++) {
				//if (vertex[k].distance == INF);
				if (vertex[k].distance > adjacent_matrix[w][k].weight + vertex[w].distance) {
					vertex[k].distance = adjacent_matrix[w][k].weight + vertex[w].distance;
					vertex[k].origin = w;
				}
				else if (vertex[w].distance > adjacent_matrix[w][k].weight + vertex[k].distance) {
					vertex[w].distance = adjacent_matrix[w][k].weight + vertex[k].distance;
					vertex[k].origin = k;
				}
			}
		}
		for (int w = 0; w < source_id; w++) {
			for (int k = 0; k < w; k++) {
				if (vertex[k].distance == INF);
				else if (vertex[k].distance > adjacent_matrix[w][k].weight + vertex[w].distance) {
					vertex[k].distance = adjacent_matrix[w][k].weight + vertex[w].distance;
					vertex[k].origin = w;
				}
				else if (vertex[w].distance > adjacent_matrix[w][k].weight + vertex[k].distance) {
					vertex[w].distance = adjacent_matrix[w][k].weight + vertex[k].distance;
					vertex[k].origin = k;
				}
			}
		}
	}
	cout << "\n ############ WYNIKI #############\n";
	for (int i = 0; i < size; i++) {
		cout << "wierzcholek " << i << " jest oddalony od wierzcholka " << source_id << " o: " << vertex[i].distance << "\n";
	}

}
*/
//########################