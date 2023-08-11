#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamVetorAux 3

// Definindo a Estrutura Pessoa
typedef struct {
	char nomePessoa[tamVetorAux][50];
	char sexoPessoa[tamVetorAux]; // Domínio Admitido : F ou M
	char abortoPessoa[tamVetorAux]; // Domínio Admitido : S ou N
} PessoaSchema;

// Instanciando / Declarando a Estrutura Pessoa
PessoaSchema Pessoa;

// declarando Variaveis Globais
float totalPessoaSexoFeminino = 0;
float totalPessoaSexoMasculino = 0;
float totalPessoaSexoMasculinoAfavorAborto = 0;
float percPessoaSexoMasculinoAbortoSIM;

// Ler vetor Struct Pessoas
void LerPessoa(int tamVetor);

// Calcula Vetor Estrutura Pessoas
void calculaPessoa(int tamVetor);

// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
void imprimirPessoa(int tamVetor);

// Programa Principal
int main(void) {
	// Ler vetor Struct Pessoas
	LerPessoa(tamVetorAux);

	// calcula vetor Struct Pessoas
	calculaPessoa(tamVetorAux);

	// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
	imprimirPessoa(tamVetorAux);

	// Imprimindo os Resultados
	printf("\n");
	printf("Total Pessoas Sexo Feminino = [%d]", totalPessoaSexoFeminino);
	printf("\n");
	printf("Percentual Pessoas do Sexo Masculino Aborto = SIM = [%.2f]", percPessoaSexoMasculinoAbortoSIM);
}

// Ler vetor Struct Pessoas
void LerPessoa(int tamVetor){
	int x;
	for (x= 0; x < tamVetor; x++){
		printf("Nome [%d]: ", x); scanf("%s", &Pessoa.nomePessoa[x]);
		setbuf(stdin, NULL);
		printf("Sexo [%d] (F/M): ", x); scanf("%c", &Pessoa.sexoPessoa[x]);
		setbuf(stdin, NULL);
		printf("A Favor do Aborto [%d] (S/N): ", x); scanf("%c", &Pessoa.abortoPessoa[x]);
		printf("\n");
	}
}

// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
void calculaPessoa(int tamVetor){
	int x;
	for (x= 0; x < tamVetorAux; x++){
		// Contator de Sexo Feminino
		if ( Pessoa.nomePessoa[x] == 'F' )
		  totalPessoaSexoFeminino++;

		// Contator de Sexo Masculino que Responderam Afavor do Aborto
		if ( Pessoa.abortoPessoa[x] == 'S' )
		  totalPessoaSexoMasculinoAfavorAborto++;
	}
	
	totalPessoaSexoMasculino = tamVetorAux - totalPessoaSexoFeminino;
	printf("\n xxxxxxxx [%d] ", totalPessoaSexoMasculino);
	
	percPessoaSexoMasculinoAbortoSIM = totalPessoaSexoMasculinoAfavorAborto / totalPessoaSexoMasculino;
}

// Imprimir Nome das Pessoas que Votaram a Favor do Aborto
void imprimirPessoa(int tamVetor){
	int x;
	for (x= 0; x < tamVetorAux; x++){
		if ( Pessoa.sexoPessoa[x] == 'M' && Pessoa.abortoPessoa[x] == 'S' )
		  printf("\nNome [%d] = %s a favor do Aborto. ", x, Pessoa.nomePessoa[x]);
	}
}

