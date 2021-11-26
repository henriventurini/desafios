/*
* Simulador de ataque zumbi, cria uma mapa com zumbis e humanos e simula seu estado cada dia até que o total de dias seja o desejado.
* Criado por: Henri Boraschi Venturini (RA 2760482121027) e Pedro Henrique Vieira (RA 2760482121022)
* Data: 09-11-2021
*/
#include <stdio.h>

int main(){
    int linha, coluna, dias;
    int matrizHoje[50][50];
    int matrizAmanha[50][50];
    printf("linhas e colunas:");
    scanf("%d%d", &linha, &coluna);
    printf("\ndias:");
    scanf("%d", &dias);
    for (int j = 0; j < linha; j++)
    {
         for (int i = 0; i < coluna; i++)
        {
            scanf("%d",&matrizHoje[j][i]);
        }
    }
    for (int a = 0; a < dias; a++)
    {
        printf("Interacao %d \n",a);
        for (int j = 0; j < linha; j++)
        {
            for (int i = 0; i < coluna; i++)
            {
                printf("%d",matrizHoje[j][i]);
                int vizinhos[8]={matrizHoje[j-1][i-1],matrizHoje[j-1][i],matrizHoje[j-1][i+1],matrizHoje[j][i-1],matrizHoje[j][i+1],matrizHoje[j+1][i-1],matrizHoje[j+1][i],matrizHoje[j+1][i+1]};
                if(j==0 && i==0){
                    vizinhos[0] = matrizHoje[linha-1][coluna-1];
                }if(j==0){
                    vizinhos[1] = matrizHoje[linha-1][i];
                }if(i==0){
                    vizinhos[3] = matrizHoje[j][coluna-1];
                }if(j==linha-1 && i==coluna-1){
                    vizinhos[7] = matrizHoje[0][0];
                }if(j==linha-1){
                    vizinhos[6] = matrizHoje[0][i];
                }if(i==coluna-1){
                    vizinhos[4] = matrizHoje[j][0];
                }if(j==0 && i==coluna-1){
                    vizinhos[2] = matrizHoje[linha-1][0];
                }if(j==linha-1 && i==0){
                    vizinhos[5] = matrizHoje[0][coluna-1];
                }if(j==0 && i!=coluna-1){
                    vizinhos[2] = matrizHoje[linha-1][i+1];
                }if(j!=linha-1 && i==0){
                    vizinhos[5] = matrizHoje[j+1][coluna-1];
                }if(j!=0 && j!=linha-1 && i==coluna-1){
                    vizinhos[2] = matrizHoje[j-1][0];
                    vizinhos[7] = matrizHoje[j+1][0];
                }
                if(j==linha-1){
                   // printf("matriz:%d - ",matrizHoje[0][coluna-1]);
                    //printf("vizinho:%d \n",vizinhos[5]);
                }      
                matrizAmanha[j][i] = matrizHoje[j][i];
                if(matrizHoje[j][i] == 0){
                    
                    int soma = 0;
                    for(int k=0; k<8;k++){
                        if(vizinhos[k]==1){
                            soma = soma+1;
                        }
                    }    
                    //printf("sum:%d\n",soma);
                    if(soma == 2){
                        //printf("nasceu\n");
                        matrizAmanha[j][i] = 1; 
                    }
                }else if(matrizHoje[j][i] == 1){
                    for(int k=0; k<8;k++){
                        if(j==linha-1){
                           // printf("vizinho:%d \n",vizinhos[k]);
                        }
                        if(vizinhos[k]==2){
                            matrizAmanha[j][i] = 2;
                        }
                    }
                    if(j==linha-1){
                        //printf("j:%d i:%d value:%d\n",j, i, matrizAmanha[j][i]);
                    }
                }else if(matrizHoje[j][i] == 2){
                    int soma = 0;
                    for(int k=0; k<8;k++){
                        if(vizinhos[k]==1){
                            soma = soma+1;
                        }
                    }    
                    if(soma > 1){
                        matrizAmanha[j][i] = 0; 
                    }if(soma == 0){           
                        matrizAmanha[j][i] = 0; 
                    }
                }
                if(j==linha-1){
                    //printf("j:%d i:%d value:%d\n",j, i, matrizAmanha[j][i]);
                }
            }
            printf("\n"); 
        }
        printf("\n");
       
        for (int j = 0; j < linha; j++)
        {
            for (int i = 0; i < coluna; i++)
            {
                //printf("i:%d j:%d mat:%d\n",j, i ,matrizAmanha[j][i]);
                matrizHoje[j][i] = matrizAmanha[j][i];
                matrizAmanha[j][i] = 0; 
            }
        }
       
    }
}