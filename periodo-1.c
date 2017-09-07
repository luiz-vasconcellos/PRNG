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
    // Não mudamos os parâmetros em periodo-1
    //lcrandom_parms(A,C,M);                          

    // Alocando um char para cada valor possível
    char *past = (char *) calloc(sizeof(char),lcrandom_max() + 1);
    if (past == NULL) abort();

    // p é o período
    unsigned long p = 0;
  
	while(++past[lcrandom()] <= 1) ++p; 

    // Liberando a memória alocada
    free(past);
    return (p-1);
}
