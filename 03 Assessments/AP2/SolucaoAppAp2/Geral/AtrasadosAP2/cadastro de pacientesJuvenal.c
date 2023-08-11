#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#define max 1000

char cpf[max][100];
char nome[max][100];
char sexo[max][100];
char datanasc[max][100];
char especialidade[max][100];
int op,i,num,senha;   
void excluir();
void cadastro(); 
void pesquisacpf();  
void lista();  
void alterar();
void salvar();
void carregar();
int main(void){
system("color 9f");
printf("digite uma senha: ");
scanf("%d", &senha);
switch(senha){
	case 601217:
		
			do{
		system("cls");
		printf(" \n\n       AMG POLICLÍNICA  %s \n",setlocale(LC_ALL,""));
   		printf("\n");
   		printf("      ***MENU INICIAL*** \n \n");
		printf(" 1 - Cadastro do Paciente \n");
		printf(" 2 - Pesquisar  pelo CPF\n");
    	printf(" 3 - Visualizar Cadastros\n");
    	printf(" 4 - Alterar Dados \n");
   		printf(" 5 - Excluir Dados \n");
   		printf(" 6 - Salvar Dados \n");
   		printf(" 7 - Carregar Dados \n");
   		printf(" 8 - Sair\n");
		printf(" \n\n Por favor selecione uma das opções acima: ");
    	scanf("%d", &op);
    	
    		
    	switch(op){
    		case 1:
    			cadastro();
    		break;
			case 2:
				pesquisacpf();
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
				printf("Opção Inválida");	
				getchar();
				getchar();
			break;			
		}	
	}while(op!=8);}
}
void lista(){ // Visualizar cadastros
	system("cls");
			
			for(i=1;i<=num;i++){
				system("cls");
				printf("\n  Exibindo os Cadastros %d  ", i);
				printf("\n CPF :%s\n nome :%s\n sexo :%s\n data de nascimento :%s\n especialidade :%s\n ", cpf[i], nome[i], sexo[i], datanasc[i], especialidade[i]);
				system("pause");
			}
	getchar();
	getchar();
}
void cadastro(){ // Cadastro dos Pacientes
			system ("cls");
    		printf("\n Quantos pacientes deseja cadastrar ? ");
    		scanf("%d", &num);
    		
			for(i=1;i<=num;i++){
    		system("cls");
    		printf("\n\n\t\t\t    Iniciando Cadastro \n");
    		printf("\n Digite o CPF: ");
    		fflush(stdin);
    		scanf("%s",&cpf[i]);
        	printf("\nDigite o nome : ");
        	fflush(stdin);
        	scanf("%s",&nome[i]);
        	printf("\nDigite o sexo : ");
        	fflush(stdin);
        	scanf("%s",&sexo[i]);
        	printf("\nDigite a data de nascimento : ");
        	fflush(stdin);
        	scanf("%s",&datanasc[i]);
        	printf("\nDigite a especialidade : ");
        	fflush(stdin);
        	scanf("%s",&especialidade[i]);

        }
} // //Fim do Cadastro

