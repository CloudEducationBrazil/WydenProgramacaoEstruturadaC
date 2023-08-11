/*
	.:CAFF - APLICAÇÃO DE CADASTRO DE FABRICANTE/FORNECEDOR:.
	.:AUTOR: ANGELO DO NASCIMENTO JUNIOR:.
	.:MATRICULA: 1920530746:.
	.:DATA: 20/11/2019:.
	.:VERSÃO 1.0:.
*/

//Bibilhotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


//Constantes
#define SIZE 50 
#define MAX_END 20
#define MAX_CNPJ 15
#define MAX_UF 4
#define MAX_TELEFONE 14
#define MAX_INSCESTADO 15
#define MAX_CEP 11

//Estrutura de cadastro
typedef struct{
	
	int  ativo;
	char nomeFantasia[SIZE];
	char razaoSocial[SIZE];
	char tipoEntidade[SIZE];
	char cnpj[MAX_CNPJ];
	char inscEstado[MAX_INSCESTADO];
	char cep[MAX_CEP];
	char endereco[SIZE];
	char bairro[MAX_END];
	char cidade[MAX_END];
	char uf[MAX_UF];
	char telefone[MAX_TELEFONE];
	char email[SIZE];
	char contato[SIZE];
	
}Fabrica_Fornecedor;
Fabrica_Fornecedor entidade[SIZE];

//Variaveis globais
int ativo;
int op;
char nomeFantasia[SIZE];
char razaoSocial[SIZE];
char tipoEntidade[SIZE];
char cnpj[MAX_CNPJ];
char inscEstado[MAX_INSCESTADO];
char cep[MAX_CEP];
char endereco[SIZE];
char bairro[MAX_END];
char cidade[MAX_END];
char uf[MAX_UF];
char telefone[MAX_TELEFONE];
char email[SIZE];
char contato[SIZE];

//Metodos 
void Menu();
void Cadastrar();
void Alterar();
void Listar();
void Consultar();
void Remover();
void Exportartxt();
void ClnBuffer();
void Sair();
			
//Metodo Principal
int main(int argc,char const *argv){
	
	system("title .:CAFF - APLICAÇÃO DE CADASTRO DE FABRICANTE/FORNECEDOR:.");
	setlocale(LC_ALL,"portuguese");
	
	Menu();	
	
}

//Metodo Menu
void Menu(){
			
	int op;
				
		system("cls");
	printf("\t\t\t\t.:CAFF - APLICAÇÃO DE CADASTRO DE FABRICANTE/FORNECEDOR:.\n\n");
	
	printf("\n 1-CADASTRAR FABRICANTE/FORNECEDOR\n 2-FABRICANTE/FORNECEDOR CADASTRADO");
	printf("\n 3-CONSULTAR FABRICANTE/FORNECEDOR\n 4-ALTERAR FABRICANTE/FORNECEDOR");
	printf("\n 5-REMOVER FABRICANTE/FORNECEDOR\n 6-EXPORTAR PARA TXT\n 7-SAIR");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
	
		switch(op){
			case 1:
				Cadastrar();
				break;
			case 2:
				Listar();
				break;
			case 3:
				Consultar();
				break;
		    case 4:
		    	Alterar();
		    	break;
		    case 5:
		    	Remover();
		    	break;
		    case 6:
		    	Exportartxt();
		    	break;
		    case 7:
		    	Sair();
		    	break;
		    default:
		    	printf("\n\n Opção invalida!\n Apenas é possivel selecionar de 1 a 7.");
		    	sleep(3);
		        Menu();
		}
}

//Limpar Buffer da variavel
void ClnBuffer(void){
	
	char cln;
	while((cln = getchar()) !='\n' && cln != EOF);
	
}

