#include <stdio.h>

int main(void)
{   struct Pesquisa {
        char nome[100];
        int idade;
    } Pesquisa;

    struct Pesquisa pesquisa[3];

    char auxnome[100];
    int auxidade;

    for(int i=0;i<3;i++){
        printf("Digite Nome: ");
        scanf("%s",pesquisa[i].nome);

        printf("Digite idade: ");
        scanf("%d",&pesquisa[i].idade);
    }
    printf("Ordenar Pesquisa\n");

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (pesquisa[j].idade > pesquisa[i].idade){
            auxnome == pesquisa[i].nome;
            auxidade = pesquisa[i].idade;
            pesquisa[i].nome == pesquisa[j].nome;
            pesquisa[i].idade = pesquisa[j].idade;
            pesquisa[j].nome == auxnome;
            pesquisa[j].idade = auxidade;
            }
        }

    }

    printf("Listar Pesquisa\n");
    for(int i=0;i<3;i++){
        printf("Nome: %s |Idade: %d\n",pesquisa[i].nome,pesquisa[i].idade);
    }

}
