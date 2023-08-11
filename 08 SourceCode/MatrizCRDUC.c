#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamDisciplina 2
#define tamNotas 3
#define tamAlunos 2 // 0 - Carina; 1- Josy; 2 - Julia

#define true 1
#define false 0

int main(void){
  //setlocale(LC_ALL, ""); // Windows = Portuguese; Linux = pt_BR_utf8
  setlocale(LC_ALL, "");

  int opc, elemento, elementoEncontrado, indiceD, indiceN, indiceA;
  int lixo, ordem, trocar;
  int a[tamDisciplina][tamNotas][tamAlunos], VetorAux[tamNotas*tamAlunos];

  printf(" ***** Menu Manutenção Matriz ***** \n");
  printf("\n");
  printf("0 - Exibir Elementos (Crescente ou Decrescente) \n");
  printf("1 - Incluir Elemento \n"); // Não permitir repetido
  printf("2 - Alterar Elemento \n");
  printf("3 - Consultar Elemento \n");
  printf("4 - Excluir Elemento\n");
  printf("5 - Exportar Vetor\n");
  printf("6 - Carregar Vetor\n");
  printf("7 - Sair\n");
  printf("Digite Opcao Desejada [0 a 7]:?\n");
  scanf("%i", &opc);

  while ( opc != 7 )
  {   switch ( opc ){
       // Exibir
        case 0 : { printf("Ordem Crescente 0 / Decrescente 1 [0 ou 1]:?\n");
                    scanf("%i", &ordem);

                    if ( ordem == 0 ) // Crescente
                       for (int x=0; x<tamDisciplina; x++){
                         printf("\n");
                         for (int y=0; y<tamNotas; y++)
                            for (int z=0; z<tamAlunos; z++)
                                { printf("Elemento[%d][%d][%d] = %d \n", x, y, z, a[x][y][z]); }
                         }
                    else
                       for (int x=tamDisciplina-1; x>=0; x--){
                          printf("\n");
                          for (int y=tamNotas-1; y>=0; y--)
                            for (int z=tamAlunos-1; z>=0; z--)
                                { printf("Elemento[%d][%d][%d] = %d \n", x, y, z, a[x][y][z]); }
                       }

                    printf("\n Fim de Exibição!!! \n");
                    setbuf(stdin, NULL);
                    getchar();

                    system("clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Exportar Vetor\n");
                    printf("6 - Carregar Vetor\n");
                    printf("7 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 7]:?\n");
                    scanf("%i", &opc);
                    break;
        }
       // Incluir
        case 1 : { for (int x=0; x<tamDisciplina; x++)
                     for (int y=0; y<tamNotas; y++)
                        for (int z=0; z<tamAlunos; z++)
                            { printf("Digite Elemento [%d][%d][%d]", x, y, z); scanf("%d", &a[x][y][z]);
                            }

                     printf("Elementos cadastrados com sucesso!!!\n");
                     setbuf(stdin, NULL);
                     getchar();

                    system("clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Exportar Vetor\n");
                    printf("6 - Carregar Vetor\n");
                    printf("7 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 7]:?\n");
                    scanf("%i", &opc);
                    break;
        }
       // Alterar
        case 2 : { printf("Digite Elemento Desejado:?"); scanf("%d", &elemento);
                   elementoEncontrado = 0;
                   for (int x=0; x<tamDisciplina; x++)
                      for (int y=0; y<tamNotas; y++)
                        for (int z=0; z<tamAlunos; z++)
                            {   if ( a[x][y][z] == elemento ){
                                    elementoEncontrado = 1;
                                    indiceD = x;
                                    indiceN = y;
                                    indiceA = z;
                                }
                            }
                   if ( elementoEncontrado == true )
                   {  printf("Elemento = %d foi Encontrado na posição [%d][%d][%d]", elemento, indiceD, indiceN, indiceA);

                      printf("\n Digite Novo Elemento:?"); scanf("%d", &elemento);
                      a[indiceD][indiceN][indiceA] = elemento;

                      printf("Elemento alterado com sucesso!!!");
                      setbuf(stdin, NULL);
                      getchar();

                   }
                   else {
                          printf("\nElemento não encontrado\n");
                          setbuf(stdin, NULL);
                          getchar();
                        }

                    system("clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Exportar Vetor\n");
                    printf("6 - Carregar Vetor\n");
                    printf("7 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 7]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Consultar
          case 3 : {
                   printf("Digite Elemento Desejado para Consulta:?"); scanf("%d", &elemento);
                   elementoEncontrado = 0;
                   for (int x=0; x<tamDisciplina; x++)
                      for (int y=0; y<tamNotas; y++)
                        for (int z=0; z<tamAlunos; z++)
                        { if ( a[x][y][z] == elemento ){
                            elementoEncontrado = 1;
                            indiceD = x;
                            indiceN = y;
                            indiceA = z;
                            }
                        }
                   if ( elementoEncontrado == true )
                      printf("Elemento = %d foi Encontrado na posição [%d][%d][%d]", elemento, indiceD, indiceN, indiceA);
                   else
                      printf("Elemento não encontrado");

                   setbuf(stdin, NULL);
                   getchar();

                    system("clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Exportar Vetor\n");
                    printf("6 - Carregar Vetor\n");
                    printf("7 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 7]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Excluir
        case 4 : {
            printf("Digite Elemento Desejado:?"); scanf("%d", &elemento);
                   elementoEncontrado = 0;
                   for (int x=0; x<tamDisciplina; x++)
                     for (int y=0; y<tamNotas; y++)
                        for (int z=0; z<tamAlunos; z++)
                        {
                            if ( a[x][y][z] == elemento ){
                                elementoEncontrado = 1;
                                indiceD = x;
                                indiceN = y;
                                indiceA = z;
                            }
                        }
                       if ( elementoEncontrado == true )
                       {  a[indiceD][indiceN][indiceA] = lixo;
                          printf("Excluido com sucesso!!!\n");
                          setbuf(stdin, NULL);
                          getchar();
                       }
                       else{  printf("Elemento não encontrado!!!\n");
                              setbuf(stdin, NULL);
                              getchar();
                           }

                    system("clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Exportar Vetor\n");
                    printf("6 - Carregar Vetor\n");
                    printf("7 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 7]:?\n");
                    scanf("%i", &opc);
                    break;
        }
        // Exportar Matriz
        case 5 : {
                   printf("Matriz - Dados Exportados com sucesso!!!\n");
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
        // Importar Matriz
        case 6 : {
                   printf("Matriz - Dados Importados com sucesso!!!\n");
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

                    system("clear");
                    printf(" ***** Menu Manutenção Vetor ***** \n");
                    printf("\n");
                    printf("0 - Exibir Elementos (Crescente ou Decrescente) \n");
                    printf("1 - Incluir Elemento \n"); // Não permitir repetido
                    printf("2 - Alterar Elemento \n");
                    printf("3 - Consultar Elemento \n");
                    printf("4 - Excluir Elemento\n");
                    printf("5 - Exportar Vetor\n");
                    printf("6 - Carregar Vetor\n");
                    printf("7 - Sair\n");
                    printf("Digite Opcao Desejada [0 a 7]:?\n");
                    scanf("%i", &opc);
                    break;
                  };
    } // Switch
  } // while
} // Main
