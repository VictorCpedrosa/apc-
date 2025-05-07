#include <stdio.h>

int main(){

char nome_produto [31];
int quantidade;
float preco;
float valor_total;

printf("Entre com o nome do produto: ");
scanf("%[^\n]s", nome_produto);
getchar();

printf("Entre com a quantidade do produto: ");
scanf("%i", &quantidade);
getchar();

printf("Entre com o preco do produto: ");
scanf("%f", &preco);
getchar();

valor_total = preco * quantidade;

printf("================================\n");
printf("     N O T A    L E G A L\n");
printf("================================\n");
printf("%-15s %3s %10s\n", "Produto", "Qtd", "Valor\n");
printf("%-15s %03i %10.2f\n", nome_produto, quantidade, preco, valor_total);
printf("Total: %23.2f\n", valor_total);

    return 0;
}