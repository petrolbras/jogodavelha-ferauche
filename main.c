#include <stdio.h>
#include <string.h>

int main() {

    char jogador_X[100];
    char jogador_O[100];
    char vencedor[100];

    int i, j;
    char mat[3][3];

    printf("Digite os nome do jogador X:\n");

    if (fgets(jogador_X, sizeof(jogador_X), stdin)) {
        jogador_X[strcspn(jogador_X, "\n")] = '\0'; 
    }

    printf("Agora, digite o nome do jogador O:\n");

    if (fgets(jogador_O, sizeof(jogador_O), stdin)) {
        jogador_O[strcspn(jogador_O, "\n")] = '\0'; 
    } 


    // o strcspn é usado para remover o \n que o fgets coloca

    // inicialização do jogo da velha

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat[i][j] = ' ';
        }
    }

    while (vencedor[0] == '\0') {

        // jogador X

        int linha, coluna;

        printf("Vez de %s:\n", jogador_X);

        printf("%s, informe linha: %d\n", jogador_X, linha);

        scanf("%d", &linha);

        printf("%s, informe coluna: %d\n", jogador_X, coluna);

        scanf("%d", &coluna);

        while (mat[linha][coluna] != ' ') {
            printf("Posição linha %d e coluna %d já ocupada. Informe nova posição!.\n", linha, coluna);

            scanf("%d", &linha);
            scanf("%d", &coluna);
        }

        mat[linha][coluna] = 'X';

        // verificar se o jogador X venceu

        if  ((mat[0][0] == 'X' && mat[0][1] == 'X' && mat[0][2] == 'X') ||
            (mat[1][0] == 'X' && mat[1][1] == 'X' && mat[1][2] == 'X') ||
            (mat[2][0] == 'X' && mat[2][1] == 'X' && mat[2][2] == 'X') ||
            (mat[0][0] == 'X' && mat[1][0] == 'X' && mat[2][0] == 'X') ||
            (mat[0][1] == 'X' && mat[1][1] == 'X' && mat[2][1] == 'X') ||
            (mat[0][2] == 'X' && mat[1][2] == 'X' && mat[2][2] == 'X') ||
            (mat[0][0] == 'X' && mat[1][1] == 'X' && mat[2][2] == 'X') ||
            (mat[0][2] == 'X' && mat[1][1] == 'X' && mat[2][0] == 'X')) {
            printf("Parabéns, %s você venceu.\n", jogador_X);

            printf(" %c | %c | %c\n", mat[0][0], mat[0][1], mat[0][2]);
            printf("----------\n");
            printf(" %c | %c | %c\n", mat[1][0], mat[1][1], mat[1][2]);
            printf("----------\n");
            printf(" %c | %c | %c\n", mat[2][0], mat[2][1], mat[2][2]);


            vencedor[0] = 'X';
            break;
        }

        printf(" %c | %c | %c\n", mat[0][0], mat[0][1], mat[0][2]);
        printf("----------\n");
        printf(" %c | %c | %c\n", mat[1][0], mat[1][1], mat[1][2]);
        printf("----------\n");
        printf(" %c | %c | %c\n", mat[2][0], mat[2][1], mat[2][2]);

        // jogador O

        printf("Vez de %s:\n", jogador_O);

        printf("%s, informe linha: %d\n", jogador_O, linha);

        scanf("%d", &linha);

        printf("%s, informe coluna: %d\n", jogador_O, coluna);

        scanf("%d", &coluna);

        while (mat[linha][coluna] != ' ') {
            printf("Posição linha %d e coluna %d já ocupada. Informe nova posição!.\n", linha, coluna);

            scanf("%d", &linha);
            scanf("%d", &coluna);
        }

        mat[linha][coluna] = 'O';

        // verificar se o jogador O venceu

        if ((mat[0][0] == 'O' && mat[0][1] == 'O' && mat[0][2] == 'O') ||
            (mat[1][0] == 'O' && mat[1][1] == 'O' && mat[1][2] == 'O') ||
            (mat[2][0] == 'O' && mat[2][1] == 'O' && mat[2][2] == 'O') ||
            (mat[0][0] == 'O' && mat[1][0] == 'O' && mat[2][0] == 'O') ||
            (mat[0][1] == 'O' && mat[1][1] == 'O' && mat[2][1] == 'O') ||
            (mat[0][2] == 'O' && mat[1][2] == 'O' && mat[2][2] == 'O') ||
            (mat[0][0] == 'O' && mat[1][1] == 'O' && mat[2][2] == 'O') ||
            (mat[0][2] == 'O' && mat[1][1] == 'O' && mat[2][0] == 'O')) {
            printf("Parabéns, %s você venceu.\n", jogador_O);

            printf(" %c | %c | %c\n", mat[0][0], mat[0][1], mat[0][2]);
            printf("----------\n");
            printf(" %c | %c | %c\n", mat[1][0], mat[1][1], mat[1][2]);
            printf("----------\n");
            printf(" %c | %c | %c\n", mat[2][0], mat[2][1], mat[2][2]);


            vencedor[0] = 'O';
            break;
        }

        printf(" %c | %c | %c\n", mat[0][0], mat[0][1], mat[0][2]);
        printf("----------\n");
        printf(" %c | %c | %c\n", mat[1][0], mat[1][1], mat[1][2]);
        printf("----------\n");
        printf(" %c | %c | %c\n", mat[2][0], mat[2][1], mat[2][2]);

        // caso de empate

        if (mat[0][0] != ' ' && mat[0][1] != ' ' && mat[0][2] != ' ' &&
            mat[1][0] != ' ' && mat[1][1] != ' ' && mat[1][2] != ' ' &&
            mat[2][0] != ' ' && mat[2][1] != ' ' && mat[2][2] != ' ') {
            printf("%s e %s empataram.\n", jogador_X, jogador_O);
            break;
        }

    }

    // perguntar se o usuário quer jogar novamente e também se são os mesmos jogadores

    char resposta;
    char mesma_partida;

    // resolver isso

    while (!resposta) {

        printf("Deseja jogar novamente? (S/N)\n");

        scanf("%c", &resposta);

        if (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n') {
            printf("Por favor responda S ou N. Deseja jogar novamente? (S/N)\n");

            scanf("%c", &resposta);
        }
    }

    //resolver isso tambem e dos nomes

    if (resposta == 'S' || resposta == 's') {

        printf("São os mesmos jogadores? (S/N)\n");

        scanf("%c", &mesma_partida);

        while (mesma_partida != 'S' && mesma_partida != 's' && mesma_partida != 'N' && mesma_partida != 'n') {
            printf("Por favor responda S ou N. São os mesmos jogadores? (S/N)\n");

            scanf("%c", &mesma_partida);
        }

        if (mesma_partida == 'S' || mesma_partida == 's') {
            vencedor[0] = '\0';

            main();
        } else {

            main();
        } 
    } else {
        printf("Fim do programa!\n");
    }


    return 0;
}