#include <stdio.h>

struct data_t
{
    int dia;
    int mes;
    int ano;
};

int main()
{
    struct data_t data;

    printf("Entre um dia: ");
    scanf("%i", &data.dia);

    printf("Entre um mês: ");
    scanf("%i", &data.mes);

    printf("Entre um ano: ");
    scanf("%i", &data.ano);

    printf("A data no formato BR: %02i/%02i/%4i\n", data.dia, data.mes, data.ano);
    printf("A data no formato US: %02i/%02i/%4i\n", data.mes, data.dia, data.ano);

    return 0;
}
