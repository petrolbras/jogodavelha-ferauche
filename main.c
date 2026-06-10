#include <stdio.h>
#include <string.h>

void jogar (char jogador_X[], char jogador_O[], char mat[3][3]) {
    
    char vencedor[100] = "";
    int i, j;

    // inicialização do jogo da velha

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat[i][j] = ' ';
        }
    }

    while(vencedor[0] == '\0') {
        // jogador X

        int linha, coluna;

        printf("Vez de %s:\n", jogador_X);

        printf("%s, informe linha: \n", jogador_X);
        scanf("%d", &linha);

        printf("%s, informe coluna: \n", jogador_X);
        scanf("%d", &coluna);

        // se o usuário estourar o limite da matriz ou escolher uma posição já ocupada, ele deve informar uma nova linha e coluna

        while (mat[linha][coluna] != ' ') {

            if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
                printf("Linha e coluna devem ser entre 0 e 2. Informe nova linha e coluna!.\n");

                scanf("%d", &linha);
                scanf("%d", &coluna);
            }

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

        printf("%s, informe linha: \n", jogador_O, linha);

        scanf("%d", &linha);

        printf("%s, informe coluna: \n", jogador_O, coluna);

        scanf("%d", &coluna);

        while (mat[linha][coluna] != ' ') {

            if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
                printf("Linha e coluna devem ser entre 0 e 2. Informe nova linha e coluna!.\n");

                scanf("%d", &linha);
                scanf("%d", &coluna);
            }

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
}

void perguntar_nomes(char jogador_X[100], char jogador_O[100], int tamanho) {

    // o strcspn é usado para remover o \n que o fgets coloca

    printf("Digite o nome do jogador X:\n");

    if (fgets(jogador_X, tamanho, stdin)) {
        jogador_X[strcspn(jogador_X, "\n")] = '\0'; 
    }

    printf("Agora, digite o nome do jogador O:\n");

    if (fgets(jogador_O, tamanho, stdin)) {
        jogador_O[strcspn(jogador_O, "\n")] = '\0'; 
    }
}

int main() {

    char jogador_X[100] = "";
    char jogador_O[100] = "";
    char mat[3][3];

    perguntar_nomes(jogador_X, jogador_O, 100);

    while (1) {
        
        jogar(jogador_X, jogador_O, mat);

        char resposta = '\0';
        char mesma_partida = '\0';

        // lógica para o usuário poder jogar de novo e escolher se quer os mesmos jogadores ou não

        do {

            printf("Deseja jogar novamente? (S/N)\n");

            scanf(" %c", &resposta);

            if (resposta && resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n') {
                printf("Por favor responda S ou N.\n");
            }

        } while (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n');

        if (resposta == 'N' || resposta == 'n') {
            printf("Fim do programa!\n");
            break;
        } else if (resposta == 'S' || resposta == 's') {
            do {
                printf("Serão os mesmos jogadores? (S/N)\n");

                scanf(" %c", &mesma_partida);

                if (mesma_partida && mesma_partida != 'S' && mesma_partida != 's' && mesma_partida != 'N' && mesma_partida != 'n') {
                    printf("Por favor responda S ou N.\n");
                }
            } while (mesma_partida != 'S' && mesma_partida != 's' && mesma_partida != 'N' && mesma_partida != 'n');
        }

        if (mesma_partida == 'N' || mesma_partida == 'n') {
            getchar(); // limpar o \n
            perguntar_nomes(jogador_X, jogador_O, 100);
        }
    }    

    return 0;
}