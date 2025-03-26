#include <stdio.h>

// Definindo o tipo de função que será usada como callback para moverPeca
// Deve ser um ponteiro para um ponteiro char, para que eu possa alterar o
// ponteiro, com apenas um ponteiro, irei apenas conseguir
// acessar.
typedef void (*mudarDirecao)(char **direcao, int localAtual);

void cavaloDirecao(char **direcao, int localAtual) {
  if (localAtual >= 2) {
    // Aqui estou alterando para aonde a direcao aponta.
    *direcao = "Direita";
  }
};

// O programador pode tanto passar uma função do tipo mudarDirecao, quanto um
// ponteiro NULL caso não queira alterar a direção em algum momento.
// Passando localAtual como ponteiro para poder alterar o valor pela função
void moverPeca(char *direcao, int *localAtual, int *localFinal,
               mudarDirecao callback) {
  printf("%s; ", direcao);

  if (*localAtual == *localFinal)
    return;

  (*localAtual)++;
  if (callback != NULL) {
    callback(&direcao, *localAtual);
  }

  moverPeca(direcao, localAtual, localFinal, callback);
}

int main() {
  // Movimentando com laço For
  printf("Movimentado Torre: \n");
  int torreLocalAtual = 0;
  int torreLocalFinal = 5;
  moverPeca("Direita", &torreLocalAtual, &torreLocalFinal, NULL);

  printf("\n\n");

  // Movimentando com While
  printf("Movimentado Bispo: \n");
  int bispoLocalInicial = 0;
  int bispoLocalFinal = 5;
  moverPeca("Direita, Cima", &bispoLocalInicial, &bispoLocalFinal, NULL);

  printf("\n\n");

  printf("Movimentado Bispo(Loop Aninhado): \n");
  int bispoAninhadoLocalFinal = 5;
  for (int i = 0; i <= bispoLocalFinal; ++i) {
    printf("Direita, ");
    for (int j = i; j < i + 1; j++) {
      printf("Cima; ");
    }
  }

  printf("\n\n");

  // Movimentando com Do While
  printf("Movimentando a Rainha: \n");
  int rainhaLocalAtual = 0;
  int rainhaLocalFinal = 5;
  moverPeca("Esquerda", &rainhaLocalAtual, &rainhaLocalFinal, NULL);

  printf("\n\n");

  printf("Movimentando Cavalo: \n");
  int cavaloLocalAtual = 0;
  int cavaloLocalFinal = 2;
  moverPeca("Cima", &cavaloLocalAtual, &cavaloLocalFinal, cavaloDirecao);

  printf("\n");

  return 0;
}
