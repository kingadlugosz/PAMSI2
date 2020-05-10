#pragma once
#include <stdio.h>
#include <limits.h>
#include <iostream>
#define INF 9999

/*
klasa stanowiaca 
*/
class Vertex {
public:
    int distance;       // odleglosc od wierzcholka startowego
    int origin;         // numer identyfikacyjny wierzcholka poprzedajacego w najkroszej sciezce- w celu jej odtworzenia
    int id;             // zmienna stanowiaca wlasny numer identyfikacyjny wierzcholka

    Vertex(int id, int distance) {
        this->id = id;
        this->distance = distance;
        this->origin = 0;
    }
    Vertex() {
        this->id = 0;
        this->distance = INF;
        this->origin=0;
    };
};


class Edge {
public:
    int weight;                 // waga krawedzi
    int destination_id;         // id wierzcholka do ktorego prowadzi krawedz
    int source_id;              // id wierzcholka od ktorego prowadzi krawedz
    Edge* destination_ptr;      // wskaznik wykorzystywany w liscie sasiedztwa

    Edge(int source, int destination, int weight) {
        this->destination_id = destination;
        this->weight = weight;
        this->source_id = source;
    }
    Edge() {
        this->destination_id = 0;
        this->weight = 0;
        this->source_id = 0;
    }
};

