#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tamVetorAux 5

// Definindo a Estrutura Pessoa
typedef struct {
	char nomePessoa[tamVetorAux][50];
	char sexoPessoa[tamVetorAux]; // Domínio Admitido : F ou M
	char abortoPessoa[tamVetorAux]; // Domínio Admitido : S ou N
} PessoaSchema;

// Instanciando / Declarando a Estrutura Pessoa
PessoaSchema Pessoa;

// declarando Variaveis Globais
int totalPessoaSexoFeminino = 0;
int totalPessoaSexoMasculino = 0;
int totalPessoaSexoMasculinoAfavorAborto = 0;

float percPessoaSexoMasculinoAbortoSIM;

// Ler vetor Struct Pessoas
void LerPessoa(int tamVetor);

// Calcula Vetor Estrutura Pessoas
void calculaPessoa(int tamVetor);

// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
void imprimirPessoa(int tamVetor);

// Programa Principal
int main(void) {
    setlocale(LC_ALL, "");

	printf("[REGISTRO] ESTRUTURA DE DADOS HETEROGENEA => Pesquisa de Opinião Sobre Aborto");
	printf("\n");
	printf("\n");

	// Ler vetor Struct Pessoas
	LerPessoa(tamVetorAux);

	// calcula vetor Struct Pessoas
	calculaPessoa(tamVetorAux);

	// Imprimindo os Resultados
	printf("\n");
	printf("Total Pessoas Sexo Feminino = [%d]", totalPessoaSexoFeminino);

	printf("\n");
	printf("Percentual Pessoas do Sexo Masculino Aborto = SIM = [%.2f]", percPessoaSexoMasculinoAbortoSIM);

	// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
	printf("\n");
	imprimirPessoa(tamVetorAux);

	getchar();
}

// Ler vetor Struct Pessoas
void LerPessoa(int tamVetor){
	int x;
	for (x= 0; x < tamVetor; x++){
		printf("Nome [%d]: ", x); scanf("%s", &Pessoa.nomePessoa[x]);
		printf("Sexo [%d] (F/M): ", x); scanf(" %c", &Pessoa.sexoPessoa[x]);
		printf("A Favor do Aborto [%d] (S/N): ", x); scanf(" %c", &Pessoa.abortoPessoa[x]);
		printf("\n");
	}
}

// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
void calculaPessoa(int tamVetor){
	int x;
	for (x= 0; x < tamVetor; x++){
		// Contator de Sexo Feminino
		if ( Pessoa.sexoPessoa[x] == 'F' )
		  totalPessoaSexoFeminino++;

		// Contator de Sexo Masculino que Responderam Afavor do Aborto
		if ( Pessoa.sexoPessoa[x] == 'M' && Pessoa.abortoPessoa[x] == 'S' )
		  totalPessoaSexoMasculinoAfavorAborto++;
	}

	totalPessoaSexoMasculino = tamVetor - totalPessoaSexoFeminino;
	percPessoaSexoMasculinoAbortoSIM = (float)totalPessoaSexoMasculinoAfavorAborto / (float)totalPessoaSexoMasculino * 100;
}

// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
void imprimirPessoa(int tamVetor){
	int x;
	for (x= 0; x < tamVetor; x++){
		if ( Pessoa.sexoPessoa[x] == 'M' && Pessoa.abortoPessoa[x] == 'S' )
		  printf("\nNome [%d] = %s a favor do Aborto. ", x, Pessoa.nomePessoa[x]);
	}
}

