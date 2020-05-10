#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "vertex_edge.h"
using namespace std;
#include "vertex_edge.h"

/*
klasa stanowiaca reprezentacje grafu w formie listy sasiedzwa
zawiera liste wskaznikow klasy krawedz i funkcje operujace na niej
*/
class GraphList {
public:

	int current_number_of_edges = 0;		// zmienna stanowiaca aktualna ilosc krawedzi w grafie- uzywane w kontroli dodawania nowych krawedzi, aby nie przekroczyc maxymalnej ilosci
	int size;								// zmienna stanowiaca ilosc wierzcholkow w grafie	
	int starting_vertex_id;					// zmienna stanowiaca wierzcholek poczatkowy- potrzebna do realizacji algorytmu wczytywania z pliku
	Edge** arr;								// zmienna stanowiaca liste wskaznikow klasy krawedz bedaca lista sasiedztwa
	Edge* get_edge_list(int, Edge*, int);	// funkcja zwracajaca wskaznik do krawedzi o zadanych parametrach
	void addEdge(int destination, int source, int weight);			// funkcja dodajaca krawedz do grafu
	void print_list(Edge*);											// funckja wyswietlajaca liste saiedztwa, wykorzystywana na etapie tworzenia programu do konroli poprawnosci konstrukcji listy sasiedztwa
	void make_random(int weight_max, int weight_min, int density);	// funkcja tworzaca graf o zadanej gestosci o losowych wagach z zadanego przedzialu
	
	GraphList(const char* filename);		// konstruktor tworzacy z pliku .txt
	GraphList(int size);					// konstruktor tworzacy graf o zadanej ilosci wierzcholkow
	~GraphList();							// destruktor uwalniajacy zarezerwowana dynamicznie pamiec

};