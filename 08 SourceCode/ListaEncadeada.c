#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int numero;
   int *proximo
} lstEncadeada;

int main(void){
    lstEncadeada    *lstEncadeada_ini;
    lstEncadeada    *lstEncadeada_prox;
    int resp;

    lstEncadeada_ini = (lstEncadeada*) malloc(sizeof(lstEncadeada));

    // deu ERRO NA LIBERAÇÃO DE MEMÓRIA
    if ( lstEncadeada_ini == NULL ) exit(1);

    lstEncadeada_prox = lstEncadeada_ini;
    while (1) {
      printf("Digite Elemento: "); scanf("%d", &lstEncadeada_prox->numero);
      printf("Continua? "); scanf("%d", &resp);

      if ( resp == 1){
       lstEncadeada_prox->proximo = (lstEncadeada*) malloc(sizeof(lstEncadeada));
       lstEncadeada_prox = lstEncadeada_prox->proximo;
       }
      else
        break;
   }
    lstEncadeada_prox->proximo = NULL;
    lstEncadeada_prox = lstEncadeada_ini;

    printf("\n\n");
    while (lstEncadeada_prox != NULL) {
       printf("Elemento = %d \n", lstEncadeada_prox->numero);
       lstEncadeada_prox = lstEncadeada_prox->proximo;
    }
}
