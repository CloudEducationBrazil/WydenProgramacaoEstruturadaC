#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define TamVet 3

struct AlunoSchema {
    int mat[TamVet];
    char nom[TamVet][30];
    int idade[TamVet];
};

typedef struct AlunoSchema AlunoSchema;

typedef struct {
    int codigo;
    char descricao[20];
} CidadeSchema;

void lerVetor(int TamVet2);

AlunoSchema     Aluno;

int main(void) {
    //Ler Vetor
    lerVetor(TamVet);
    printf("\n");
    printf("Mat: = %d  Nome = %s  Idade = %d ", Aluno.mat[1], Aluno.nom[1], Aluno.idade[1]);
}

void lerVetor(int TamVet2) {
    // Leitura dados do Aluno
    for (int x=0; x < TamVet2; x++){
          printf("Matricula: "); scanf("%d", &Aluno.mat[x]);
          setbuf(stdin, NULL);

          printf("Nome Aluno: "); gets(Aluno.nom[x]);
          printf("Idade: "); scanf("%d", &Aluno.idade[x]);
    }
}
