#include "graph.hpp"
#include <iostream>

using namespace std;

Grafo::Grafo(int numVertices) : _conexao(numVertices, std::vector<int>(numVertices, -1)){
    _numVertices = numVertices;
	_numArestas = 0;
}

void Grafo::adicionaAresta(vertice v1, vertice v2, int peso){
	//Como o grafo sera nao-direcionado, a matriz eh simetrica.
	_conexao[v1][v2] = peso;
	_conexao[v2][v1] = peso;
	_numArestas++;
}

void Grafo::removeAresta(vertice v1, vertice v2){
	_conexao[v1][v2] = -1;
	_conexao[v2][v1] = -1;
	_numArestas--;
}

bool Grafo::existeAresta(vertice v1, vertice v2) const{
	return _conexao[v1][v2];
}

int Grafo::getNumVertices() const{
	return _numVertices;
}
int Grafo::getNumArestas() const{
	return _numArestas;
}

int Grafo::getPesoAresta(vertice v1, vertice v2) const{
	return _conexao[v1][v2];
}

void Grafo::imprimir() const{
	for(vertice v = 0; v< _numVertices; v++){
		std::cout<< "Lista de adjacencia do vertice "<< v+1 <<std::endl;
		for(vertice w = 0; w< _numVertices; w++){
			if(_conexao[v][w] != -1)
				std::cout<<"-> "<< w+1 <<std::endl;
		}
	}
}

void Grafo::imprimirPesos() const{
	for(vertice v = 0; v< _numVertices; v++){
		for(vertice w = v; w< _numVertices; w++){
			if(_conexao[v][w] == -1)
				continue;
			std::cout<<"Peso da aresta "<< v+1 <<"-"<< w+1 << " = "<<_conexao[v][w]<<std::endl;

		}
	}
}