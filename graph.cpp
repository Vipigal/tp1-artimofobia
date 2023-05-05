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
	return _conexao[v1][v2] != -1;
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
				int pesoAtual = getPesoAresta(v, i);
				if(pesoAtual != -1){
					int distNova = dist[v] + pesoAtual;
					if(distNova < dist[i]){
						dist[i] = distNova;
						filaPrioridade.push(make_pair(dist[i], i));
					}
				}
			}
		}
	}

	return (dist[destino] != INF) ? dist[destino] : -1;

}

//4 
//0-3

int Grafo::menorCaminho(vertice origem, vertice destino){
	Grafo* Gaux = new Grafo(2*_numVertices+3);
	for(int i = 0; i < _numVertices; i++){
		pair<int, int> i_imparr(i,1);
		vertice i_impar = (i * 2) + 1;
		vertice i_par = (i * 2);
		for(int j = i; j<_numVertices; j++){
			vertice j_impar = (j * 2) + 1;
			vertice j_par = (j * 2);
			if(existeAresta(i,j)){
				int peso = getPesoAresta(i,j);
				Gaux->adicionaAresta(i_impar, j_par, peso);
				Gaux->adicionaAresta(i_par, j_impar, peso);
			}
		}
	}

	int result = Gaux->dijkstra(origem*2, destino*2);
	return result;

}