void pesquisacpf(){ //Pesquisa pelo CPF do Paciente
	char cpfPesquisa[100];
	int i;
			do{			
				system("cls");
				printf("Digite o CPF :");
				scanf("%s", &cpfPesquisa);
				for (i=0;i<=num;i++){
					if(strcmp(cpf[i], cpfPesquisa)==0){
						printf("\ncpf :%s\n nome :%s\n sexo :%s\n data de nascimento :%s\n especialidade :%s\n", cpf[i],  nome[i], sexo[i], datanasc[i], especialidade[i]);
						}
					}
					break;
		
				}while(op==1);
				getchar();
				getchar();
}
void alterar(){ // Alterar dados do paciente
	char cpfPesquisa[100];
	int i,op2;
	
		system("cls");
		printf("Insira o cpf :");
		scanf("%s", &cpfPesquisa);
		for (i=0;i<=num;i++){
			if(strcmp(cpf[i], cpfPesquisa)==0){
				system("cls");
				printf("\n  Alterar Cadastro %d  ",i);
				printf("\n 1 - Alterar o nome");
				printf("\n 2 - Alterar o sexo");
				printf("\n 3 - Alterar a data de nacimento");
				printf("\n 4 - Alterar a especialidade\n\n");
				printf("Selecione uma das opções acima\n");
				scanf("%d", &op2);
					
				switch(op2){
					
					case 1 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o nome : ");
						fflush(stdin);
						scanf("%[^\n]s",&nome[i]);
						printf("\n Novo nome: %s \n\n\n",&nome[i]);
						system("pause");
						
						break;
					
					case 2 :
						
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar o sexo: ");
						fflush(stdin);
						scanf("%[^\n]s",&sexo[i]);
						printf("\n Novo sexo: %s \n\n\n",&sexo[i]);
						system("pause");
						
						break;
					
					case 3 :
					
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar data de nascimento: ");
						fflush(stdin);
						scanf("%[^\n]s",&datanasc[i]);
						printf("\n Nov idade: %s \n\n",&datanasc[i]);
						system("pause");
						
						break;
						
					case 4 :
					    
						system("cls");
						printf("\n\n Cadastro %d \n",i);
						printf("\n Alterar a Especialidade: ");
						fflush(stdin);
						scanf("%[^\n]d",&especialidade[i]);
						printf("\n Nova Especialidade: %s \n\n",&especialidade[i]);
						system("pause");
				}
			}
		}
	
}

void excluir(){ // Excluir dados do paciente
	char cpfPesquisa[100];
	int i,op3;
	
		system("cls");
		printf("Insira o CPF :");
		scanf("%s", &cpfPesquisa);
		for (i=0;i<=num;i++){
			if(strcmp(cpf[i], cpfPesquisa)==0){
				printf("\n  Excluir Cadastro %d  ",i);
				printf("\n 1 - Excluir o nome");
				printf("\n 2 - Excluir a sexo");
				printf("\n 3 - Excluir a data de nascimento");
				printf("\n 4 - Excluir a especialidade");
				printf("\n\n\n - Selecione uma das opcoes acima");
				scanf("%d", &op3);
			
				switch(op3){

					case 1 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&nome[i],0,sizeof(nome[i]));
							printf(" Excluida com sucesso!\n\n");
							system("pause");
						
						break;	
					
					case 2 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&sexo[i],0,sizeof(sexo[i]));
							printf(" Excluida com sucesso!\n\n");
							system("pause");
						
						break;
					
					case 3 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&datanasc[i],0,sizeof(datanasc[i]));
							printf(" Excluida com sucesso!\n\n");
							system("pause");
						
						break;	
						
					case 4 :
						
							system("cls");
							printf("\n\n Cadastro %d \n",i);
							printf("\n\n");
							memset(&especialidade[i],0,sizeof(especialidade[i]));
							printf(" Excluida com sucesso!\n\n");
							system("pause");
				}
			}
		}
	
}

void salvar(){ //SALVAR cadastro do paciente
	system("cls");
	FILE *Arquivo;
	Arquivo = fopen("CADASTROS.txt", "wt");
	if ( Arquivo == NULL ) 
	printf("Arquivo não pode ser encontrado");
	for(i=1;i<=num;i++){
	system("cls");
	system("pause");
	
	fprintf(Arquivo, "cpf :%s\t nome :%s\t sexo :%s\t datanasc :%s\t especialidade :%s\t \n", cpf[i], nome[i], sexo[i], datanasc[i], especialidade[i]);
	}
	fclose(Arquivo);
	printf("Arquivo salvo em: Cadastros.txt ");
			
	getchar();
	getchar();

}

void carregar(){ //CARREGAR CADASTRO DOS PACIENTES
	system("cls");
	FILE *Arquivo;
	Arquivo = (FILE*) malloc(sizeof(FILE));
	Arquivo = fopen("CADASTRO.txt", "r");
	char cadastro[100];
	char* result;
	if ( Arquivo == NULL ) { 
		printf("Erro ao abrir o arquivo");
	};
	while ( !feof(Arquivo) ) {
     	result = fgets(cadastro, 100, Arquivo);
     	if ( result )
     	printf("Linha %s \n", cadastro);
    }
	
    fclose(Arquivo);
     		
    getchar();
    getchar();

}

