// Kruskal.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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

typedef  pair<int, int> iPair;

struct Graph
{
	int V, E;
	vector< pair<int, iPair> > edges;

	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}

	void addEdge(int u, int v, int w)
	{
		edges.push_back({ w, {u, v} });
	}

	int kruskalMST();
};
 
struct DisjointSets
{
	int *parent, *rnk;
	int n;

	DisjointSets(int n)
	{ 
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];

		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;

			parent[i] = i;
		}
	}

	int find(int u)
	{

		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		if (rnk[x] > rnk[y])
			parent[y] = x;
		else
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};


int Graph::kruskalMST()
{
	int mst_wt = 0; 

	sort(edges.begin(), edges.end());

	DisjointSets ds(V);

	vector< pair<int, iPair> >::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if (set_u != set_v)
		{
			cout << u << " - " << v << endl;
 
			mst_wt += it->first;

			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}

void calculate(std::string file, char delim) {

	cout << "Calculando MST do arquivo: " << file << '\n';
	string line;
	ifstream myfile(file);
	if (myfile.is_open())
	{
		getline(myfile, line);
		int V = std::stoi(line) - 1;
		Graph g(V + 1, 10);
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
		int mst_wt = g.kruskalMST();

		cout << "\nTamanho da MST: " << mst_wt << '\n';
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
