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
  // Alocando um char para cada valor possível
	char *past = (char *) malloc(lcrandom_max() + 1);
  // p é o período
  unsigned long p = 0;
  
	while(++past[lcrandom()] <= 1) ++p;
  // Liberando a memória alocada
  free(past);
  return (p-1);

}
