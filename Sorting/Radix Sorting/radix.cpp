#include<iostream>
#include <time.h>
using namespace std;
 
// Funçaão que acha o maior valor no array
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// Fução que realiza counting sort do array
void countSort(int arr[], int n, int exp)
{
    int output[n]; // array de saida
    int i, count[10] = {0};
 
    // Guarda o contador de ocorrencias em count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // muda count[i] para que agora ele contenha o valor correto
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Constroi o array de saida
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copia o array de saida para o de entrada, agora na ordem correta
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
//Função que ordena o array com n elementos
void radixsort(int arr[], int n)
{
    // Achar o maior numero para descobrir o numero de digitos
    int m = getMax(arr, n);
 
    // Fazer o counting sort para cada digito. Note that instead
    // Ao inves de passar o digito, passamos exp (10^i onde i é o digito atual).
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// Função para mostrar o array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}

int main()
{
    int arr[] = {100
, 9356
, 5028
, 9057
, 9511
, 4095
, 8951
, 467
, 2026
, 3426
, 5256
, 9989
, 3903
, 5023
, 7588
, 1416
, 3700
, 2492
, 6397
, 5252
, 7042
, 6074
, 2746
, 4321
, 8382
, 3621
, 2404
, 72
, 2346
, 9024
, 6723
, 9555
, 8731
, 6222
, 4892
, 9882
, 8729
, 2456
, 6828
, 4534
, 1218
, 7416
, 1616
, 1410
, 3728
, 6501
, 9729
, 1087
, 5598
, 3902
, 7247
, 1247
, 9473
, 2988
, 9542
, 7200
, 1772
, 5605
, 5976
, 8691
, 4729
, 6541
, 3888
, 2446
, 7426
, 9702
, 7378
, 4958
, 3556
, 6368
, 6296
, 6951
, 2327
, 9786
, 1295
, 6268
, 8103
, 5911
, 5094
, 4207
, 9621
, 6500
, 3476
, 6330
, 7142
, 6807
, 4257
, 605
, 6389
, 4459
, 6592
, 2048
, 5425
, 1119
, 8747
, 3878
, 6124
, 4845
, 5030
, 6881
, 3521};
    int n = sizeof(arr)/sizeof(arr[0]);

     clock_t start, end;
    double cpu_time_used;

    start = clock();

    radixsort(arr, n);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    cout << "\n Radix Sort terminado." << "\n";
    cout << "\nTempo de Execução: " << cpu_time_used << " segundo(s).\n\n";

    print(arr, n);
    return 0;
}
