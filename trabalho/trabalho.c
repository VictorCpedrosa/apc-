#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int tentativasrestantes;
int opcao;
int dificuldade = 0;
int executando = 1;
char *dificuldades_texto[3] = {"FACIL", "MEDIO", "DIFICIL"};

struct
{
    char segredo[30];
    char palavra[30];
} comparar;

char *Facil[] = {"Mesa", "Dente", "Porta", "Casa", "Carro", "Cama"};
char *Medio[] = {"Caderno", "Tesoura", "Girafa", "Espelho", "Moldura", "Bexiga"};
char *Dificil[] = {"Procrastinar", "Alquimia", "Convalescer", "Ambiguidade", "Resiliencia", "Paralelepipedo"};

int main()


{
    srand(time(NULL));

    while (executando)
    {
        printf("\n========================\n");
        printf("         MENU          \n");
        printf("========================\n");
        printf("1- DIFICULDADE\n");
        printf("2- JOGAR\n");
        printf("3- SAIR\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Opcao invalida. Tente novamente\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        getchar();

        char *cores[] = {
            "\033[1;32mFACIL\033[0m",
            "\033[1;33mMEDIO\033[0m",
            "\033[1;31mDIFICIL\033[0m"};

        switch (opcao)
        {
        case 1:
            printf("\n========================\n");
            printf("      DIFICULDADES     \n");
            printf("========================\n");
            printf("1- \033[1;32mFACIL\033[0m\n");
            printf("2- \033[1;33mMEDIO\033[0m\n");
            printf("3- \033[1;31mDIFICIL\033[0m\n");
            printf("Escolha a dificuldade: ");
            scanf("%d", &dificuldade);
            getchar();
            if (dificuldade >= 1 && dificuldade <= 3)
            {
                printf("Dificuldade escolhida: %s\n", cores[dificuldade - 1]);
            }
            else
            {
                printf("Opcao invalida.\n");
                dificuldade = 0;
            }
            break;

        case 2:
            if (dificuldade < 1 || dificuldade > 3)
            {
                printf("Por favor escolha a dificuldade antes de jogar.\n");
            }
            else
            {
                printf("\nIniciando o jogo na dificuldade: %s\n", cores[dificuldade - 1]);

                tentativasrestantes = 6;
                int palavra_escolhida = rand() % 6;
                char *palavra;

                if (dificuldade == 1)
                    palavra = Facil[palavra_escolhida];
                else if (dificuldade == 2)
                    palavra = Medio[palavra_escolhida];
                else
                    palavra = Dificil[palavra_escolhida];

                strcpy(comparar.segredo, palavra);
                for (int i = 0; i < strlen(palavra); i++)
                    comparar.palavra[i] = '_';
                comparar.palavra[strlen(palavra)] = '\0';

                while (tentativasrestantes > 0)
                {
                    printf("\nPalavra: ");
                    for (int i = 0; i < strlen(palavra); i++)
                    {
                        printf("%c ", comparar.palavra[i]);
                    }

                    printf("\nTentativas restantes: %d\n", tentativasrestantes);
                    printf("Digite uma letra: ");

                    char letra;
                    scanf(" %c", &letra);

                    letra = tolower(letra);

                    int acertou = 0;
                    for (int i = 0; i < strlen(palavra); i++)
                    {
                        if (tolower(palavra[i]) == letra && comparar.palavra[i] == '_')
                        {
                            comparar.palavra[i] = palavra[i];
                            acertou = 1;
                        }
                    }

                    if (!acertou)
                    {
                        tentativasrestantes--;
                    }

                    if (strcmp(palavra, comparar.palavra) == 0)
                    {
                        printf("\nPARABENS! VOCE GANHOU! A palavra era: %s\n", palavra);
                        break;
                    }
                }

                if (tentativasrestantes == 0)
                {
                    printf("\nVOCE PERDEU. A palavra era: %s\n", palavra);
                }
            }
            break;

        case 3:
            printf("\033[1;37mOBRIGADO POR JOGAR\033[0m\n");
            executando = 0;
            break;

        default:
            printf("OPCAO INVALIDA. TENTE NOVAMENTE\n");
            break;
        }
    }

    return 0;
}
