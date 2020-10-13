#include <cstdio>
#include <iostream>
#include <chrono>
#include "string.h"

using namespace std;

string nome_p[2000000];
int dados_p[2000000][2];

void quicksort(int inicio, int fim){
int i, j, pivo, aux[1][2];
string aux_p;
i = inicio;
j = fim-1;
pivo = dados_p[(inicio + fim)/2][0];
	while(i <= j){
		while(dados_p[i][0] < pivo && i < fim){
			i++;
		}
		while(dados_p[j][0] > pivo && j > inicio){
			j--;
		}
		if(i <= j){
			aux[0][0] = dados_p[i][0];
			aux[0][1] = dados_p[i][1];
			aux_p = nome_p[i];
			dados_p[i][0] = dados_p[j][0];
			dados_p[i][1] = dados_p[j][1];
			nome_p[i] = nome_p[j];
			dados_p[j][0] = aux[0][0];
			dados_p[j][1] = aux[0][1];
			nome_p[j] = aux_p;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quicksort(inicio, j+1);
	if(i < fim)
		quicksort(i, fim);
}

//-------------------------------------------------------------------------------------

void quicksort2(int inicio, int fim){
int i, j, pivo, aux[1][2];
string aux_p;
i = inicio;
j = fim-1;
pivo = dados_p[(inicio + fim)/2][1];
	while(i <= j){
		while(dados_p[i][1] > pivo && i < fim){
			i++;
		}
		while(dados_p[j][1] < pivo && j > inicio){
			j--;
		}
		if(i <= j){
			aux[0][0] = dados_p[i][0];
			aux[0][1] = dados_p[i][1];
			aux_p = nome_p[i];
			dados_p[i][0] = dados_p[j][0];
			dados_p[i][1] = dados_p[j][1];
			nome_p[i] = nome_p[j];
			dados_p[j][0] = aux[0][0];
			dados_p[j][1] = aux[0][1];
			nome_p[j] = aux_p;
			i++;
			j--;
		}
	}
	if(j > inicio)
		quicksort2(inicio, j+1);
	if(i < fim)
		quicksort2(i, fim);
}

//-------------------------------------------------------------------------------------

int main() {
  
int num_planetas;
int i,j,k,aux;
	cin >> num_planetas;
	for (i = 0; i < num_planetas; i++){
		cin >> nome_p[i] >> dados_p[i][0] >> dados_p[i][1];
        }
	auto start = chrono::high_resolution_clock::now(); 
	ios_base::sync_with_stdio(false);
	quicksort(0,num_planetas);
	aux=dados_p[0][0];
	for(i=1,k=0,j=1; i<num_planetas; i++){
		if(dados_p[i][0] == aux){
			j++; //contabiliza quantos planetas tem a mesma distancia
			if(i= num_planetas-1){ //se forem os planetas até o final dos dados ele arruma até o final
				quicksort2(k,j+k);
			}
		} else {
			if(j>1){
				quicksort2(k,k+j);
			}
			aux= dados_p[i][0];
			k=i;
			j=1;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	cout << endl << "-------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < num_planetas; i++) {
        cout << nome_p[i] + " " + to_string(dados_p[i][0]) + " " + to_string(dados_p[i][1]) << endl;
    	}
	double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << fixed  << time_taken << setprecision(9);
  
  return 0;
}
