#include <stdio.h>

int main(){

    char tecla;
printf("Pressione uma tecla e depois ENTER: ");
    scanf("%c", &tecla); // tecla = 'a'
getchar(); // ler /n da leitura anterior

printf("Voce pressionou a tecla %c\n", tecla);

printf("Pressione outra tecla e depois ENTER: ");
    scanf("%c", &tecla); // tecla = 'a'
    getchar(); // ler /n da leitura anterior

printf("Voce pressiounou a tecla %c\n", tecla);


    return 0;
}