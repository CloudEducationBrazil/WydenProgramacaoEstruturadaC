#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
	int opcao, loop=1, cont=0, inserir=1;
	int cod, alterar, excluir;
	char nulo[2]="";

	const int tamvetor=0; // SÓ NÃO ERROS QUANDO ATRIBUO UM DEFINE PARA TAMVETOR!
	int codigo[tamvetor], anofab[tamvetor], anomod[tamvetor];
	char marca[tamvetor][30], modelo[tamvetor][30], tipo[tamvetor][30], cor[tamvetor][30];
	float preco[tamvetor];

//***********************************************
//FUNÇÕES USADAS PARA AS OPÇÕES LISTADAS NO MENU!
void menu(){
	printf("\nMENU DE OPÇÕES:\n");
	printf("0- INSERIR\n 1- CONSULTAR DADOS\n 2- ALTERAR\n 3- EXCLUIR\n 4- RELATÓRIO DOS DADOS\n 5- QUANTIDADE DE REGISTROS\n");
	printf("DIGITE A SUA OPÇÃO: ");
	scanf("%d",&opcao);
}
void inserir_dados(){
				while(loop==1)
				{
					printf("\nINSERIR DADOS\n\n");
					cont += 1;
					//codigo[cont]+=1;
					printf("\nDIGITE O TIPO DO VEÍCULO (EX: CARRO, MOTO, CAMINHÃO): ");
					scanf("%s", tipo[cont]);
					printf("\nDIGITE A MARCA DO VEÍCULO: ");
					scanf("%s", &marca[cont]);
					printf("\nDIGITE O MODELO DO VEÍCULO: ");
					scanf("%s", &modelo[cont]);
					printf("\nDIGITE O ANO DE FABRICAÇÃO DO VEÍCULO: ");
					scanf("%d", &anofab[cont]);
					printf("\nDIGITE O ANO DO MODELO DO VEÍCULO: ");
					scanf("%d", &anomod[cont]);
					printf("\nDIGITE O PREÇO DO VEÍCULO: R$");
					scanf("%f", &preco[cont]);
					printf("\nDIGITE A COR DO VEÍCULO: R$");
					scanf("%f", &cor[cont]);
					printf("\nDESEJA CONTINUAR? ");
					scanf("%d", &loop);
				}
}
void alterar_dados(){
				printf("\nALTERAÇÃO DE DADOS\n\n");
				printf("\nDIGITE O CÓDIGO DO VEÍCULO: ");
				scanf("%d", &cod);
				printf("\nDIGITE 0- TIPO DO VEÍCULO\n 1- MARCA DO VEÍCULO\n 2- MODELO DO VEÍCULO\n 3- ANO DE FABRICAÇÃO\n 4- ANO DO MODELO\n 5- PREÇO DO VEÍCULO\n 6- COR DO VEÍCULO\n");
				printf("\nDIGITE SUA OPÇÃO AQUI: ");
				scanf("%d", &alterar);
					if(alterar == 0)
					{
						printf("\nTIPO DE VEÍCULO\n\n");
						printf("DIGITE O TIPO DE VEÍCULO: ");
						printf("%s", &tipo[cod]);
					}
					else if(alterar == 1)
					{
						printf("\nMARCA DO VEÍCULO\n\n");
						printf("DIGITE A MARCA DO VEÍCULO: ");
						printf("%s", &marca[cod]);
					}
					else if(alterar == 2)
					{
						printf("\nMODELO DO VEÍCULO\n\n");
						printf("DIGITE O MODELO DO VEÍCULO: ");
						printf("%s", &modelo[cod]);
					}
					else if(alterar == 3)
					{
						printf("\nANO DE FABRICAÇÃO DO VEÍCULO\n\n");
						printf("DIGITE O ANO DE FABRICAÇÃO DO VEÍCULO: ");
						printf("%d", &anofab[cod]);
					}
					else if(alterar == 4)
					{
						printf("\nANO DO MODELO DO VEÍCULO\n\n");
						printf("DIGITE O ANO DO MODELO DO VEÍCULO: ");
						printf("%d", &anomod[cod]);
					}
					else if(alterar == 5)
					{
						printf("\nPREÇO DO VEÍCULO\n\n");
						printf("DIGITE O PREÇO DO VEÍCULO: R$");
						printf("%s", &preco[cod]);
					}
					else if(alterar == 6)
					{
						printf("\nPREÇO DO VEÍCULO\n\n");
						printf("DIGITE A COR DO VEÍCULO: ");
						printf("%s", &cor[cod]);
					}
					else
					{
						printf("\nOPÇÃO INVÁLIDA.\n");
						return;
					}
}
void excluir_dados(){
		printf("\nEXCLUSÃO DE DADOS\n\n");
					printf("DIGITE O CÓDIGO DO VEÍCULO: ");
					scanf("%d", cod);
					printf("\nDIGITE 0- TIPO DO VEÍCULO\n 1- MARCA DO VEÍCULO\n 2- MODELO DO VEÍCULO\n 3- ANO DE FABRICAÇÃO\n 4- ANO DO MODELO\n 5- PREÇO DO VEÍCULO\n 6- COR DO VEÍCULO\n");
					printf("\nDIGITE SUA OPÇÃO AQUI: ");
					scanf("%d", &excluir);
						if(excluir == 0)
						{
							printf("\nTIPO DE VEÍCULO\n\n");
							printf("EXCLUINDO O TIPO DE VEÍCULO...\n");
							strcpy(tipo[cod], nulo);
						}
						else if(excluir == 1)
						{
							printf("\nMARCA DO VEÍCULO\n\n");
							printf("EXCLUINDO A MARCA DO VEÍCULO... ");
							strcpy(marca[cod], nulo);
						}
						else if(excluir == 2)
						{
							printf("\nMODELO DO VEÍCULO\n\n");
							printf("EXCLUINDO O MODELO DO VEÍCULO... ");
							strcpy(modelo[cod], nulo);
						}
						else if(excluir == 3)
						{
							printf("\nANO DE FABRICAÇÃO DO VEÍCULO\n\n");
							printf("EXCLUINDO O ANO DE FABRICAÇÃO DO VEÍCULO... ");
							anofab[cod]=0;
						}
						else if(excluir == 4)
						{
							printf("\nANO DO MODELO DO VEÍCULO\n\n");
							printf("EXCLUINDO O ANO DO MODELO DO VEÍCULO... ");
							anomod[cod]=0;
						}
						else if(excluir == 5)
						{
							printf("\nPREÇO DO VEÍCULO\n\n");
							printf("EXCLUINDO O PREÇO DO VEÍCULO...");
							preco[cod]=0;
						}
						else if(excluir == 6)
						{
							printf("\nMODELO DO VEÍCULO\n\n");
							printf("EXCLUINDO A COR DO VEÍCULO... ");
							strcpy(cor[cod], nulo);
						}
						else
						{
							printf("\nOPÇÃO INVÁLIDA.\n ABRA O PROGRAMA NOVAMENTE.\n");
							return;
						}
}
void relatorio(){
	printf("\nRELATÓRIO DE DADOS\n\n");
	printf("\n*********************************************\n");
	for(int x=0; x<tamvetor; x++){
		printf("CÓDIGO DO VEÍCULO: ", codigo[x]);
		printf("\nTIPO DO VEÍCULO: ", tipo[x]);
		printf("\nMARCA DO VEÍCULO: ", marca[x]);
		printf("\nMODELO DO VEÍCULO: ", modelo[x]);
		printf("\nANO DE FABRICAÇÃO DO VEÍCULO: ", anofab[x]);
		printf("\nANO DO MODELO DO VEÍCULO: ", anomod[x]);
		printf("\nPREÇO DO VEÍCULO: ", preco[x]);
		printf("\nCOR DO VEÍCULO: ", cor[x]);
		printf("\n*********************************************\n");
	}
}
//***********************************************
int main (void){

		void menu();
			switch(opcao){
				case 0: //INSERIR DADOS
					void inserir_dados();
				case 1: //CONSULTAR DADOS

				case 2: //ALTERAR DADOS
					void alterar();
				case 3: //EXCLUIR DADOS
					void excluir();
				case 4: //RELATÓRIO DE DADOS
					void relatorio();
				case 5: //QUANTIDADE DE REGISTROS
					{printf("\nQUANTIDADE DE REGISTROS FEITOS: ", cont);
					printf("\n");}
			}
}
