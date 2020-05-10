#include "graph_matrix.h"
#include "graph_list.h"
#include "bellman-ford_matrix.h"
#include "bellman-ford_list.h"
#include "save_results_to_file.h"
#include <chrono>

void run_test_list(int quantity,int density,int number_of_vertex) {
	float time = 0;
	int starting_vertex_id = 2;
	for (int i = 0; i < quantity; i++) {
		GraphList graph(number_of_vertex);
		graph.make_random(10, 1, density);
		cout << "badanie nr. " << i << ". START:";
		auto start = std::chrono::steady_clock::now();
		bellman_ford_list(&graph, starting_vertex_id);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		cout << "STOP: " << elapsed_seconds.count() << "\n";
		time = time + elapsed_seconds.count();
	}
	cout << "\n ################# WYNIKI ################# \n";
	cout << "Liczba wierzcholkow: " << number_of_vertex << "; Gestosc:  " << density << "; czas sr: " << time/quantity << "\n";
}

void load_from_file_save_to_file_LIST(const char* data, const char* results) {
	GraphList graph(data);
	save_results_to_file(bellman_ford_list(&graph, graph.starting_vertex_id), graph.starting_vertex_id, graph.size, results);
}

void run_test_matrix(int quantity, int density, int number_of_vertex) {
	float time = 0;
	int starting_vertex_id = 2;
	for (int i = 0; i < quantity; i++) {
		GraphMatrix graph(number_of_vertex, density);
		graph.make_random(10, 1);
		cout << "badanie nr. " << i << ". START:";
		auto start = std::chrono::steady_clock::now();
		bellman_ford_matrix(&graph, starting_vertex_id);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		cout << "STOP: " << elapsed_seconds.count() << "\n";
		time = time + elapsed_seconds.count();
	}
	cout << "\n ################# WYNIKI ################# \n";
	cout << "Liczba wierzcholkow: " << number_of_vertex << "; Gestosc:  " << density << "; czas sr: " << time / quantity << "\n";
}

void load_from_file_save_to_file_MATRIX(const char* data, const char* results) {
	GraphMatrix graph(data);
	save_results_to_file(bellman_ford_matrix(&graph, graph.starting_vertex_id), graph.starting_vertex_id, graph.size, results);
}

int main() {



	bool run = true;
	while (run) {
		cout << "############# MENU ###############\n";
		cout << "1. wygeneruj losowy graf\n";
		cout << "2. wczytaj graf z pliku\n";
		cout << "3. wyjscie\n"; 
		cout << "##################################\n\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "czy zapisac wynik do pliku .txt (1- tak 0-nie)\n";
			bool save;
			cin >> save;
			cout << "liczba wierzcholkow: ";
			int number_of_vertex;
			cin >> number_of_vertex;
			cout << "\ngestosc: ";
			int density;
			cin >> density;
			cout << "\n wierzcholek poczatkowy: ";
			int starting_vertex_id;
			cin >> starting_vertex_id;
			cout << "\nreprezentacja grafu (1-lista 2-macierz): ";
			int representation;
			cin >> representation;
			cout << "\n";
			

			if (representation == 1) {
				GraphMatrix graph(number_of_vertex, density);
				graph.make_random(10, 1);
				cout << "badanie START:";
				auto start = std::chrono::steady_clock::now();
				Vertex* results = bellman_ford_matrix(&graph, starting_vertex_id);
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_seconds = end - start;
				cout << "STOP: " << elapsed_seconds.count() << "\n";
				if (save) {
					save_results_to_file(results, starting_vertex_id, number_of_vertex, "results.txt");
				}
			}
			else if (representation == 2) {
				GraphMatrix graph(number_of_vertex, density);
				graph.make_random(10, 1);
				cout << "badanie START:";
				auto start = std::chrono::steady_clock::now();
				Vertex* results = bellman_ford_matrix(&graph, starting_vertex_id);
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_seconds = end - start;
				cout << "STOP: " << elapsed_seconds.count() << "\n";
				if (save) {
					save_results_to_file(results, starting_vertex_id, number_of_vertex, "results.txt");
				}
			}
			else cout << "zly wybor\n";

			

			break;

		case 2:
			cout << "\n plik z danymi musi nosic nazwe 'data.txt'\n";
			cout << "reprezentacja (1-lista 2-macierz): ";
			int representation2;
			cin >> representation2;
			cout << "\n";
			if (representation2 == 1) {
				load_from_file_save_to_file_LIST("data.txt", "results.txt");
			}
			else if (representation2 == 2) {
				load_from_file_save_to_file_MATRIX("data.txt", "results.txt");
			}
			else cout << "zly wybor\n";
			break;

		case 3:
			return 0;

		default:
			break;

		}
	}

	

	return 0;
}