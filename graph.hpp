#ifndef GRAPH_HPP
#define GRAPH_HPP

#define vertice int
#define INF 0x3f3f3f3f

#include <queue>
#include <vector>

class Grafo {
private:
  int _numVertices;
  int _numArestas;
  std::vector<std::vector<int>> _conexao;

public:
  /**
   * @brief Constrói um novo objeto Grafo
   *
   * @param numVertices Número de vértices do grafo
   */
  Grafo(int numVertices);

  /**
   * @brief Adiciona uma aresta v1-v2 no grafo.
   *
   * @param v1 identificador do vértice 1
   * @param v2 identificador do vértice 2
   */
  void adicionaAresta(vertice v1, vertice v2, int peso);

  /**
   * @brief Remove uma aresta do grafo.
   *
   * @param v1 identificador do vértice 1
   * @param v2 identificador do vértice 2
   */
  void removeAresta(vertice v1, vertice v2);

  /**
   * @brief Checa se existe uma aresta no grafo.
   *
   * @param v1 identificador do vértice 1
   * @param v2 identificador do vértice 2
   * @return true
   * @return false
   */
  bool existeAresta(vertice v1, vertice v2) const;

  /**
   * @brief Getter para o numero total de vértices do grafo
   *
   */
  int getNumVertices() const;

  /**
   * @brief Getter para o numero total de arestas do grafo
   *
   */
  int getNumArestas() const;

  /**
   * @brief Getter para o peso de uma aresta entre v1 e v2.
   *
   * @param v1 identificador do vértice 1
   * @param v2 identificador do vértice 2
   * @return int
   */
  int getPesoAresta(vertice v1, vertice v2) const;

  /**
   * @brief Imprime o grafo por meio da lista de adjacencia de cada vertice
   *
   */
  void imprimir() const;

  /**
   * @brief Imprime os pesos entre cada aresta do grafo.
   *
   */
  void imprimirPesos() const;

  int dijkstra(vertice origem, vertice destino);

  int menorCaminho(vertice origem, vertice destino);
};

#endif // GRAPH_HPP