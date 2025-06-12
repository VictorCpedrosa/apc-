#include <stdio.h>

int main()
{
    int mes;

    const char *meses[12] = {
        "Janeiro", "Fevereiro", "Marco", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"};

    enum mes_e
    {
        jan,
        fev,
        mar,
        abr,
        mai,
        jun,
        jul,
        ago,
        set,
        out,
        nov,
        dez
    };

    for (int i = 0; i < 12; i++)
    {
        printf("Mês %d: %s\n", i + 1, meses[i]);
    }

    printf("Entre com um mes de 1 a 12: ");
    scanf("%d", &mes);

    if (mes >= 1 && mes <= 12)
    {
        printf("O mes escolhido foi %s\n", meses[mes - 1]);
    }
    else
    {
        printf("Mes invalido!\n");
    }

    return 0;
}
