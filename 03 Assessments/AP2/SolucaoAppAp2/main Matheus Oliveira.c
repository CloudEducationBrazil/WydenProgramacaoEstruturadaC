#include <stdio.h>
#include <stdlib.h>

//#include <C:\Users\m_oli\OneDrive\Documentos\Code block\Linguagem de Programação\menu.h>




//Estruturas do software

int conta[100];
int agencia[100];
int cpf[100];
char nome[100][100];
int count = -1;
int cadastrados = 0;

void importar();
void menu();
void cadastro();
void listar();
void buscar();
void editar();
void excluir();
void salvar();

int main()
{

    menu();


}

void cadastro()
{

    cadastrados++;
    count++;
    int op;
    int i =0;

    system("cls || clear");
    printf("Cadastro de um novo cliente\n");
    printf("Digite o nome completo do cliente:");
    scanf("%s", &nome[count]);
    printf("Digite o numero do CPF (somente numeros): ");
    scanf("%d",&cpf[count]);
    printf("Digite o numero da agencia:");
    scanf("%d",&agencia[count]);
    printf("Digite o numero da conta:");
    scanf("%d",&conta[count]);

    system("cls || clear");
    printf("Corretista cadastrado com sucesso !!!\n");
    do
    {

        printf("Cadastrar novo usuario ?\n");
        printf("1 - SIM\n2 - NÃO\n");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
          return  cadastro();
            break;

        }
    }while(op != 2);
    system("cls || clear");
    return menu();
}


void listar()
{
    int i =0;

    system("cls || clear");
    for(i; i<cadastrados; i++)
    {
        printf("Nome: %s CPF: %d Agencia: %d Conta: %d\n\n", nome[i], cpf[i] ,agencia[i],conta[i]);
    }

    system("pause");
    menu();


}






void menu()
{

    int op;

    
    printf("1 - CADASTRAR \n2 - LISTAR TODOS CORRETISTAS \n3 - ATUALIZAR \n4 - SALVAR \n5 - IMPORTAR \n0 - SAIR\n");
    scanf("%d", &op);



    switch(op)
    {
    case 1:
        cadastro();

        break;

    case 2:
        return  listar();
        break;

    case 3:
        buscar();
        break;

    case 4:
        salvar();
        break;
    case 5:
        importar();
        break;
    case 0:
        printf("sair..." );
        exit;
        break;
    default:
        system("clear");
        printf("OPÇÃO INVALIDA , POR GENTILEZA DIGITE NOVAMENTE*\n");

        menu();

    }

}


void buscar()
{
    int contaBusca;
    int i;
    int op;
    printf("\n Digite o numero da conta do seu cliente: ");
    scanf("%d", &contaBusca);
    for(i=0; i<2; i++)
    {
        if(conta[i]==contaBusca)
        {   system("cls || clear");
            printf("Cliente encontrado:");
            printf("\n\n Nome: %s\t CPF: %d\t Agencia: %d \t Conta: %d \t\n ", nome[i], cpf[i],conta[i],agencia[i]);
            do
            {
                printf("Editar ou Excluir?\n");
                printf("[1] Editar\n");
                printf("[2] Excluir\n");
                printf("[0] Menu\n");
                scanf("%d", &op);

                switch(op)
                {
                case 1:
                    return editar(i);
                    break;
                case 2:
                   return excluir(i);
                    break;
                case 0:
                    break;
                default:
                    printf("Digite uma opção valida!!");
                }
                system("cls || clear");
            }
            while(op != 0);
            menu();

        }
    }
    printf("Dados não encontrado!");
    menu();

}





void editar(int i)
{
    system("cls || clear");
    printf("\n Nome: %s CPF: %d agencia: %d conta: %d\n\n  ", nome[i], cpf[i] ,agencia[i],conta[i]);

    printf("Coloque abaixo os novos dados:\n");
    printf("Digite o novo nome:\n");
    scanf("%s", &nome[i]);
    printf("Digite o novo numero do CPF(somente numeros):\n ");
    scanf("%d",&cpf[i]);
    printf("Digite o numero da conta:\n ");
    scanf("%d",&conta[i]);
    printf("Digite o numero da agencia:\n ");
    scanf("%d",&agencia[i]);
    system("cls || clear");
    printf("Dados atualizados com sucesso!!\n");
    printf("\n Nome: %s CPF: %d agencia: %d conta: %d\n\n  ", nome[i], cpf[i] ,agencia[i],conta[i]);
    menu();

}


void excluir (int i)
{


    for(i; i<cadastrados-1; i++)
    {
        nome[i][100]= nome[i+1][100];
        cpf[i]
        =  cpf[i+1];
        conta[i] = cpf[i+1];
        agencia[i] =  cpf[i+1];
    }
     cadastrados--;
    listar();
    printf("Corretista excluído com sucesso");
    printf("Você será redirecionado para o meunu principal...");
    system("pause");
    menu();



}

void salvar()
{

    FILE *arquivo;
    int i =0;
    arquivo = fopen("Usuarios.txt", "a");


     if(arquivo == NULL){
         printf("Erro ao abrir arquivo");
     }
    for (i; i<cadastrados; i++)
    {
        fprintf(arquivo, "Nome:%s\t Cpf:%d\t Agencia:%d\t Conta:%d\t \n", nome[i],cpf[i],agencia[i], conta[i]);

    }
    printf("\t\t\tArquivos armazenados com sucesso!!");
  
} 


void importar(){


    FILE *arquivo;
     char linha[100];
     char *result;
     int i=0;

     arquivo = fopen("Usuarios.txt" , "rt");


     if(arquivo == NULL){
         printf("Erro ao abrir arquivo");
     }

     while(!feof(arquivo)){
          result = fgets(linha,100,arquivo);

          if(result){
              printf("%s",linha);
            fscanf(arquivo,"%s %d %d %d", &nome[i],&cpf[i],&agencia[i],&conta[i]);
          }

     }
     menu();


}
