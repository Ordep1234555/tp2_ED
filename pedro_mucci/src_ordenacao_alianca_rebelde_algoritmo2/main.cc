#include <cstdio>
#include <iostream>
#include <chrono>
#include "string.h"

using namespace std;

string nome_p[2000000];
int dados_p[2000000][2];

void heapsort(int n) {
   int i, pai, filho, aux[1][2];
   string aux_p;
   i = n/2;
   while(true) {
      if (i > 0) {
          i--;
          aux[0][0] = dados_p[i][0];
          aux[0][1] = dados_p[i][1];
          aux_p = nome_p[i];
      } else {
          n--;
          if (n <= 0) return;
          aux[0][0] = dados_p[n][0];
          aux[0][1] = dados_p[n][1];
          aux_p = nome_p[n];
          dados_p[n][0] = dados_p[0][0];
          dados_p[n][1] = dados_p[0][1];
          nome_p[n] = nome_p[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (dados_p[filho + 1][0] > dados_p[filho][0]))
              filho++;
          if (dados_p[filho][0] > aux[0][0]) {
             dados_p[pai][0] = dados_p[filho][0];
             dados_p[pai][1] = dados_p[filho][1];
             nome_p[pai] = nome_p[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      dados_p[pai][0] = aux[0][0];
      dados_p[pai][1] = aux[0][1];
      nome_p[pai] = aux_p;
   }
}

//-------------------------------------------------------------------------------------

void heapsort2(int inicio, int fim) {
   int i, pai, filho, aux[1][2];
   string aux_p;
   int n=fim-inicio;
   i = n/2;
   while(true) {
      if (i > inicio) {
          i--;
          aux[0][0] = dados_p[i][0];
          aux[0][1] = dados_p[i][1];
          aux_p = nome_p[i];
      } else {
          n--;
          if (n <= 0) return;
          aux[0][0] = dados_p[n][0];
          aux[0][1] = dados_p[n][1];
          aux_p = nome_p[n];
          dados_p[n][0] = dados_p[0][0];
          dados_p[n][1] = dados_p[0][1];
          nome_p[n] = nome_p[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < fim) {
          if ((filho + 1 < fim)  &&  (dados_p[filho + 1][1] < dados_p[filho][1]))
              filho++;
          if (dados_p[filho][1] < aux[0][1]) {
             dados_p[pai][0] = dados_p[filho][0];
             dados_p[pai][1] = dados_p[filho][1];
             nome_p[pai] = nome_p[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      dados_p[pai][0] = aux[0][0];
      dados_p[pai][1] = aux[0][1];
      nome_p[pai] = aux_p;
   }
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
	heapsort(num_planetas);
	cout << endl << "-------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < num_planetas; i++) {
        cout << nome_p[i] + " " + to_string(dados_p[i][0]) + " " + to_string(dados_p[i][1]) << endl;
    	}
	aux=dados_p[0][0];
	for(i=1,k=0,j=1; i<num_planetas; i++){
		if(dados_p[i][0] == aux){
			j++; //contabiliza quantos planetas tem a mesma distancia
			if(i == num_planetas-1){ //se forem os planetas até o final dos dados ele arruma até o final
				heapsort2(k,k+j);
			}
		} else {
			if(j>1){
				heapsort2(k,k+j);
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
