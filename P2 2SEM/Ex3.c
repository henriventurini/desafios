#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char car;
    int peso;
} Cell;

int soma(Cell* vet, int i, int n, int somaPeso);

int main() {
    int i = 0; ///indice inicial
    int n = 7; ///tamanho do vetor
    int somaPeso = 0; ///soma do peso das faixas
    Cell *vet = malloc((n) * sizeof(Cell)); ///Vetor de cell

    vet[0].car = 'y';
    vet[0].peso = 1;

    vet[1].car = 'y';
    vet[1].peso = 2;

    vet[2].car = 'z';
    vet[2].peso = 5;

    vet[3].car = 'z';
    vet[3].peso = 4;

    vet[4].car = 'z';
    vet[4].peso = 5;

    vet[5].car = 'y';
    vet[5].peso = 4;

    vet[6].car = 'a';
    vet[6].peso = 3;

    somaPeso = soma(vet, i , n , somaPeso);
    printf("A soma eh: %d", somaPeso);

    return 0;
}
int soma(Cell* vet, int i, int n, int somaPeso){
    if(vet[i].car == vet[i-1].car || vet[i].car == vet[i+1].car){
        somaPeso = somaPeso + vet[i].peso;
    }
    if(i < n){
        return soma(vet, i+1, n, somaPeso);
    } else {
        return somaPeso;
    }
}


