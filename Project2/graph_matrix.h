#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "vertex_edge.h"
using namespace std;
#define INF 9999



/*
klasa bedaca reprezentacja grafu za pomoca macierzy sasiedztwa
zawiera w sobie tablice 2D ktorej kazde pole odpowiada krawedzi, a indexy symbolizuja wierzcholki
*/
class GraphMatrix {

public:
	int size;						// zmienna stanowiaca liczbe wierzcholkow w grafie
	int number_of_edge;				// zmienna stanowiaca liczbe krawedzi w grafie zadeklarowana podczas jego tworzenia
	int density;					// gestosc grafu
	int current_number_of_edge;		// zmienna stanowiaca aktualna liczbe krawedzi w grafie- uzywana do kontroli podczas dodawania kolejnych krawedzi
	Edge* edge;						
	Vertex* vertex;					// zmienna bedaca lista wierzcholkow- uzywana do zapisu wyniku algorytmu do pliku
	Edge** adjacent_matrix;			// zmienna bedaca macierza sasiedzctwa deklarowana dynamicznie w zaleznosci od zadanego rozmiaru grafu
	int starting_vertex_id;			// zmienna stanowiaca wierzcholek poczatkowy- potrzebna do realizacji algorytmu wczytywania z pliku
																
	void addEdge(int,int,int);									// funkcja dodajaca krawedz do grafu
	void print_adjacent_matrix();								// funckja wyswietlajaca macierz saiedztwa, wykorzystywana na etapie tworzenia programu do konroli poprawnosci konstrukcji macierzy sasiedztwa
	void make_random(int weight_max, int weight_min);			// funkcja tworzaca graf o zadanej gestosci o losowych wagach z zadanego przedzialu
	
		
	GraphMatrix(int number_of_vertex, int density);				// konstruktor tworzacy graf o zadanej ilosci wierzcholkow i gestosci
	GraphMatrix(const char* filename);							// konstruktor tworzacy z pliku .txt
	~GraphMatrix();												// destruktor uwalniajacy zarezerwowana dynamicznie pamiec

};