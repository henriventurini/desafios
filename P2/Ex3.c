#include <stdio.h>
/*
* Henri Venturini e Pedro Henrique
* 25-11-2021
* le uma matriz e fala se ela é um quadrado magico ou não
*/

int main(){
    int matriz[10][10];
    int soma[22];
    int dimensao;
    int sum = 0;
    printf("dimensao:");
    scanf("%d", &dimensao);
    for (int j = 0; j < dimensao; j++)
    {
         for (int i = 0; i < dimensao; i++)
        {
            scanf("%d",&matriz[j][i]);
        }
    }
    ////////////soma as linhas
    for (int j = 0; j < dimensao; j++)
    {
        sum = 0;
        for (int i = 0; i < dimensao; i++)
        {
            sum = sum + matriz[j][i];
        }
        soma[j] = sum;
    }
    //////////////soma as colunas
    for (int j = 0; j < dimensao; j++)
    {
        sum = 0;
        for (int i = 0; i < dimensao; i++)
        {
            sum = sum + matriz[i][j];
            
        }
        soma[j+dimensao] = sum;
    }
    ////////////soma a diagonal principal 
    sum = 0;
    for (int j = 0 ,i = 0; j < dimensao; j++, i++)
    {
        sum = sum + matriz[j][i];
    }
    soma[dimensao+dimensao] = sum;
    ////////////soma a diagonal secundaria 
    sum = 0;
    for (int j = 0 ,i = dimensao-1; j < dimensao; j++, i--)
    {
        sum = sum + matriz[j][i];
    }
    soma[1+dimensao+dimensao] = sum;
    int igual = soma[0];
    int i = 1;
    for (i = 1; i < (dimensao*2)+2; i++)
    {
        if(soma[i] != igual){
            printf("Quadrado apenas");
            break;
        }
    }
    if(i == (dimensao*2)+2){
        printf("Quadrado magico");
    }
    return 0;
}