// Luiz Fernando Azevedo Vasconcellos GRR20171629
// E-mail: lfav17@inf.ufpr.br

#include <stdio.h>
#include <stdlib.h>
#include "lcrandom.h"

#define A0 1103515245
#define C0 12345
#define M0 2147483648

unsigned long period(unsigned long, unsigned long,
                     unsigned long, unsigned long);

int main () {
  printf("%lu\n", period(0,A0,C0,M0));
  return 0; 
}

/*
    Cálcula o período de um gerador LCM, um número que pode
    ser no máximo M.
    Parâmetros:
     - seed: o valor inicial do LCM
     - A,C, M: parâmetros pro LCM 
*/
unsigned long period (unsigned long seed, unsigned long A,
                      unsigned long C, unsigned long M) {
  lcrandom_parms(A,C,M);                             

  char  *past = (char *) malloc (lcrandom_max() + 1);   // Um LCM tem no máximo período M
  int size = 8;                                         // 1 char == 8 bits 
  unsigned long p = 0;                                  // Periodo
  for(int i = 0; i <= lcrandom_max(); ++i)
    past[i] = 0;
  
  while(1) {
    unsigned long random_no = lcrandom();               // Gera um número aleatório

    unsigned long idx = (random_no / size);
    unsigned long pos = random_no % size;
    // Cálcula a posição do vetor past e o bit correspondente
    unsigned long mask = 1 << pos;

    if(past[idx]  == (past[idx] | mask)) {              // Compara se o número já foi gerado
      free(past);
      return p-1;
    }
    
    past[idx] |= mask;                                  // Registra o número
    ++p;
  }
}