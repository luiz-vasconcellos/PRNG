//Luiz Fernando Azevedo Vasconcellos GRR20171629 
// E-mail: lfav17@inf.ufpr.br

#include "lcrandom.h"

// Variáveis de estado interno da biblioteca
// inicializadas com valores default
unsigned long lcr_A = 40692, lcr_C = 127, lcr_M = 10000000 ;
unsigned long lcr_number = 0;

// Uso simples da fórmula de congruência para 
// números pseudoaleatórios
unsigned long lcrandom () {
  unsigned long res = lcr_number;
  lcr_number = (lcr_A * lcr_number + lcr_C) % lcr_M;
  return res;
}

void lcrandom_seed(unsigned long s) {
  lcr_number = s;
}

// Na aritmética modular, o maior número de Zn é sempre n-1
unsigned long lcrandom_max() {
  return lcr_M - 1;
}

// Atribuição dos parâmetros da fórmula de recorrência LCMRNG
void lcrandom_parms(unsigned long A, unsigned long C,
                             unsigned long M) {
  lcr_A = A;
  lcr_C = C;
  lcr_M = M;
}


