/*
* Simulador de ataque zumbi, cria uma mapa com zumbis e humanos e simula seu estado cada dia até que o total de dias seja o desejado.
* Criado por: Henri Boraschi Venturini (RA 2760482121027) e Pedro Henrique Vieira (RA 2760482121022)
* Data: 09-11-2021
*/
#include <stdio.h>

int main(){
    //modulo da inicialização das variaveis
    int linha, coluna, dias;
    int matrizHoje[50][50];
    int matrizAmanha[50][50];
    ///modulo da leitura das informaçãoes
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
    //inicio da função
    for (int a = 0; a < dias; a++)//for para a repetição dos dias
    {
        printf("Interacao %d \n",a);//mostra o dia para a vizualização no terminal
        for (int j = 0; j < linha; j++)//for para a repetição das linhas da matriz
        {
            for (int i = 0; i < coluna; i++)//for para a repetição das coluna da matriz
            {
                //modulo da criação dos vizinhos padrões
                printf("%d",matrizHoje[j][i]);//monta a matriz para a visualização no terminal
                int vizinhos[8]={matrizHoje[j-1][i-1],matrizHoje[j-1][i],matrizHoje[j-1][i+1],matrizHoje[j][i-1],matrizHoje[j][i+1],matrizHoje[j+1][i-1],matrizHoje[j+1][i],matrizHoje[j+1][i+1]};
                //modulo da criação dos vizinhos para casos especiais
                if(j==0 && i==0){//ponta superior esquerda
                    vizinhos[0] = matrizHoje[linha-1][coluna-1];
                    vizinhos[1] = matrizHoje[linha-1][0];
                    vizinhos[2] = matrizHoje[linha-1][1];
                    vizinhos[3] = matrizHoje[0][coluna-1];
                    vizinhos[5] = matrizHoje[1][coluna-1]; 
                }else if(j==linha-1 && i==0){//ponta inferior esquerda
                    vizinhos[0] = matrizHoje[linha-2][coluna-1];
                    vizinhos[3] = matrizHoje[linha-1][coluna-1];
                    vizinhos[5] = matrizHoje[0][coluna-1];
                    vizinhos[6] = matrizHoje[0][0];
                    vizinhos[7] = matrizHoje[0][1];
                }else if(j==0 && i==coluna-1){//ponta superior direita 
                    vizinhos[0] = matrizHoje[linha-1][coluna-2];
                    vizinhos[1] = matrizHoje[linha-1][coluna-1];
                    vizinhos[2] = matrizHoje[linha-1][0];
                    vizinhos[4] = matrizHoje[0][0];
                    vizinhos[7] = matrizHoje[1][0];
                }else if(j==linha-1 && i==coluna-1){//ponta inferior direita
                    vizinhos[2] = matrizHoje[linha-2][0];
                    vizinhos[4] = matrizHoje[linha-1][0];
                    vizinhos[5] = matrizHoje[0][coluna-2];
                    vizinhos[6] = matrizHoje[0][coluna-1];
                    vizinhos[7] = matrizHoje[0][0];
                }
                else if(j==0 && i!=0 && i!=coluna-1){//primeira linha menos a primeira e ultima coluna
                    vizinhos[0] = matrizHoje[linha-1][i-1];
                    vizinhos[1] = matrizHoje[linha-1][i];
                    vizinhos[2] = matrizHoje[linha-1][i+1];
                }
                else if(i==0 && j!=0 && j!=coluna-1){//primeira coluna menos a primeira e ultima linha
                    vizinhos[0] = matrizHoje[j-1][coluna-1];
                    vizinhos[3] = matrizHoje[j][coluna-1];
                    vizinhos[5] = matrizHoje[j+1][coluna-1];
                }
                else if(j==linha-1 && i!=0 && i!=coluna-1){//ultima linha menos a primeira e ultima coluna
                    vizinhos[5] = matrizHoje[0][i-1];
                    vizinhos[6] = matrizHoje[0][i];
                    vizinhos[7] = matrizHoje[0][i+1];
                }
                else if(i==coluna-1 && j!=0 && j!=coluna-1){//ultima coluna menos a primeira e ultima linha
                    vizinhos[2] = matrizHoje[j-1][0];
                    vizinhos[4] = matrizHoje[j][0];
                    vizinhos[7] = matrizHoje[j+1][0];
                }
                matrizAmanha[j][i] = matrizHoje[j][i];//ajusta a matriz do dia seguinte para os valores imutados de acordo como a matriz hoje
                if(matrizHoje[j][i] == 0){//modulo para caso o espaço esteja vazio
                    int soma = 0;
                    for(int k=0; k<8;k++){//verificação dos vizinhos
                        if(vizinhos[k]==1){
                            soma = soma+1;
                        }
                    }    
                    if(soma == 2){//caso o requisito seja cumprido aparecera um novo humano
                        matrizAmanha[j][i] = 1; 
                    }
                }else if(matrizHoje[j][i] == 1){//modulo para caso o espaço esteja com um humano
                    for(int k=0; k<8;k++){//verificação dos vizinhos
                        if(vizinhos[k]==2){//caso o requisito seja cumprido o humano morrera
                            matrizAmanha[j][i] = 2;
                        }
                    }
                }else if(matrizHoje[j][i] == 2){//modulo para caso o espaço esteja com um zumbi
                    int soma = 0;
                    for(int k=0; k<8;k++){//verificação dos vizinhos
                        if(vizinhos[k]==1){
                            soma = soma+1;
                        }
                    }    
                    if(soma > 1){//caso o requisito seja cumprido o zumbi morrera
                        matrizAmanha[j][i] = 0; 
                    }if(soma == 0){//caso o requisito seja cumprido o zumbi morrera         
                        matrizAmanha[j][i] = 0; 
                    }
                }
            }
            printf("\n"); 
        }
        printf("\n");
        //modulo para a aplicação do dia de amanha para a matriz atual
        for (int j = 0; j < linha; j++)
        {
            for (int i = 0; i < coluna; i++)
            {
                matrizHoje[j][i] = matrizAmanha[j][i];
                matrizAmanha[j][i] = 0; 
            }
        }
       
    }
}