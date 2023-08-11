#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	
	int opcao, opcao1, opcao2, opcao3, opcao4, i, quant;
	
	struct referencia{
		
		char nome0[100], nome1[100], nome2[100], nome3[100], nome4[100];
	}
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
CA[600];
		char nome5[100];
		
		
	system("cls");
	printf("Nome do Atendente: ");
	fflush(stdin);
	scanf("%[^\n]s", nome5);
	printf("Senha: ");
	fflush(stdin);
	scanf("%d", &opcao3);
	
	
	
		if ( opcao3 == 123456){
		 	
		 	while(opcao!=6){
	while(opcao2!=1){
		system("color F4");
		system("cls");
		
				printf("------------------------------------------------------------\n\n");
				printf("\t\t\t Seja Bem vindo, Atendente %s\n", nome5);
				printf("1-Cadastrar\n ");
				printf("2-Exibir Dados\n ");
				printf("3-Alterar\n ");
				printf("4-Excluir\n ");
				printf("5-Informacoes do Sistema\n ");
				printf("6-Sair\n ");
				printf("------------------------------------------------------------\n\n ");
				printf("\nQual opcao voce deseja acessar? ");
				scanf("%d", &opcao);
				
	switch(opcao){
					case 1:
						system("cls");
						printf("\n\n Quantos cadastros voce deseja realizar? ");;
						scanf("%d", &quant);
						
					for(i=1;i<=quant;i++){
						system("cls");
						printf("\n\n\t\t\t INICIANDO CADASTRO %d\n", i);
						printf("\t\t\t    -------------\n\n");
						printf("\n Nome do Cliente: ");
						fflush(stdin);
						scanf("%[^\n]s", CA[i].nome0);
						printf("\n CPF do Cliente: ");
						fflush(stdin);
						scanf("%[^\n]s", CA[i].nome1);
						printf("\n Numero do Cartao: ");
						fflush(stdin);
						scanf("%[^\n]s", CA[i].nome2);
						printf("\n Limite do Cartao: ");
						fflush(stdin);
						scanf("%[^\n]s", CA[i].nome3);
						printf("\n Telefone do Cliente: ");
						fflush(stdin);
						scanf("%[^\n]s", CA[i].nome4);
						printf("\n\n\t\t");
						system("pause");
						system("cls");
					}
					break;
					
					case 2:
						system("cls");
						
						for(i=1;i<=quant;i++){
							system("cls");
							printf("\n\n\t\t\t   EXIBINDO CADASTRO %d\n",i);
							printf("\t\t\t   --------------\n\n");
							printf("Nome do Cliente : %s\n", CA[i].nome0);
							printf("\n CPF do Cliente : %s\n", CA[i].nome1);
							printf("\n Numero do Cartao : %s\n", CA[i].nome2);
							printf("\n Limite do Cartao : %s\n", CA[i].nome3);
							printf("\n Telefone do Cliente : %s\n", CA[i].nome4);
							system("pause");
				}
						
							break;
							
							case 3:
								system("cls");
						for(i=1;i<=quant;i++){
							printf("\n\n\t\t\t   ALTERAR CADASTRO\n");
							printf("\t\t\t   --------------\n\n");
							printf("  1- Nome do Cliente");
							printf("\n 2- CPF do Cliente");
							printf("\n 3- Numero do Cartao");
							printf("\n 4- Limite do Cartao");
							printf("\n 5- Telefone do Cliente");
							printf("\nQual opcao voce deseja acessar? \n");
							scanf("%d", &opcao1);
			switch(opcao1){
				case 1:
					for(i=1;i<=quant;i++){
						system ("cls");
						printf("\n\n CADASTRO %d\n", i);
						printf("\n Alterar Nome do Cliente: ");
						fflush(stdin);
						scanf("%[^\n]s", &CA [i].nome0);
						printf("\n Novo Nome do Cliente: %s\n\n\t\t");
						system("pause");
				   }
				   break;
				   
				case 2:
					for(i=1;i<=quant;i++){
						system ("cls");
						printf("\n\n CADASTRO %d\n", i);
						printf("\n Alterar o CPF do Cliente: ");
						fflush(stdin);
						scanf("%[^\n]s", &CA [i].nome1);
						printf("\n Novo CPF do Cliente: %s\n\n\t\t");
						system("pause");
				    }
				    break;
				
				case 3:
					for(i=1;i<=quant;i++){
						system ("cls");
						printf("\n\n CADASTRO %d\n", i);
						printf("\n Alterar Numero do Cartao: ");
						fflush(stdin);
						scanf("%[^\n]s", &CA [i].nome2);
						printf("\n Novo Numero do Cartao: %s\n\n\t\t");
						system("pause");
				   }
				   break;
				
				case 4:
					for(i=1;i<=quant;i++){
						system ("cls");
						printf("\n\n CADASTRO %d\n", i);
						printf("\n Alterar Limite do Cartao: ");
						fflush(stdin);
						scanf("%[^\n]s", &CA [i].nome3);
						printf("\n Novo Limite do Cartao: %s\n\n\t\t");
						system("pause");
				   }
				   break;
				   
				   case 5:
					for(i=1;i<=quant;i++){
						system ("cls");
						printf("\n\n CADASTRO %d\n", i);
						printf("\n Alterar Telefone do Cliente: ");
						fflush(stdin);
						scanf("%[^\n]s", &CA [i].nome4);
						printf("\n Novo Telefone do Cliente: %s\n\n\t\t");
						system("pause");
				   }
				   break;
				   
			}
		}
		break;
			case 4:
				system("cls");
				for(i=1;i<=quant;i++){
							printf("\n\n\t\t\t    EXCLUIR CADASTRO\n");
							printf("\t\t\t   --------------\n\n");
							printf("  1- Nome do Cliente");
							printf("\n 2- CPF do Cliente");
							printf("\n 3- Numero do Cartao");
							printf("\n 4- Limite do Cartao");
							printf("\n 5- Telefone do Cliente");
							printf("\n 6- Exlcluir Todos os Dados\n\n");
							printf("Qual Opcao Voce Deseja Acessar? \n");
							scanf("%d", &opcao4);
							
					switch(opcao4){
						case 1:
							for(i=1;i<=quant;i++){
								system("cls");
								memset(&CA [i].nome0,0,sizeof(CA [i].nome0));
								printf("Nome do Cliente Excluido!\n\n");
								system("pause");
							}
							break;
						
						case 2:
							for(i=1;i<=quant;i++){
								system("cls");
								memset(&CA[ i].nome1,0, sizeof(CA [i].nome1));
								printf("CPF do Cliente Excluido!\n\n");
								system("pause");
							}
							break;
							
						case 3:
							for(i=1;i<=quant;i++){
								system("cls");
								memset(&CA [i].nome2,0, sizeof(CA [i].nome2));
								printf("Numero do Cartao Excluido!\n\n");
								system("pause");
							}
							break;
							
						case 4:
							for(i=1;i<=quant;i++){
								system("cls");
								memset(&CA [i].nome3,0, sizeof(CA [i].nome3));
								printf("Limite do Cartao Excluido!\n\n");
								system("pause");
							}
							break;
							
						case 5:
							for(i=1;i<=quant;i++){
								system("cls");
								memset(&CA [i].nome4,0, sizeof(CA [i].nome4));
								printf("Telefone do Cliente Excluido!\n\n");
								system("pause");
							}
							break;
							
						case 6:
							for(i=1;i<=quant;i++){
								system("cls");
								memset(&CA [i].nome0,0,sizeof(CA[i].nome0));
								memset(&CA [i].nome1,0,sizeof(CA[i].nome1));
								memset(&CA [i].nome2,0,sizeof(CA[i].nome2));
								memset(&CA [i].nome3,0,sizeof(CA[i].nome3));
								memset(&CA [i].nome4,0,sizeof(CA[i].nome4));
								printf("Todos os Dados Foram Excluidos!\n\n");
								system("pause");
							}
							break;	
							
					}
							
				}
				break;
				
			case 5:
				system("cls");
				printf("\n Voce Realmente Deseja Sair do programa ?\n\n");
				printf(" 1- Sim\n 2- Nao");
				printf("\n\n");
				scanf("%d", &opcao2);
				
				switch(opcao2){
					case 1:
						system("cls");
						printf("\n\n Volte Sempre ! \n\n\n\t\t");
						system("pause");
						return 0;
						break;
						
				}
				}				   
				}
				break;
				}
			 }
			 
			 else printf("Senha Incorreta! \n");
			 
system("pause");
return 0;		 
}
