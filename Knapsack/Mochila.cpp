// Mochila.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int W, vector <int> wt, vector <int> val, int n)
{

	if (n == 0 || W == 0)
		return 0;


	if (wt[n - 1] > W) {

		return knapSack(W, wt, val, n - 1);

	}


	else {

		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
			knapSack(W, wt, val, n - 1));

	}


}


int calculate(string file) {
	std::cout << "Calculando Problema da Mochila para o arquivo: " << file << '\n';
	string  first_line;
	int n_products;
	int knapsack_w;
	vector <int> profits;
	vector <int> weigths;
	int result;
	ifstream myfile(file);
	if (myfile.is_open())
	{
		getline(myfile, first_line);
		char delimiter = ' ';
		if (first_line.back() != delimiter) {
			first_line.push_back(delimiter);
		}
		size_t pos = 0;
		std::string token;
		int i = 0;
		std::cout << "N_Produtos Pesos: " << first_line << '\n';
		while ((pos = first_line.find(delimiter)) != std::string::npos) {
			if (i == 0) {
				//std::cout << "Elemento 1 da linha 1: " << i << '\n';
				token = first_line.substr(0, pos);
				n_products = stoi(token);
			}
			else {
				//std::cout << "Elemento 2 da linha 1: " << i << '\n';
				token = first_line.substr(0, pos);
				knapsack_w = stoi(token);
			}

			first_line.erase(0, pos + 1);
			i++;
		}
		string line;
		for (int c_l = 0; c_l < n_products; c_l++)
		{
			getline(myfile, line);
			//std::cout << "Linha: " << i <<  " Le: " << line << '\n';
			char delimiter = ' ';
			if (line.back() != delimiter) {
				line.push_back(delimiter);
			}
			size_t pos = 0;
			std::string token;
			int j = 0;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				if (j == 0) {
					//std::cout << "Elemento " << j << " da linha " << c_l << '\n';
					token = line.substr(0, pos);
					//std::cout << token << '\n';
					weigths.push_back(stoi(token));
					j = j + 1;
				}
				else {
					//std::cout << "Elemento " << j << " da linha " << c_l << '\n';
					token = line.substr(0, pos);
					//std::cout << token << '\n';
					profits.push_back(stoi(token));
					j = 0;
				}
				line.erase(0, pos + 1);
			}

			//std::cout << "Fim do while" << '\n';
		}
		result = knapSack(knapsack_w, weigths, profits, n_products);
		std::cout << "O lucro maximo da mochila: " << result << "\n";
		myfile.close();
	}
	else std::cout << "Unable to open file\n";
	return result;
}

int main()
{

	calculate("mochila01.txt.txt");
	calculate("mochila02.txt.txt");
	

	return 0;
}