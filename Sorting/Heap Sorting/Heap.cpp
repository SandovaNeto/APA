
#include <iostream>
using namespace std;
 

void heapify(int arr[], int n, int i)
{
    int largest = i;  // Inicializa a raiz
    int l = 2*i + 1;  // Define o filho da esquerda
    int r = 2*i + 2;  // Define o Filho da direita
 
    // se o filho da esquerda é maior que a raiz
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // Se o Filho da direita é maior que o maior atual
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // Se o maior não é a raiz
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Chamada recursiva
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Constroi a heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move a raiz atual para o fim
        swap(arr[0], arr[i]);
 
        // Chama a função heapfy na subarvore
        heapify(arr, i, 0);
    }
}
 

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 

int main()
{
    int arr[] = {22, 122, 66, 6, 1, 76, 32, 12, 55, 22, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nArray antes do Sorting: \n";
    printArray(arr, n);
 
    heapSort(arr, n);
 
    cout << "\nArray depois do Sorting: \n";
    printArray(arr, n);
}
