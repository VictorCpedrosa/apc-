#include <stdio.h>

int main() {
    // Imprimir de 0 a 9
    for (int i = 0; i < 10; i++) {
        printf("%i\n", i); 
    }

    // Imprimir de 9 a 0
    for (int i = 9; i >= 0; i--) {
        printf("%i\n", i);
    }

    // Mensagem final
    printf("Ao infinito e alem!\n");

    return 0;
}
