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
  // We don't change params for periodo-1
  //lcrandom_parms(A,C,M);                          

  // Allocating one char for every possible result
	char *past = (char *) malloc(lcrandom_max() + 1);
  unsigned long p = 0; // P is period
  
	while(++past[lcrandom()] <= 1) ++p; 
  free(past);          // Don't forget to deallocate
  return (p-1);
}
