/*
* Henri Venturini e Pedro Henrique
* 25-11-2021
* Le valores dentro de um vetor e encontra o indice chave
*/

#include <stdio.h>

int main(void) {

  // variaveis
  int valor;
  int tam;
  int chave;
  int posicao;

  // tamanho do vetor
  printf("Entre com o tamanho: ");
  scanf("%d", &tam);

  int v[tam];

  // valores
  printf("Entre com os valores: ");
  
  for(int i = 0; i < tam; i++){
    scanf("%d", &valor);
    v[i] = valor;
    // printf("%d", v[i]);
  }

  // chave
  printf("Entre com a chave: ");
  scanf("%d", &chave);

  // encontrar o indice com a chave 
   for(int i = 0; i < tam; i++){
     if(v[i] == chave){
       posicao = i;
       printf("Resultado: %d", posicao);
       break;
     }
     if(i == (tam - 1)){
       if(i != posicao){
         printf("Valor não encontrado");
       }
     }
  }
}