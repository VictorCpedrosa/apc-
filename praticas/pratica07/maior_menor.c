#include <stdio.h>

int main() {
    int numero, maior, menor;

    printf("Digite um numero (0 para parar): ");
    scanf("%d", &numero);

    maior = numero;
    menor = numero;

    while(numero != 0) {
        if (numero > maior) {
            maior = numero;
        }

        if (numero < menor) {
            menor = numero;
        }

        printf("Digite um numero (0 para parar): ");
        scanf("%d", &numero);
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}
