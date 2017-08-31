
#include<stdio.h>
 

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // ultimo elemento do array
    int i = (low - 1);  // indice do primeiro elemento
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot) //se o elemento atual é menor ou igual ao ultimo indice
        {
            i++;    // incrementa o indice do primeiro elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);//Caso não, troca o ultimo elemento pela proxima posição no array
    return (i + 1);
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high); //pi é o indice do ultimo elemento que agora foi para sua posição correta no array
 
        //Chamada recursiva da função
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 

int main()
{
    int arr[] = {12, 11, 5, 55, 1, 1, 6, 44, 66, 33, 21, 76};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array antes do Sorting: \n");
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printf("\nArray depois do Sorting: \n");
    printArray(arr, n);
    return 0;
}
