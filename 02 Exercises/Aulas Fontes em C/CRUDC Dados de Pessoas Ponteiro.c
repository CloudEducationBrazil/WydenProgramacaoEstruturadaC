/*Elaborar o escopo de um programa que será elaborado usando lista encadeada

Características:
Ao menos uma variável float
Ao menos uma variável int
Ao menos uma variável char
É necessário ter um índice que não pode ser repetido (chave)
A busca poderá ser realizada por dois campos.

Módulos:
Criação da lista.
Verificação de lista vazia
Inserção – campo chave deve ser preenchido
Busca – deverá buscar por dois campos
Exclui – opção para excluir o primeiro elemento ou o último
Imprime – Relatório das informações cadastradas
Adicional: ordenar os elementos da lista
Código de referência em C:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //?
#include <conio.h>  //clrscr

#define BUFFER 64

/* Estrutura da lista declarada para armazenar nossos dados. */
typedef struct lista {
        char *nome;
        int idade;
        struct lista *proximo;
} Dados;

/* Prototipo das funcoes de manuseio dos dados. */
Dados *inicia_dados(char *nome, int idade);
Dados *insere_dados(Dados *dados, char *nome, int idade);
void exibe_dados(Dados *dados);
void busca_dados(Dados *dados, char *chave);
Dados *deleta_dados(Dados *dados);
int checa_vazio(Dados *dados);

/* Prototipo das funcoes do menu.*/
void insere(void);
void exibe(void);
void busca(void);
void deleta(void);

/* Inicializa a estrutura de dados principal. */
Dados *principal = NULL;

/* Cria a nova lista apontando o proximo no para NULL. */
Dados *inicia_dados(char *nome, int idade) {
        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->idade = idade;
        novo->proximo = NULL;

        return novo;
}

/* Como a lista nao esta mais vazia, apontamos o proximo no para lista anterior. */
Dados *insere_dados(Dados *dados, char *nome, int idade) {
        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->idade = idade;
        novo->proximo = dados;

        return novo;
}

/* Percorre todos os campos da lista e imprime ate o ponteiro proximo chegar em NULL. */
void exibe_dados(Dados *dados) {
        fprintf(stdout, "Cadastro:\n\n");

        fprintf(stdout, "------------------------\n");

        for (; dados != NULL; dados = dados->proximo) {
                fprintf(stdout, "Nome: %s\n", dados->nome);
                fprintf(stdout, "Idade: %d\n", dados->idade);
                fprintf(stdout, "------------------------\n ");
        }
        printf("Pressione uma tecla para continuar.");
        getch();
}

/* Percorre cada ponta comparando o nome com a chave. */
void busca_dados(Dados *dados, char *chave) {
        int achou = 0;

        fprintf(stdout, "Cadastro:\n\n");
        for (; dados != NULL; dados = dados->proximo) {
                if (strcmp(chave, dados->nome) == 0) {

                        fprintf(stdout, "------------------------\n");
                        fprintf(stdout, "Nome: %s\n", dados->nome);
                        fprintf(stdout, "Idade: %d\n", dados->idade);
                        fprintf(stdout, "------------------------\n");
                        achou++;
                }
        }

        if (achou == 0)
                fprintf(stdout, "Nenhum resultado encontrado.\nPressione uma tecla para continuar.\n");
        else
                fprintf(stdout, "Foram encontrados %d registros. \nPressione uma tecla para continuar.\n", achou);

        sleep(1);
        getch();
}

/* Deleta o ultimo registro inserido. */
Dados *deleta_dados(Dados *dados) {
        Dados *novo;

        novo = dados->proximo;

        free(dados->nome);
        free(dados);

        fprintf(stdout, "O ultimo registro inserido foi deletado com sucesso.\\n");
        sleep(1);

        return novo;
}

/* a pena checa se a lista e NULL ou nao. */
int checa_vazio(Dados *dados) {
        if (dados == NULL) {
                fprintf(stdout, "Lista vazia!\\n");
                sleep(1);
                return 1;
        } else
                return 0;
}

/* Obtem os dados necessarios para chamar as funcoes de manuseio de dados. */
void insere(void) {
        char *nome;
        int idade;

        nome = (char *)malloc(BUFFER);

        fprintf(stdout, "\n\nDigite o Nome: \n----> ");
        scanf("%s", nome);
        fprintf(stdout, "\n");

        fprintf(stdout, "Digite a Idade: \n----> ");
        scanf("%d", &idade);
        fprintf(stdout, "\n");

        if (principal == NULL)
                principal = inicia_dados(nome, idade);
        else
                principal = insere_dados(principal, nome, idade);
}

void exibe(void) {
        if (!checa_vazio(principal))
                exibe_dados(principal);
}

void busca(void) {
        char *chave;

        if (!checa_vazio(principal)) {

                chave = (char *)malloc(BUFFER);

                fprintf(stdout, "Digite o nome para buscar: \\n--> ");
                scanf("%s", chave);

                busca_dados(principal, chave);
                getch();
        }
}

void deleta(void) {
        if (!checa_vazio(principal))
                principal = deleta_dados(principal);
}

int main(void) {
        char escolha;
        do {
                system("cls");
                fprintf(stdout, "\n Cadastro de Pessoas\n\n");
                fprintf(stdout, "Escolha uma opcao: \n\n");
                fprintf(stdout, "1 - Insere Dados\n");
                fprintf(stdout, "2 - Exibe Dados\n");
                fprintf(stdout, "3 - Busca Dados\n");
                fprintf(stdout, "4 - Deleta Dados\n");
                fprintf(stdout, "5 - Sair\n\n");

                scanf("%c", &escolha);

                switch(escolha) {
                        case '1':
                                insere();
                                break;

                        case '2':
                                exibe();
                                break;

                        case '3':
                                busca();
                                break;

                        case '4':
                                deleta();
                                break;

                        case '5':
                                exit(0);
                                break;

                        default:
                                fprintf(stderr,"Digite uma opcao valida!\\n");
                                sleep(1);
                                break;
                }
                //getchar(); /* E para impedir sujeira na entrada da escolha. Nao lembro de nada melhor tambem.   */
        }
        while (escolha > 0); /* Loop Principal. */
        return 0;
}