//Metodo cadastrar fabricante/fornecedor
void Cadastrar(){	
	
	int i;
			
		system("cls");
	printf("\n .:ADICIONAR NOVO FABRICANTE/FORNECEDOR:.\n\n");
		
	printf(" Informe o nome fantasia: ");
	fgets(nomeFantasia,sizeof(nomeFantasia),stdin);
	printf("\n Informe a razão social: ");
	fgets(razaoSocial,sizeof(razaoSocial),stdin);
	printf("\n Informe o tipo da entidade: ");
	fgets(tipoEntidade,sizeof(tipoEntidade),stdin);
	printf("\n Informe o CNPJ: ");
	fgets(cnpj,sizeof(cnpj),stdin);
	printf("\n Informe a inscrição estadual: ");
	fgets(inscEstado,sizeof(inscEstado),stdin);
	printf("\n Informe o CEP: ");
	fgets(cep,sizeof(cep),stdin);
	printf("\n Informe o endereço: ");
	fgets(endereco,sizeof(endereco),stdin);
	printf("\n Informe o bairro: ");
	fgets(bairro,sizeof(bairro),stdin);
	printf("\n Informe a UF da entidade: ");
	fgets(uf,sizeof(uf),stdin);
	printf("\n Informe a cidade: ");
	fgets(cidade,sizeof(cidade),stdin);
	printf("\n Informe o contato: ");
	fgets(contato,sizeof(contato),stdin);
	printf("\n Informe o e-mail: ");
	fgets(email,sizeof(email),stdin);
	printf("\n Informe o telefone: ");
	fgets(telefone,sizeof(telefone),stdin);
	ClnBuffer();
	
	
		for(i=0; i < SIZE; i++) 
		{
			if(entidade[i].ativo == 0)
			{
				strcpy(entidade[i].nomeFantasia,nomeFantasia);
				strcpy(entidade[i].razaoSocial,razaoSocial);
				strcpy(entidade[i].tipoEntidade,tipoEntidade);
				strcpy(entidade[i].cnpj,cnpj);
				strcpy(entidade[i].inscEstado,inscEstado);
				strcpy(entidade[i].cep,cep);
				strcpy(entidade[i].endereco,endereco);
				strcpy(entidade[i].bairro,bairro);
				strcpy(entidade[i].uf,uf);
				strcpy(entidade[i].cidade,cidade);
				strcpy(entidade[i].contato,contato);
				strcpy(entidade[i].email,email);
				strcpy(entidade[i].telefone,telefone);
				entidade[i].ativo = 1;				
				break;
			}
		}
	
	Operacao();
						
}

//Metodo listar fabricante/fornecedor
void Listar(){
	
	int i;
	
		system("cls");
	printf("\n .:FABRICANTE/FORNECEDOR CADASTRADOS:.\n\n");
	
	
		for(i = 0; i < SIZE; i++)
		{
			if(entidade[i].ativo != 0 && entidade[i].ativo == 1)
			{
				printf("\n-------------------\n");
				printf(" ID: %d\n",i);
				printf(" Nome Fantasia: %s",entidade[i].nomeFantasia);
				printf(" Razão Social: %s",entidade[i].razaoSocial);
				printf(" Tipo da Entidade: %s",entidade[i].tipoEntidade);
				printf(" CNPJ: %s",entidade[i].cnpj);
				printf(" Inscrição Estadual: %s",entidade[i].inscEstado);
				printf(" CEP: %s",entidade[i].cep);
				printf(" Endereço: %s",entidade[i].endereco);
				printf(" Bairro: %s",entidade[i].bairro);
				printf(" UF: %s",entidade[i].uf);
				printf(" Cidade: %s",entidade[i].cidade);
				printf(" Contato: %s",entidade[i].contato);
				printf(" E-mail: %s",entidade[i].email);
				printf(" Telefone: %s",entidade[i].telefone);
			}
			else
			{
				if(entidade[i].ativo == 0)
				{
					continue;
				}
				else
				{
					break;
				}
			}				
		}
	
	Operacao2();
	
}

