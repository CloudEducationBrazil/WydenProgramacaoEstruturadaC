#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
	int opcao, loop=1, cont=0, inserir=1;
	int cod, alterar, excluir;
	char nulo[2]="";

	const int tamvetor=0; // S� N�O ERROS QUANDO ATRIBUO UM DEFINE PARA TAMVETOR!
	int codigo[tamvetor], anofab[tamvetor], anomod[tamvetor];
	char marca[tamvetor][30], modelo[tamvetor][30], tipo[tamvetor][30], cor[tamvetor][30];
	float preco[tamvetor];

//***********************************************
//FUN��ES USADAS PARA AS OP��ES LISTADAS NO MENU!
void menu(){
	printf("\nMENU DE OP��ES:\n");
	printf("0- INSERIR\n 1- CONSULTAR DADOS\n 2- ALTERAR\n 3- EXCLUIR\n 4- RELAT�RIO DOS DADOS\n 5- QUANTIDADE DE REGISTROS\n");
	printf("DIGITE A SUA OP��O: ");
	scanf("%d",&opcao);
}
void inserir_dados(){
				while(loop==1)
				{
					printf("\nINSERIR DADOS\n\n");
					cont += 1;
					//codigo[cont]+=1;
					printf("\nDIGITE O TIPO DO VE�CULO (EX: CARRO, MOTO, CAMINH�O): ");
					scanf("%s", tipo[cont]);
					printf("\nDIGITE A MARCA DO VE�CULO: ");
					scanf("%s", &marca[cont]);
					printf("\nDIGITE O MODELO DO VE�CULO: ");
					scanf("%s", &modelo[cont]);
					printf("\nDIGITE O ANO DE FABRICA��O DO VE�CULO: ");
					scanf("%d", &anofab[cont]);
					printf("\nDIGITE O ANO DO MODELO DO VE�CULO: ");
					scanf("%d", &anomod[cont]);
					printf("\nDIGITE O PRE�O DO VE�CULO: R$");
					scanf("%f", &preco[cont]);
					printf("\nDIGITE A COR DO VE�CULO: R$");
					scanf("%f", &cor[cont]);
					printf("\nDESEJA CONTINUAR? ");
					scanf("%d", &loop);
				}
}
void alterar_dados(){
				printf("\nALTERA��O DE DADOS\n\n");
				printf("\nDIGITE O C�DIGO DO VE�CULO: ");
				scanf("%d", &cod);
				printf("\nDIGITE 0- TIPO DO VE�CULO\n 1- MARCA DO VE�CULO\n 2- MODELO DO VE�CULO\n 3- ANO DE FABRICA��O\n 4- ANO DO MODELO\n 5- PRE�O DO VE�CULO\n 6- COR DO VE�CULO\n");
				printf("\nDIGITE SUA OP��O AQUI: ");
				scanf("%d", &alterar);
					if(alterar == 0)
					{
						printf("\nTIPO DE VE�CULO\n\n");
						printf("DIGITE O TIPO DE VE�CULO: ");
						printf("%s", &tipo[cod]);
					}
					else if(alterar == 1)
					{
						printf("\nMARCA DO VE�CULO\n\n");
						printf("DIGITE A MARCA DO VE�CULO: ");
						printf("%s", &marca[cod]);
					}
					else if(alterar == 2)
					{
						printf("\nMODELO DO VE�CULO\n\n");
						printf("DIGITE O MODELO DO VE�CULO: ");
						printf("%s", &modelo[cod]);
					}
					else if(alterar == 3)
					{
						printf("\nANO DE FABRICA��O DO VE�CULO\n\n");
						printf("DIGITE O ANO DE FABRICA��O DO VE�CULO: ");
						printf("%d", &anofab[cod]);
					}
					else if(alterar == 4)
					{
						printf("\nANO DO MODELO DO VE�CULO\n\n");
						printf("DIGITE O ANO DO MODELO DO VE�CULO: ");
						printf("%d", &anomod[cod]);
					}
					else if(alterar == 5)
					{
						printf("\nPRE�O DO VE�CULO\n\n");
						printf("DIGITE O PRE�O DO VE�CULO: R$");
						printf("%s", &preco[cod]);
					}
					else if(alterar == 6)
					{
						printf("\nPRE�O DO VE�CULO\n\n");
						printf("DIGITE A COR DO VE�CULO: ");
						printf("%s", &cor[cod]);
					}
					else
					{
						printf("\nOP��O INV�LIDA.\n");
						return;
					}
}
void excluir_dados(){
		printf("\nEXCLUS�O DE DADOS\n\n");
					printf("DIGITE O C�DIGO DO VE�CULO: ");
					scanf("%d", cod);
					printf("\nDIGITE 0- TIPO DO VE�CULO\n 1- MARCA DO VE�CULO\n 2- MODELO DO VE�CULO\n 3- ANO DE FABRICA��O\n 4- ANO DO MODELO\n 5- PRE�O DO VE�CULO\n 6- COR DO VE�CULO\n");
					printf("\nDIGITE SUA OP��O AQUI: ");
					scanf("%d", &excluir);
						if(excluir == 0)
						{
							printf("\nTIPO DE VE�CULO\n\n");
							printf("EXCLUINDO O TIPO DE VE�CULO...\n");
							strcpy(tipo[cod], nulo);
						}
						else if(excluir == 1)
						{
							printf("\nMARCA DO VE�CULO\n\n");
							printf("EXCLUINDO A MARCA DO VE�CULO... ");
							strcpy(marca[cod], nulo);
						}
						else if(excluir == 2)
						{
							printf("\nMODELO DO VE�CULO\n\n");
							printf("EXCLUINDO O MODELO DO VE�CULO... ");
							strcpy(modelo[cod], nulo);
						}
						else if(excluir == 3)
						{
							printf("\nANO DE FABRICA��O DO VE�CULO\n\n");
							printf("EXCLUINDO O ANO DE FABRICA��O DO VE�CULO... ");
							anofab[cod]=0;
						}
						else if(excluir == 4)
						{
							printf("\nANO DO MODELO DO VE�CULO\n\n");
							printf("EXCLUINDO O ANO DO MODELO DO VE�CULO... ");
							anomod[cod]=0;
						}
						else if(excluir == 5)
						{
							printf("\nPRE�O DO VE�CULO\n\n");
							printf("EXCLUINDO O PRE�O DO VE�CULO...");
							preco[cod]=0;
						}
						else if(excluir == 6)
						{
							printf("\nMODELO DO VE�CULO\n\n");
							printf("EXCLUINDO A COR DO VE�CULO... ");
							strcpy(cor[cod], nulo);
						}
						else
						{
							printf("\nOP��O INV�LIDA.\n ABRA O PROGRAMA NOVAMENTE.\n");
							return;
						}
}
void relatorio(){
	printf("\nRELAT�RIO DE DADOS\n\n");
	printf("\n*********************************************\n");
	for(int x=0; x<tamvetor; x++){
		printf("C�DIGO DO VE�CULO: ", codigo[x]);
		printf("\nTIPO DO VE�CULO: ", tipo[x]);
		printf("\nMARCA DO VE�CULO: ", marca[x]);
		printf("\nMODELO DO VE�CULO: ", modelo[x]);
		printf("\nANO DE FABRICA��O DO VE�CULO: ", anofab[x]);
		printf("\nANO DO MODELO DO VE�CULO: ", anomod[x]);
		printf("\nPRE�O DO VE�CULO: ", preco[x]);
		printf("\nCOR DO VE�CULO: ", cor[x]);
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
				case 4: //RELAT�RIO DE DADOS
					void relatorio();
				case 5: //QUANTIDADE DE REGISTROS
					{printf("\nQUANTIDADE DE REGISTROS FEITOS: ", cont);
					printf("\n");}
			}
}
