#include <stdio.h>

int main() {
    int numero = 0;

    printf("Digite um numero: ");
    scanf("%i", &numero);

    if (numero < 0 || numero > 255) {
        printf("Por favor, digite um numero entre 0 e 255.\n");
        return 1;
    }

    
    for (int i = 128; i > 0; i = i / 2) {
        int bit = numero / i;
        numero = numero % i;
        printf("%i", bit);
    }

    printf("\n");

    return 0;
}
