#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct{
	char nome[50];
	char endereco[50];
	char telefone[15];
	int valor_transporte;
} transportadoras;

//Diego Eduardo Lima Santos - 181050811
transportadoras vet[TAM];
int posicao_livre = 0;

void cadastrar();
void listar();
void editar();
void excluir();
void salvar();
void ler();
void inicializarEstrutura();
void pesquisar();

int main(void){
	
	int opcao = 0;
	int op_ed = -1;
	int op_ex = -1;
	int op_pesq = -1;
	inicializarEstrutura();
	ler();
	while(opcao!=8){
		
		
		printf("| CADASTRO DE TRANSPORTADORAS---\n");		
		printf("| MENU----\n");
		printf("| 1 - Listar\n");
		printf("| 2 - Cadastrar\n");
		printf("| 3 - Editar\n");
		printf("| 4 - Excluir\n");
		printf("| 5 - Pesquisar\n");
		printf("| 6 - Salvar\n");
		printf("| 7 - Carregar\n");
		printf("| 8 - Sair\n");
				
		printf("Escolha uma opcao:");
		fflush(stdin);
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				listar();
				printf("Fim da listagem.\n");
				break;
			case 2:
				cadastrar();
				printf("Cadastro efetuado.\n");
				break;
			case 3:
				system("cls");
				listar();
				printf("Digite qual codigo da transportadora vai editar:\n");
				fflush(stdin);
				scanf("%d", &op_ed);
					if(op_ed>=1 && op_ed<=TAM){
						editar(op_ed-1);							
					}else{
						printf("Opcao invalida!\n");
					}
				
				break;
			
			case 4:
				system("cls");
				listar();
				printf("Digite qual transportadora excluir:\n");
				fflush(stdin);
				scanf("%d", &op_ex);
				
				if(op_ex>=1 && op_ex<=TAM){
					excluir(op_ex-1);
				}else{
					printf("Opcao invalida!");
				}
				break;
				
			case 5:
				printf("Digite o codigo da Transportadora:\n");
				fflush(stdin);
				scanf("%d", &op_pesq);				
				if(op_pesq>=1 && op_pesq<=TAM){
					pesquisar(op_pesq-1);
				}else{
					printf("Opcao invalida!");
				}
				break;
				
			case 6: 
				salvar();
				printf("Arquivo salvo.\n");
				break;
				
			case 7:
				//carregar
				ler();
				printf("Arquivo carregado.\n");
				break;
				
			case 8:
				//Sair
				salvar();
				printf("O programa sera encerrado... Fui!!\n");
				break;
				
			default:
				printf("opcao invalida!\n");
		}
		
		fflush(stdin);
		getchar();
		//system("pause");
		system("cls");
	}
	

	
	return 1;
}


void cadastrar(){
	
	
	printf("Digite o nome da Transportadora:\n");
	fflush(stdin);
	fgets(vet[posicao_livre].nome,50,stdin);
	
	printf("Digite o Endereco:\n");
	fflush(stdin);
	fgets(vet[posicao_livre].endereco,50,stdin);
	
	printf("Digite o telefone:\n");
	fflush(stdin);
	fgets(vet[posicao_livre].telefone,15,stdin);
	
	printf("Digite o valor do frete:\n");
	fflush(stdin);
	scanf("%d", &vet[posicao_livre].valor_transporte);
	
	
	posicao_livre++;

	
}



void inicializarEstrutura(){
	
	int i;
	for( i = 0; i<TAM; i++){		
			vet[i].valor_transporte = 0;
	}
	
}



void listar(){
	int i;
	for(i = 0; i<TAM; i++){
		if(vet[i].valor_transporte>0){
			printf("----------------------------------------\n");
			printf("|         Cod: %d\n", i+1);
			printf("|        Nome: %s", vet[i].nome);
			printf("|    Endereco: %s", vet[i].endereco);
			printf("|    Telefone: %s", vet[i].telefone);
			printf("|    R$ Frete: %d\n", vet[i].valor_transporte);	
			printf("----------------------------------------\n");
		}
	}
	
}

void pesquisar(int pos){

	if(vet[pos].valor_transporte>0){
		printf("----------------------------------------\n");
		printf("|         Cod: %d\n", pos+1);
		printf("|        Nome: %s", vet[pos].nome);
		printf("|    Endereco: %s", vet[pos].endereco);
		printf("|    Telefone: %s", vet[pos].telefone);
		printf("|    R$ Frete: %d\n", vet[pos].valor_transporte);	
		printf("----------------------------------------\n");
	}
	else{
		printf("Codigo de transportadora invalido");
	}
}

void editar(int pos){
	int opcao = 0;
	
	
	if(vet[pos].valor_transporte>0){
		
	printf("Escolha a opcao que voce quer editar:\n");
	printf("1-Nome , 2-Endereco, 3-Telefone, 4-Valor do frete\n");
	fflush(stdin);
	scanf("%d",&opcao);
	
	
	switch(opcao){
		case 1:
			printf("Digite o novo nome:\n");
			fflush(stdin);
			fgets(vet[pos].nome,50,stdin);
			break;
		case 2:
			printf("Digite o novo endereco:\n");
			fflush(stdin);
			fgets(vet[pos].endereco,50,stdin);
			break;
			
		case 3: 
			printf("Digite o novo telefone:\n");
			fflush(stdin);
			fgets(vet[pos].telefone,15,stdin);
			break;
		
		case 4:
			printf("Digite o novo valor do frete:\n");
			fflush(stdin);
			scanf("%d", &vet[pos].valor_transporte);
			break;
		
		default: break;
	}
	
	printf("Edicao efetuada.\n");
	
	}else{
		printf("Edicao invalida!\n");
	}
	
}

void excluir(int pos){
	
	if(vet[pos].valor_transporte>0){
		vet[pos].valor_transporte = 0;
		printf("Exclusao efetuada.\n");	
	}else{
		printf("Exlusao invalida!\n");
	}
	
}


void salvar(){
	int i;
	FILE *arq;
	
	arq = fopen("cadastro.txt","w");
	
	for(i = 0; i<TAM; i++){
		if(vet[i].valor_transporte>0){
			
			fprintf(arq,"%s", vet[i].nome);
			fprintf(arq,"%s", vet[i].endereco);
			fprintf(arq,"%s", vet[i].telefone);
			fprintf(arq,"%d\n", vet[i].valor_transporte);
			fprintf(arq,"%s\n", "_");
		}
		
	}
	
	fclose(arq);
}


void ler(){
	
	int i=0;
	FILE *arq;
	char marcador[50];

	arq = fopen("cadastro.txt","r");
	
	if(arq == NULL){
		printf("Erro ao abrir arquivo!\n");
	}else{
		
		
		while(!feof(arq)){

			fgets(vet[i].nome,50,arq);
			fgets(vet[i].endereco,50,arq);
			fgets(vet[i].telefone,50,arq);	
			fscanf(arq,"%d\n", &vet[i].valor_transporte);
			fgets(marcador,50,arq);
			i++;
			
		}
		
	}
	
	fclose(arq);
	posicao_livre = i;
	
}

