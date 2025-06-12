#include <stdio.h>

int main()
{

    const int LIMITE = 10;

    struct aluno_t
    {
        int matricula;
        char email[101];
    };

    struct aluno_t alunos[LIMITE];

    for (int i = 0; i < LIMITE; i++)
    {

        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Digite o email do aluno %d: ", i + 1);
        scanf("%100s", alunos[i].email);
    }

    int matricula;

    printf("\nEntre com uma matricula: ");
    scanf("%d", &matricula);

    int achou = -1;

    for (int i = 0; i < LIMITE; i++)
    {

        if (matricula == alunos[i].matricula)
        {

            achou = i;
            break;
        }
    }

    if (achou < 0)
    {

        printf("Matricula nao localizada!\n");
    }
    else
    {

        printf("O email do aluno, matricula %d, eh %s\n", alunos[achou].matricula, alunos[achou].email);
    }

    return 0;
}
