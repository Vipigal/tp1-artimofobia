#include <iostream>
#include "graph.hpp"

#define INF 0x3f3f3f3f


using namespace std;

int main(int argc, char const *argv[]) {
	int numeroDeCidades{0};
	int numeroDeEstradas{0};
	cin>>numeroDeCidades>>numeroDeEstradas;
	Grafo* G = new Grafo(numeroDeCidades);

	int identificadorV1, identificadorV2, peso;
	while(cin>>identificadorV1>>identificadorV2>>peso){
		G->adicionaAresta(identificadorV1 - 1, identificadorV2 - 1, peso);
	}

	G->imprimir();
	G->imprimirPesos();



    return 0;
}