#include <stdio.h>
#include <stdlib.h>

/***********************************
    Testes com Struct e Vetores
***********************************/
typedef struct registro{
    int vet[3];
    int valor;

}res;

void leRegistro(res registro);

int somaVet(res registro);

void leVetor(res registro);

int main()
{
    res g1;
    int valorVet, valor, soma;

    for(int i = 0; i < 3; i++){
        printf("\nEntre com o valor do %d valor do vetor: ", i);
        scanf("%d", &valorVet);
        g1.vet[i] = valorVet;
    }

    printf("\nEntre com o valor: ");
    scanf("%d", &valor);
    g1.valor = valor;

    leVetor(g1);

    soma = somaVet(g1);
    printf("\nSoma: %d ", soma);

    leRegistro(g1);
}

void leRegistro(res registro){

    int i = 0;
    for(i = 0; i < 3; i++){
        printf("\nPosicao %d -> %d", i, registro.vet[i]);
    }


    printf("\nValor: %d", registro.valor);
}
int somaVet(res registro){
    int soma = 0;
    for(int i = 0; i < 3; i++){
         soma += registro.vet[i];
    }

    return soma;
}
void leVetor(res registro){
    for(int i = 0; i < 3; i++){
        printf("\nPosicao %d = %d", i, registro.vet[i]);
    }
}
