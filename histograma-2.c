// Luiz Fernando Azevedo Vasconcellos GRR20171629
// E-mail: lfav17@inf.ufpr.br

#include "lcrandom.h"
#include <stdio.h>

#define RANGE 100
#define ONE_MILLION 1000000

#define A0 1103515245
#define C0 12345
#define M0 2147483648

// Declaração das funções auxiliares (Ver implementação p/ comentários)
void print_hist(unsigned long*, unsigned long);
void print_hist_line(unsigned long, unsigned long, unsigned long);

int main () {
  // Definição da amostra e de seu tamanho
  unsigned long sample[RANGE] = {0};
  unsigned long sample_size = ONE_MILLION; // 10^6

  // "Zerando" o seed e atribuindo novos parâmetros
  // para a geração de números randômicos
  lcrandom_seed(0);
  lcrandom_parms(A0,C0,M0);

  /*
     Distribuição dos parâmetros randômicos com os
     valores default da biblioteca e valor de seed 0.
     Foi tirado o módulo em 100 para que os números
     gerados estejam entre 0 e 99.
  */
  for(unsigned long i = 0; i < sample_size; ++i)
    ++sample[lcrandom()%RANGE];

  // Apresenta os dois histogramas na saída padrão.
  print_hist(sample, RANGE);

  return 0;
}


/*
    Imprime o histograma na saída padrão. Cada valor possível
    de ser gerado é mostrado como uma porcentagem das vezes 
    da moda da distribuição.
    Parâmetros:
     - freq: um array de frequências
     - max: o valor máximo 
*/
void print_hist(unsigned long *freq, unsigned long max) {
  int i;
  // calcula a frequência do mais frequente
  unsigned long most_freq = 0;
  for(unsigned long i = 0; i < max; ++i)
     if(most_freq < freq[i]) most_freq = freq[i];
  
  // Imprime o cabeçalho do histograma
  printf("  ");
  for(i = 0; i <= 100; i += 10)
    printf("%d   ", i);
  printf("\n  +");    
  for(i = 0; i < 10; ++i)
    printf("----+");
  printf("\n"); 

  // Imprime cada uma das linhas do histograma 
  for (unsigned long line = 0; line < max; ++line) 
    print_hist_line (freq[line], line, most_freq); 
}


/*
      Calcula a frequência relativa de uma única linha e 
    imprime uma única linha do histograma, uma função aux
    de print_hist.
      Parâmetros:
       - freq_i: a frequência do i-ésimo termo
       - idx: posição da linha
       - max: frequência máxima da distribuição
*/
void print_hist_line(unsigned long freq_i,
                     unsigned long idx, unsigned long max) {

  printf("%2lu|", idx);
  // Calculo do tamanho da coluna da frequência relativa:
  // 100 * (freq_i/max) / 2;
  unsigned long col_size = (50 * freq_i) / max;

  for(unsigned long i = 0; i < col_size; ++i) 
    printf("*");
  printf("\n");
}
