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
//FUNÇÕES USADAS PARA AS OPÇÕES LISTADAS NO MENU!
void menu(){
	printf("\nMENU DE OPÇÕES:\n\n");
	printf(" 0- INSERIR DADOS\n 1- CONSULTAR DADOS\n 2- ALTERAR DADOS\n 3- EXCLUIR DADOS\n 4- RELATÓRIO DOS DADOS\n 5- QUANTIDADE DE REGISTROS\n 6- GRAVAR DADOS EM .TXT\n 7- IMPRIMIR DADOS .TXT\n 9- SAIR\n\n");
	printf("DIGITE A SUA OPÇÃO: ");
	scanf("%d", &opcao);
    }
void inserir_dados(){
    system("cls");
    if(cont==tamvetor-1){
        printf("LIMITE MÁXIMO ATINGIDO!.\n");
    }
    else{
    cont ++;
    printf("****************\n");
    printf(" INSERIR DADOS\n");
    printf("****************\n\n");
    printf("-> TODOS OS VEÍCULOS RECEBERÃO COMO CÓDIGO A ORDEM EM QUE SERÁ REGISTRADO, PORTANTO, O CÓDIGO DESTE VEÍCULO SERÁ %d <-\n\n", cont);
    codigo[cont]= cont; // ??? Gerador de Código, rever lógica
    printf("\nDIGITE O TIPO DO VEÍCULO (EX: CARRO, MOTO, CAMINHÃO): ");
    scanf("%s", tipo[cont]);
	printf("\nDIGITE A MARCA DO VEÍCULO: ");
	scanf("%s", marca[cont]);
	printf("\nDIGITE O MODELO DO VEÍCULO: ");
	scanf("%s", modelo[cont]);
	printf("\nDIGITE O ANO DE FABRICAÇÃO DO VEÍCULO: ");
	scanf("%d", &anofab[cont]);
	printf("\nDIGITE O ANO DO MODELO DO VEÍCULO: ");
	scanf("%d", &anomod[cont]);
	printf("\nDIGITE O PREÇO DO VEÍCULO: R$");
	scanf("%f", &preco[cont]);
	printf("\nDIGITE A COR DO VEÍCULO: ");
	scanf("%s", cor[cont]);
	system("cls");
	printf("DADOS INSERIDOS COM SUCESSO.\n");
    }
}
void alterar_dados(){
    if(cont == -1){
        system("cls");
        printf("NÃO EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VEÍCULO E TENTE NOVAMENTE.\n");
    }
    else{
                system("cls");
                printf("********************\n");
                printf(" ALTERAÇÃO DE DADOS\n");
                printf("********************\n\n");
				printf("\nDIGITE O CÓDIGO DO VEÍCULO: ");
				scanf("%d", &cod);
				printf("\nDIGITE 0- TIPO DO VEÍCULO\n 1- MARCA DO VEÍCULO\n 2- MODELO DO VEÍCULO\n 3- ANO DE FABRICAÇÃO\n 4- ANO DO MODELO\n 5- PREÇO DO VEÍCULO\n 6- COR DO VEÍCULO\n");
				printf("\nDIGITE SUA OPÇÃO AQUI: ");
				scanf("%d", &alterar);
					if(alterar == 0)
					{
						printf("\nTIPO DE VEÍCULO\n\n");
						printf("DIGITE O TIPO DE VEÍCULO: ");
						scanf("%s", tipo[cod]);
					system ("cls");
                    printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 1)
					{
						printf("\nMARCA DO VEÍCULO\n\n");
						printf("DIGITE A MARCA DO VEÍCULO: ");
						scanf("%s", marca[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 2)
					{
						printf("\nMODELO DO VEÍCULO\n\n");
						printf("DIGITE O MODELO DO VEÍCULO: ");
						scanf("%s", modelo[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 3)
					{
						printf("\nANO DE FABRICAÇÃO DO VEÍCULO\n\n");
						printf("DIGITE O ANO DE FABRICAÇÃO DO VEÍCULO: ");
						scanf("%d", &anofab[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 4)
					{
						printf("\nANO DO MODELO DO VEÍCULO\n\n");
						printf("DIGITE O ANO DO MODELO DO VEÍCULO: ");
						scanf("%d", &anomod[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 5)
					{
						printf("\nPREÇO DO VEÍCULO\n\n");
						printf("DIGITE O PREÇO DO VEÍCULO: R$");
						scanf("%f", &preco[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else if(alterar == 6)
					{
						printf("\nCOR DO VEÍCULO\n\n");
						printf("DIGITE A COR DO VEÍCULO: ");
						scanf("%s", cor[cod]);
						system ("cls");
                        printf("\nDADO ALTERADO COM SUCESSO\n");
					}
					else
					{
						printf("\nOPÇÃO INVÁLIDA.\n");
					}

    }
}
void excluir_dados(){
    if(cont == -1){
            system("cls");
        printf("NÃO EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VEÍCULO E TENTE NOVAMENTE.\n");
    }
    else{
                    system("cls");
                    printf("*******************\n");
					printf(" EXCLUSÃO DE DADOS\n");
					printf("*******************\n\n");
					printf("DIGITE O CÓDIGO DE CADASTRO DO VEÍCULO: ");
					scanf("%d", &cod);
					printf("\nDIGITE 0- TIPO DO VEÍCULO\n 1- MARCA DO VEÍCULO\n 2- MODELO DO VEÍCULO\n 3- ANO DE FABRICAÇÃO\n 4- ANO DO MODELO\n 5- PREÇO DO VEÍCULO\n 6- COR DO VEÍCULO\n");
					printf("\nDIGITE SUA OPÇÃO AQUI: ");
					scanf("%d", &excluir);
						if(excluir == 0)
						{
							printf("\nTIPO DE VEÍCULO\n\n");
							printf("EXCLUINDO O TIPO DE VEÍCULO...\n");
							strcpy(tipo[cod], nulo);
                            printf("\nDADO EXCLUÍDO COM SUCESSO.\n");
						}
						else if(excluir == 1)
						{
							printf("\nMARCA DO VEÍCULO\n\n");
							printf("EXCLUINDO A MARCA DO VEÍCULO... ");
							strcpy(marca[cod], nulo);
                            printf("\nDADO EXCLUÍDO COM SUCESSO.\n");
						}
						else if(excluir == 2)
						{
							printf("\nMODELO DO VEÍCULO\n\n");
							printf("EXCLUINDO O MODELO DO VEÍCULO... ");
							strcpy(modelo[cod], nulo);
                            printf("\nDADO EXCLUÍDO COM SUCESSO.\n");
						}
						else if(excluir == 3)
						{
							printf("\nANO DE FABRICAÇÃO DO VEÍCULO\n\n");
							printf("EXCLUINDO O ANO DE FABRICAÇÃO DO VEÍCULO... ");
							anofab[cod]=0;
                            printf("\nDADO EXCLUÍDO COM SUCESSO.\n");
						}
						else if(excluir == 4)
						{
							printf("\nANO DO MODELO DO VEÍCULO\n\n");
							printf("EXCLUINDO O ANO DO MODELO DO VEÍCULO... ");
							anomod[cod]=0;
                            printf("\nDADO EXCLUÍDO COM SUCESSO.\n");
						}
						else if(excluir == 5)
						{
							printf("\nPREÇO DO VEÍCULO\n\n");
							printf("EXCLUINDO O PREÇO DO VEÍCULO...");
							preco[cod]=0;
                            printf("\nDADO EXCLUÍDO COM SUCESSO.\n");
						}
						else if(excluir == 6)
						{
							printf("\nCOR DO VEÍCULO\n\n");
							printf("EXCLUINDO A COR DO VEÍCULO... ");
							strcpy(cor[cod], nulo);
                            printf("\nDADO EXCLUÍDO COM SUCESSO.\n");
						}
						else
						{
						    system ("cls");
							printf("\nOPÇÃO INVÁLIDA.\n");
						}
    }
}
void consultar(){
    if(cont == -1){
        printf("NÃO EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VEÍCULO E TENTE NOVAMENTE.\n");
    }
    else{
        printf("*********************\n");
        printf(" CONSULTA DE DADOS\n");
        printf("*********************\n\n");
        printf("CÓDIGO DO VEÍCULO: ");
        scanf("%d", &cod);
        if(cod>cont){
            printf("\nNÃO EXISTE CADASTRO COM ESTE CÓDIGO. TENTE NOVAMENTE!\n");
        }
        else{
        printf("\nQUAL DADO QUER CONSULTAR?\n");
        printf("DIGITE 0- TIPO DO VEÍCULO\n 1- MARCA DO VEÍCULO\n 2- MODELO DO VEÍCULO\n 3- ANO DE FABRICAÇÃO\n 4- ANO DO MODELO\n 5- PREÇO DO VEÍCULO\n 6- COR DO VEÍCULO\n");
        printf("DIGITE SUA OPÇÃO AQUI: ");
        scanf("%d", &consulte);
        system("cls");
                        if(consulte == 0)
                        {
                            printf("\nTIPO DO VEÍCULO: %s\n", tipo[cod]);
                        }
                        else if(consulte == 1)
                        {
                            printf("\nMARCA DO VEÍCULO: %s\n", marca[cod]);
                        }
                        else if(consulte == 2)
                        {
                            printf("\nMODELO DO VEÍCULO: %s\n", modelo[cod]);
                        }
                        else if(consulte == 3)
                        {
                            printf("\nANO DE FABRICAÇÃO DO VEÍCULO: %d\n", anofab[cod]);
                        }
                        else if(consulte == 4)
                        {
                            printf("\nANO DO MODELO DO VEÍCULO: %d\n", anomod[cod]);
                        }
                        else if(consulte == 5)
                        {
                            printf("\nPREÇO DO VEÍCULO: %.2f\n", preco[cod]);
                        }
                        else if(consulte == 6)
                        {
                            printf("\nCOR DO VEÍCULO: %s\n", cor[cod]);
                        }
                        else
                        {
                            printf("\nOPÇÃO INVÁLIDA.\n");
                            printf("ESCOLHA UM OPÇÃO VÁLIDA\n");
                            consultar();
                        }
        }
    }
}
void arquivo_gravar(){
    FILE *arquivo;
    printf("*******************\n");
    printf(" GRAVAÇÃO DE DADOS\n");
    printf("*******************\n\n");
    arquivo = fopen("Lista.txt", "w");
    if(cont== -1){
        printf("NÃO EXISTEM CADASTROS NO MOMENTO. POR FAVOR CADASTRE UM VEÍCULO E TENTE NOVAMENTE.\n");
    }
    else{
        if (arquivo == NULL){
            printf("ERRO NA CRIAÇÃO DO ARQUIVO!. REVEJA O DIRETÓRIO E TENTE NOVAMENTE.\n");
        }
        else{
            for (int x=0; x<=cont; x++){
                fprintf(arquivo, "****************************************\n");
                fprintf(arquivo, "CÓDIGO DO VEÍCULO: %d\n", x);
                fprintf(arquivo, "TIPO[%d]: %s\n", x, tipo[x]);
                fprintf(arquivo, "MARCA[%d]: %s\n", x , marca[x]);
                fprintf(arquivo, "MODELO[%d]: %s\n", x, modelo[x]);
                fprintf(arquivo, "ANO DE FABRICAÇÃO[%d]: %d\n", x, anofab[x]);
                fprintf(arquivo, "ANO DO MODELO[%d]: %d\n", x, anomod[x]);
                fprintf(arquivo, "PREÇO[%d]: %2.f\n", x, preco[x]);
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
    printf(" LEITURA E IMPRESSÃO DE DADOS\n");
    printf("******************************\n\n");
    if(cont== -1){
        printf("NÃO EXISTEM CADASTROS NO MOMENTO. POR FAVOR CADASTRE UM VEÍCULO E TENTE NOVAMENTE.\n");
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
        printf("NÃO EXISTEM CADASTROS NO MOMENTO.\nPOR FAVOR, CADASTRE ALGUM VEÍCULO E TENTE NOVAMENTE.\n");
    }
    else{
        printf("*********************\n");
        printf(" RELATÓRIO DE DADOS\n");
        printf("*********************\n\n");
        for(int x=0; x<=cont; x++){
            printf("--------------------------\n");
            printf("CÓDIGO DO VEÍCULO: %d\n", codigo[x]);
            printf("\nTIPO DO VEÍCULO: %s\n", tipo[x]);
            printf("\nMARCA DO VEÍCULO: %s\n", marca[x]);
            printf("\nMODELO DO VEÍCULO: %s\n", modelo[x]);
            printf("\nANO DE FABRICAÇÃO DO VEÍCULO: %d\n", anofab[x]);
            printf("\nANO DO MODELO DO VEÍCULO: %d\n", anomod[x]);
            printf("\nPREÇO DO VEÍCULO: %.2f\n", preco[x]);
            printf("\nCOR DO VEÍCULO: %s\n", cor[x]);
            printf("--------------------------\n\n");
        }
    printf("\nDESEJA GRAVAR ESTES DADOS EM UM ARQUIVO TXT? (DIGITE 1 CASO SIM, OU DIGITE QUALQUER OUTRO NÚMERO PARA CONTINUAR)\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("ATENÇÃO: CASO JÁ TENHA SALVADO O ARQUIVO COMO .TXT, CERTIFIQUE-SE DE FAZER UM BACKUP DO MESMO, POIS SERÁ SUBSTITUÍDO CASO DIGITE 1\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("DIGITE SUA OPÇÃO AQUI: ");
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
        printf(" CONCESSIONÁRIA DE SEMI-NOVOS AREA1 MOTORS\n");
        printf("-------------------------------------------\n");
		printf("*******************************************\n");
        printf("\nABRINDO MENU DE OPÇÕES...\n\n");
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
				else if (opcao == 4){ //RELATÓRIO DE DADOS
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
                    printf("DESCULPE, OPÇÃO INVÁLIDA. :( POR FAVOR, ESCOLHA UMA DAS OPÇÕES DO MENU.\n");
                    menu();
                }
            }
return 0;
}
