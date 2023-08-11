#include <stdio.h>
#include <stdlib.h>
#define tamlinha 2
#define tamcoluna 2
#define tamvetor 4

int main(void) {
    int M[tamlinha] [tamcoluna];
    int V[tamvetor];
    int x=0;
    int fat=1;

   for(int l=0;l<tamlinha;l++){
    for(int c=0;c<tamcoluna;c++){
     printf("Elemento[%i][%i]: ",l,c);
     scanf("%i",&M[l][c]);
    }
   }

    for(int l=0;l<tamlinha;l++){
       for(int c=0;c<tamcoluna;c++){
        V[x]= M[l][c];x++;
       }
    }

     for(int x=0;x<tamvetor;x++){
          printf("o valor do vetor[%d]:  [%d]\n",x,V[x]);
     }
int aux;
      for(x=0;x<tamvetor;x++){
      for(aux = 1; V[x] >= 1; V[x] = V[x] - 1){
        fat= fat*aux;
         printf("O valor fatorial [%d]:  %d \n",x, fat);
      }
      }
}