//Metodo que filtra um fabricante/fornecedor especifico
void Consultar(){
	
	int i=0;
	
		system("cls");
	printf("\n .:CONSULTAR FABRICANTE/FORNECEDOR:.\n\n");
	printf(" Digite a ID para pesquisar: ");
	scanf("%d",&i);
	ClnBuffer();
	
	if(entidade[i].ativo != 0 && entidade[i].ativo == 1)
	{
			if(i == i)
			{
				printf("\n-------------------\n");
				printf(" ID: %d\n",i);
				printf(" Nome Fantasia: %s",entidade[i].nomeFantasia);
				printf(" Razão Social: %s",entidade[i].razaoSocial);
				printf(" Tipo da Entidade: %s",entidade[i].tipoEntidade);
				printf(" CNPJ: %s",entidade[i].cnpj);
				printf(" Inscrição Estadual: %s",entidade[i].inscEstado);
				printf(" CEP: %s",entidade[i].cep);
				printf(" Endereço: %s",entidade[i].endereco);
				printf(" Bairro: %s",entidade[i].bairro);
				printf(" UF: %s",entidade[i].uf);
				printf(" Cidade: %s",entidade[i].cidade);
				printf(" Contato: %s",entidade[i].contato);
				printf(" E-mail: %s",entidade[i].email);
				printf(" Telefone: %s",entidade[i].telefone);
				printf("-------------------\n");		
						
			}
			else
			{
				system("cls");
				printf("\n Entidade não localizada!\n");
			}	
	}
	else
	{
		system("cls");
		printf("\n Entidade não localizada!\n");
	}
	
	Operacao3();
}
//Metodo alterar fabricante/fornecedor
void Alterar(){
	
	int i=0;
	
		system("cls");
	printf("\n .:ALTERAR FABRICANTE/FORNECEDOR:.\n\n");
	printf(" Digite a ID para pesquisar: ");
	scanf("%d",&i);
	ClnBuffer();
	
	if(entidade[i].ativo != 0 && entidade[i].ativo == 1)
	{
			if(i == i)
			{
				printf("\n-------------------\n");
				printf(" ID: %d\n",i);
				printf(" Nome Fantasia: %s",entidade[i].nomeFantasia);
				printf(" Razão Social: %s",entidade[i].razaoSocial);
				printf(" Tipo da Entidade: %s",entidade[i].tipoEntidade);
				printf(" CNPJ: %s",entidade[i].cnpj);
				printf(" Inscrição Estadual: %s",entidade[i].inscEstado);
				printf(" CEP: %s",entidade[i].cep);
				printf(" Endereço: %s",entidade[i].endereco);
				printf(" Bairro: %s",entidade[i].bairro);
				printf(" UF: %s",entidade[i].uf);
				printf(" Cidade: %s",entidade[i].cidade);
				printf(" Contato: %s",entidade[i].contato);
				printf(" E-mail: %s",entidade[i].email);
				printf(" Telefone: %s",entidade[i].telefone);
				printf("-------------------\n");
				
				printf("\n 1-Alterar nome fantasia\n 2-Alterar razão social\n 3-Alterar CNPJ\n 4- Alterar inscrição estadual");
				printf("\n 5-Alterar CEP\n 6-Alterar endereço\n 7-Alterar bairro\n 8-Alterar UF\n 9-Alterar cidade");
				printf("\n 10-Alterar contato\n 11-Alterar e-mail\n 12-Alterar telefone\n 13-Alterar tipo da entidade");
				printf("\n\n Opção: ");
				scanf("%d",&op);
				ClnBuffer();
					
					switch(op)
					{	
						case 1:
							printf("\n Nome fantasia: ");
							fgets(nomeFantasia,sizeof(nomeFantasia),stdin);
							ClnBuffer();
							strcpy(entidade[i].nomeFantasia,nomeFantasia);
							printf("\n Nome fantasia alterado com sucesso!\n");
						break;
						
						case 2:	
							printf("\n Razão social: ");
							fgets(razaoSocial,sizeof(razaoSocial),stdin);
							ClnBuffer();
							strcpy(entidade[i].razaoSocial,razaoSocial);
							printf("\n Razão social alterada com sucesso!\n");
						break;
						
						case 3:
							printf("\n CNPJ: ");
							fgets(cnpj,sizeof(cnpj),stdin);
							ClnBuffer();
							strcpy(entidade[i].cnpj,cnpj);
							printf("\n CNPJ alterado com sucesso!\n");
						break;
						
						case 4:
							printf("\n Inscrição estadual: ");
							fgets(inscEstado,sizeof(inscEstado),stdin);
							ClnBuffer();
							strcpy(entidade[i].inscEstado,inscEstado);
							printf("\n Inscrição estadual alterada com sucesso!\n");
						break;
						
						case 5:
							printf("\n CEP: ");
							fgets(cep,sizeof(cep),stdin);
							ClnBuffer();
							strcpy(entidade[i].cep,cep);
							printf("\n CEP alterado com sucesso!\n");
						break;
						
						case 6:
							printf("\n Endereço: ");
							fgets(endereco,sizeof(endereco),stdin);
							ClnBuffer();
							strcpy(entidade[i].endereco,endereco);
							printf("\n Endereço alterado com sucesso!\n");
						break;
						
						case 7:
							printf("\n Bairro: ");
							fgets(bairro,sizeof(bairro),stdin);
							ClnBuffer();
							strcpy(entidade[i].bairro,bairro);
							printf("\n Bairro alterado com sucesso!\n");
						break;
						
						case 8:
							printf("\n UF: ");
							fgets(uf,sizeof(uf),stdin);
							ClnBuffer();
							strcpy(entidade[i].uf,uf);
							printf("\n UF alterada com sucesso!\n");
						break;
						
						case 9:
							printf("\n Cidade: ");
							fgets(cidade,sizeof(cidade),stdin);
							ClnBuffer();
							strcpy(entidade[i].cidade,cidade);
							printf("\n Cidade alterada com sucesso!\n");
						break;
						
						case 10:
							printf("\n Contato: ");
							fgets(contato,sizeof(contato),stdin);
							ClnBuffer();
							strcpy(entidade[i].contato,contato);
							printf("\n Contato alterado com sucesso!\n");
						break;
						
						case 11:
							printf("\n E-mail: ");
							fgets(email,sizeof(email),stdin);
							ClnBuffer();
							strcpy(entidade[i].email,email);
							printf("\n E-mail alterado com sucesso!\n");
						break;
						
						case 12:
							printf("\n Telefone: ");
							fgets(telefone,sizeof(telefone),stdin);
							ClnBuffer();
							strcpy(entidade[i].telefone,telefone);
							printf("\n Telefone alterado com sucesso!\n");
						break;
						
						case 13:
							printf("\n Tipo da entidade: ");
							fgets(tipoEntidade,sizeof(tipoEntidade),stdin);
							ClnBuffer();
							strcpy(entidade[i].tipoEntidade,tipoEntidade);
							printf("\n Tipo da entidade alterada com sucesso!\n");
						break;	
						
						default:
							system("cls");
							printf("\n Opção Incorreta!\n");
							sleep(3);
					}
						
			}
			else
			{
				system("cls");
				printf("\n Entidade não localizada!\n");
			}	
	}
	else
	{
		system("cls");
		printf("\n Entidade não localizada!\n");
	}
	
	Operacao4();
	
}

