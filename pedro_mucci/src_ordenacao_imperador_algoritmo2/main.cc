#include <cstdio>
#include <iostream>
#include <chrono>
#include "string.h"

using namespace std;

string nome_p[2000000];
int dados_p[2000000][2];

void selecao(int num_planetas){
  
  int i, j, Min, aux[1][2];
  string aux_p;
    for (i = 0; i < num_planetas-1; i++){
      Min = i;
      for (j = i + 1 ; j < num_planetas; j++){
        if (dados_p[j][0] < dados_p[Min][0])
        Min = j;
        }
            aux[0][0] = dados_p[i][0];
			aux[0][1] = dados_p[i][1];
			aux_p = nome_p[i];
			dados_p[i][0] = dados_p[Min][0];
			dados_p[i][1] = dados_p[Min][1];
			nome_p[i] = nome_p[Min];
			dados_p[Min][0] = aux[0][0];
			dados_p[Min][1] = aux[0][1];
			nome_p[Min] = aux_p;
    }
}

void selecao2(int inicio, int fim){
  
  int i, j, Max, aux[1][2];
  string aux_p;
    for (i = inicio; i < fim; i++){
      Max = i;
      for (j = i+1 ; j < fim+1; j++){
        if (dados_p[j][1] > dados_p[Max][1])
        Max = j;
        }
            aux[0][0] = dados_p[i][0];
			aux[0][1] = dados_p[i][1];
			aux_p = nome_p[i];
			dados_p[i][0] = dados_p[Max][0];
			dados_p[i][1] = dados_p[Max][1];
			nome_p[i] = nome_p[Max];
			dados_p[Max][0] = aux[0][0];
			dados_p[Max][1] = aux[0][1];
			nome_p[Max] = aux_p;
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
	selecao(num_planetas);
	aux=dados_p[0][0];
	for(i=1,k=0,j=1; i<num_planetas; i++){
		if(dados_p[i][0] == aux){
			j++; //contabiliza quantos planetas tem a mesma distancia
			if(i= num_planetas-1){ //se forem os planetas até o final dos dados ele arruma até o final
				selecao2(k,k+j);
			}
		} else {
			if(j>1){
				selecao2(k,k+j);
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
