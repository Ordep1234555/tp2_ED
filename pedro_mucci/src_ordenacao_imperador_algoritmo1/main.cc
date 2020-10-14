#include <cstdio>
#include <iostream>
#include <chrono>
#include "string.h"

using namespace std;

string nome_p[2000000];
int dados_p[2000000][2];

void bolha(int num_planetas) {
int i, j, trocou, aux[1][2];
string aux_p;
  
  for(i = 0; i < num_planetas-1; i++){
    trocou = 0;
    for(j = 1; j < num_planetas-i; j++)
      if (dados_p[j][0] < dados_p[j-1][0]){
        aux[0][0] = dados_p[i][0];
			  aux[0][1] = dados_p[i][1];
			  aux_p = nome_p[i];
			  dados_p[i][0] = dados_p[j][0];
			  dados_p[i][1] = dados_p[j][1];
			  nome_p[i] = nome_p[j];
			  dados_p[j][0] = aux[0][0];
			  dados_p[j][1] = aux[0][1];
			  nome_p[j] = aux_p;
        trocou = 1;
    }
    if (!trocou) break;
  }
}

void bolha2(int inicio, int fim) {
int i, j, k, trocou, aux[1][2];
string aux_p;
  for(i = inicio,k=0; i < fim; i++,k++){
    trocou = 0;
    for(j = inicio+1; j < fim+1-k; j++)
      if (dados_p[j][1] > dados_p[j-1][1]){
        aux[0][0] = dados_p[j-1][0];
	    aux[0][1] = dados_p[j-1][1];
		aux_p = nome_p[j-1];
		dados_p[j-1][0] = dados_p[j][0];
		dados_p[j-1][1] = dados_p[j][1];
		nome_p[j-1] = nome_p[j];
		dados_p[j][0] = aux[0][0];
		dados_p[j][1] = aux[0][1];
		nome_p[j] = aux_p;
        trocou = 1;
    }
    if (!trocou) break;
  }
}

int main() {
  
int num_planetas;
int i,j,k,aux;
	cin >> num_planetas;
	for (i = 0; i < num_planetas; i++){
		cin >> nome_p[i] >> dados_p[i][0] >> dados_p[i][1];
        }
	auto start = chrono::high_resolution_clock::now(); 
	ios_base::sync_with_stdio(false);
	bolha(num_planetas);
	aux=dados_p[0][0];
	for(i=1,k=0,j=1; i<num_planetas; i++){
		if(dados_p[i][0] == aux){
			j++; //contabiliza quantos planetas tem a mesma distancia
			if(i= num_planetas-1){ //se forem os planetas até o final dos dados ele arruma até o final
				bolha2(k,k+j);
			}
		} else {
			if(j>1){
				bolha2(k,k+j);
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
	cout << fixed  << time_taken;
  
  return 0;
}
