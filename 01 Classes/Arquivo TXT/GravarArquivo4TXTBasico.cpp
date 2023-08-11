// Bibliotecas da linguagem C
#include <stdio.h>
#include <stdlib.h>

// Função Principal de um programa na linguagem C
int main(void){
    // Cria uma variável ponteiro do tipo Arquivo 
  	FILE *Arquivo;

    // Declaração de Variáveis
	char nome[100]; // Variável string
	char sexo; // Variável literal tamanho 1 caractere
	int idade; // Variável string

     // Cria o Arquivo LISTA.txt no HD - wt (Arquivo craido para gravação - Se o arquivo não existir será criado e se existir será sobreposto)
     Arquivo = fopen("LISTA.txt", "wt");
  
     // Cria o Arquivo LISTA.txt
	 if ( Arquivo == NULL ) printf("Erro na criação do arquivo");
	
     // Estrutura de Repetiação Para com contagem inicial e final
	 for (int x=1; x<=3; x++) { 
	   printf("Digite Convidado: "); scanf("%s", nome); // Leitura Variável nome do Tipo String (já eh um ponteiro - Não PRECISA do & na leitura da variável)
	   printf("Digite Sexo: ");      scanf(" %c", &sexo); // Leitura Variável sexo do Tipo Literal (1 Caractere) (não eh ponteiro, PRECISA do & na leitura)
	   printf("Digite Idade: ");     scanf("%d", &idade); // Leitura Variável idade do Tipo Inteiro (não eh ponteiro, PRECISA do & na leitura)
	
	   // Gravação de Dados no Arquivo LISTA.txt
	   fprintf(Arquivo, "%s\t%c\t%d \n", nome, sexo, idade);
	 
	   // Imprime uma linha em branco
	   printf("\n");
	 }
	
	 // Fecha o Arquivo LISTA.txt
	 fclose(Arquivo);
	
	 printf("Gravação do arquivo LISTA.txt com sucesso");
}
