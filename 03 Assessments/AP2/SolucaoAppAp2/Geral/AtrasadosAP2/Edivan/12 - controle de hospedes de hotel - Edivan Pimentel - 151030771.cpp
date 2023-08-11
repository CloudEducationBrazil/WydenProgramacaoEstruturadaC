#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 2


FILE *arq;
struct cadastro
{
     int cod; 
     char nome[50]; 
     char cidade[30]; 
     char motivo[30];
     int quarto; 
     int idade;
     
};

struct cadastro hospedes[MAX];
int topo;
void inserir();
void excluir();
void listar();
void pesquisar();
void alterar();



int main()
{
      int opcao;
      char seguir = 's';

      topo = 0;

      while(seguir == 's')
      {
      printf("    *** Cadastro de Hospedes *** \n\n");
      printf("  1) cadastrar novo hospede \n");
      printf("  2) remover hospede \n");
      printf("  3) Listar hospedes \n");
      printf("  4) pesquisar hospede \n");
      printf("  5) alterar cadastro de hospede \n");
      printf("  6) Exportar dados de cadastro \n");
      printf("  7) Importar dados de cadastro \n\n\n");
      printf(" Digite sua opcao: \n");
      scanf("%d%*c",&opcao);
      printf("\n");


      switch(opcao)
      {
        case 1:
             {
               printf(" Cadastrando novo hospede \n\n");
               if(topo < MAX)
               {
                 inserir();
                 printf(" Cadastro Realizado!!\n\n");
               }
               else
               {
                 printf(" Numero maximo de hospedes atigindo!\n\n");
               }
               break;
             }

        case 2:
             {
               if(topo == 0)
               {
                 printf("não há nenhum hospede para ser excluido!\n\n");
               }
               else
               {
                 excluir();
                 printf(" Hospede removido do Cadastro\n\n");
               }
               break;
             }
        case 3:
             {
               if(topo == 0)
               {
                 printf("não há dados no sistema!\n\n");
               }
               else
               {
                 printf(" Listando os Hospedes cadastrados\n\n");
                 listar();
               }
               break;
             }
        case 4:
             {
               if(topo == 0)
               {
                 printf("não há dados no sistema!\n\n");
               }
               else
               {
                 printf(" PESQUIZANDO DADO\n\n");
                 pesquisar();
               }
               break;
             }
        case 5:
             {
               if(topo == 0)
               {
                 printf("não há dados no sistema!\n\n");
               }
               else
               {
                 printf(" ALTERARANDO DADOS!\n\n");
                 alterar();
                 printf(" DADOS ALTERADOS COM SUCESSO!\n\n");
               }
               break;
             }
        case 6:
             {
            arq = fopen("Hospedes.txt", "w"); 
        for(int i=0;i<20;i++){
          if(strcmp((hospedes[i]).nome, "")){
            fprintf(arq, "%d\n", (hospedes[i]).cod);
            fprintf(arq, "%s\n", (hospedes[i]).nome);
            fprintf(arq, "%s\n", (hospedes[i]).cidade);
            fprintf(arq, "%s\n", (hospedes[i]).motivo);
            fprintf(arq, "%d\n", (hospedes[i]).quarto);
            fprintf(arq, "%d\n", (hospedes[i]).idade);
       
        fclose(arq);
        printf( "arquivo Salvo na mesma pasta do programa\n\n\n");
        
               break;
          }
        }
        }
        default:
               printf("\n\n");

      }
      printf(" CONTINUAR?(S/N) ");
      scanf("%s",&seguir);
      printf("\n");
      }

getch();
return 0;

}



void inserir()
{
     hospedes[topo].cod = topo+1;
     printf(" Codigo do Hospede : %d\n",hospedes[topo].cod);

     printf(" nome: ");
     fgets(hospedes[topo].nome,50,stdin);
     hospedes[topo].nome[strlen(hospedes[topo].nome)-1] ;

    

     printf(" Cidade natal: ");
     fgets(hospedes[topo].cidade,50,stdin);
     hospedes[topo].nome[strlen(hospedes[topo].cidade)-1] ;

     printf(" motivo da viagem: ");
     fgets(hospedes[topo].motivo,30,stdin);
     hospedes[topo].motivo[strlen(hospedes[topo].motivo)-1] ;

     printf(" Numero do quarto: ");
     scanf("%d", &hospedes[topo].quarto);

     printf(" Idade: ");
     scanf("%d", &hospedes[topo].idade);



     printf("\n");

     topo = topo + 1;
}



void excluir()
{
     topo  = topo - 1;
}



void listar()
{
     int i;

     for(i = 0;i < topo; i++)
     {
           printf(" ***************************\n\nARQUIVO %d\n\n",(i+1));
           printf(" CODIGO: %d\n",hospedes[i].cod);
           printf(" \n NOME: %s\n",hospedes[i].nome);
           printf(" CIDADE NATAL: %s\n",hospedes[i].cidade);
           printf(" MOTIVO DA VIAGEM : %s\n",hospedes[i].motivo);
           printf(" QUARTO: %d\n\n", hospedes[i].quarto);
           printf(" IDADE: %d\n ***************************\n\n\n",hospedes[i].idade);
           printf("\n\n");
     }
}


void alterar()
{
     int i,dado,cont = 0;

     printf(" ATENCAO! PARA ALTERAR UM REGISTRO \n");
     printf(" EFETUE UMA PESQUISA PELO SEU CODIGO. \n\n");
     printf(" CODIGO DO REGISTRO: ");
     scanf("%d",&dado);
     for(i = 0;i < topo; i++)
     {
       if(dado == hospedes[i].cod)
       {
         cont = cont + 1;

           printf(" NOME: ");
           fgets(hospedes[topo].nome,50,stdin);
           hospedes[topo].nome[strlen(hospedes[topo].nome)-1] ;

    

           printf(" CIDADE NATAL: ");
          scanf("%s", &hospedes[topo].cidade);

          printf(" MOTIVO DA VIAGEM: ");
          fgets(hospedes[topo].motivo,30,stdin);
          hospedes[topo].motivo[strlen(hospedes[topo].motivo)-1] ;

          printf(" NUMERO DO QUARTO: ");
          scanf("%d", &hospedes[topo].quarto);

          printf(" IDADE: ");
          scanf("%d", &hospedes[topo].idade);



       }
     }
     if(cont == 0)
     {
       printf(" HOSPEDE NAO ENCONTRADO!\n\n");
     }
}


void pesquisar()
{
     int i,dado,cont = 0;
     printf(" PESQUISA POR CODIGO: ");
     scanf("%d",&dado);
     for(i = 0;i < topo; i++)
     {
       if(dado == hospedes[i].cod)
       {
          printf("Dado Encontrado \n\n");
          printf(" CODIGO: %d",hospedes[i].cod);
          printf(" NOME: %s",hospedes[i].nome);
         
          printf(" CIDADE: %s",hospedes[i].cidade);
          printf(" MOTIVO: %s",hospedes[i].motivo);
          printf(" QUARTO: %d", hospedes[i].quarto);
          printf(" IDADE: %d",hospedes[i].idade);

          printf("\n");
         cont = cont + 1;
       }
     }
     if(cont == 0)
     {
       printf(" Registro nao Encontrado!\n\n");
     }
}
