#include <stdio.h>
#include <string.h>
#include <time.h>
#define RANGE 255
 
// Faz o Sorting de uma array em ordem alfabetica

void countSort(char arr[])
{
    // Array de saida
    char output[strlen(arr)];
 
    // Cria uma array para guardar o count de cada caractere e inicializa esse array com 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
 
    // Armazena o count de cada caractere
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];
 
    // Muda o count[i] para que agora ele contenha a posição do seu caractere no array de saida
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];
 
    // Monta o array de saida
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
 
    // Copia o array de saida para o array de entrada, agora contendo os caracteres ordenados
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
 

int main()
{

    clock_t start, end;
    double cpu_time_used;


    char arr[] = "xadkmferfntjrnfiwjdmfiwjeaajnfpirn   f4";
 
    start = clock();

    countSort(arr);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    printf("\nCounting Sort Completo\n\n");
    printf("Tempo de Execução %f segundo(s).\n\n", cpu_time_used);

    printf("Array de caracteres ordenados é: %sn", arr);
    return 0;
}
