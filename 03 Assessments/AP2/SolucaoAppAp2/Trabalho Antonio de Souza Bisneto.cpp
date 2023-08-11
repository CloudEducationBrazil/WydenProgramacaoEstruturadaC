#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define TAM 200

char codigo[TAM][40];
char nome[TAM][40];
char tipo[TAM][40];
char tempo[TAM][40];
char situacao[TAM][40];
char lucro[TAM][40];
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
		printf("  Controle de financas de empresas \n\n\n");
   		printf(" Seja Bem vindo(a)\n\n");
		printf(" 1 - Cadastrar empresa\n");
-+		printf(" 2 - Pesquisar  pelo Codigo\n");
    	printf(" 3 - Listar empresas\n");
    	printf(" 4 - Alterar cadastros \n");
   		printf(" 5 - Excluir cadastros \n");
   		printf(" 6 - Salvar cadastros \n");
   		printf(" 7 - Carregar cadastros \n");
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
				printf("\ncodigo :%s\n nome :%s\n tipo de empresa :%s\n tempo em anos no mercado :%s\n situacao financeira atual(positiva ou negativa) :%s\n lucro medio mensal :%s\n ", codigo[i],  nome[i], tipo[i], tempo[i], situacao[i], lucro[i]);
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
        	printf("\nDigite o tipo de empresa: ");
        	fflush(stdin);
        	scanf("%s",&tipo[i]);
        	printf("\nDigite o tempo no mercado em anos : ");
        	fflush(stdin);
        	scanf("%s",&tempo[i]);
        	printf("\nDigite a situacao financeira atual (positiva ou negativa): ");
        	fflush(stdin);
        	scanf("%s",&situacao[i]);
        	printf("\nDigite o lucro medio mensal: ");
        	fflush(stdin);
        	scanf("%s",&lucro[i]);

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
						printf("\ncodigo :%s\n nome :%s\n tipo de empresa :%s\n tempo em anos no mercado :%s\n situacao financeira atual(positiva ou negativa) :%s\n lucro medio mensal :%s\n ", codigo[i],  nome[i], tipo[i], tempo[i], situacao[i], lucro[i]);
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
				printf("\n 2 - Alterar o tipo de empresa");
				printf("\n 3 - Alterar a tempo no mercado");
				printf("\n 4 - Alterar a situacao financeira");
				printf("\n 5 - Alterar o lucro medio mensal \n\n");
				printf("Selecione uma das opcoes por favor \n");
				scanf("%d", &op2);
					
				switch(op2){
					
					case 1 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o nome : ");
						fflush(stdin);
						scanf("%[^\n]s",&nome[i]);
						printf("\n Nova nome: %s \n\n",&nome[i]);
						system("pause");
						
						break;
					
					case 2 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o tipo de empresa: ");
						fflush(stdin);
						scanf("%[^\n]s",&tipo[i]);
						printf("\n Novo tipo de empresa: %s \n\n",&tipo[i]);
						system("pause");
						
						break;
					
					case 3 :
					
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a tempo no mercado: ");
						fflush(stdin);
						scanf("%[^\n]s",&tempo[i]);
						printf("\n Novo tempo no mercado: %s \n\n",&tempo[i]);
						system("pause");
						
						break;
						
					case 4 :
					    
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a situacao financeira: ");
						fflush(stdin);
						scanf("%[^\n]d",&situacao[i]);
						printf("\n Nova situacao financeira: %s \n\n",&situacao[i]);
						system("pause");
						
						break;
						
						case 5 :
					    
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o lucro medio mensal: ");
						fflush(stdin);
						scanf("%[^\n]d",&lucro[i]);
						printf("\n Novo lucro medio mensal : %s \n\n",&lucro[i]);
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
				printf("\n 2 - Excluir o tipo de empresa");
				printf("\n 3 - Excluir o tempo em anos");
				printf("\n 4 - Excluir a situacao financeira atual");
				printf("\n 5 - Excluir o lucro medio mensal");
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
							memset(&tipo[i],0,sizeof(tipo[i]));
							printf(" Excluida!\n\n");
							system("pause");
						
						break;
					
					case 3 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&tempo[i],0,sizeof(tempo[i]));
							printf(" Excluida!\n\n");
							system("pause");
						
						break;	
						
					case 4 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&situacao[i],0,sizeof(situacao[i]));
							printf(" Excluida!\n\n");
							system("pause");
							
						break;
														
					case 5 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&lucro[i],0,sizeof(lucro[i]));
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
	
	fprintf(Arquivo, "codigo :%s\n nome :%s\n tipo de empresa :%s\n tempo em anos no mercado :%s\n situacao financeira atual(positiva ou negativa) :%s\n lucro medio mensal :%s\n ", codigo[i],  nome[i], tipo[i], tempo[i], situacao[i], lucro[i]);
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
