/*******************************************************************************************************
* Recebe palavras de um dicionario e depois uma senha, avalia a senha com base nos criterios exigidos  *
* Criado por: Henri Boraschi Venturini (RA 2760482121027), Pedro Henrique Vieira (RA 2760482121022),   *
* Beatriz Rodrigues de Souza (RA 2760482121032) e Lucas Guilherme Rodrigues Santana (RA 2760482121004) *
* Data: 04-12-2021                                                                                     *
********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    // Criacao das variaveis
    int valid = 0;
    int ok = 1;
    int qtdDic;
    char dic[50][20];
    char senha[50];
    char ponteiro;

    printf("Entre com a quantidade de palavras no dicionario: ");
    scanf("%d", &qtdDic);

    printf("Entre com as palavras do dicionario: ");
    for (int i = 0; i < qtdDic; i++)
    {
        scanf("%s", &dic[i]);
    }
    printf("Entre com a senha : ");
    scanf("%s", &senha);

    // Verifica o tamanho
    if(strlen(senha) < 8){
        printf("A senha deve conter mais de 8 caracteres\n");
    }

    // Verifica se tem maiuscula
    for(int i = 0; i < strlen(senha); i++){
        ponteiro = senha[i];

        if(isupper(ponteiro)){
            valid = 1;
            break;
        }
    }
    if(valid == 0){
        ok = 0;
        printf("A senha deve conter pelo menos um caracter maiusculo\n");
    }else{
        valid = 0;
    }

    // Verifica se tem minuscula
    for(int i = 0; i < strlen(senha); i++){
        ponteiro = senha[i];

        if(islower(ponteiro)){
            valid = 1;
            break;
        }
    }
    if(valid == 0){
         ok = 0;
        printf("A senha deve conter pelo menos um caracter minusculo\n");
    }else{
        valid = 0;
    }

    // Verifica se tem numero
    for(int i = 0; i < strlen(senha); i++){
        ponteiro = senha[i];

        if(isdigit(ponteiro)){
            valid = 1;
            break;
        }
    }
    if(valid == 0){
        ok = 0;
        printf("A senha deve conter pelo menos um numero\n");
    }else{
        valid = 0;
    }

    // Verifica se tem ! ? # @ $
    for(int i = 0; i < strlen(senha); i++){
        ponteiro = senha[i];

        if(ponteiro == '!' || ponteiro == '?' || ponteiro == '#' || ponteiro == '@' || ponteiro == '$'){
            valid = 1;
            break;
        }
    }
    if(valid == 0){
        ok = 0;
        printf("A senha deve conter pelo menos um caracter especial (! ? # @ $)\n");
    }else{
        valid = 0;
    }

    // Verifica se eh um palindromo
    char senhaInversa[strlen(senha)];
    for(int i = 0,j = strlen(senha) - 1; i < strlen(senha); i++,j--){
        senhaInversa[i] = senha[j];
    }
    int igualPalin = 1;
    for (int i = 0; i < strlen(senha); i++)
    {
       if(senhaInversa[i] != senha[i]){
           igualPalin = 0;
           break;
       }
    }
    if(igualPalin){
        ok = 0;
        printf("A senha nao pode ser um palindromo\n");
    }

    // Verifica se a palavra contem no dicionario
    int igualSubString = 0;
    char senhaMin[50];
    for (int i = 0; i < strlen(senha); i++)
    {
        senhaMin[i] = tolower(senha[i]);
    }
    
    for (int i = 0; i < qtdDic; i++)
    {
        char dicMin[20];
        for (int j = 0; j < strlen(dic[i]-1); j++)
        {
            dicMin[j] = tolower(dic[i][j]);
        }
        if(strstr(senhaMin,dicMin) != 0){
           igualSubString = 1; 
        }
    }
    if(igualSubString){
        ok = 0;
        printf("A senha nao pode conter palavras reservadas\n");
    }
    if(ok){
        printf("\nOk");
    }
    

}
