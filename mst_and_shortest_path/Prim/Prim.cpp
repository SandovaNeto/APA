// Prim.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

#include "pch.h"

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
# define INF 0x3f3f3f3f 

using namespace std;

typedef pair<int, int> iPair;

class Graph
{
	int V;

	list< pair<int, int> > *adj;

public:
	Graph(int V);

	void addEdge(int u, int v, int w);

	void primMST();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

void Graph::primMST()
{
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

	int src = 0;

	vector<int> key(V, INF);

	vector<int> parent(V, -1);

	vector<bool> inMST(V, false);

	pq.push(make_pair(0, src));
	key[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		inMST[u] = true; 

		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;

			if (inMST[v] == false && key[v] > weight)
			{
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
				
			}
		}
	}

	int sum = 0;
	for (int i = 1; i < V; ++i) {
		printf("%d - %d - %d\n", parent[i], i, key[i]);
		sum = sum + key[i];
	}
	cout << "Total: " << sum << '\n';
}

void calculate(std::string file, char delim) {

	cout << "Calculando MST do arquivo: " << file << '\n';
	string line;
	ifstream myfile(file);
	if (myfile.is_open())
	{
		getline(myfile, line);
		int V = std::stoi(line) - 1;
		Graph g(V + 1);
		cout << V << '\n';
		for (int i = 0; i < V; i++)
		{
			getline(myfile, line);
			char delimiter = delim;
			if (line.back() != delimiter) {
				line.push_back(delimiter);
			}
			size_t pos = 0;
			std::string token;
			int j = i + 1;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				if (j > V) break;
				token = line.substr(0, pos);
				g.addEdge(i, j, stoi(token));
				line.erase(0, pos + 1);
				++j;
			}
		}
		g.primMST();
		myfile.close();
	}
	else cout << "Unable to open file\n";

}


int main()
{

	
	calculate("dij10.txt", ' ');
	calculate("dij20.txt", '\t');
	calculate("dij40.txt", '\t');
	calculate("dij50.txt", '\t');

	

	return 0;
}

// This code is contributed by rathbhupendra 


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
