// Aluno: Luís Paulo Matos
// Matrícula: 191030038


#include<stdio.h>
#define SIZE 100 
#include<string.h>
#include<stdlib.h>

char nome_animal[SIZE][50];
char especie_animal[SIZE][50];
char raca_animal[SIZE][50];
int idade_animal[SIZE];
float peso_animal[SIZE];
char nome_dono[SIZE][50];
char email[SIZE][50];
int rg_dono[SIZE];
int tel_dono[SIZE];
int op;



void cadastro(); //Função do Cadastro
void pesquisa(); //Função para Pesquisar os Cdastros
void lista (); //Lista Todos os Cadastros


int main(void)
{ 
    
    do{ //Função do Menu
        system("cls");
        printf("\n-------MENU------\n1  -  Cadastrar\n2  -  Listar todos\n3  -  Pesquisar\n4  -  Sair\n\n");
        scanf("%d", &op);
        switch(op) {
            case 1: 
            cadastro();
                break;
            case 2:
            lista();
                break;
            case 3:
            pesquisa();
                break;
            case 4:
            system("exit");
                break;
            default:
            printf("Opção inválida!");
                break;
        }
    }while(op!=4);
}
void lista (){
    int i;
    for(i=0;i<SIZE;i++){
        if(rg_dono[i]>0){
            printf("\n Nome do animal: %s\nEspecie do animal: %s\n Raca do animal: %s\n Idade do animal: %d\n Peso do animal: %f\n Nome do dono: %s\n Email do dono: %s\n RG do dono: %d\n Telefone do dono: %d", nome_animal[i], especie_animal[i], raca_animal[i], idade_animal[i], peso_animal[i], nome_dono[i], email[i], rg_dono[i], tel_dono[i]);
  
        }
        else{
            break;
        }
        
    }
}
void cadastro (){
    static int linha;
    do{
        printf("\n Digite o nome do animal: \n\n");
        scanf("%s", &nome_animal[linha]);
        printf("\nDigite a especie do animal:\n\n");
        scanf("%s", &especie_animal[linha]);
        printf("\n Digite a raca do animal:\n\n");
        scanf("%s", &raca_animal[linha]);
        printf("\n Digite a idade do animal em anos:\n\n");
        scanf("%d", &idade_animal[linha]);
        printf("\n Digite o peso do animal em quilos:\n\n");
        scanf("%f", &peso_animal[linha]);
        printf("\nDigite o nome do dono:\n\n");
        scanf("%s", &nome_dono[linha]);
        printf("\nDigite email do dono:\n\n");
        scanf("%s", &email[linha]);
        printf("\nDigite o RG do dono:\n\n");
        scanf("%d", &rg_dono[linha]);
        printf("\nDigite o telefone do dono:\n\n");
        scanf("%d", &tel_dono[linha]);
        
        printf("\nDigite 1 para continuar ou 0 para sair");
        scanf("%d",& op);
        
        linha++;
    }while(op==1);
} // fim do cadastro

void pesquisa() {
    int rg_pesquisa;
    char email_pesquisa[50];
    int i;
    do{
        printf("\nDigite 1 para pesquisar pelo RG do dono ou 2 para pesquisar pelo Email do dono");
        scanf("%d", &op);
        
        switch(op){
            case 1: 
                printf("\nDigite o RG do dono para pesquisar:");
                scanf("%d", &rg_pesquisa);
                
                for(i=0; i<SIZE; i++){
                    if(rg_dono[i] ==rg_pesquisa){
                        printf("\n Nome do animal: %s\nEspecie do animal: %s\n Raca do animal: %s\n Idade do animal: %d\n Peso do animal: %f\n Nome do dono: %s\n Email do dono: %s\n RG do dono: %d\n Telefone do dono: %d", nome_animal[i], especie_animal[i], raca_animal[i], idade_animal[i], peso_animal[i], nome_dono[i], email[i], rg_dono[i], tel_dono[i]);
                    }
                }
            break;
            
            case 2:
                printf("\nDigite o Email para pesquisar:");
                scanf("%s", &email_pesquisa);
                
                for(i=0; i<SIZE; i++){
                    if(strcmp(email[i], email_pesquisa)==0){
                        printf("\n Nome do animal: %s\nEspecie do animal: %s\n Raca do animal: %s\n Idade do animal: %d\n Peso do animal: %f\n Nome do dono: %s\n Email do dono: %s\n RG do dono: %d\n Telefone do dono: %d", nome_animal[i], especie_animal[i], raca_animal[i], idade_animal[i], peso_animal[i], nome_dono[i], email[i], rg_dono[i], tel_dono[i]);
                    }
                    
                }
            break;
            
            default:
                printf("\nOpção inválida!");
            
            break;
        }
        printf("\nDigite 1 para continuar pesquisando");
        scanf("%d", &op);
    }while(op==1);
}
