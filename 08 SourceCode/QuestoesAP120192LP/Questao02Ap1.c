#include <stdio.h>
#include <stdlib.h>

#define tamVet 500

int main(void){
  char sexo[tamVet]; // M; F
  char olhos[tamVet]; // A; V; C
  char cabelos[tamVet]; // L; C; P
  int  idade[tamVet], maiorIdade = -1, qtdPessoas = 0;

  for (int x= 0; x < tamVet; x++){
    printf("\nSexo (F/M)? "); scanf(" %c", &sexo[x]);
    printf("\nOlhos (A/V/C)? "); scanf(" %c", &olhos[x]);
    printf("\nCabelos (L/C/P)? "); scanf(" %c", &cabelos[x]);
    printf("\nIdade ? "); scanf("%d", &idade[x]);

    if (maiorIdade < idade[x])
      maiorIdade = idade[x];

    if ( sexo[x] == 'F' && idade[x] > 18 && idade[x] < 35 && olhos[x] == 'V' && cabelos[x] == 'L')
      qtdPessoas++;
  }

  printf("\n");
  printf("\n");
  printf("\nMaior Idade = %d ", maiorIdade);
  printf("\n");
  printf("\nQuantidade de indivíduos do sexo feminino, cuja idade está [18;35] anos e que tenham olhos verdes e cabelos louros = %d ", qtdPessoas);
  printf("\n");

  for (int x= 0; x < tamVet; x++)
    if ( maiorIdade == idade[x] )
      printf("\nPesssoa [%d] ", x);
}