//Metodo remover fabricante/fornecedor
void Remover(){
	
	int i=0;
		
		system("cls");
	printf("\n .:REMOVER FABRICANTE/FORNECEDOR:.\n");	
	
	printf("\n Digite a ID da entidade a ser removida: ");
	scanf("%d", &i);
	ClnBuffer();
		
		if(entidade[i].ativo == 1)
		{
			entidade[i].ativo = 0;
			printf("\n Entidade removida com sucesso!\n");
		}	
		else
		{
			system("cls");
			printf("\n ID inexistente!\n");
		}
	
	Operacao5();
			
}

//Metodo de criação de arquivo txt
void Exportartxt(){
	
	FILE *file; //Ponteiro file
	char texto[1000];
	int i;
	
		system("cls");
	printf("\n .:EXPORTAR PARA TXT:. \n");
	
	printf("\n 1-Exportar para txt\n 2-Visualizar informações do arquivo ");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
	printf("\n");
	

		switch(op)
		{
	  		case 1:	
				file = fopen("Arquivo\\FABRICANTE_FORNECEDOR.txt","a");
					if(file != NULL)
					{
						for(i=0; i<SIZE; i++)
						{
							if(entidade[i].ativo != 0 && entidade[i].ativo == 1)
							{
								fprintf(file,"\n--------------------------\n");
								fprintf(file," Nome Fantasia: %s",entidade[i].nomeFantasia);
								fprintf(file," Razão Social: %s",entidade[i].razaoSocial);
								fprintf(file," Tipo da Entidade: %s",entidade[i].tipoEntidade);
								fprintf(file," CNPJ: %s",entidade[i].cnpj);
								fprintf(file," Inscrição Estadual: %s",entidade[i].inscEstado);
								fprintf(file," CEP: %s",entidade[i].cep);
								fprintf(file," Endereço: %s",entidade[i].endereco);
								fprintf(file," Bairro: %s",entidade[i].bairro);
					     		fprintf(file," UF: %s",entidade[i].uf);
								fprintf(file," Cidade: %s",entidade[i].cidade);
								fprintf(file," Contato: %s",entidade[i].contato);
								fprintf(file," E-mail: %s",entidade[i].email);
								fprintf(file," Telefone: %s",entidade[i].telefone);
							}
						}
					}
					else
					{
						printf("\n Exportação não realizada!\n");
						sleep(3);
						ClnBuffer();
						Exportartxt();	
					}
				fclose(file);
				printf("\n Exportação realizada com sucesso!\n");	
			break;
			
			case 2:
				file = fopen("Arquivo\\FABRICANTE_FORNECEDOR.txt","r");
					if(file == NULL)
					{
						printf("\n Não foi possivel abrir o arquivo! \n");
						sleep(3);
						Exportartxt();
					}
					else
					{
						while(fgets(texto,1000,file) != NULL)
						{
							printf("%s",texto);
						}
					}
				fclose(file);
				printf("\n\n Fim da operação! \n\n");
				system("pause");
			break;

			default:
				printf("\n Opção invalida, operação não realizada!\n");
				sleep(3);
				Exportartxt();
		}	
						
	Operacao6();
}

