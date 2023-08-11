#include <stdio.h>
#define tamVetor 3

int main()
{   // Somar os elementos do vetor de 10 posições:

    int vetor[tamVetor], soma=0; 
    //int vetor[3][4][5][30], soma=0; 
    
    // 1 dimensão representa a IES 
    // 2 dimensão representa a disciplina
    // 3 dimensão representa o aluno
    
    // 0 Area 1; 0 Disciplina Estrutura de Dados; 1 = Algoritmo; 0 Aluno Joao 1 Aluno Isais
    // 1 UniRuy; 0 Disciplina Ling C; 1 = Banco de Dados; 0 Aluno Raphael 1 Murilo
    
    //vetor[0][0][0][0] eh o aluno Joao que cursa Estrutura de Dados na Area 1
    //vetor[0][1][1] eh o aluno Isais que cursa Algoritmo de Dados na Area 1

    //vetor[1][0][0] eh o aluno Raphael que cursa Ling C de Dados na UniRuy
    //vetor[1][0][1] eh o aluno Murilo que cursa Ling C de Dados na UniRuy

    // Entrada (inputs) => processamento => output (saída)
    // os inputs são os elementos do vetor
    // Entrada de Dados
    // os elementos do vetor são conhecidos ?
    // Sim ou Não ?
    // Não ? Logo a entrada de dados será através de leitura via teclado

    // Entrada de Dados    
    for (int indice = 0; indice < tamVetor; indice++){
      printf("Digite o elemento [%d] \n", indice); 
      scanf("%d", &vetor[indice]);
    }

    // Processamento    
    soma = 0;
    for (int indice = 0; indice < tamVetor; indice++)
      soma = soma + vetor[indice];

    // Impressão dos elementos
    for (int indice = 0; indice < tamVetor; indice++)
      printf("Elemento [%d] = %d \n", indice, vetor[indice]);

    printf("Soma = %d \n", soma);

    return 0;
}
