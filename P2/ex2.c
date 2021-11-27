/*
    * Henri Venturini e Pedro Henrique
    * 25-11-2021
    * Le valores dentro de um vetor e encontra o indice chave
    */

#include <stdio.h>

int main(void)
{

  //variaveis

  int tamUm, tamDois, tamMax, valor, maior;

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

  // daqui pra frente é sopa de letrinha
  if (tamUm >= tamDois)
  {
    maior = 1;
  }

  for (int i = 0; i < tamMax; i++)
  {

    if (maior == 1)
    {
      for (int j = 0; j < tamUm; j++)
      {
        terceiro[j] = primeiro[j];
      }
      int ind = 0;
      for (int k = tamUm; k < tamMax; k++)
      {
        terceiro[k] = segundo[ind];
        ind++;
      }
    }
    else
    {
      for (int j = 0; j < tamDois; j++)
      {
        terceiro[j] = segundo[j];
      }
      int ind = 0;
      for (int k = tamDois; k < tamMax; k++)
      {
        terceiro[k] = primeiro[ind];
        ind++;
      }
    }
    // printf("%d", terceiro[i]);
	}

  // Temos um vetor "terceiro" concatenado de tamanho "tamMax (tamanho do 1 + o do 2)" porem ele repete valores
  // Se entramos com "1 2 3 4 5" e "5 6 7" recebemos "1 2 3 4 5 5 6 7" -> precisamos de "1 2 3 4 5 6 7" (numeros repetidos somem)

  /*
  int uniao[tamMax];
	
	int casos;
	
	for(int i = 0; i < tamMax; i++){
		casos = 0;
		valor = terceiro[i];
		for(int k = 0; k < tamMax; k++){
			if(valor == terceiro[k]){
				casos++;
			}
		}
		if(casos < 2){
			uniao[i] = valor;
		}

    printf("%d", uniao[i]);
  }
  */
}
