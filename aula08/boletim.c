#include <stdio.h>

int main(){

    float boletim[6] [3]; // matriz bidimensional = tabela
    //    0 1 2
    // 0 | | | |
    // 1 | | | | 
    // 2 | | | |
    // 3 | | | |
    // 4 | | | |
    // 5 | | | |


  

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 2 ; j++) {
            printf("Entre com sua nota: ");
        scanf("%f", &boletim[i][j]);

        }
        boletim[i][2] = 0.4f * boletim [i][0] + 0.6f * boletim[i][1];

    }

    printf("Seu boletim: \n");
    for (int i = 0; i < 6 ; i++){
        printf("Disciplina %i: ", i + 1);
        for (int j = 0; j < 3; j++){
            printf("%5.1f" , boletim[i][j]);}

        
    }
            printf("\n");


    return 0;
}