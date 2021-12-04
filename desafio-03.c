/*****************************************************************************************************
* Recebe palavras de um dicionario e depois uma senha, avalia a senha com base no exigido            *
* Criado por: Henri Boraschi Venturini (RA 2760482121027) e Pedro Henrique Vieira (RA 2760482121022) *
* Data: 04-12-2021                                                                                   *
******************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int valid = 0;
    char senha[50];
    char ponteiro;

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
        printf("A senha deve conter pelo menos um caracter especial (! ? # @ $)\n");
    }else{
        valid = 0;
    }

    // Verifica se eh um palindromo
    char senhaInversa[strlen(senha)];
    int j = strlen(senha);

    for(int i = 0; i < strlen(senha); i++){
        senhaInversa[j] = senha[i];
        j--;
    }

    printf("\nSenha: %s", senha);
    printf("\nSenha Inversa: %s", senhaInversa);
    printf("\nTamanho da String: %d", strlen(senha));

}
