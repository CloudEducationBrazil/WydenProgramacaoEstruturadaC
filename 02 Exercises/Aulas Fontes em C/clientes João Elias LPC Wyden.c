/*
	Name: 
	Copyright: FSOFTWARE Ltda. Todos os direitos reservados
	Author: Jo�o Elias Ferraz Santana
	Date: 02/05/20 19:37
	Description: O programa cadastra N clientes de uma loja. As informa��es necess�rias
	s�o: nome, endere�o e telefone. Foi usada uma estrutura de registro para a constru��o
	deste cadastro. O programa dever� suportar at� N clientes, quantidade essa informada
	pelo usu�rio. Al�m disso, ele tem op��es para ver todos os clientes atualizar os dados,
	e excluir um cliente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
	char rua[100];
	int numero;
	char bairro[20];
	int CEP;
}Endereco;

typedef struct{
	char nome[75];
	Endereco end;
	int telefone;
}Cliente;

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int N, op, i, j, op1, pos;
	char sair;
	start:printf("Entre com o n�mero de clientes:\n");
	printf("N�mero: ");
	scanf("%d", &N);
	if(N<=0){
		printf("N�mero inv�lido!\n\n");
		system("pause");
		system("cls");
		goto start;
	}
	system("cls");
	Cliente mrs[N];
	for(i=0; i<N; i++){
		fflush(stdin);
		printf("\t\tCliente %d\n\n", i+1);
		printf("Entre com o nome do cliente:\n");
		gets(mrs[i].nome);
		fflush(stdin);
		printf("Entre com o endere�o:\n");
		printf("Rua: ");
		gets(mrs[i].end.rua);
		fflush(stdin);
		printf("N�mero: ");
		scanf("%d", &mrs[i].end.numero);
		fflush(stdin);
		printf("Bairro: ");
		gets(mrs[i].end.bairro);
		fflush(stdin);
		printf("CEP.: ");
		scanf("%d", &mrs[i].end.CEP);
		printf("Entre com o telefone: ");
		scanf("%d", &mrs[i].telefone);
		system("cls");
	}
	do{
		printf("\t\t\tMenu principal\n\n\n");
		printf("Op��es:\n");
		printf("1.\tVer clientes\n");
		printf("2.\tAlterar dados\n");
		printf("3.\tExcluir cliente\n");
		printf("4.\tSair da aplica��o\n\n");
		printf("Op��o escolhida: ");
		scanf("%d", &op);
		system("cls");
		if(op==1){
			for(i=0; i<N; i++){
				for(j=1; j<10; j++){
					printf("*");
				}
				printf("\n\nNome: ");
				for(j=0; j<strlen(mrs[i].nome); j++){
					printf("%c", mrs[i].nome[j]); //escreve o nome do cliente letra a letra
				}
				printf("\n");
				printf("Endere�o:\n");
				printf("Rua: ");
				for(j=0; j<strlen(mrs[i].end.rua); j++){
					printf("%c", mrs[i].end.rua[j]); //escreve o nome da rua letra a letra
				}
				printf("\nN�mero: %d\n", mrs[i].end.numero);
				printf("Bairro: ");
				for(j=0; j<strlen(mrs[i].end.bairro); j++){
					printf("%c", mrs[i].end.bairro[j]); //escreve o nome do cliente letra a letra
				}
				printf("\nTelefone: %d\n", mrs[i].telefone);
				printf("CEP.: %d\n\n", mrs[i].end.CEP);
				for(j=1; j<10; j++){
					printf("*");
				}
				printf("\n\n");
			}
			system("pause");
			system("cls");
		}
		else if(op==2){
			printf("Qual dado deseja alterar?\n");
			printf("1.\tNome\n");
			printf("2.\tEndere�o\n");
			printf("3.\tTelefone\n\n");
			printf("Escolha: ");
			scanf("%d", &op1);
			if(op1==1){
				printf("Entre com a posi��o do cliente: ");
				scanf("%d", &pos);
				if(pos>N-1||pos<0){
					printf("Posi��o inv�lida!\n\n");
				}
				else{
					fflush(stdin);
					printf("Entre com o nome: ");
					gets(mrs[pos].nome);
					fflush(stdin);
				}
			}
			else if(op1==2){
				printf("Entre com a posi��o do cliente: ");
				scanf("%d", &pos);
				if(pos>N-1||pos<0){
					printf("Posi��o inv�lida!\n\n");
				}
				else{
					fflush(stdin);
					printf("Entre com a rua: ");
					gets(mrs[pos].end.rua);
					fflush(stdin);
					printf("Entre com o n�mero: ");
					scanf("%d", &mrs[i].end.numero);
					fflush(stdin);
					printf("Entre com o bairro: ");
					gets(mrs[pos].end.bairro);
					fflush(stdin);
					printf("Entre com o CEP.: ");
					scanf("%d", &mrs[pos].end.CEP);
					printf("Dados alterados com sucesso!\n\n");
				}
			}
			else if(op1==3){
				printf("Entre com a posi��o do cliente: ");
				scanf("%d", &pos);
				if(pos>N-1||pos<0){
					printf("Posi��o inv�lida!\n\n");
				}
				else{
					printf("Entre com o telefone: ");
					scanf("%d", &mrs[pos].telefone);
				}
			}
			system("pause");
			system("cls");
		}
		else if(op==3){
			printf("Entre com a posi��o do cliente: ");
			scanf("%d", &pos);
			if(pos>N-1||pos<0){ //verifica se a posi��o informada � v�lida
				printf("Posi��o inv�lida!\n\n");
			}
			else{
				for(i=0; i<75; i++){
					mrs[pos].nome[i]='\0'; //apaga o nome do cliente
				}
				mrs[pos].telefone=0;
				for(i=0; i<100; i++){
					mrs[pos].end.bairro[i]='\0';
					mrs[pos].end.rua[i]='\0';
				}
				mrs[pos].end.CEP=0;
				mrs[pos].end.numero=0;
				printf("Cliente removido com sucesso!\n\n");
			}
			system("pause");
			system("cls");
		}
		else if(op==4){
			break;
		}
		else{
			printf("Op��o inv�lida!\n\n");
			system("pause");
			system("cls");
		}
	}while(op!=4);
	return 0;
}
