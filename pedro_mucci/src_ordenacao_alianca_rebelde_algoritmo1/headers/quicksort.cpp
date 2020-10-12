#include "Quicksort.hpp"
#include <cstdio>
#include <iostream>
#include "string.h"

using namespace std;

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


void quicksort2(int inicio, int fim){
	int i, j, pivo, aux[1][2];
  string aux_p;
	i = inicio;
	j = fim-1;
	pivo = dados_p[(inicio + fim)/2][0];
	while(i <= j){
		while(dados_p[i][1] < pivo && i < fim){
			i++;
		}
		while(dados_p[j][1] > pivo && j > inicio){
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
