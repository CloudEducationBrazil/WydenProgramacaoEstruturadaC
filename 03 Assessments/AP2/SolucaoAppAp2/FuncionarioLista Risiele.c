#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 100
#define TAMCHAR 30

typedef int TIPOCHAVE; //a chave da lista é um tipo inteiro

typedef struct{
    TIPOCHAVE matricula;  //matricula do funcionario
   	char nome[TAMCHAR]; //nome do funcionarios
    char endereco[TAMCHAR]; //endx	ereco do funcionario
	char sexo; //sexo M ou F
	char cargo[TAMCHAR]; // cargo que o funcionario trabalho
	int cargah; //carga horaria diaria do funcionario
	int tel; //telefone do funcionario
	float salario;
} FUNCIONARIO;

typedef struct{
    FUNCIONARIO vetor[TAM+1];  //lista sequencial de tipo funcionario
    int nroElem;  //variavel para contar o numero de elementos
} LISTA;

FILE *ArqFuncionarios;

void criarLista(LISTA *l);     //funçao que cria a lista
void reiniciarLista(LISTA *l);  //funçao que reinicia lista do 0

void inserirFuncionario(LISTA *l, FUNCIONARIO func);  //fimçao de inserir funcionario na lista
void imprimirFuncionarios(LISTA *l);  //funçao que mostra todos os funcionario na lista
void imprimirMatricula(LISTA *l, TIPOCHAVE matricula); //funçao que imprime funcionario de acordo com a matricula
void deletarFuncionario(LISTA *l, int posicao); //funçao que deleta o funcionario
void alterarFuncionario(LISTA *l, TIPOCHAVE matricula); //funçao que altera informaçao de um funcionario

