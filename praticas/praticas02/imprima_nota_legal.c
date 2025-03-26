#include <stdio.h>

int main() {
    printf("================================\n");
    printf("     N O T A    L E G A L\n");
    printf("================================\n");
    printf("%-15s %3s %10s\n", "Produto", "Qtd", "Valor Unit");
    printf("%-15s %03i %10.2f\n", "Camiseta", 2, 39.99);
    printf("%-15s %03i %10.2f\n", "Calca", 1, 89.90);
    printf("%-15s %03i %10.2f\n", "Meia Social", 3, 19.99);
    printf("================================\n");
    printf("Total: %23.2f\n", (2 * 39.99) + (1 * 89.90) + (3 * 19.99));

    return 0;
}
