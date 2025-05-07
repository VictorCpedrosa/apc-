#include <stdio.h>

int main(){

    int numero = 0;
    int decimal = 0;

    printf("Digite um numero:");
    scanf("%i", &numero);

    for(int i=128; i>0; i=i/2) {    int bit = decimal / i;
        decimal = decimal %i;
        printf("%i", bit);
    }


    
    return 0;
}