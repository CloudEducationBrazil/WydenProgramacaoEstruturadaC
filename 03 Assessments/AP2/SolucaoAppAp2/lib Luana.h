#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXALUNO 100

typedef struct aluno{
	char nome_aluno[100];
	char matricula[100];
	char cpf[100];
	char rg[100];
	char curso[100];
	char ano_ingresso[100];
	char turno[100];
}Aluno;


//definicao da estrutura de armazenamento
Aluno lista_alunos[MAXALUNO];
Aluno aux_lista_alunos[MAXALUNO];

//assinatura das funcoes para serem executadas posteriormente
void menu();
void cadastrar();
void listar();
void editar();
void excluir();
void inicializaSistema();


void inicializaSistema(){
	
		int contador = 0;
		for(contador;contador<MAXALUNO;contador++){
			strcpy(lista_alunos[contador].nome_aluno,"");	
			strcpy(lista_alunos[contador].matricula,"");	
			strcpy(lista_alunos[contador].cpf,"");
			strcpy(lista_alunos[contador].rg,"");	
			strcpy(lista_alunos[contador].curso,"");	
			strcpy(lista_alunos[contador].ano_ingresso,"");	
		}    	
		menu();
}
// funcao que vai executar o menu do meu sistema e ela é chamada no programa principal (main)
void menu(){
	
	printf("\n##########   M E N U   #########\n\n");
	char opcao;
	printf("selecione a opcao desejada:\n\n");
	printf("[1] cadastrar\n");
	printf("[2] listar\n");
	printf("[3] editar\n");
	printf("[4] excluir\n");
	printf("[5] exportar para txt\n");
	printf("[6] importar txt\n");
	printf("[0] sair\n");
	scanf("%c",&opcao);
	//getchar() para remover a tecla enter do bufer quando a opcao for invalida
	//getchar();
	system("cls");

	switch(opcao){
		case '1': cadastrar();
			break;
		case '2': listar();
			break;
		case '3': editar();
			break;
		case '4': excluir();
		break;	
		case '5': salvar(lista_alunos);
				  printf("\nEXPORTACAO REALIZADA COM SUCESSO\n");
				  system("pause");
				  menu();
		break;	
		case '6': carrega(lista_alunos);
			printf("\nIMPORTACAO REALIZADA COM SUCESSO\n");
			system("pause");
		menu();
		break;
		case '0': 
			printf("Saindo....");
			system("exit");
			break;
		default:
			menu();
			break;
	}
}

