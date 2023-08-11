#include <stdio.h>

int main (void) {
   char nome[50];

   // Opção 1
   printf("Digite um nome 1: ");
   scanf("%s[^\n]", nome);
   printf("O nome digitado foi 1: %s", nome);

   printf("\n");
   printf("\n");

   // Opção 2 - Somente no SO Windows
   //printf("Digite um nome 2: ");
   //gets(nome);
   //printf("O nome digitado foi 2: %s", nome);

   printf("\n");
   printf("\n");

   // Opção 3
   printf("Digite um nome 3: ");
   scanf("%s", &nome);
   printf("O nome digitado foi 3: %s", nome);

   printf("\n");
   printf("\n");

   // Declarando uma variável do tipo String (endereço de memória)
   char sexo_string[10];
   
   // Atribuir de uma variável string
   strcpy(sexo_string, "F"); // Feminino
   
   // Ou
   // Leitura de uma string STRING
   // scanf("%s", sexo_string); // Não tem & na leitura
   // printf("%s", sexo_string);
   
   // Comparando uma variável String do tipo char nome[50]
   // Na comparação de uma variável do tipo STRING utiliza-se Aspas duplas "
   if ( strcmp(sexo_string, "M") == 0) // Uma variável do tipo string eh um ponteiro (referência - endereço de memória), seu conteúdo eh um endereço de memória
     print("Masculino");
   else
     print("Feminino");
 
   // Declarando uma variável do tipo char
   char sexo_char;  
   scanf("%c", &sexo_char); // Existe & na leitura
   
   // // Na comparação de uma variável do tipo CHAR utiliza-se aspas simples '
   if ( sexo_char == 'M' ) // Aspas simples 
     print("Masculino");
   else
     print("Feminino");
}
