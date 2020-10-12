#include "TAD.hpp"
#include <cstdio>
#include <iostream>
#include "string.h"

using namespace std;

#define Troca(A, B) {Item c = A; A = B; B = c; }

void Bolha (Item *v, int n) {
int i, j, trocou;
  
  for(i = 0; i < n-1; i++){
    trocou = 0;
    for(j = 1; j < n-i; j++)
      if (v[j].chave < v[j-1].chave){
        Troca(v[j-1], v[j]);
        trocou = 1;
    }
    if (!trocou) break;
  }
}

