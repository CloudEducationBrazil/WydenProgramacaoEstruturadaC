#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char nome[100];
   int idade;
}pessoa;

int main(int argc, char** argv) {
   pessoa p[5];
   int i, k, menor;
   int flag[5];
   for (i=0; i<5; i++)
      flag[i] = 0;

   for (i=0; i<5; i++){
      printf("Entre com o nome (%d de 100): ", i+1);
      scanf("%s", &(p[i].nome));
      printf("Entre com a idade: ");
      scanf("%d", &(p[i].idade));
   }

   for (k=0; k<5; k++){
      menor = 0;
      while(flag[menor] == 1){
         menor++;
      }

      flag[menor] = 1;
      for (i=0; i<5; i++){
         if (flag[i] == 0){
            if (p[i].idade < p[menor].idade ){
               flag[menor] = 0;
               menor = i;
               flag[i] = 1;
            }
         }
      }
      printf("%s\n", p[menor].nome);
   }
   return (EXIT_SUCCESS);
}
