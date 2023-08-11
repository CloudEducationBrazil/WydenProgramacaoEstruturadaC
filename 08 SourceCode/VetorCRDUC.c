#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamVetor 3
#define true 1
#define false 0

int main(void){
  //setlocale(LC_ALL, ""); // Exemplo: Portuguese; Linux = pt_BR_utf8
  setlocale(LC_ALL, "");

  int opc, elemento, elementoEncontrado, indice;
  int lixo, ordem, trocar;
  int a[tamVetor];

  printf(" ***** Menu Manutenção Vetor [%d] ***** \n", tamVetor);
  printf("\n");
  printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
  printf("1 - Incluir Elemento \n"); // Não permitir repetido
  printf("2 - Alterar Elemento \n");
  printf("3 - Consultar Elemento \n");
  printf("4 - Excluir Elemento\n");
  printf("5 - Ordenar Vetor Crescente\n");
  printf("6 - Ordenar Vetor Decrescente\n");
  printf("7 - Exportar Vetor\n");
  printf("8 - Carregar Vetor\n");
  printf("9 - Sair\n");
  printf("Digite Opcao Desejada [0 a 9]:?\n");
  scanf("%i", &opc);

  while ( opc != 9 )
  {   switch ( opc ){
       // Exibir
        case 0 : { printf("\n");
                   printf("Ordem Crescente 0 / Decrescente 1 pelo Indice? [0 ou 1]:?\n");
                   scanf("%i", &ordem);

                    if ( ordem == 0 ) // Crescente pelo Índice
                       for (int x=0; x<tamVetor; x++)
                          { printf("Elemento[%d] = %d \n", x, a[x]); }
                    else // Decrescente pelo Índice
                       for (int x=tamVetor-1; x>=0; x--)
                          { printf("Elemento[%d] = %d \n", x, a[x]); }

                    printf("\n Fim de Exibição!!! \n");
                    setbuf(stdin, NULL);
                    getchar();

                    system("cls || clear"); // cls - WIndows; clear - Linux
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }
       // Incluir
        case 1 : { for (int x=0; x<tamVetor; x++)
                   { printf("Digite Elemento [%d]", x); scanf("%d", &a[x]);
                   }

                     printf("Elementos cadastrados com sucesso!!!\n");
                     setbuf(stdin, NULL);
                     getchar();

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }
       // Alterar
        case 2 : { printf("Digite Elemento Desejado:?"); scanf("%d", &elemento);
                   elementoEncontrado = 0;
                   for (int x=0; x<tamVetor; x++)
                   {   if ( a[x] == elemento ){
                        elementoEncontrado = 1;
                        indice = x;
                       }
                   }
                   if ( elementoEncontrado == true )
                   {  printf("Elemento = %d foi Encontrado na posição [%d]", elemento, indice);

                      printf("\n Digite Novo Elemento:?"); scanf("%d", &elemento);
                      a[indice] = elemento;

                      printf("Elemento alterado com sucesso!!!");
                      setbuf(stdin, NULL);
                      getchar();

                   }
                   else {
                          printf("\nElemento não encontrado\n");
                          setbuf(stdin, NULL);
                          getchar();
                        }

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Consultar
          case 3 : {
                   printf("Digite Elemento Desejado para Consulta:?"); scanf("%d", &elemento);
                   elementoEncontrado = 0;
                   for (int x=0; x<tamVetor; x++)
                   { if ( a[x] == elemento ){
                        elementoEncontrado = 1;
                        indice = x;
                     }
                   }
                   if ( elementoEncontrado == true )
                      printf("Elemento = %d foi Encontrado na posição [%d]", elemento, indice);
                   else
                      printf("Elemento não encontrado");

                   setbuf(stdin, NULL);
                   getchar();

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Excluir
        case 4 : {
            printf("Digite Elemento Desejado:?"); scanf("%d", &elemento);
                   elementoEncontrado = 0;
                   for (int x=0; x<tamVetor; x++)
                   {
                       if ( a[x] == elemento ){
                        elementoEncontrado = 1;
                        indice = x;
                       }
                   }
                       if ( elementoEncontrado == true )
                       {  a[indice] = lixo;
                          printf("Excluido com sucesso!!!\n");
                          setbuf(stdin, NULL);
                          getchar();
                       }
                       else{  printf("Elemento não encontrado!!!\n");
                              setbuf(stdin, NULL);
                              getchar();
                           }

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }

        // Ordenar Crescente
        case 5 : {
                   for (int x=0; x<tamVetor; x++)
                   { for (int y=x+1; y<tamVetor; y++)
                        { elemento = a[x];
                          if ( elemento > a[y] ){
                            trocar = a[y];
                            a[y] = elemento;
                            a[x] = trocar;
                           }
                        }
                   }
                   printf("Crescente - Dados ordenados com sucesso!!!\n");
                   setbuf(stdin, NULL);
                   getchar();

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }

        // Ordenar Decrescente
        case 6 : {
                   for (int x=0; x<tamVetor; x++)
                   { for (int y=x+1; y<tamVetor; y++)
                        { elemento = a[x];
                          if ( elemento < a[y] ){
                            trocar = a[y];
                            a[y] = elemento;
                            a[x] = trocar;
                           }
                        }
                   }
                   printf("Decrescente - Dados ordenados com sucesso!!!\n");
                   setbuf(stdin, NULL);
                   getchar();

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Exportar Vetor
        case 7 : {
                   printf("Vetor - Dados Exportados com sucesso!!!\n");
                   setbuf(stdin, NULL);
                   getchar();

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Importar Vetor
        case 8 : {
                   printf("Vetor - Dados Importados com sucesso!!!\n");
                   setbuf(stdin, NULL);
                   getchar();

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Invalida
        default : {
                    printf("Opção invalida\n");
                    setbuf(stdin, NULL);
                    getchar();

                    system("cls || clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos pelo Índice (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Ordenar Vetor Crescente\n");
                    printf("6 - Ordenar Vetor Decrescente\n");
                    printf("7 - Exportar Vetor\n");
                    printf("8 - Carregar Vetor\n");
                    printf("9 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 9]:?\n");
                    scanf("%i", &opc);
                    break;
                  };
    } // Switch
  } // while
} // Main
