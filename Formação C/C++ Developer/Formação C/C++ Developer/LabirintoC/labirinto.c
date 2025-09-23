#include <stdio.h>
#include <stdlib.h> 
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define ROWS 7
#define COLS 10

char mapa[ROWS][COLS] = {
    "#########",
    "#@   ^  #",
    "# ## ## #",
    "#   #   #",
    "###   ###",
    "#   ^   E",
    "#########"
};

int vidas = 3;
int jogadorR = 1, jogadorC = 1; 
int venceu = 0; 

void imprimirMapa() {
    system(CLEAR); 
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", mapa[i]);
    }
    printf("Vidas: %d\n", vidas);
}

void moverJogador(char direcao) {
    int novaR = jogadorR, novaC = jogadorC;

    if (direcao == 'w') novaR--;
    else if (direcao == 's') novaR++;
    else if (direcao == 'a') novaC--;
    else if (direcao == 'd') novaC++;
    else {
        printf("Comando inválido! Use apenas W, A, S ou D.\n");
        return;
    }

    char destino = mapa[novaR][novaC];

    if (destino == '#') {
        printf("Movimento inválido! Você bateu numa parede.\n");
        return;
    } else if (destino == '^') {
        vidas--;
        printf("Você pisou em uma armadilha! -1 vida\n");
    } else if (destino == 'E') {
        jogadorR = novaR;
        jogadorC = novaC;
        mapa[jogadorR][jogadorC] = '@';
        printf("Parabéns! Você encontrou a saída!\n");
        venceu = 1;
        return;
    }

    // Atualiza posição
    mapa[jogadorR][jogadorC] = ' ';
    jogadorR = novaR;
    jogadorC = novaC;
    mapa[jogadorR][jogadorC] = '@';
}

int main() {
    char comando;

    printf("=== JOGO DO LABIRINTO ===\n");
    printf("Use W/A/S/D para mover. Chegue até 'E'.\n\n");

    while (vidas > 0 && !venceu) {
        imprimirMapa();
        printf("Digite seu movimento: ");
        scanf(" %c", &comando);

        moverJogador(comando);
    }

    if (vidas <= 0 && !venceu) {
        printf("Game Over! Você perdeu todas as vidas.\n");
    }

    return 0;
}
