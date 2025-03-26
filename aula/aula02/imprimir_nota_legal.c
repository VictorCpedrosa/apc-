#include <stdio.h>

int main() {
    printf("--------------------------------------\n");
    printf("           NOTA LEGAL                 \n");
    printf("--------------------------------------\n");
    printf("%-20s %3s %6s %6s\n", "Item", "Qde", "Prc", "Valor");
    printf("%-20s %3d %6.2f %6.2f\n", "Caneta Azul", 2, 2.00, 4.00);
    printf("%-20s %3d %6.2f %6.2f\n", "Borracha", 1, 5.00, 5.00);
    printf("%-20s %3d %6.2f %6.2f\n", "Resma de papel", 1, 12.00, 12.00);
    printf("--------------------------------------\n");
    printf("TOTAL..........................: R$ %.2f\n", 21.00);
    
    return 0;
}
