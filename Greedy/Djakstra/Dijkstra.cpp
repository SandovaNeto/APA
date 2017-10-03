 
#include <stdio.h>
#include <limits.h>
  
#define V 9 // Numero de Vertices no Grafo
  

int minDistance(int dist[], bool sptSet[]) //Acha o Vertice com o valor de distancia minima dos vertices que ainda não
{						// foram para a arvore de menor caminhos
   //Inicializa o Min
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
//Printa a Solução
int printSolution(int dist[], int n)
{
   printf("Vertice   Distancia da Root\n");
   for (int i = 0; i < V; i++)
      printf("%d \t %d \n", i, dist[i]);
}
  
//Dijkstra
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     //Array de saida contendo o caminho mais curto
  
     bool sptSet[V]; //Array que guarda se o vertice ja foi visitado, 1 caso sim, 0 caso não
  
     // Inicializa todas as distancias com o maximo inteiro possivel e inicializa sptSet com 0
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distancia da Origem para ela mesma é 0
     dist[src] = 0;
  
     // Acha o caminho mais curto
     for (int count = 0; count < V-1; count++)
     {
       //Acha a distancia minima dos vertices ainda não processados
       int u = minDistance(dist, sptSet);
  
       //Marca o Vertice como processado
       sptSet[u] = true;
  
       //Incrementa o Valor da Distancia
       for (int v = 0; v < V; v++)
  

	//Atualiza a distatncia[v] apenas se ja não tiver sido visitado, ou seja se não estivar em sptSet
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     //Pronta a saida
     printSolution(dist, V);
}
  

int main()
{

   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
