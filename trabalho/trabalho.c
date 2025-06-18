//Victor Cardozo Pedrosa 2322130027
// Joao Paulo Monteiro Brandão 2512082041



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define FILENAME "ranking.txt"

int main()
{
    srand(time(NULL));

    int tentativasrestantes;
    int opcao;
    int dificuldade = 0;
    int executando = 1;
    int pontuacao_atual = 0;
    char *dificuldades_texto[3] = {"FACIL", "MEDIO", "DIFICIL"};

    struct
    {
        char segredo[30];
        char palavra[30];
    } comparar;

    typedef struct
    {
        char nome[MAX_NAME_LENGTH];
        int pontuacao;
    } Player;

    Player ranking[MAX_PLAYERS];
    int num_players = 0;

    
    char *Facil[] = {"Mesa", "Dente", "Porta", "Casa", "Carro", "Cama"};
    char *Medio[] = {"Caderno", "Tesoura", "Girafa", "Espelho", "Moldura", "Bexiga"};
    char *Dificil[] = {"Procrastinar", "Alquimia", "Convalescer", "Ambiguidade", "Resiliencia", "Paralelepipedo"};

    
    FILE *file = fopen(FILENAME, "r");
    if (file != NULL)
    {
        while (num_players < MAX_PLAYERS && fscanf(file, "%s %d", ranking[num_players].nome, &ranking[num_players].pontuacao) == 2)
        {
            num_players++;
        }
        fclose(file);
        printf("Ranking carregado com sucesso.\n");
    }
    else
    {
        printf("Arquivo de ranking nao encontrado. Um novo sera criado.\n");
    }

    while (executando)
    {
        printf("\n========================\n");
        printf("         MENU           \n");
        printf("========================\n");
        printf("1- DIFICULDADE\n");
        printf("2- JOGAR\n");
        printf("3- RANKING\n");
        printf("4- SAIR\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Opcao invalida. Tente novamente\n");
            while (getchar() != '\n');
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
            printf("      DIFICULDADES      \n");
            printf("========================\n");
            printf("1- \033[1;32mFACIL\033[0m\n");
            printf("2- \033[1;33mMEDIO\033[0m\n");
            printf("3- \033[1;31mDIFICIL\033[0m\n");
            printf("Escolha a dificuldade: ");
            scanf("%d", &dificuldade);
            getchar();
            if (dificuldade >= 1 && dificuldade <= 3)
                printf("Dificuldade escolhida: %s\n", cores[dificuldade - 1]);
            else
            {
                printf("Opcao invalida.\n");
                dificuldade = 0;
            }
            break;

        case 2:
            if (dificuldade < 1 || dificuldade > 3)
            {
                printf("Por favor, escolha a dificuldade antes de jogar.\n");
                break;
            }

            pontuacao_atual = 0;
            tentativasrestantes = 6;

            char nome_jogador[MAX_NAME_LENGTH];
            printf("Digite seu nome (max %d caracteres): ", MAX_NAME_LENGTH - 1);
            fgets(nome_jogador, MAX_NAME_LENGTH, stdin);
            nome_jogador[strcspn(nome_jogador, "\n")] = 0;

            int palavra_escolhida_idx = rand() % 6;
            char *palavra_secreta_ptr;

            if (dificuldade == 1)
                palavra_secreta_ptr = Facil[palavra_escolhida_idx];
            else if (dificuldade == 2)
                palavra_secreta_ptr = Medio[palavra_escolhida_idx];
            else
                palavra_secreta_ptr = Dificil[palavra_escolhida_idx];

            strcpy(comparar.segredo, palavra_secreta_ptr);
            for (int i = 0; i < strlen(palavra_secreta_ptr); i++)
                comparar.palavra[i] = '_';
            comparar.palavra[strlen(palavra_secreta_ptr)] = '\0';

            while (tentativasrestantes > 0)
            {
                printf("\nPalavra: ");
                for (int i = 0; i < strlen(palavra_secreta_ptr); i++)
                    printf("%c ", comparar.palavra[i]);
                printf("\nTentativas restantes: %d\n", tentativasrestantes);
                printf("Pontuacao atual: %d\n", pontuacao_atual);
                printf("Digite uma letra: ");

                char letra_digitada;
                scanf(" %c", &letra_digitada);
                getchar();
                letra_digitada = tolower(letra_digitada);

                int acertou_letra = 0;
                for (int i = 0; i < strlen(palavra_secreta_ptr); i++)
                {
                    if (tolower(palavra_secreta_ptr[i]) == letra_digitada && comparar.palavra[i] == '_')
                    {
                        comparar.palavra[i] = palavra_secreta_ptr[i];
                        acertou_letra = 1;
                    }
                }

                if (!acertou_letra)
                {
                    tentativasrestantes--;
                    printf("Letra incorreta!\n");
                }
                else
                {
                    if (dificuldade == 1)
                        pontuacao_atual += 5;
                    else if (dificuldade == 2)
                        pontuacao_atual += 10;
                    else
                        pontuacao_atual += 20;
                    printf("Letra correta!\n");
                }

                if (strcmp(palavra_secreta_ptr, comparar.palavra) == 0)
                {
                    printf("\nPARABENS! VOCE GANHOU! A palavra era: %s\n", palavra_secreta_ptr);
                    printf("Sua pontuacao final: %d\n", pontuacao_atual);
                    tentativasrestantes = 0;
                }
            }

            if (strcmp(palavra_secreta_ptr, comparar.palavra) != 0)
            {
                printf("\nVOCE PERDEU. A palavra era: %s\n", palavra_secreta_ptr);
                printf("Sua pontuacao final: %d\n", pontuacao_atual);
            }

            
            int atualizado = 0;
            for (int i = 0; i < num_players; i++)
            {
                if (strcmp(ranking[i].nome, nome_jogador) == 0)
                {
                    if (pontuacao_atual > ranking[i].pontuacao)
                    {
                        ranking[i].pontuacao = pontuacao_atual;
                        printf("Pontuacao de %s atualizada para %d.\n", nome_jogador, pontuacao_atual);
                    }
                    atualizado = 1;
                    break;
                }
            }

            if (!atualizado)
            {
                if (num_players < MAX_PLAYERS)
                {
                    strcpy(ranking[num_players].nome, nome_jogador);
                    ranking[num_players].pontuacao = pontuacao_atual;
                    num_players++;
                    printf("%s adicionado ao ranking com %d pontos.\n", nome_jogador, pontuacao_atual);
                }
                else
                {
                    int idx_pior = 0;
                    for (int i = 1; i < num_players; i++)
                        if (ranking[i].pontuacao < ranking[idx_pior].pontuacao)
                            idx_pior = i;

                    if (pontuacao_atual > ranking[idx_pior].pontuacao)
                    {
                        strcpy(ranking[idx_pior].nome, nome_jogador);
                        ranking[idx_pior].pontuacao = pontuacao_atual;
                        printf("%s substituiu um jogador no ranking com %d pontos.\n", nome_jogador, pontuacao_atual);
                    }
                    else
                    {
                        printf("Sua pontuacao de %d nao foi suficiente para entrar no ranking.\n", pontuacao_atual);
                    }
                }
            }

            
            for (int i = 0; i < num_players - 1; i++)
            {
                for (int j = 0; j < num_players - i - 1; j++)
                {
                    if (ranking[j].pontuacao < ranking[j + 1].pontuacao)
                    {
                        Player temp = ranking[j];
                        ranking[j] = ranking[j + 1];
                        ranking[j + 1] = temp;
                    }
                }
            }

            
            file = fopen(FILENAME, "w");
            if (file != NULL)
            {
                for (int i = 0; i < num_players; i++)
                    fprintf(file, "%s %d\n", ranking[i].nome, ranking[i].pontuacao);
                fclose(file);
                printf("Ranking salvo com sucesso.\n");
            }
            else
            {
                printf("Erro ao salvar o ranking.\n");
            }
            break;

        case 3:
            printf("\n========================\n");
            printf("         RANKING        \n");
            printf("========================\n");
            if (num_players == 0)
                printf("Nenhum jogador no ranking ainda.\n");
            else
            {
                printf("Posicao | Nome               | Pontuacao\n");
                printf("------------------------------------------\n");
                for (int i = 0; i < num_players; i++)
                    printf("%-7d | %-18s | %d\n", i + 1, ranking[i].nome, ranking[i].pontuacao);
                printf("------------------------------------------\n");
            }
            break;

        case 4:
            printf("\033[1;37mOBRIGADO POR JOGAR!\033[0m\n");
            executando = 0;
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}