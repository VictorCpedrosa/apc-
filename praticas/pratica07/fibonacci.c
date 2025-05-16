#include <stdio.h>

int main(){

    int numero = 0;
    int anterior = 0;
    int proximo = 1;
    int n = 0;

    printf("Digite um numero:");
    scanf("%i", &n);

    for(int i=0; i<n; i++) {printf("%i, ", proximo);
        proximo = proximo + anterior;
        anterior = proximo - anterior;
    }

    
    

    return 0;
}