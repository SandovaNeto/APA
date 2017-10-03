
#include <stdio.h>
#include <limits.h>
 
//Numero de Vertices no Grafo
#define V 5
 
//Acha a menor key dentro da MST
int minKey(int key[], bool mstSet[])
{
   //Inicializa
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
//Printa a MST
int printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
//Constroi e printa a MST para grafo de adjacencia
void primMST(int graph[V][V])
{
     int parent[V]; // Array qye guarda a MST
     int key[V];   //Keys para achar o menor valor
     bool mstSet[V];  //Representar indices vistos
 
     //Inicializa com INT_MAX
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     //Associa a root ao indice 1
     key[0] = 0;     
     parent[0] = -1;
 
 
     for (int count = 0; count < V-1; count++)
     {
        //Acha a key minima dos vertices ainda não visitados
        int u = minKey(key, mstSet);
 
        // Adiciona o Vertice para a MST
        mstSet[u] = true;
 
        //Atualiza o valor
        for (int v = 0; v < V; v++)
 

          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 

     printMST(parent, V, graph);
}
 
 

int main()
{

   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    primMST(graph);
 
    return 0;
}
