#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

#define max 100

int fim=0;

typedef struct Veiculo tipoveiculo;

struct veiculo{
	char modelo[20];
	char placa [20];
	char cor [10];
	int ano [10];
	int valor[10];
}Cadastro [max];

int menu (void),verificarlista(void);
void inicia (void),Cadastrar (void);
void exibir(void);



int main (void){
	return 0;
}
int menu (void){
	char opc[50];
	int opcao;
	
	fflush(stdin);
	printf("1-Cadastrar veiculo\n ");
	printf("2-Lista  todos os veiculo\n ");
	printf("3-Buscar veiculo por nome \n ");
	printf("4-Listar veiculo por cor \n ");
	printf ("5-lista veiculo por valor\n");
	printf("6-Alterar  veiculo\n ");
	printf("7-Excluir  veiculo\n ");
	printf("8-Sair\n ");
	
	
	do{
		
		printf("\n>");
		fflush(stdout);
		gets(opc);
		
		
		opcao = atoi(opc);
		
	} while (opc < 0 || opc > 8 );
	 
	 	return (opcao);
	


void inicia (void){
	register int i;
	for (i=0; i<max; ++i), cadastro [i].veiculo[0] ='\0';
}

void Cadastrar (void){
	
	int Cad;
	
	int  maior valor >10.000;
Cad = verificarLista();
	
	printf ("Digite o modelo do veiculo \n");
	fflush (stdout);
	scanf("%s",&Cadastro[Cad].modelo);
	 
	printf("Digite a placa do veiculo \n");
	fflush(stdout);
	gets(Cadastro[cad].placa);
	
	printf("Digite a cor do veiculo\n");
	fflush(stdout);
	gets(Cadastro[Cad].cor);
printf ("Digite o ano do veiculo\n");
	fflush(stdout);
	scanf("%d",&Cadastro[cad].ano);
	
	printf("Digite o valor do veiculo\n");
	fflush(stdout);
	scanf("%f",&Cadastro.[Cad].Valor);
	
	
	fim++;
	
}
int verificarlista(void){
register int t;
		for (t=0 ; t < Cadastro; Cadastro [t].veiculo[0]; && t < max; t++)  { 
			if (t== max) return = -1;
				return 0;	
			
			
		}
		
	  return t;
	  
	
void exibir(void){
if(fim==0){
			   printf ( "\n Nao existe nenhum cadastro");
		    return();
	}else {
		for(i=0; I<fim ;i++){
			printf("\n Maior Valor:%d",Cadastro[i].valor);
		}
	}
}



