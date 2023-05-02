#include "graph.hpp"
#include <iostream>

using namespace std;

//Todo: adicionar checks de parametros -> Ver se nao esta sobrescrevendo nenhuma aresta e testar os indices

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

int Grafo::dijkstra(vertice origem, vertice destino){
	int totalVertices = getNumVertices();

	vector<int> dist(totalVertices, INF); //Vetor que armazena as distancias dos vertices
	vector<bool> visitados(totalVertices, false); //Vetor que armazena quais vertices ja foram visitados

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> filaPrioridade; //Fila de prioridades com o menor elemento no topo

	dist[origem] = 0;
	filaPrioridade.push(make_pair(dist[origem], origem));

	while(!filaPrioridade.empty()){
		pair<int, int> p = filaPrioridade.top();
		vertice v = p.second;
		filaPrioridade.pop();

		if(visitados[v] == false){
			visitados[v] = true;
			
			for(int i=0; i<totalVertices; i++){
				if(_conexao[v][i] != -1){
					int alt = dist[v] + _conexao[v][i];
					if(alt < dist[i]){
						dist[i] = alt;
						filaPrioridade.push(make_pair(dist[i], i));
					}
				}
			}
		}
	}

	return (dist[destino] != INF) ? dist[destino] : -1;

}