/****************************************************************************
 * Criado por: Henri Boraschi Venturini (RA 2760482121027) em 21-08-2021    *
 * Programa: des01.c (calculaCircunferencia), dado o valor da distancia em  *
 * estadios e o angulo o programa calcula a circunferencia de um planeta x  *
 * e imprime na tela o seu resultado em estadios e em KM                    *
 ***************************************************************************/

//importa a biblioteca do proprio C

#include <stdio.h>

void main()
{
    // cria as variaveis sem inicializar

    float circunEstad, circunKM, distancia, angulo, proporcao;

    //le os valores de distancia e angulo do teclado

    printf("Entre com a distancia [em estadios]: ");
    scanf("%f", &distancia);

    printf("\nEntre com o angulo: ");
    scanf("%f", &angulo);

    //calcula a proporcao com base na angulo de uma circunferencia

    proporcao = 360 / angulo;

    //calcula a circunferencia do planeta em estadios

    circunEstad = proporcao * distancia;

    //converte de estadios para KM

    circunKM = (circunEstad * 176.4) / 1000;

    //mostra na tela os resultados

    printf("\nA distancia em estadios e em KM sao respectivamente: %.1f e %.1f", circunEstad, circunKM);

}
