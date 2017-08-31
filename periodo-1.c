// Luiz Fernando Azevedo Vasconcellos GRR20171629
// E-mail: lfav17@inf.ufpr.br

#include <stdio.h>
#include <stdlib.h>
#include "lcrandom.h"

unsigned long period(unsigned long, unsigned long,
                     unsigned long, unsigned long);

int main () {
  printf("%lu\n", period(0,0,0,0));
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
  //lcrandom_parms(A,C,M);                             

	char *past = (char *) malloc(lcrandom_max() + 1);
  unsigned long p = 0;
  
	while(++past[lcrandom()] <= 1) ++p;
  free(past);
  return (p-1);
}
