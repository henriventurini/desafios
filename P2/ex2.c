/*
    * Henri Venturini e Pedro Henrique
    * 25-11-2021
    * Le valores de dois vetores e concatena ambos
    */

#include <stdio.h>
#include <string.h>

int main(void)
{

  //variaveis

  int tamUm, tamDois, tamMax, valor, maior, existe = 0;

  // ler tamanho e valores (primeiro vetor)
  printf("Entre com o tamanho do PRIMEIRO vetor: ");
  scanf("%d", &tamUm);

  int primeiro[tamUm];

  printf("Entre com os valores do vetor: ");
  for (int i = 0; i < tamUm; i++)
  {
    scanf("%d", &valor);
    primeiro[i] = valor;
  }

  // ler tamanho e valores (segundo vetor)
  printf("\nEntre com o tamanho do SEGUNDO vetor: ");
  scanf("%d", &tamDois);

  int segundo[tamDois];

  printf("Entre com os valores do vetor: ");
  for (int i = 0; i < tamDois; i++)
  {
    scanf("%d", &valor);
    segundo[i] = valor;
  }

  // tamanho do vetor de concatenacao
  tamMax = tamUm + tamDois;

  int terceiro[tamMax];
  //adiciona o primeiro vetor ao vetor final
  for (int i = 0; i < tamUm; i++)
  {
    terceiro[i] = primeiro[i];
  }
  //modulo para verificação e união do segundo vetor
  for (int i = 0; i < tamDois; i++)//para percorrer o segundo vetor
  {
    for (int e = 0; e < tamUm; e++)//para percorrrer o vetor final
    {
      if(segundo[i] == terceiro[e]){//se o numero ja existe ele nao vai adicionado
        existe = 1;
      }
    }
    if(existe == 0){//se ele nao existe ele vai adicionado
      tamUm++;
      terceiro[tamUm-1] = segundo[i];
    }
    existe = 0;
  }
  for (int i = 0; i < tamUm; i++)
  {
    printf("%d ", terceiro[i]);//mostra os numeros do vetor final
  }
}
