#include <stdio.h>
#include <string.h>
#include <locale.h>

int venceu(char mat[3][3], char simbolo) {
    
    // verificar se alguem venceu

    if ((mat[0][0] == simbolo && mat[0][1] == simbolo && mat[0][2] == simbolo) ||
        (mat[1][0] == simbolo && mat[1][1] == simbolo && mat[1][2] == simbolo) ||
        (mat[2][0] == simbolo && mat[2][1] == simbolo && mat[2][2] == simbolo) ||
        (mat[0][0] == simbolo && mat[1][0] == simbolo && mat[2][0] == simbolo) ||
        (mat[0][1] == simbolo && mat[1][1] == simbolo && mat[2][1] == simbolo) ||
        (mat[0][2] == simbolo && mat[1][2] == simbolo && mat[2][2] == simbolo) ||
        (mat[0][0] == simbolo && mat[1][1] == simbolo && mat[2][2] == simbolo) ||
        (mat[0][2] == simbolo && mat[1][1] == simbolo && mat[2][0] == simbolo)) {
        return 1;
    }

    return 0;
}

void mostrar_tabuleiro(char mat[3][3]) {

    // printar o tabuleiro quando requisitada a função

    printf("\n %c | %c | %c\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", mat[2][0], mat[2][1], mat[2][2]);

}

void fazer_jogada(char jogador[], char mat[3][3], int *linha, int *coluna) {

    // função que realiza a jogada baseado em qual jogador está jogando

    do {

        printf("\n\033[34mVez de %s: \033[0m\n", jogador);
        printf("\033[1m%s\033[0m, informe linha: \n", jogador);

        if (scanf("%d", linha) != 1) {

            printf("\033[1;31m[ Digite um número válido! ] \033[0m\n");

            // limpeza do buffer

            while (getchar() != '\n');

            continue;
        }

        printf("\033[1m%s\033[0m, informe coluna: \n", jogador);

        if (scanf("%d", coluna) != 1) {

            printf("\033[1;31m[ Digite um número válido! ] \033[0m\n");

            // limpeza do buffer

            while (getchar() != '\n');

            continue;
        }

        if (*linha < 0 || *linha > 2 || *coluna < 0 || *coluna > 2) {

            printf("\033[1;31m[ Linha e coluna devem ser entre 0 e 2. Informe nova linha e coluna! ] \033[0m\n");

        } else if (mat[*linha][*coluna] != ' ') {

            printf("\033[1;31m[ Essa posição já está ocupada. Informe nova linha e coluna! ] \033[0m\n");

        } else {
            break;
        }
    } while (1);
}

void jogar(char jogador_X[], char jogador_O[], char mat[3][3]) {

    char vencedor = '\0';
    int i, j;

    // inicialização do jogo da velha

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat[i][j] = ' ';
        }
    }

    while (vencedor == '\0') {

        // jogador X

        int linha, coluna;

        fazer_jogada(jogador_X, mat, &linha, &coluna);

        mat[linha][coluna] = 'X';

        // verificar se o jogador X venceu

        if (venceu(mat, 'X')) {

            printf("\033[35mParabéns, %s você venceu. \033[0m\n", jogador_X);

            mostrar_tabuleiro(mat);

            break;
        }

        // verificar empate

        if (mat[0][0] != ' ' && mat[0][1] != ' ' && mat[0][2] != ' ' &&
            mat[1][0] != ' ' && mat[1][1] != ' ' && mat[1][2] != ' ' &&
            mat[2][0] != ' ' && mat[2][1] != ' ' && mat[2][2] != ' ') {

            vencedor = 'E';

            mostrar_tabuleiro(mat);

            printf("\x1b[33m%s e %s empataram.\033[0m\n", jogador_X, jogador_O);
            break;
        }

        mostrar_tabuleiro(mat);

        // jogador O

        fazer_jogada(jogador_O, mat, &linha, &coluna);

        mat[linha][coluna] = 'O';

        // verificar se o jogador O venceu

        if (venceu(mat, 'O')) {

            printf("\033[35mParabéns, %s você venceu. \033[0m\n", jogador_O);

            mostrar_tabuleiro(mat);

            break;
        }

        // verificar empate

        if (mat[0][0] != ' ' && mat[0][1] != ' ' && mat[0][2] != ' ' &&
            mat[1][0] != ' ' && mat[1][1] != ' ' && mat[1][2] != ' ' &&
            mat[2][0] != ' ' && mat[2][1] != ' ' && mat[2][2] != ' ') {

            vencedor = 'E';

            mostrar_tabuleiro(mat);

            printf("\x1b[33m%s e %s empataram.\033[0m\n", jogador_X, jogador_O);
            break;
        }

        mostrar_tabuleiro(mat);
    }
}

void perguntar_nomes(char jogador_X[100], char jogador_O[100], int tamanho) {

    // o strcspn é usado para remover o \n que o fgets coloca

    printf("\033[33mDigite o nome do jogador X:\033[0m\n");

    if (fgets(jogador_X, tamanho, stdin)) {
        jogador_X[strcspn(jogador_X, "\n")] = '\0';
    }

    printf("\033[33mDigite o nome do jogador O:\033[0m\n");

    if (fgets(jogador_O, tamanho, stdin)) {
        jogador_O[strcspn(jogador_O, "\n")] = '\0';
    }
}

int main() {

    // permitir acentos e caracteres especiais

    setlocale(LC_ALL, "");

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

            if (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n') {
                printf("Por favor responda S ou N.\n");
            }

        } while (resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n');

        if (resposta == 'N' || resposta == 'n') {
            printf("Fim do programa!\n");
            break;
        }
        else if (resposta == 'S' || resposta == 's') {
            do {
                printf("Serão os mesmos jogadores? (S/N)\n");

                scanf(" %c", &mesma_partida);

                if (mesma_partida != 'S' && mesma_partida != 's' && mesma_partida != 'N' && mesma_partida != 'n') {
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