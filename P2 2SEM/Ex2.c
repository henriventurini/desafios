#include <stdio.h>
#include <stdlib.h>

void mostraVetores(int *v1, int *v2, int n1, int n2);
int insereVet2(int *v1, int *v2, int n1);
void ordenaVet(int *v1, int n1);
void insereVet1(int *v1, int n1);

int main() {
    int n1; /// tamanho do primeiro vetor
    int n2; ///tamanho do segundo vetor
    int *v1; ///ponteiro do primeiro vetor
    int *v2; ///ponteiro do segundo vetor

    //////////////////LE O TAMANHO DO VETOR N1//////////////
    printf("Entre com o tamanho:");
    scanf("%d", &n1);

    /////////CRIA OS VETORES DINAMICAMENTE/////////
    v1 = malloc(n1 * sizeof(int));
    v2 = malloc(n1 * sizeof(int));

    //////INSERIR NO VETOR DE MANEIRA ORDENADA///////////
    insereVet1(v1, n1);

    //////CRIA O SEGUNDO VETOR//////////////
    n2 = insereVet2(v1, v2, n1);

    //////MOSTRA OS VALORES////////////////
    mostraVetores(v1, v2, n1, n2);
    
    return 0;
}
void insereVet1(int *v1, int n1){
    int i;
    for(i = 0; i < n1; i++){
        printf("Entre com o numero %d:", i);
        scanf("%d", &v1[i]);
        ordenaVet(v1, i);

    }
}
void ordenaVet(int *v1, int n1) {
    int i, aux;
    for(i = n1; i > 0; i--) {
        if (v1[i] < v1[i - 1]) {
            aux = v1[i - 1];
            v1[i - 1] = v1[i];
            v1[i] = aux;
        }
    }
}
int insereVet2(int *v1,int *v2, int n1){
    int i, e, j, n2 = 0;
    int exist;
    for(i = 0; i < n1; i++) {
        exist = 0;
        for (j = 0; j < n1; j++) {
            for (e = j + 1; e < n1; e++) {
                if (v1[j] + v1[e] == v1[i]){
                    exist = 1;
                }
            }
        }
        if(!exist){
            v2[n2] = v1[i];
            n2++;
        }
    }
    return n2;
}
void mostraVetores(int *v1, int *v2, int n1, int n2){
    int i;
    for(i = 0; i < n1; i++){
        printf("%d ", v1[i]);
    }
    printf("\n");
    for(i = 0; i < n2; i++){
        printf("%d ", v2[i]);
    }
}