//Metodo de operação n°1
Operacao(void){	
		
	int op;
		
	printf("\n 1-Repetir operação");
	printf("\n 2-Retornar ao menu");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
		
		if(op == 1)
		{
			Cadastrar();	
		}
		else if(op == 2)
		{
			Menu();
		}
		else
		{	
			printf("\n\n Opção invalida!\n Apenas é possivel selecionar de 1 a 2.\n");
		    sleep(3);
		    system("cls");
		   	Operacao();
		}				
}

//Metodo de operação n°2
Operacao2(void){
		
	int op;
		
	printf("\n\n 1-Repetir operação");
	printf("\n 2-Retornar ao menu");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
		
		if(op == 1)
		{
			Listar();	
		}
		else if(op == 2)
		{
			Menu();
		}
		else
		{	
			printf("\n\n Opção invalida!\n Apenas é possivel selecionar de 1 a 2.\n");
		    sleep(3);
		    system("cls");
		   	Operacao2();
		}				
}

//Metodo de operação n°3
Operacao3(void){
	
	int op;
		
	printf("\n 1-Repetir operação");
	printf("\n 2-Retornar ao menu");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
		
		if(op == 1)
		{
			Consultar();	
		}
		else if(op == 2)
		{
			Menu();
		}
		else
		{	
			printf("\n\n Opção invalida!\n Apenas é possivel selecionar de 1 a 2.\n");
		    sleep(3);
		    system("cls");
		   	Operacao3();
		}
}

//Metodo de operação n°4
Operacao4(void){
	
	int op;
		
	printf("\n 1-Repetir operação");
	printf("\n 2-Retornar ao menu");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
		
		if(op == 1)
		{
			Alterar();	
		}
		else if(op == 2)
		{
			Menu();
		}
		else
		{	
			printf("\n\n Opção invalida!\n Apenas é possivel selecionar de 1 a 2.\n");
		    sleep(3);
		    system("cls");
		   	Operacao4();
		}				
}

//Metodo de operação n°5
Operacao5(void){
	
	int op;
		
	printf("\n 1-Repetir operação");
	printf("\n 2-Retornar ao menu");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
		
		if(op == 1)
		{
			Remover();	
		}
		else if(op == 2)
		{
			Menu();
		}
		else
		{	
			printf("\n\n Opção invalida!\n Apenas é possivel selecionar de 1 a 2.\n");
		    sleep(3);
		    system("cls");
		   	Operacao5();
		}				
}

//Metodo de operação n°6
Operacao6(){
	
	int op;
	
	printf("\n 1-Repetir operação");
	printf("\n 2-Retornar ao menu");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
		
	if(op == 1)
		{
			Exportartxt();	
		}
		else if(op == 2)
		{
			Menu();
		}
		else
		{	
			printf("\n\n Opção invalida!\n Apenas é possivel selecionar de 1 a 2.\n");
		    sleep(3);
		    system("cls");
		   	Operacao6();
		}				
}

//Metodo Sair
void Sair(){
	
	int op;
		
		system("cls");
	printf(" Deseja realmente sair?\n");
	printf("\n 1-Sim \t2-Não");
	printf("\n\n Opção: ");
	scanf("%d",&op);
	ClnBuffer();
	
		if(op == 1)
		{
			system("exit");
		}
		else if(op == 2)
		{
			Menu();
		}
		else
		{
			printf("\n Opção invalida!\n");
		    sleep(3);
		    Sair();
		}
}
