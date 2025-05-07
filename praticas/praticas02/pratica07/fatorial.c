#include <stdio.h>

int main(){

int numero = 0;
int fatorial = 1;

printf("Digite um numero: ");
scanf("%i", &numero);

    for(int i=numero; i>0; i--) {fatorial = fatorial * i;
        printf("%i\n", fatorial);
        
}



    return 0;
}