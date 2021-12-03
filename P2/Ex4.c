#include <stdio.h>
#include <string.h>
/*
* Henri Venturini e Pedro Henrique
* 25-11-2021
* le uma string de até 30 caracteres e fala quantos caracteres diferentes a palavra tem
*/

int main()
{
    char palavra[30];
    char caracteresUsados[30] ;
    int jaUsado = 0;
    scanf("%s",&palavra);
    int tamanho = strlen(palavra);
    //inicia o vetor de confirmação totalmente com o valor vazio
    for (int i = 0; i < 30; i++)
    {
        caracteresUsados[i] = '\0';
    }
    //for para a rotação dos caracteres da palavra lida
    for (int i = 0; i < tamanho; i++)
    {
        //for para a rotação dos caracteres para confirmação
        for (int e = 0; e < tamanho; e++)
        {
            if(palavra[i] == caracteresUsados[e]){
                jaUsado = 1;
            }
            
        }
        //se nao tiver sido usado até entao é posto no array para confirmação posterior
        if(jaUsado == 0){
                for (int i = 0; i < 30; i++)
                {
                    if(caracteresUsados[i] == '\0'){
                        caracteresUsados[i] = palavra[i];
                        break;
                    }
                }
            }
            jaUsado = 0; 
    }
    //resultado final é mostrado
    printf("O numero de letras diferentes e:%d",strlen(caracteresUsados));
    return 0;
}
