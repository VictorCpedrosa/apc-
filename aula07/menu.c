#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao = 0;


    while(opcao != 4) {
        sistem("clear");
        printf("+------------------------+\n");
        printf("|     MENU PRINCIPAL     |\n");
        printf("+------------------------+\n");
        printf("| 1- Novo jogo           |\n");
        printf("| 2- Ver Score           |\n");
        printf("| 3- Sobre o jogo        |\n");
        printf("| 4- Sair                |\n");
        printf("+------------------------+\n");
        printf("Escolha uma opcao > ");
        scanf("%i", &opcao);
        while(getchar() != '\n'); // Limpa o buffer

        switch(opcao) {
            case 1: {
                int nivel = 0;
                sistem("clear");
                printf("Nivel do jogo:\n");
                printf("1 - Facil\n");
                printf("2 - Medio\n");
                printf("3 - Dificil\n");
                printf("Escolha um nivel > ");
                scanf("%i", &nivel);
                while(getchar() != '\n');
                printf("Voce escolheu o nivel %i\n", nivel);
                break;
            }
            case 2: {
                sistem("clear");
                printf("Score do jogo:\n");
                printf("1 - Jogador A - 1000 pontos\n");
                printf("2 - Jogador B - 2000 pontos\n");
                printf("3 - Jogador C - 5000 pontos\n");
                printf("4 - Jogador D - 3000 pontos\n");
                printf("5 - Jogador E - 10000 pontos\n");
                break;
            }
            case 3: {
                sistem("clear");
                printf("Sobre o jogo:\n");
                printf("Jogo desenvolvido em C\n");
                printf("Desenvolvido por Dev 1 e Dev 2\n");
                printf("Copyright (c) 2024\n");
                printf("Pressione ENTER para continuar...\n");
                while(getchar() != '\n'); 
                break;
            }
            case 4:{
                printf("Obrigado por jogar!\n");
                break;
            default:
                printf("OPCAO INVALIDA! TENTE NOVAMENTE.\n");
             
                }
        }
    }

    return 0;
}
