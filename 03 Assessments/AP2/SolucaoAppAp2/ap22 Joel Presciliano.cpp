#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
	
	
struct cadastro{
	
    char especie[200];
    char familia[200];
    char nome[200];
    char genero[200];
    char codigo[200];
    int idade[200];
    
}
log[200];

int main(void){

		
	    int opcao,opcao1,opcao2,opcao3,i,quant,op;
	    char codPesquisa[50];
		char nomePesquisa[50];
	    char funcionario[50];
	
	
    system ("cls");
    printf("Nome do Funcionario: ");
    fflush(stdin);
    scanf("%[^\n]s", funcionario);
    		
    		while(opcao!=6){
	        while(opcao1!=1){
        	system("color F1");
    		system ("cls");
    		
    		printf(" ***** Menu Dos Animais do ZOO ***** \n");
    		printf("\n");
    		printf(" Seja Bem vindo(a) %s\n ", funcionario);
    		printf("1 - Cadastrar Novo Animal\n");
			printf(" 2 - Pesquisar Animal pelo Codigo\n");
			printf(" 3 - Pesquisar Animal pelo Nome\n");
    		printf(" 4 - Dados do Animal\n");
    		printf(" 5 - Alterar Dados do Animal\n");
    		printf(" 6 - Excluir Dados do Animal\n");
    		printf(" 7 - Salvar Cadastro\n");
    		printf(" 8 - Importar Cadastro\n");
    		printf(" 9 - Sair\n");
			printf(" \nSelecione uma opcao por favor: ");
    		scanf("%d", &opcao);
    		
    switch (opcao){
    	case 1:{ // CADASTRAR 
    		system ("cls");
    		printf("\n Quantos Cadastros Deseja Realizar? ");
    		scanf("%d", &quant);
    		
    	for(i=1;i<=quant;i++){
    		system("cls");
    		printf("\n\n\t\t\t    Iniciando Cadastro %d\n",i);
    		printf("\n Digite o codigo do animal: ");
    		fflush(stdin);
    		scanf("%[^\n]s",log[i].codigo);
    		printf("\n Digite a especie do animal: ");
        	fflush(stdin);
        	scanf("%[^\n]s",log[i].especie);
        	printf("\n Digite a familia do animal: ");
        	fflush(stdin);
        	scanf("%[^\n]s",log[i].familia);
        	printf("\n Digite o genero do animal: ");
        	fflush(stdin);
        	scanf("%[^\n]s",log[i].genero);
        	printf("\n Digite o nome do animal: ");
        	fflush(stdin);
        	scanf("%[^\n]s",log[i].nome);
        	printf("\n Digite a idade do animal: ");
        	fflush(stdin);
        	scanf("%[^\n]s",log[i].idade);
        	system("pause");
        	system("cls");
		}
		
	}
		break;
		
		case 4: // DADOS DOS ANIMAIS
			system("cls");
			
			for(i=1;i<=quant;i++){
				system("cls");
				printf("\n ***** Exibindo Cadastros %d ***** ", i);
				printf("\n\n Codigo: %s\n",log[i].codigo);
				printf("\n Especie: %s\n",log[i].especie);
				printf("\n Familia: %s\n",log[i].familia);
				printf("\n Genero: %s\n",log[i].genero);
				printf("\n Nome: %s\n",log[i].nome);
				printf("\n Idade: %s\n",log[i].idade);
				system("pause");
			}
		break;
			
		case 5 : // ALTERAR
			system("cls");
			printf("Digite o codigo\n");
			scanf("%s", &codPesquisa);
			for(i=1;i<=quant;i++){
			if(strcmp(log[i].codigo, codPesquisa)==0){	
				system("cls");
				printf("\n ***** Alterar Cadastro %d ***** ",i);
				printf("\n\n 1 - Alterar a especie do animal");
				printf("\n 2 - Alterar a familia do animal");
				printf("\n 3 - Alterar o genero do animal");
				printf("\n 4 - Alterar o nome do animale");
				printf("\n 5 - Alterar a idade do animal\n\n");
				printf("Selecione uma das opcoes por favor \n");
				scanf("%d", &opcao2);
					
				switch(opcao2){
					case 1:
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n Alterar a especie: ");
							fflush(stdin);
							scanf("%[^\n]s",&log [i].especie);
							printf("\n Nova Especie: %s\n\n",&log [i].especie);
							system("pause");
						
						break;
					
					case 2 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a Familia: ");
						fflush(stdin);
						scanf("%[^\n]s",&log [i].familia);
						printf("\n Nova Familia: %s \n\n",&log [i].familia);
						system("pause");
						
						break;
					
					case 3 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a Genero: ");
						fflush(stdin);
						scanf("%[^\n]s",&log [i].genero);
						printf("\n Novo Genero: %s \n\n",&log [i].genero);
						system("pause");
						
						break;
					
					case 4 :
					
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a Nome: ");
						fflush(stdin);
						scanf("%[^\n]s",&log [i].nome);
						printf("\n Novo Nome: %s \n\n",&log [i].nome);
						system("pause");
						
						break;
						
					case 5 :
					    
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a idade: ");
						fflush(stdin);
						scanf("%[^\n]d",&log [i].idade);
						printf("\n Nova idade: %s \n\n",&log [i].idade);
						system("pause");
						
						break;	 
					
				}
			}
		}
		break;
			
		case 6: // EXCLUIR
			system("cls");
			printf("Digite o codigo\n");
			scanf("%s", &codPesquisa);
			for (i=0;i<=quant;i++){
			if(strcmp(log[i].codigo, codPesquisa)==0){
				printf("\n\n\t\t\t ***** Excluir Cadastro %d *****\n",i);
				printf("\n\n 1 - Excluir Especie");
				printf("\n 2 - Excluir Familia");
				printf("\n 3 - Excluir Genero");
				printf("\n 4 - Excluir Nome");
				printf("\n 5 - Excluir idade");
				printf("\n 6 - Excluir Todos os Dados \n\n");
				printf(" Selecione uma opcao por favor");
				scanf("%d", &opcao3);
			
				switch(opcao3){
					case 1 :
					
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");	
							memset(&log[i].especie,0,sizeof(log[i].especie));
							printf("Especie Excluida!\n\n");
							system("pause");
						
						break;
						
					case 2 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&log [i].familia,0,sizeof(log[i].familia));
							printf("Familia Excluida!\n\n");
							system("pause");
						
						break;	
					
					case 3 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&log[i].genero,0,sizeof(log[i].genero));
							printf("Genero Excluido!\n\n");
							system("pause");
						
						break;
					
					case 4 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&log[i].nome,0,sizeof(log[i].nome));
							printf("Nome Excluido!\n\n");
							system("pause");
						
						break;	
						
					case 5 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&log[i].idade,0,sizeof(log[i].idade));
							printf("idade Excluida!\n\n");
							system("pause");
						
						break;
								
					case 6 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&log [i].especie,0,sizeof(log[i].especie));
							memset(&log [i].familia,0,sizeof(log[i].familia));
							memset(&log [i].genero,0,sizeof(log[i].genero));
							memset(&log [i].nome,0,sizeof(log[i].nome));
							memset(&log [i].idade,0,sizeof(log[i].idade));
							printf("Todos os Dados Foram Excluidos\n\n");
							system("pause");
						
						break;		
				}	
			}
		}
		break;
			
		case 2 : // Pesquisar por Codigo
			do{			
				system("cls");
				printf("Digite o codigo\n");
				scanf("%s", &codPesquisa);
				for (i=0;i<=quant;i++){
					if(strcmp(log[i].codigo, codPesquisa)==0){
						printf("\n\n Codigo: %s\n",log[i].codigo);
						printf("\n Especie: %s\n",log[i].especie);
						printf("\n Familia: %s\n",log[i].familia);
						printf("\n Genero: %s\n",log[i].genero);
						printf("\n Nome: %s\n",log[i].nome);	
						printf("\n Idade: %s\n",log[i].idade);
						}
					}
					break;
		
				}while(op==1);
				getchar();
				getchar();	
		break;
		
		case 3 : // Pesquisar por Nome
			do{			
				system("cls");
				printf("Digite o nome\n");
				scanf("%s", &nomePesquisa);
				for (i=0;i<=quant;i++){
					if(strcmp(log[i].nome, nomePesquisa)==0){
						printf("\n\n Codigo: %s\n",log[i].codigo);
						printf("\n Especie: %s\n",log[i].especie);
						printf("\n Familia: %s\n",log[i].familia);
						printf("\n Genero: %s\n",log[i].genero);
						printf("\n Nome: %s\n",log[i].nome);
						printf("\n Idade: %s\n",log[i].idade);
						}
					}
					break;
				}while(op==1);				
				getchar();
				getchar();
		break;
		
		case 7 :
			system("cls");
			FILE *Arquivo;
			Arquivo = fopen("ZOO.txt", "wt");
			if ( Arquivo == NULL ) 
				printf("Erro na criação do arquivo");
			for(i=1;i<=quant;i++){
				system("cls");
				system("pause");
				
				fprintf(Arquivo, "Codigo :%s\tEspecie :%s\tFamilia :%s\tGenero :%s\tNome :%s\tIdade :%s\t \n" ,log[i].codigo ,log[i].especie ,log[i].familia ,log[i].genero ,log[i].nome ,log[i].idade);
				printf("\n");
			}
			fclose(Arquivo);
			printf("Gravacao do arquivo ZOO.txt com sucesso");
			
			getchar();
			getchar();
		break;
		
		case 8 :
			system("cls");
			Arquivo = (FILE*) malloc(sizeof(FILE));
			Arquivo = fopen("ZOO.txt", "r");
			char  linha[200];
			char* result;
			if ( Arquivo == NULL ) { 
				printf("Erro ao abrir o arquivo");
			};
			while ( !feof(Arquivo) ) {
     			result = fgets(linha, 100, Arquivo);
     			if ( result )
     			printf("Linha %s \n", linha);
     		}
     		fclose(Arquivo);
     		
     		getchar();
     		getchar();
     		
     	break;
     		
   		case 9 :
    		system("cls");
    		printf("\n Voce Realmente Deseja Sair do Programa");
    		printf("\n 1 - Sim\n 2 - Nao");
    		printf("\n\n ");
   			scanf("%d", &opcao1);	
    		switch(opcao1){
    			case 1 :
    				system("cls");
    				printf("\n\nFechando o Programa \n\n\n\t\t");
    				system("pause");
    				return 0;
    				break;
					}		
				}
			}
	break;
			}	
	} 
    
