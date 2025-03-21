#include <stdio.h>

int main() {
  // Movimentando com laço For
  printf("Movimentado Torre: \n");
  for (size_t i = 0; i < 5; ++i) {
    printf("Direita; ");
  }

  printf("\n\n");

  // Movimentando com While
  printf("Movimentado Bispo: \n");
  int localBispo = 0;

  while (localBispo < 5) {
    printf("Cima, Direita; ");
    ++localBispo;
  }

  printf("\n\n");

  // Movimentando com Do While
  printf("Movimentando a Rainha: \n");
  int localRainha = 0;

  do {
    printf("Esquerda; ");
    ++localRainha;
  } while (localRainha < 5);

  printf("\n");

  return 0;
}
