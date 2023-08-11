#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define tamvetor 1000
    int opcao, loop=1, cont=-1, inserir=1;
	int cod, alterar, excluir;
	char nulo[2]="";
	int codigo[tamvetor], anofab[tamvetor], anomod[tamvetor], consulte;
	char marca[tamvetor][30], modelo[tamvetor][30], tipo[tamvetor][30], cor[tamvetor][30];
	float preco[tamvetor];


//***********************************************
//FUN��ES USADAS PARA AS OP��ES LISTADAS NO MENU!
void menu(){
	printf("\nMENU DE OP��ES:\n\n");
	printf(" 0- INSERIR DADOS\n 1- CONSULTAR DADOS\n 2- ALTERAR DADOS\n 3- EXCLUIR DADOS\n 4- RELAT�RIO DOS DADOS\n 5- QUANTIDADE DE REGISTROS\n 6- GRAVAR DADOS EM .TXT\n 7- IMPRIMIR DADOS .TXT\n 9- SAIR\n\n");
	printf("DIGITE A SUA OP��O: ");
	scanf("%d", &opcao);
    }
void inserir_dados(){
    system("cls");
    if(cont==tamvetor-1){
        printf("LIMITE M�XIMO ATINGIDO!.\n");
    }
    else{
    cont ++;
    printf("****************\n");
    printf(" INSERIR DADOS\n");
    printf("****************\n\n");
    printf("-> TODOS OS VE�CULOS RECEBER�O COMO C�DIGO A ORDEM EM QUE SER� REGISTRADO, PORTANTO, O C�DIGO DESTE VE�CULO SER� %d <-\n\n", cont);
    codigo[cont]= cont; // ??? Gerador de C�digo, rever l�gica
    printf("\nDIGITE O TIPO DO VE�CULO (EX: CARRO, MOTO, CAMINH�O): ");
    scanf("%s", tipo[cont]);
	printf("\nDIGITE A MARCA DO VE�CULO: ");
	scanf("%s", marca[cont]);
	printf("\nDIGITE O MODELO DO VE�CULO: ");
	scanf("%s", modelo[cont]);
	printf("\nDIGITE O ANO DE FABRICA��O DO VE�CULO: ");
	scanf("%d", &anofab[cont]);
	printf("\nDIGITE O ANO DO MODELO DO VE�CULO: ");
	scanf("%d", &anomod[cont]);
	printf("\nDIGITE O PRE�O DO VE�CULO: R$");
	scanf("%f", &preco[cont]);
	printf("\nDIGITE A COR DO VE�CULO: ");
	scanf("%s", cor[cont]);
	system("cls");
	printf("DADOS INSERIDOS COM SUCESSO.\n");
    }
}
void alterar_dados(){
    if(cont == -1){
        system("cls");
        printf("N�O EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VE�CULO E TENTE NOVAMENTE.\n");
    }
    else{
                system("cls");
                printf("********************\n");
                printf(" ALTERA��O DE DADOS\n");
                printf("********************\n\n");
				printf("\nDIGITE O C�DIGO DO VE�CULO: ");
				scanf("%d", &cod);
				printf("\nDIGITE 0- TIPO DO VE�CULO\n 1- MARCA DO VE�CULO\n 2- MODELO DO VE�CULO\n 3- ANO DE FABRICA��O\n 4- ANO DO MODELO\n 5- PRE�O DO VE�CULO\n 6- COR DO VE�CULO\n");
				printf("\nDIGITE SUA OP��O AQUI: ");
				scanf("%d", &alterar);
					if(alterar == 0)
					{
						printf("\nTIPO DE VE�CULO\n\n");
						printf("DIGITE O TIPO DE VE�CULO: ");
						scanf("%s", tipo[cod]);
					system ("cls");
                    printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 1)
					{
						printf("\nMARCA DO VE�CULO\n\n");
						printf("DIGITE A MARCA DO VE�CULO: ");
						scanf("%s", marca[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 2)
					{
						printf("\nMODELO DO VE�CULO\n\n");
						printf("DIGITE O MODELO DO VE�CULO: ");
						scanf("%s", modelo[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 3)
					{
						printf("\nANO DE FABRICA��O DO VE�CULO\n\n");
						printf("DIGITE O ANO DE FABRICA��O DO VE�CULO: ");
						scanf("%d", &anofab[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 4)
					{
						printf("\nANO DO MODELO DO VE�CULO\n\n");
						printf("DIGITE O ANO DO MODELO DO VE�CULO: ");
						scanf("%d", &anomod[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 5)
					{
						printf("\nPRE�O DO VE�CULO\n\n");
						printf("DIGITE O PRE�O DO VE�CULO: R$");
						scanf("%f", &preco[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 6)
					{
						printf("\nCOR DO VE�CULO\n\n");
						printf("DIGITE A COR DO VE�CULO: ");
						scanf("%s", cor[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else
					{
						printf("\nOP��O INV�LIDA.\n");
					}

    }
}
void excluir_dados(){
    if(cont == -1){
            system("cls");
        printf("N�O EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VE�CULO E TENTE NOVAMENTE.\n");
    }
    else{
                    system("cls");
                    printf("*******************\n");
					printf(" EXCLUS�O DE DADOS\n");
					printf("*******************\n\n");
					printf("DIGITE O C�DIGO DE CADASTRO DO VE�CULO: ");
					scanf("%d", &cod);
					printf("\nDIGITE 0- TIPO DO VE�CULO\n 1- MARCA DO VE�CULO\n 2- MODELO DO VE�CULO\n 3- ANO DE FABRICA��O\n 4- ANO DO MODELO\n 5- PRE�O DO VE�CULO\n 6- COR DO VE�CULO\n");
					printf("\nDIGITE SUA OP��O AQUI: ");
					scanf("%d", &excluir);
						if(excluir == 0)
						{
							printf("\nTIPO DE VE�CULO\n\n");
							printf("EXCLUINDO O TIPO DE VE�CULO...\n");
							strcpy(tipo[cod], nulo);
                            printf("\nDADO EXCLU�DO COM SUCESSO.\n");
						}
						else if(excluir == 1)
						{
							printf("\nMARCA DO VE�CULO\n\n");
							printf("EXCLUINDO A MARCA DO VE�CULO... ");
							strcpy(marca[cod], nulo);
                            printf("\nDADO EXCLU�DO COM SUCESSO.\n");
						}
						else if(excluir == 2)
						{
							printf("\nMODELO DO VE�CULO\n\n");
							printf("EXCLUINDO O MODELO DO VE�CULO... ");
							strcpy(modelo[cod], nulo);
                            printf("\nDADO EXCLU�DO COM SUCESSO.\n");
						}
						else if(excluir == 3)
						{
							printf("\nANO DE FABRICA��O DO VE�CULO\n\n");
							printf("EXCLUINDO O ANO DE FABRICA��O DO VE�CULO... ");
							anofab[cod]=0;
                            printf("\nDADO EXCLU�DO COM SUCESSO.\n");
						}
						else if(excluir == 4)
						{
							printf("\nANO DO MODELO DO VE�CULO\n\n");
							printf("EXCLUINDO O ANO DO MODELO DO VE�CULO... ");
							anomod[cod]=0;
                            printf("\nDADO EXCLU�DO COM SUCESSO.\n");
						}
						else if(excluir == 5)
						{
							printf("\nPRE�O DO VE�CULO\n\n");
							printf("EXCLUINDO O PRE�O DO VE�CULO...");
							preco[cod]=0;
                            printf("\nDADO EXCLU�DO COM SUCESSO.\n");
						}
						else if(excluir == 6)
						{
							printf("\nCOR DO VE�CULO\n\n");
							printf("EXCLUINDO A COR DO VE�CULO... ");
							strcpy(cor[cod], nulo);
                            printf("\nDADO EXCLU�DO COM SUCESSO.\n");
						}
						else
						{
						    system ("cls");
							printf("\nOP��O INV�LIDA.\n");
						}
    }
}
void consultar(){
    if(cont == -1){
        printf("N�O EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VE�CULO E TENTE NOVAMENTE.\n");
    }
    else{
        printf("*********************\n");
        printf(" CONSULTA DE DADOS\n");
        printf("*********************\n\n");
        printf("C�DIGO DO VE�CULO: ");
        scanf("%d", &cod);
        if(cod>cont){
            printf("\nN�O EXISTE CADASTRO COM ESTE C�DIGO. TENTE NOVAMENTE!\n");
        }
        else{
        printf("\nQUAL DADO QUER CONSULTAR?\n");
        printf("DIGITE 0- TIPO DO VE�CULO\n 1- MARCA DO VE�CULO\n 2- MODELO DO VE�CULO\n 3- ANO DE FABRICA��O\n 4- ANO DO MODELO\n 5- PRE�O DO VE�CULO\n 6- COR DO VE�CULO\n");
        printf("DIGITE SUA OP��O AQUI: ");
        scanf("%d", &consulte);
        system("cls");
                        if(consulte == 0)
                        {
                            printf("\nTIPO DO VE�CULO: %s\n", tipo[cod]);
                        }
                        else if(consulte == 1)
                        {
                            printf("\nMARCA DO VE�CULO: %s\n", marca[cod]);
                        }
                        else if(consulte == 2)
                        {
                            printf("\nMODELO DO VE�CULO: %s\n", modelo[cod]);
                        }
                        else if(consulte == 3)
                        {
                            printf("\nANO DE FABRICA��O DO VE�CULO: %d\n", anofab[cod]);
                        }
                        else if(consulte == 4)
                        {
                            printf("\nANO DO MODELO DO VE�CULO: %d\n", anomod[cod]);
                        }
                        else if(consulte == 5)
                        {
                            printf("\nPRE�O DO VE�CULO: %.2f\n", preco[cod]);
                        }
                        else if(consulte == 6)
                        {
                            printf("\nCOR DO VE�CULO: %s\n", cor[cod]);
                        }
                        else
                        {
                            printf("\nOP��O INV�LIDA.\n");
                            printf("ESCOLHA UM OP��O V�LIDA\n");
                            consultar();
                        }
        }
    }
}
void arquivo_gravar(){
    FILE *arquivo;
    printf("*******************\n");
    printf(" GRAVA��O DE DADOS\n");
    printf("*******************\n\n");
    arquivo = fopen("Lista.txt", "w");
    if(cont== -1){
        printf("N�O EXISTEM CADASTROS NO MOMENTO. POR FAVOR CADASTRE UM VE�CULO E TENTE NOVAMENTE.\n");
    }
    else{
        if (arquivo == NULL){
            printf("ERRO NA CRIA��O DO ARQUIVO!. REVEJA O DIRET�RIO E TENTE NOVAMENTE.\n");
        }
        else{
            for (int x=0; x<=cont; x++){
                fprintf(arquivo, "****************************************\n");
                fprintf(arquivo, "C�DIGO DO VE�CULO: %d\n", x);
                fprintf(arquivo, "TIPO[%d]: %s\n", x, tipo[x]);
                fprintf(arquivo, "MARCA[%d]: %s\n", x , marca[x]);
                fprintf(arquivo, "MODELO[%d]: %s\n", x, modelo[x]);
                fprintf(arquivo, "ANO DE FABRICA��O[%d]: %d\n", x, anofab[x]);
                fprintf(arquivo, "ANO DO MODELO[%d]: %d\n", x, anomod[x]);
                fprintf(arquivo, "PRE�O[%d]: %2.f\n", x, preco[x]);
                fprintf(arquivo, "COR[%d]: %s\n", x, cor[x]);
                fprintf(arquivo, "****************************************\n\n");
                }
                printf("ARQUIVO CRIADO COM SUCESSO!\n");
        }
        fclose(arquivo);
    }
}
void arquivo_ler(){
    FILE *arquivoler;
    char linha[300];
    char *result;
    printf("******************************\n");
    printf(" LEITURA E IMPRESS�O DE DADOS\n");
    printf("******************************\n\n");
    if(cont== -1){
        printf("N�O EXISTEM CADASTROS NO MOMENTO. POR FAVOR CADASTRE UM VE�CULO E TENTE NOVAMENTE.\n");
    }
    else{
        arquivoler = fopen("Lista.txt", "r");
        if(arquivoler == NULL){
            printf("ERRO AO ABRIR O ARQUIVO.\n");
        }
        else{
            while(!feof(arquivoler)){
                result = fgets(linha, 300, arquivoler);
                if (result){
                    printf(linha);
                }
            }
        printf("\nDADOS LIDOS COM SUCESSO.\n");
        fclose(arquivoler);
        }
    }
}
void relatorio(){
    int gravar;
        if(cont == -1){
        printf("N�O EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VE�CULO E TENTE NOVAMENTE.\n");
    }
    else{
        printf("*********************\n");
        printf(" RELAT�RIO DE DADOS\n");
        printf("*********************\n\n");
        for(int x=0; x<=cont; x++){
            printf("--------------------------\n");
            printf("C�DIGO DO VE�CULO: %d\n", codigo[x]);
            printf("\nTIPO DO VE�CULO: %s\n", tipo[x]);
            printf("\nMARCA DO VE�CULO: %s\n", marca[x]);
            printf("\nMODELO DO VE�CULO: %s\n", modelo[x]);
            printf("\nANO DE FABRICA��O DO VE�CULO: %d\n", anofab[x]);
            printf("\nANO DO MODELO DO VE�CULO: %d\n", anomod[x]);
            printf("\nPRE�O DO VE�CULO: %.2f\n", preco[x]);
            printf("\nCOR DO VE�CULO: %s\n", cor[x]);
            printf("--------------------------\n\n");
        }
    printf("\nDESEJA GRAVAR ESTES DADOS EM UM ARQUIVO TXT? (DIGITE 1 CASO SIM, OU DIGITE QUALQUER OUTRO N�MERO PARA CONTINUAR)\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("ATEN��O: CASO J� TENHA SALVADO O ARQUIVO COMO .TXT, CERTIFIQUE-SE DE FAZER UM BACKUP DO MESMO, POIS SER� SUBSTITU�DO CASO DIGITE 1\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("DIGITE SUA OP��O AQUI: ");
    scanf("%d", &gravar);
        if(gravar == 1){
            system("cls");
            arquivo_gravar();
        }
    }
}
//***********************************************
int main (){
		setlocale(LC_ALL,"");
		printf("*******************************************\n");
        printf("-------------------------------------------\n");
        printf(" CONCESSION�RIA DE SEMI-NOVOS AREA1 MOTORS\n");
        printf("-------------------------------------------\n");
		printf("*******************************************\n");
        printf("\nABRINDO MENU DE OP��ES...\n\n");
		menu();
            while(opcao!=9){
				if (opcao == 0){ //INSERIR DADOS
                    system("cls");
					inserir_dados();
					menu();
				}
				else if (opcao == 1){ //CONSULTAR DADOS
                    system("cls");
					consultar();
					menu();
				}
				else if (opcao == 2){ //ALTERAR DADOS
                    system("cls");
					alterar_dados();
					menu();
				}
				else if (opcao == 3){//EXCLUIR DADOS
				    system("cls");
					excluir_dados();
					menu();
				}
				else if (opcao == 4){ //RELAT�RIO DE DADOS
				    system("cls");
					relatorio();
					menu();
				}
				else if (opcao == 5){//QUANTIDADE DE REGISTROS
                    system("cls");
                    if(cont == -1)
                        printf("\nQUANTIDADE DE REGISTROS FEITOS: 0 REGISTROS.\n");
                    else
					printf("\nQUANTIDADE DE REGISTROS FEITOS: %d\n", cont+1);
					menu();
				}
				else if (opcao == 6){ //GRAVAR ARQUIVO .TXT
                    system("cls");
                    arquivo_gravar();
                    menu();
				}
				else if (opcao == 7){ //IMPRIMIR AQUIVO .TXT
                    system("cls");
                    arquivo_ler();
                    menu();
				}
				else {
                    system("cls");
                    printf("DESCULPE, OP��O INV�LIDA. :( POR FAVOR, ESCOLHA UMA DAS OP��ES DO MENU.\n");
                    menu();
                }
            }
return 0;
}
