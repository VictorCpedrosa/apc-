#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int tentativasrestantes = 6; 
int opcao;
int dificuldade = 0;
int executando = 1;
char palavra [20];
char segredo [20];

int main (){

        printf("\n========================\n");
        printf("         MENU          \n");
        printf("========================\n");
        printf("1- SELECIONAR DIFICULDADE: \n");
        printf("2- JOGAR: \n");
        printf("3- SAIR: \n");
        printf("Escolha uma opcao: ");
        scanf("%d", opcao);
        getchar(); //limpar buffer do teclado


    return 0;
}