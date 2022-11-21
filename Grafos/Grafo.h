#pragma once
#include "LLDE.h"

class Grafo
{
	class Aresta {
	private:
		int v1;
		int v2;
		int peso;

	public:
		Aresta(int v1, int v2, int peso) {
			this->v1 = v1;
			this->v2 = v2;
			this->peso = peso;
		}

		int v1() { return v1; }
		int v2() { return v2; }
		int peso() { return peso; }
	};

	class Celula {
	public:
		int vertice;
		int peso;

		Celula();

		Celula(int vertice, int peso) {
			this->vertice = vertice;
			this->peso = peso;
		}

		bool equals(Celula obj) {
			Celula item = obj;
			return (vertice == item.vertice);
		}
	};

private:
	//minhaNamespace::LLDE<minhaNamespace::LLDE<Celula>>* adj = nullptr;
	//minhaNamespace::LLDE<minhaNamespace::LLDE<Celula>>* adj = nullptr;
	minhaNamespace::LLDE<Celula> *adj = nullptr;
	int numVertices = 0;

public:
	Grafo(int numVertices) {
		//adj = new minhaNamespace::LLDE<Celula>(numVertices);
		adj = new minhaNamespace::LLDE<Celula>[numVertices];
		this->numVertices = numVertices;

		for (int i = 0; i < numVertices; i++) {
			//adj[i] = new minhaNamespace::LLDE<minhaNamespace::LLDE<Celula>>();
			/*minhaNamespace::LLDE<Celula> item = minhaNamespace::LLDE<Celula>();
			adj->inserirInicio(item);*/
			Celula item = Celula();
			adj->inserirInicio(item);
		}
	}

	void insereAresta(int v1, int v2, int peso) {
		Celula item = Celula(v2, peso);
		adj[v1].inserirInicio(item);
	}

	bool existeAresta(int v1, int v2) {
		Celula item = Celula(v2, 0);
		return (adj[v1].getQuantidadeDeElementos() == 0); // AJUSTAR METODO DE BUSCA
	}

	bool listaAdjVazia(int v) {
		return adj[v].estaVazio();
	}


};

