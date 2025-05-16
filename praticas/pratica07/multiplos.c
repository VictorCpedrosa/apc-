#include <stdio.h>

int main(){
    int numero = 0;

    printf("Digite um numero para ver o seu multiplo:");
    scanf("%i", &numero);

    for(int i=1; i<101; i++) {if (i % numero == 0) {
        printf("%i, ", i);
      }
      
    }
    

    return 0;
}