int main(){

	LISTA l;
    FUNCIONARIO func;	//func é do tipo funcionario e guarda informaçoes e a chave(mat)
    TIPOCHAVE matricula;
    int opcao=0, posicao;
    criarLista(&l);
    
	do{
       	system("cls || clear");
       	
		printf("Seja bem vindo!\n");
        printf("Selecione uma das opcoes abaixo:\n\n");
        printf("1 - Exibir Funcionarios\n");
        printf("2 - Buscar Funcionario\n");
        printf("3 - Alterar Funcionario\n");
        printf("4 - Inserir Funcionario\n");
        printf("5 - Excluir Funcionario\n");
        printf("6 - Reiniciar Lista de Funcionario\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&opcao);
        
        switch(opcao){
            case 1:{
            	system("cls || clear");
      			imprimirFuncionarios(&l);
				break;
			}
			case 2:{
				system("cls || clear");
				printf("Informe a Matricula do Funcionario que deseja Buscar: ");
				scanf("%d",&matricula);
				imprimirMatricula(&l,matricula);
				break;
			}
			case 3:{
				system("cls || clear");
				printf("Informe a Matricula do Funcionario que deseja Alterar: ");
				scanf("%d",&matricula);
				alterarFuncionario(&l,matricula);

				break;
			}
			case 4:{
				system("cls || clear");
        		printf("Informe a Matricula:\n");
        		scanf("%d",&func.matricula);
        		
        		printf("Informe o Nome do Funcionario:\n");
        		fflush(stdin);
        		gets(func.nome);
        		
        		printf("Informe o Endereco do Funcionario:\n");
        		fflush(stdin);
        		gets(func.endereco);
        		
        		printf("Informe o Sexo (M/F) do Funcionario:\n");
        		fflush(stdin);
        		scanf("%c", &func.sexo);
        		
        		printf("Informe o Cargo do Funcionario:\n");
        		fflush(stdin);
        		gets(func.cargo);
        		
        		printf("Informe a Carga Horaria do Funcionario:\n");
        		scanf("%d",&func.cargah);
        		
        		printf("Informe o Telefone do Funcionario:\n");
        		scanf("%d",&func.tel);
        		
        		printf("Informe o Salario do Funcionario:\n");
        		scanf("%f",&func.salario);
        		
        		fprintf(ArqFuncionarios, "%d\nNome:%s\nEndereco:%s\nSexo:%c\nCargo:%s\nCarga Horaria:%d\nTelefone:%d\nSalario:%f", 
				func.matricula, func.nome, func.endereco, func.sexo, func.cargo, func.cargah, func.tel, func.salario);
        		fprintf(ArqFuncionarios,"\n____________________________________\n");
        		
				inserirFuncionario(&l,func);
				break;
			}
			case 5:{
				system("cls || clear");
				printf("Informe a Matricula: ");
				scanf("%d",&matricula);
				deletarFuncionario(&l,matricula);
				break;
			}
			case 6: {
				reiniciarLista(&l);
				break;
			}
			case 0:{
				exit(1);
				break;
			}
            default: {
            	system("cls || clear");
                printf("Opcao Invalida!\nVoce Voltara ao Menu!\n");
                system("pause");
                break;
            }
        }
    }while(opcao!=0);
    
    fclose(ArqFuncionarios);
    
	return 0;
}
void criarLista(LISTA *l){ //função que cria lista de fncionarios
    l->nroElem = 0;        //lista criada com 0 elementos
    ArqFuncionarios = fopen("ListaFuncionarios.txt", "wt"); //criacao do arquivo txt em formato texto
    if ( ArqFuncionarios == NULL ){
    	printf("Erro na criação do arquivo");
	}
	fclose(ArqFuncionarios);
}

void reiniciarLista(LISTA *l){  //reinicia lista de funcionarios
    l->nroElem = 0;				//zera o numero de elementos
    system("cls || clear");
    printf("Reiniciado com Sucesso!\n");
    system("pause");
    ArqFuncionarios = fopen("ListaFuncionarios.txt", "w"); 
    if ( ArqFuncionarios == NULL ){
    	printf("Erro na criação do arquivo");
	}
	fprintf(ArqFuncionarios,"\n");
	fclose(ArqFuncionarios);
}

void inserirFuncionario(LISTA *l, FUNCIONARIO func){  //inseri funcionario na lista
    l->vetor[l->nroElem] = func; //no vetor de tipo fucionarios, atribui funcionario a posiçao disponivel
    l->nroElem = l->nroElem+1; //passa para e proxima posiçao da lista incrementando o num de elementos
    system("cls || clear");
    printf("Sucesso!\n");
    system("pause");
}
    

void imprimirMatricula(LISTA *l, TIPOCHAVE matricula){  //imprime funcionario por matricula
	int i=0, verificador=0;  	//verifica se encontrou a chave na lista	
	system("cls || clear");
	for(i=0;i<l->nroElem;i++){  
		if(matricula==l->vetor[i].matricula){	//se a chave passada como parametro for igual a do funcionario que foi passado
			//imprimi informaçoes do funcionario
			printf("%d - %d \n",i,l->vetor[i].matricula); 
        	printf("Nome: %s\n",l->vetor[i].nome); 
        	printf("Endereco: %s\n", l->vetor[i].endereco);
        	printf("Sexo: %c\n",l->vetor[i].sexo);
        	printf("Cargo: %s\n",l->vetor[i].cargo);
        	printf("Carga Horaria: %d\n",l->vetor[i].cargah);
        	printf("Telefone: %d\n",l->vetor[i].tel);
        	printf("Salario: %f\n",l->vetor[i].salario);
			verificador=1;		//muda o verificador se encontrado o funcionario
			break;
		}	
	}
	if(verificador==0){  //se verificador igual a 0, não tem o funcionario
		printf("Funcionario nao encontrado!\n");
		system("pause");
	}
	system("pause");
}

void imprimirFuncionarios(LISTA *l){ //imprimi a lista de funcionarios
	int i;
	if(l->nroElem==0){
		printf("Lista Vazia!\n");
		system("pause");
	}else{
	    printf("Funcionarios:\n");
	    printf("\n____________________________________\n");
    	for(i=0; i<l->nroElem;i++){
        	printf("%d - %d \n",i,l->vetor[i].matricula); //imprimi matricula do funcionar
        	printf("Nome: %s\n",l->vetor[i].nome);
        	printf("Endereco: %s\n", l->vetor[i].endereco);
        	printf("Sexo: %c\n",l->vetor[i].sexo);
        	printf("Cargo: %s\n",l->vetor[i].cargo);
        	printf("Carga Horaria: %d\n",l->vetor[i].cargah);
        	printf("Telefone: %d\n",l->vetor[i].tel);
        	printf("Salario: %f\n",l->vetor[i].salario);
        	printf("\n____________________________________\n");
    	}
		system("pause");
	}
}

void deletarFuncionario(LISTA *l, TIPOCHAVE matricula){ //deleta funcionario
	int i, posicao, verificador = 0;
	for(i=0;i<l->nroElem;i++){
		if(matricula==l->vetor[i].matricula){
			posicao = i;
			verificador = 1;
			break;
		}
	}
	if(posicao<l->nroElem){
		if(posicao==(l->nroElem-1)){   //verifica se a posição a ser deletada é o ultimo elemento
			l->nroElem = l->nroElem-1; //se verdade, apenas decrementa o número de elementos
		}else{
			for(i=posicao;i<l->nroElem-1;i++){ //se falso, copia os elementos que sucedem para a posição anterior a partir da posição
				l->vetor[i] = l->vetor[i+1];
			}
			l->nroElem = l->nroElem-1;   //Decrementa o número de elementos	
		}
		system("cls || clear");
		printf("Sucesso!\n");
		system("pause");
	}
	if(verificador==0){
		system("cls || clear");
		printf("Funcionario nao existe!\n");
		system("pause");
	}
}

void alterarFuncionario(LISTA *l ,TIPOCHAVE matricula){
	int i, opc, verificador=0;
	for(i=0;i<l->nroElem;i++){
		if(matricula==l->vetor[i].matricula){
			imprimirMatricula(l, matricula);
			printf("\nQual Informacao Deseja Alterar?\n\n");
			printf("DIGITE\n0-NOME\n1-ENDERECO\n2-SEXO\n3-CARGO\n4-CARGA HORARIA\n5-TELEFONE\n6-SALARIO\n");
			printf("Opcao:\n");
			scanf("%d",&opc);
			switch(opc){
				case 0:{
					printf("DIGITE O NOVO NOME\n");
					fflush(stdin);
					gets(l->vetor[i].nome);
					break;
				}
				case 1:{
					printf("DIGITE O NOVO ENDERCO\n");
					fflush(stdin);
					gets(l->vetor[i].endereco);
					break;
				}
				case 2:{
					printf("DIGITE O NOVO SEXO(M/F)\n");
					fflush(stdin);
					scanf("%c", &l->vetor[i].sexo);
					break;
				}
				case 3:{
					printf("DIGITE O NOVO CARGO\n");
					fflush(stdin);
					gets(l->vetor[i].cargo);
					break;
				}
				case 4:{
					printf("DIGITE A NOVA CARGA HORARIA\n");
					scanf("%d", &l->vetor[i].cargah);
					break;
				}
				case 5:{
					printf("DIGITE O NOVO TELEFONE\n");
					scanf("%d", &l->vetor[i].tel);
					break;
				}
				case 6:{
					printf("DIGITE O NOVO SALARIO\n");
					scanf("%f", &l->vetor[i].salario);
					break;
				}
				
					
			}
			verificador=1;
			break;
		}
	} 
	system("cls || clear");
	if(verificador==0){
		printf("Funcionario nao existe!\n");
	} else {
		printf("Funcionario Alterado com Sucesso\n");
	}		
	system("pause");

}
