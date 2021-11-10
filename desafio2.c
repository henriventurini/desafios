/*
* Simulador de ataque zumbi, cria uma mapa com zumbis e humanos e simula seu estado cada dia até que o total de dias seja o desejado.
* Criado por: Henri Boraschi Venturini (RA 2760482121027) e Pedro Henrique Vieira (RA 2760482121022)
* Data: 09-11-2021
*/
#include <stdio.h>

int main(){
    int linha, coluna, dias;
    printf("linhas e colunas:");
    scanf("%d%d", &linha, &coluna);
    printf("\ndias:");
    scanf("%d", &dias);
    int matriz[linha][coluna];
    for (int j = 0; j < linha; j++)
    {
         for (int i = 0; i < coluna; i++)
        {
            scanf("%d",&matriz[j][i]);
        }
    }
    for (int a = 0; a < dias; a++)
    {
        for (int j = 0; j < linha; j++)
        {
            for (int i = 0; i < coluna; i++)
            {
                printf("%d",matriz[j][i]);
                
                if(j == 0 || i == 0 || j == linha || i == coluna){
                }else{
                    int vizinhos[8] = { matriz[j-1][i-1],matriz[j-1][i], matriz[j-1][i+1], matriz[j][i-1], matriz[j][i+1], matriz[j+1][i-1], matriz[j+1][i], matriz[j+1][i+1]};
                }

               
                printf("teste - %d %d %d %d %d %d %d %d",matriz[j-1][i-1], matriz[j-1][i], matriz[j-1][i+1], matriz[j][i-1], matriz[j][i+1], matriz[j+1][i-1], matriz[j+1][i], matriz[j+1][i+1]);
                if(matriz[j][i] == 0){
                    int sum = 0;
                    for (int e = 0; e < 8; e++)
                    {
                        if(vizinhos[e] == 1){
                            sum++;
                        }
                    }
                    if(sum == 2){
                        matriz[j][i] = 1;
                    }
                }
                else if (matriz[j][i] == 1)
                {
                    for (int e = 0; e < 8; e++)
                    {
                        
                        if(vizinhos[e] == 2){
                            matriz[j][i] == 2;
                        }
                    }
                }else if(matriz[j][i] == 2){
                    int sum = 0;
                    for (int e = 0; e < 8; e++)
                    {
                        if(vizinhos[e] == 1){
                            sum++;
                        }
                    }
                    if(sum >= 2 || sum == 0){
                        matriz[j][i] = 0;
                    }
                }
           
            }
            printf("\n");
        }
        printf("\n");
    }
}