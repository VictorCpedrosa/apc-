#include <stdio.h>
#include <string.h>

int main()
{

    char verbo[21];

    char pronomes[6][5] = {"EU", "TU", "ELE", "NOS", "VOS", "ELES"};
    char sufixos[6][5] = {"O", "AS", "A", "AMOS", "AIS", "AMAM"};

    printf("Entre com um verbo terminado em AR: ");
    scanf("%s", verbo);

    int tamanho = strlen(verbo);
    int ultima_posicao = tamanho - 1;
    int penultima_posicao = ultima_posicao - 1;

    if (verbo[ultima_posicao] == 'r' && verbo[penultima_posicao] == 'a')
    {

        printf("Conjugacao do verbo %s no presente indicativo\n");

        char radical[21];
        strcpy(radical, verbo); // radical verbo
        radical[penultima_posicao] = '\0';

        for (int i = 0; i < 6; i++)
        {
            char conjugacao[61];
            strcpy(conjugacao, pronomes[i]);
            strcat(conjugacao, " ");
            strcat(conjugacao, radical);
            strcat(conjugacao, " ");
            strcat(conjugacao, sufixos[i]);
            printf("%s\n", conjugacao);
        }
    }
    else
    {
        printf("Verbo %s nao termina em AR\n");
    }
    return 0;
}