#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *DocumentoListaEstatica;
	char texto[200];
	int tam;

	//fflush(stdin);
	//scanf("%200[^\n]", texto); ou

	printf("Digite um texto?");
	fflush(stdin);
	fgets(texto, 200, stdin); // Elimina o enter do buffer. new line

    /* remove newline, if present */
    tam = strlen(texto)-1;
    if( texto[tam] == '\n')
      texto[tam] = '\0';

	// Somente no Windows
	// gets(texto); // Elimina o enter do buffer. new line

	system("cls || clear");

	DocumentoListaEstatica = fopen("ArqListaEstatica3.txt", "w"); // w; r; a

	// No formato de Linha
	fprintf(DocumentoListaEstatica, "%s\t%d\t%.2f\t%s\t%d", texto, 121, 23.5, texto, 13);

	// No formato de Coluna
	//fprintf(DocumentoListaEsatatica, "%d ", 121);
	//fprintf(DocumentoListaEstatica, "%s \t", texto);
	//fprintf(DocumentoListaEstatica, "%.2f \t", 23.5);
	//fprintf(DocumentoListaEstatica, "%s \t", texto);
	fclose(DocumentoListaEstatica);
	return 0;
}
