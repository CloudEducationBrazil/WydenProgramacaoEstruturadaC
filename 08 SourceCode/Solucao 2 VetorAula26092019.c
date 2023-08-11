#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tamVetorAux 5

// Programa Principal
int main(void) {
    setlocale(LC_ALL, "");

    // Definindo Variáveis Tipo Vetor
    char nomePessoa[tamVetorAux][50];
    char sexoPessoa[tamVetorAux]; // Domínio Admitido : F ou M
    char abortoPessoa[tamVetorAux]; // Domínio Admitido : S ou N

    // declarando Variaveis Locais
    int totalPessoaSexoFeminino = 0;
    int totalPessoaSexoMasculino = 0;
    int totalPessoaSexoMasculinoAfavorAborto = 0;
	int x;

    float percPessoaSexoMasculinoAbortoSIM;

	printf("[VETOR] - ESTRUTUA DE DADOS HOMOGENEA => Pesquisa de Opinião Sobre Aborto");
	printf("\n");
	printf("\n");

	// Entrada de Dados
    for (x= 0; x < tamVetorAux; x++){
        printf("Nome [%d]: ", x); scanf("%s", &nomePessoa[x]);
        printf("Sexo [%d] (F/M): ", x); scanf(" %c", &sexoPessoa[x]);
        printf("A Favor do Aborto [%d] (S/N): ", x); scanf(" %c", &abortoPessoa[x]);
        printf("\n");
	}

    // Processamento
	for (x= 0; x < tamVetorAux; x++){
		// Contator de Sexo Feminino
		if ( sexoPessoa[x] == 'F' )
		  totalPessoaSexoFeminino++;

		// Contator de Sexo Masculino que Responderam Afavor do Aborto
		if ( sexoPessoa[x] == 'M' && abortoPessoa[x] == 'S' )
		  totalPessoaSexoMasculinoAfavorAborto++;
	}

	totalPessoaSexoMasculino = tamVetorAux - totalPessoaSexoFeminino;
	percPessoaSexoMasculinoAbortoSIM = (float)totalPessoaSexoMasculinoAfavorAborto / (float)totalPessoaSexoMasculino * 100;

 	// Saída de Dados - Resultados
	printf("\n");
	printf("Total Pessoas Sexo Feminino = [%d]", totalPessoaSexoFeminino);

	printf("\n");
	printf("Percentual Pessoas do Sexo Masculino Aborto = SIM = [%.2f]", percPessoaSexoMasculinoAbortoSIM);

	// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
	printf("\n");

    // Imprimir Nome das Pessoas que Votaram a Favor do Aborto
	for (x= 0; x < tamVetorAux; x++){
		if ( sexoPessoa[x] == 'M' && abortoPessoa[x] == 'S' )
		  printf("\nNome [%d] = %s a favor do Aborto. ", x, nomePessoa[x]);
	}

	getchar();
}
