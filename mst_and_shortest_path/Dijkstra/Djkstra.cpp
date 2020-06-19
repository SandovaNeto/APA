// Djkstra.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

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


	void shortestPath(int s);
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

void Graph::shortestPath(int src)
{
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			
			}
		}
	}


	for (int i = 0; i < V; ++i)
		printf("Caminho mais curto de 0 a %d: %d\n", i, dist[i]);
}

void calculate(std::string file, char delim) {

	cout << "Calculando	Todos os menores caminhos para o arquivo: " << file << '\n';
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
		g.shortestPath(0);
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