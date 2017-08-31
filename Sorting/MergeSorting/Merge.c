
#include<stdlib.h>
#include<stdio.h>
 

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /*Arrays temporarios */
    int L[n1], R[n2];
 
    /* Copiar dados para L[] e R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Une os dois Arrays em um [l..r]*/
    i = 0; // Indice inicial do Array da esquerda
    j = 0; // Indice inicial do Array da direita
    k = l; // Indice inicial o Array final
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) //Se o elemento da esquerda for menor, o array recebe esquerda
        {
            arr[k] = L[i];
            i++;
        }
        else // Se não, o Array recebe direita
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Acha a metade do Array
        int m = l+(r-l)/2;
 
        // Recursão
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int main()
{
    int arr[] = {22, 51, 35, 1, 3, 1, 5, 12, 33, 97, 76};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Array antes do Sorting \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nArray depois do Sorting \n");
    printArray(arr, arr_size);
    return 0;
}
