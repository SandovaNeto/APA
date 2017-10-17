#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void LeArquivo(string Entrada, vector <int> V, vector <int> W){

    int Peso, Valor;
    ifstream Arquivo(Entrada);
    while(Arquivo >> Peso >> Valor){

        V.push_back(Valor);
        W.push_back(Peso);

    }

}



int max(int a, int b) { return (a > b)? a : b; }


int knapSack(int W, vector <int> wt, vector <int> val, int n)
{

    if (n == 0 || W == 0)
        return 0;


    if (wt[n-1] > W){

        return knapSack(W, wt, val, n-1);

    }


    else{


                return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1));

    }


}


int main()
{
    vector <int> val = {1, 6, 18, 22, 28, 40,60};
    vector <int> wt = {1, 2, 5, 6, 7, 9,11};
    int  W = 23;
    int n = val.size();
    cout << "O lucro maximo é de: " << knapSack(W, wt, val, n) << "\n";
    return 0;
}
