#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define TAM 200

char codigo[TAM][40];
char nome[TAM][40];
char raca[TAM][40];
char idade[TAM][40];
char Peso[TAM][40];
char vetor6[TAM][40];
int op,i,num;    
void excluir();
void cadastro(); 
void pesquisaCod();  
void lista();  
void alterar();
void salvar();
void carregar();
int main(){


	do{
		system("cls");
		printf("  CANIL  \n");
   		printf("\n");
   		printf(" Seja Bem vindo(a) \n ");
		printf("1 - Cadastrar cachorro\n");
		printf(" 2 - Pesquisar  pelo Codigo\n");
    	printf(" 3 - Listar cachorro\n");
    	printf(" 4 - Alterar Dados \n");
   		printf(" 5 - Excluir Dados \n");
   		printf(" 6 - Salvar Dados \n");
   		printf(" 7 - Carregar Dados \n");
   		printf(" 8 - Sair\n");
		printf(" \nSelecione uma opcao por favor: ");
    	scanf("%d", &op);
    		
    	switch(op){
    		case 1:
    			cadastro();
    		break;
			case 2:
				pesquisaCod();
			break;
			case 3:
				lista();
			break;
			case 4:
				alterar();
			break;
			case 5:
				excluir();
			break;	
			case 6:
				salvar();
			break;	
			case 7:
				carregar();	
			break;		
			case 8:
				system("exit");
			break;
			default:
				printf("Opcao Invalida");	
				getchar();
				getchar();
			break;			
		}	
	}while(op!=8);
}
void lista(){ // LISTA
	system("cls");
			
			for(i=1;i<=num;i++){
				system("cls");
				printf("\n  Exibindo Cadastros %d  ", i);
				printf("\ncodigo :%s\n nome :%s\n raça :%s\n idade :%s\n Peso :%s\n ", codigo[i],  nome[i], raca[i], idade[i], Peso[i]);
				system("pause");
			}
	getchar();
	getchar();
}
void cadastro(){ // CADASTRO
			system ("cls");
    		printf("\n Quantos Cadastros Deseja Realizar? ");
    		scanf("%d", &num);
    		
			for(i=1;i<=num;i++){
    		system("cls");
    		printf("\n\n\t\t\t    Iniciando Cadastro \n");
    		printf("\n Digite o codigo 3 numeros: ");
    		fflush(stdin);
    		scanf("%s",&codigo[i]);
        	printf("\nDigite o nome : ");
        	fflush(stdin);
        	scanf("%s",&nome[i]);
        	printf("\nDigite a raça : ");
        	fflush(stdin);
        	scanf("%s",&raca[i]);
        	printf("\nDigite a idade : ");
        	fflush(stdin);
        	scanf("%s",&idade[i]);
        	printf("\nDigite a Peso : ");
        	fflush(stdin);
        	scanf("%s",&Peso[i]);

        }
} // Fim do Cadastro

void pesquisaCod(){ //Pesquisa por Codigo
	char codPesquisa[50];
	int i;
			do{			
				system("cls");
				printf("Digite o codigo :");
				scanf("%s", &codPesquisa);
				for (i=0;i<=num;i++){
					if(strcmp(codigo[i], codPesquisa)==0){
						printf("\ncodigo :%s\n nome :%s\n raça :%s\n idade :%s\n Peso :%s\n ", codigo[i],  nome[i], raca[i], idade[i], Peso[i]);
						}
					}
					break;
		
				}while(op==1);
				getchar();
				getchar();
}
void alterar(){ // ALTERAR
	char codPesquisa[50];
	int i,op2;
	
		system("cls");
		printf("Insira o codigo :");
		scanf("%s", &codPesquisa);
		for (i=0;i<=num;i++){
			if(strcmp(codigo[i], codPesquisa)==0){
				system("cls");
				printf("\n  Alterar Cadastro %d  ",i);
				printf("\n 1 - Alterar o nome");
				printf("\n 2 - Alterar a especie");
				printf("\n 3 - Alterar a idade");
				printf("\n 4 - Alterar o vetor5\n\n");
				printf("Selecione uma das opcoes por favor \n");
				scanf("%d", &op2);
					
				switch(op2){
					
					case 1 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o nome : ");
						fflush(stdin);
						scanf("%[^\n]s",&nome[i]);
						printf("\n Nova vetor: %s \n\n",&nome[i]);
						system("pause");
						
						break;
					
					case 2 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a raca: ");
						fflush(stdin);
						scanf("%[^\n]s",&raca[i]);
						printf("\n Nova raça: %s \n\n",&raca[i]);
						system("pause");
						
						break;
					
					case 3 :
					
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a idade: ");
						fflush(stdin);
						scanf("%[^\n]s",&idade[i]);
						printf("\n Novo idade: %s \n\n",&idade[i]);
						system("pause");
						
						break;
						
					case 4 :
					    
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a Peso: ");
						fflush(stdin);
						scanf("%[^\n]d",&Peso[i]);
						printf("\n Nova Peso: %s \n\n",&Peso[i]);
						system("pause");
				}
			}
		}
	
}

void excluir(){ // EXCLUIR
	char codPesquisa[50];
	int i,op3;
	
		system("cls");
		printf("Insira o codigo :");
		scanf("%s", &codPesquisa);
		for (i=0;i<=num;i++){
			if(strcmp(codigo[i], codPesquisa)==0){
				printf("\n  Excluir Cadastro %d  ",i);
				printf("\n 1 - Excluir o nome");
				printf("\n 2 - Excluir a raça");
				printf("\n 3 - Excluir a idade");
				printf("\n 4 - Excluir o Peso");
				printf(" Selecione um opcao por favor");
				scanf("%d", &op3);
			
				switch(op3){

					case 1 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&nome[i],0,sizeof(nome[i]));
							printf(" Excluida!\n\n");
							system("pause");
						
						break;	
					
					case 2 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&raca[i],0,sizeof(raca[i]));
							printf(" Excluida!\n\n");
							system("pause");
						
						break;
					
					case 3 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&idade[i],0,sizeof(idade[i]));
							printf(" Excluida!\n\n");
							system("pause");
						
						break;	
						
					case 4 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&Peso[i],0,sizeof(Peso[i]));
							printf(" Excluida!\n\n");
							system("pause");
				}
			}
		}
	
}

void salvar(){ //SALVAR CADASTRO
	system("cls");
	FILE *Arquivo;
	Arquivo = fopen("CADASTRO.txt", "wt");
	if ( Arquivo == NULL ) 
	printf("Arquivo não encontrado");
	for(i=1;i<=num;i++){
	system("cls");
	system("pause");
	
	fprintf(Arquivo, "codigo :%s\t nome :%s\t raça :%s\t idade :%s\t Peso :%s\t \n", codigo[i], nome[i], raca[i], idade[i], Peso[i]);
	}
	fclose(Arquivo);
	printf("Salvo arquivo Cadastro.txt ");
			
	getchar();
	getchar();

}

void carregar(){ //CARREGAR CADASTRO
	system("cls");
	FILE *Arquivo;
	Arquivo = (FILE*) malloc(sizeof(FILE));
	Arquivo = fopen("CADASTRO.txt", "r");
	char  linha[100];
	char* result;
	if ( Arquivo == NULL ) { 
		printf("Erro ao abrir o arquivo");
	};
	while ( !feof(Arquivo) ) {
     	result = fgets(linha, 200, Arquivo);
     	if ( result )
     	printf("Linha %s \n", linha);
    }
	
    fclose(Arquivo);
     		
    getchar();
    getchar();

}

