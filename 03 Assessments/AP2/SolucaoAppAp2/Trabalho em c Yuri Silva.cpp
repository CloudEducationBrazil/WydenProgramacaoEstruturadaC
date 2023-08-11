#include <stdio.h>
#include <stdlib.h>

int main(){

int opcao,opcao1,opcao2,opcao3,opcao4,i,quant;

struct referencia{

char nome0[100],nome1[100],nome2[100],nome3[100],nome4[100];
}

CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
}
char nome5[100];

system("cls");
printf ("Nome do Vendedor:\n");
fflush (stdin);
scanf("%[^\n]s",&nome5);
printf("Senha de acesso a Loja YuriPhone:");
scanf("%d",&opcao3);

                    switch(opcao3){
                       case 132231:

                          while (opcao!=6){
                   while(opcao2!=1){
                   	    system("Color F4");
                        system("cls");

                             printf("........................................................"); 
                             printf("\t\t\t\tLoja YuriPhone\n");
                             printf("........................................................\n\n");
                             printf("\t\t\t\tSeja Bem vindo, Vendedor %s|n",nome5);
                             printf("________\n");
                             printf("1- Cadastrar\n");
                             printf("2- Exibir Cadastro\n");
                             printf("3- Alterar Cadastro\n");
                             printf("4- Excluir Cadastro\n");
                             printf("5- Inforamacoes do Sistema\n");
                             printf("6- Sair\n");
                             printf("-------------------------------------------------------------\n");
                             printf("\nEscolha uma opcao:");
                             scanf("%d",&opcao);
                        
                                    

switch(opcao){
      case 1:
             system("cls");
             printf("\n\n Quantos Cadastros deseja realizar?:"); 
             scanf("%d",&quant);

for(i=1;1<=quant;i++){
system("cls");
printf("\n\n\t\t\t     INICIANDO CADASTRO %d\n",i);
printf("\t\t\t ------------------\n\n");
printf("\n Nome do Cliente: ");
fflush(stdin);
scanf("%[^\n]s", CA[i].nome0);
printf("\n Insira o telefone do cliente: ");
fflush(stdin);
scanf("%[^\n]s",CA[i].nome1);
printf("\n Marca do Produto: ");
fflush(stdin);
scanf("%[^\n]s",CA[i].nome2);
printf("\n Codigo do Produto: ");
fflush(stdin);
scanf("%[^\n]a",CA[i].nome3);
printf("\n Preco do Produto: ");
fflush(stdin);
scanf("%[^\n]s",CA[i].nome4);
printf("\n\n\t\t");
system("pause");
system("cls");
}
break;

case 2:
system("cls");

for(i=1;i<=quant;i++){
system("cls");
printf("\n\n\t\t\t   EXIBIR CADASTRO %d\n", i);
printf("\t\t\t  ----------------------\n\n");
printf(" Nome do Cliente: %s\n",CA[i].nome0);
printf("\n Insira o telefone do Cliente: %s\n", CA [1].nome1);
printf("\n Marca do Produto: %s\n",CA[i].nome2);
printf("\n Codigo do Produto: %s\n",CA[i].nome3);
printf("\n Preco do Produto: %s\n",CA[i].nome4);
system("pause");
}
break;

case 3:
system ("cls");
for(i=1;i<=quant;i++);
printf("\n\n\t\t\t  ALTERAR CADASTRO");
printf("\t\t\t  ----------------------\n\n");
                             printf("1- Nome do Cliente");
                             printf("2- Insira o telefone do Cliente\n");
                             printf("3- Marca do Produto\n");
                             printf("4- Codigo do Porduto\n");
                             printf("5- Preco do Produto\n");
                             printf("\nEscolha uma opcao:");
                             scanf("%",&opcao1);
switch(opcao1){

case 1:
for(i=1;i<=quant;i++){
system("cls");
printf("\n\n  CADASTRO %d\n",i);
printf("\n Alterar Nome do Comprador: ");
fflush(stdin);
scanf("%[^\n]s", &CA[i].nome0);
printf("\n Insira o Novo Nome do Cliente: %s\n\n\t\t");
system("pause");
}
break;

case 2:
for(i=1;i<=quant;i++){
system("cls");
printf("\n\n CADASTRO %d\n",i);
printf("\n Alterar telefone do Cliente: ");
fflush(stdin);
scanf("%[^\n]s",&CA[i].nome1);
printf("\n Insira o Novo telefone do cliente:%s\n\n\t\t");
system("pause");
}
break;

case 3:
for(i=1;i<=quant;i++){
system("cls");
printf("\n\n CADASTRO %d\n",i);
printf("\n Alterar a Marca do Porduto: ");
fflush(stdin);
scanf("%[^\n]s",&CA[i].nome2);
printf("\n Insira a Nova Marca do Porduto: %s\n\n\t\t");
system("pause");
}
break;

case 4:
for(i=1;i<=quant;i++){
system("cls");
printf("\n\n CADASTRO %d\n",i);
printf("\n Alterar o Codigo do Produto: ");
fflush(stdin);
scanf("%[^\n]s",&CA[i].nome3);
printf("\n Insira o Novo Codigo do Produto: %s\n\n\t\t");
system("pause");
}
break;

case 5:
for(i=1;i<=quant;i++){
system("cls");
printf("\n\n CADASTRO %d\n",i);
printf("\n Alterar o Preco do Produto: ");
fflush(stdin);
scanf("%[^\n]s",&CA[i].nome4);
printf("\n Insira o Novo Preco do Porduto: %s\n\n\t\t");
system("pause");
}
break;
}
}
break;

case 4:
for(i=1;i<=quant;i++){
printf("\n\n\t\t\t  EXCLUIR CADASTRO");
printf("\t\t\t  ----------------------\n\n");
                             printf("1- Nome do Cliente");
                             printf("2- Insira o telefone do Cliente\n");
                             printf("3- Marca do Produto\n");
                             printf("4- Codigo do Porduto\n");
                             printf("5- Preco do Produto\n");
                             printf("6- Excluir Todos os Dados\n");
                             printf("\nEscolha uma opcao:");
                             scanf("%",&opcao4);
switch(opcao4){
case 1:
for(i=1;i<=quant;i++){
system("cls");
memset(&CA[i].nome0,0,sizeof(CA[i].nome0));
printf("Nome do Cliente Excluido! \n\n");
system("pause");
}
break;
} 

case 2:
for(i=1;i<=quant;i++){
system("cls");
memset(&CA[i],nome1,0,sizeof(CA[i].nome1));
printf("Telefone do Cliente excluido!\n\n");
system("pause");
}
break;

case 3:
for(i=1;i<=quant;i++){
system("cls");
memset(&CA[i],nome2,0,sizeof(CA[i].nome2));
printf("Marca do Produto excluido!\n\n");
system("pause");
}
break;

case 4:
for(i=1;i<=quant;i++){
system("cls");
memset(&CA[i],nome3,0,sizeof(CA[i].nome3));
printf("Codigo do Produto excluido!\n\n");
system("pause");
}
break;

case 5:
for(i=1;i<=quant;i++){
system("cls");
memset(&CA[i],nome4,0,sizeof(CA[i].nome4));
printf("Preco do Produto excluido!\n\n");
system("pause");
}
break;

case 6:
for(i=1;i<=quant;i++){
system("cls");
memset (&CA[i].nome0,0,sizeof(CA [i].nome0));
memset (&CA[i].nome1,0,sizeof(CA [i].nome1));
memset (&CA[i].nome2,0,sizeof(CA [i].nome2));
memset (&CA[i].nome3,0,sizeof(CA [i].nome3));
memset (&CA[i].nome4,0,sizeof(CA [i].nome4));
printf("Todos os Dados Foram Excluidos!\n\n");
system("pause");
}
break;
}
}
break;

case 5:
system("cls");
printf("Nome do Aluno Programador:\n\n");
printf("Yuri Silva Oliveira\n");
system("pause");
break;

case 6:
system("cls");
printf("\n Deseja Realmente sair do Sistema da Loja YuriPhone?\n\n");
printf("1- Sim\n 2- Nao");
printf("\n\n");
scanf("%d",&opcao2);

switch(opcao2){
case 1:
system("cls");
printf("\n\n Volte Sempre a Loja YuriPhone!\n\n\n\t\t");
system("pause");
return 0;
break;
}
}
