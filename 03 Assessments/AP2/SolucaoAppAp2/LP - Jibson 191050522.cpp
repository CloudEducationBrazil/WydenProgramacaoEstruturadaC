#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define TAM 200

char codigo[TAM][40];
char nome[TAM][40];
char produto[TAM][40];
char frete[TAM][40];
char cnpj[TAM][40];
char raio[TAM][40];
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
		printf("  Empresas do ramo alimenticio \n\n");
   		printf("\n");
   		printf(" Seja Bem vindo(a)\n\n");
		printf(" 1 - Cadastrar empresa\n");
		printf(" 2 - Pesquisar  pelo Codigo\n");
    	printf(" 3 - Listar empresas\n");
    	printf(" 4 - Alterar dados \n");
   		printf(" 5 - Excluir dados \n");
   		printf(" 6 - Salvar dados \n");
   		printf(" 7 - Carregar dados \n");
   		printf(" 8 - Sair \n\n");
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
				printf("\ncodigo :%s\n nome :%s\n tipo de produto fornecido :%s\n distancia maxima para frete gratis em km :%s\n cnpj da empresa :%s\n raio de cobertura em km :%s\n ", codigo[i],  nome[i], produto[i], frete[i], cnpj[i], raio[i]);
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
    		printf("\n Digite o  Codigo: ");
    		fflush(stdin);
    		scanf("%s",&codigo[i]);
        	printf("\nDigite o nome : ");
        	fflush(stdin);
        	scanf("%s",&nome[i]);
        	printf("\nDigite o tipo de produto fornecido: ");
        	fflush(stdin);
        	scanf("%s",&produto[i]);
        	printf("\nDigite a distancia maxima para frete gratis em km : ");
        	fflush(stdin);
        	scanf("%s",&frete[i]);
        	printf("\nDigite o cnpj da empresa: ");
        	fflush(stdin);
        	scanf("%s",&cnpj[i]);
        	printf("\nDigite o raio de cobertura em km: ");
        	fflush(stdin);
        	scanf("%s",&raio[i]);

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
						printf("\ncodigo :%s\n nome :%s\n tipo de produto fornecido :%s\n distancia maxima para frete gratis em km :%s\n cnpj da empresa :%s\n raio de cobertura em km :%s\n ", codigo[i],  nome[i], produto[i], frete[i], cnpj[i], raio[i]);
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
				printf("\n 2 - Alterar o tipo de produto fornecido ");
				printf("\n 3 - Alterar a distancia maxima para frete gratis em km");
				printf("\n 4 - Alterar o cnpj da empresa");
				printf("\n 5 - Alterar o raio de cobertura em km \n\n");
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
						printf("\n Alterar o tipo de produto fornecido: ");
						fflush(stdin);
						scanf("%[^\n]s",&produto[i]);
						printf("\n Novo vetor: %s \n\n",&produto[i]);
						system("pause");
						
						break;
					
					case 3 :
					
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a distancia maxima para frete gratis em km: ");
						fflush(stdin);
						scanf("%[^\n]s",&frete[i]);
						printf("\n Novo vetor: %s \n\n",&frete[i]);
						system("pause");
						
						break;
						
					case 4 :
					    
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o cnpj da empresa: ");
						fflush(stdin);
						scanf("%[^\n]d",&cnpj[i]);
						printf("\n Nova vetor: %s \n\n",&cnpj[i]);
						system("pause");
						
						break;
						
						case 5 :
					    
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o raio de cobertura em km: ");
						fflush(stdin);
						scanf("%[^\n]d",&raio[i]);
						printf("\n Nova vetor: %s \n\n",&raio[i]);
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
				printf("\n 2 - Excluir o tipo de produto fornecido ");
				printf("\n 3 - Excluir a distancia maxima para frete gratis em km");
				printf("\n 4 - Excluir o cnpj da empresa");
				printf("\n 5 - Excluir o raio de cobertura em km \n\n");
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
							memset(&produto[i],0,sizeof(produto[i]));
							printf(" Excluida!\n\n");
							system("pause");
						
						break;
					
					case 3 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&frete[i],0,sizeof(frete[i]));
							printf(" Excluida!\n\n");
							system("pause");
						
						break;	
						
					case 4 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&cnpj[i],0,sizeof(cnpj[i]));
							printf(" Excluida!\n\n");
							system("pause");
							
						break;
														
					case 5 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&raio[i],0,sizeof(raio[i]));
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
	
	fprintf(Arquivo, "\ncodigo :%s\n nome :%s\n tipo de produto fornecido :%s\n distancia maxima para frete gratis em km :%s\n cnpj da empresa :%s\n raio de cobertura em km :%s\n ", codigo[i],  nome[i], produto[i], frete[i], cnpj[i], raio[i]);
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