void cadastrar(){
	printf("\n##########   CADASTRO DE ALUNO   #########\n\n");
	//percorre  o vetor até nome_aluno ser igual a "0"
	//quando o vetor for zero, vai salvar os dados do aluno
	//solicitar a digitacao dos dados (mostrar na tela e ler do teclado. use o gets()
	int contador = 0;	
	int cadastrado=0; // Fleag para saber se o aluno foi cadastrado ou não (0 é não e 1 é sim)
	
	for(contador;contador<MAXALUNO && cadastrado==0; contador++){
		if((strcmp(lista_alunos[contador].nome_aluno,"")==0)){
			getchar();
			printf("\nINFORME O NOME DO ALUNO:\n");
			gets(lista_alunos[contador].nome_aluno);
			printf("\nINFORME A MATRICULA DO ALUNO:\n");
			gets(lista_alunos[contador].matricula);
			printf("\nINFORME O CPF DO ALUNO:\n");
			gets(lista_alunos[contador].cpf);
			printf("\nINFORME O RG DO ALUNO:\n");
			gets(lista_alunos[contador].rg);
			printf("\nINFORME O ANO DE INGRESSO DO ALUNO:\n");
			gets(lista_alunos[contador].curso);
			printf("\nINFORME O TURNO DO ALUNO:\n");
			gets(lista_alunos[contador].ano_ingresso);
			cadastrado=1;
		}
    }
    
    if (contador==MAXALUNO & cadastrado==0){
    	printf("\n O ESPACO DE ARMAZENAMENTO ESTA CHEIO:\n");
    	getchar();
	}
	menu(); // Após o cadastro ficar ok, ele direciona o usuário para o menu
	
}
/*
A função do listar é para saber a lista dos dados que foram cadastrados
*/
void listar(){
	printf("\n##########  LISTA DE ALUNOS   #########\n\n");
	int contador = 0;
	for(contador;contador<MAXALUNO && (!strcmp(lista_alunos[contador].nome_aluno,"")==0);contador++){
		printf("ID do aluno:\t %d\n",contador+1);	
		printf("NOME:\t\t %s\n",lista_alunos[contador].nome_aluno);	
		printf("MATRICULA:\t %s\n",lista_alunos[contador].matricula);	
		printf("CPF:\t\t %s\n",lista_alunos[contador].cpf);	
		printf("RG:\t\t %s\n",lista_alunos[contador].rg);	
		printf("CURSO:\t\t %s\n",lista_alunos[contador].curso);
		printf("ANO DE INGRESSO: %s\n",lista_alunos[contador].ano_ingresso);					
		printf("\n___________________________________\n");
	}
	system("pause");
	menu();	
}
/*
A função do editar funciona a partir do ID que se quer mudar no cadastro
O ID nesta modelagem é representado pelo índice do vetor+1
*/
void editar(){
	printf("\n##########   EDICAO DE CADASTRO    #########\n\n");
	int id_aluno;	
	int opc;
	
		// Vai informar o ID do aluno
	printf("\nINFORME O ID DO ALUNO:\n");
	scanf("%d", &id_aluno);
	id_aluno = id_aluno-1; // Vai informar o ID do aluno - 1 para a posição do vetor
	if (id_aluno>=MAXALUNO || strcmp(lista_alunos[id_aluno].nome_aluno,"")==0 ){
		system("cls");
		printf("\nESSE CADASTRO NAO EXISTE:\n");
		system("pause");
		menu();
	
	} else {
	
	//Vai mostrar na tela os dados do ID informado
	printf("ID do aluno:\t\t%d\n",id_aluno+1);	
	printf("NOME:\t\t %s\n",lista_alunos[id_aluno].nome_aluno);	
	printf("MATRICULA:\t\t %s\n",lista_alunos[id_aluno].matricula);	
	printf("CPF:\t\t %s\n",lista_alunos[id_aluno].cpf);	
	printf("RG:\t\t %s\n",lista_alunos[id_aluno].rg);	
	printf("CURSO:\t\t %s\n",lista_alunos[id_aluno].curso);
	printf("ANO DE INGRESSO:\t\t %s\n",lista_alunos[id_aluno].ano_ingresso);		
	
	printf("[1] atualizar\n");
	printf("[2] informar outro usuario\n");
	printf("[3] voltar para o menu\n");
	scanf("%d",&opc);
	
// É fornecido para o usuário o menu, caso ele digita uma funcao incorreta ou desista de editar

	switch(opc){
		case 1: 
			// Vai receber as novas informações
			printf("\nINFORME O NOME DO ALUNO:\n");
			getchar();
			gets(lista_alunos[id_aluno].nome_aluno);
			printf("\nINFORME A MATRICULA DO ALUNO:\n");
			gets(lista_alunos[id_aluno].matricula);
			printf("\nINFORME O CPF DO ALUNO:\n");
			gets(lista_alunos[id_aluno].cpf);
			printf("\nINFORME O RG DO ALUNO:\n");
			gets(lista_alunos[id_aluno].rg);
			printf("\nINFORME O ANO DE INGRESSO DO ALUNO:\n");
			gets(lista_alunos[id_aluno].curso);
			printf("\nINFORME O TURNO DO ALUNO:\n");
			gets(lista_alunos[id_aluno].ano_ingresso);
			
			printf("\nSEUS DADOS FORAM ATUALIZADOS:\n");
		
			printf("ID do aluno:\t\t%d\n",id_aluno+1);	
			printf("NOME:\t\t %s\n",lista_alunos[id_aluno].nome_aluno);	
			printf("MATRICULA:\t\t %s\n",lista_alunos[id_aluno].matricula);	
			printf("CPF:\t\t %s\n",lista_alunos[id_aluno].cpf);	
			printf("RG:\t\t %s\n",lista_alunos[id_aluno].rg);	
			printf("CURSO:\t\t %s\n",lista_alunos[id_aluno].curso);
			printf("ANO DE INGRESSO:\t\t %s\n",lista_alunos[id_aluno].ano_ingresso);			
			system("pause");
			menu();
			break;
		case 2: editar();
			break;
		default:
			system("pause");
			menu();
			break;
		}
	}
}
void excluir(){
	printf("\n##########   EXCLUSAO DE CADASTRO   #########\n\n");
	
	int id_aluno;	
	int opc;
	
		// Vai informar o ID do aluno
	printf("\nINFORME O ID DO ALUNO:\n");
	scanf("%d", &id_aluno);
	id_aluno = id_aluno-1; // Vai informar o ID do aluno - 1 para a posição do vetor
	if (id_aluno>=MAXALUNO || strcmp(lista_alunos[id_aluno].nome_aluno,"0")==0 ){
		system("cls");
		printf("\nESSE CADASTRO NAO EXISTE:\n");
		system("pause");
		menu();
	
	} else {
	
	//Vai mostrar na tela os dados do ID informado
	printf("ID do aluno:\t\t%d\n",id_aluno+1);	
	printf("NOME:\t\t %s\n",lista_alunos[id_aluno].nome_aluno);	
	printf("MATRICULA:\t\t %s\n",lista_alunos[id_aluno].matricula);	
	printf("CPF:\t\t %s\n",lista_alunos[id_aluno].cpf);	
	printf("RG:\t\t %s\n",lista_alunos[id_aluno].rg);	
	printf("CURSO:\t\t %s\n",lista_alunos[id_aluno].curso);
	printf("ANO DE INGRESSO:\t\t %s\n",lista_alunos[id_aluno].ano_ingresso);		
	
	printf("[1] excluir\n");
	printf("[2] informar outro usuario\n");
	printf("[3] voltar para o menu\n");
	scanf("%d",&opc);
	
// É fornecido para o usuário o menu, caso ele digita uma funcao incorreta ou desista de editar

	switch(opc){
		case 1: 
			// Vai zerar todos os dados para permitir que a posicao seja utilizada
			strcpy(lista_alunos[id_aluno].nome_aluno,"0");	
			strcpy(lista_alunos[id_aluno].matricula,"0");	
			strcpy(lista_alunos[id_aluno].cpf,"0");
			strcpy(lista_alunos[id_aluno].rg,"0");	
			strcpy(lista_alunos[id_aluno].curso,"0");	
			strcpy(lista_alunos[id_aluno].ano_ingresso,"0");
										
			printf("\nSEUS DADOS FORAM EXCLUIDOS:\n");
			system("pause");
			menu();
			break;
			
		case 2: excluir();
			break;
		default:
			menu();
			break;
		}
	}
		system("pause");
		menu();
}


