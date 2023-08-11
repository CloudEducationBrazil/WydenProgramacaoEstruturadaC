#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#define SIZE 30
#define TAM 2
typedef struct data DATA;
struct data{
	int dia [TAM];
	int mes [TAM];
	int ano [4];
	
};
typedef struct endereco ENDERECO;
struct endereco{
	char nomeevento[SIZE];
	char local[SIZE];
	char cidade [SIZE];
	char estado[TAM];
	char telefone [15];
	DATA event;
};
void cabecalho();
void inserir();
void listar();
void pesquisar();
void remover();

main (){
	setlocale(LC_ALL,"portuguese");
	int opcao;
	do{
		cabecalho();
    	printf("1 - inserir\n");
		printf("2 - listar\n");
		printf("3 - pesquisar\n");
		printf("4 - remover\n");
		printf("5 - sair\n\n");
		printf("escolha uma opção:");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				inserir();
			break;
				
			case 2:
				listar();
			break;
			
		    case 3:
		    	pesquisar();
			break;	
			
		    case 4:
		    	remover();
		    	printf("nome excuido");
		    	getch();
			break;
			
		    case 5:
		    printf("operação concluida!\n");
		    getch();
			break;	
			
		    default :
		    printf("opção invalida!\n");
		    getch();
			break;		
			
		}
		
	
	}while (opcao!=5); 
	
}

void cabecalho (){
	system("cls");
	printf("--------------------------------------------------------------------\n");
	printf("agenda de compromisso\n");
	printf("--------------------------------------------------------------------\n");
}

void inserir(){
	FILE* arquivo;
	ENDERECO end;
	
	arquivo = fopen("agenda.txt", "ab");
	if(arquivo == NULL){
		printf("problema de abertura do arquivo!\n");
		
	}
	else{
		do {
			cabecalho();
			
			fflush (stdin);
			printf("digite o nome do evento:");
			gets(end.nomeevento);
				
			fflush (stdin);
			printf("digite o telefone:");
			gets(end.telefone);
			
			fflush (stdin);
			printf("digite o local:");
			gets(end.local);
			
			fflush (stdin);
			printf("digite a cidade:");
			gets(end.cidade);
			
			fflush (stdin);
			printf("digite o estado:");
			gets(end.estado);
			
			printf("digite evento do mês:");
			scanf("%d %d %d", &end.event.dia, &end.event.mes, &end.event.ano);
			fwrite(&end, sizeof(ENDERECO), 1, arquivo);
			printf("deseja continuar (s/n)?");
			
		}while(getche()=='s');
		fclose(arquivo);
		
	}
}

void listar(){
	FILE* arquivo;
	ENDERECO end;
	
	arquivo = fopen("agenda.txt", "rb");
	
	cabecalho();
	
	if(arquivo == NULL){
		printf("problema de abertura do arquivo!\n");
	}
	else{
		while(fread(&end,sizeof(ENDERECO),1,arquivo)==1){
			printf("nomeevento:%s\n,end.nome");
			printf("local:%s\n,end.local");
			printf("cidade:%s\n,end.cidade");
			printf("estado:%s\n,end.estado");
			printf("telefone:%s\n,end.telefone");
			printf("evento:%d%d%d\n,end.evento.dia, end.evento.mes, end.evento.ano");
			printf("---------------------------------------------------------------\n\n");
			
			
		}
	}
		fclose(arquivo);
		getch();

}

void pesquisar(){
	FILE* arquivo;
	ENDERECO end;
	char nomeevento [30];
	
	cabecalho();
	arquivo=fopen ("agenda. txt", "rb");
	
	if (arquivo==NULL){
	printf("problemas de abertura do arquivo\n");
	
	}
	else{
		fflush(stdin);
		printf("digite o nome que deseja pesquisar");
		gets(nomeevento);
		
	while(fread(&end,sizeof(ENDERECO),1,arquivo)==1){
			if (strcmp(nomeevento,end.nomeevento)==0){
				
			printf("nomeevento:%s\n,end.nome");
			printf("local:%s\n,end.local");
			printf("cidade:%s\n,end.cidade");
			printf("estado:%s\n,end.estado");
			printf("telefone:%s\n,end.telefone");
			printf("evento:%d%d%d\n,end.evento.dia, end.evento.mes, end.evento.ano");
			printf("---------------------------------------------------------------\n\n");
			
			}
			printf("nomeevento:%s\n,end.nome");
	}
	
	
}
	fclose(arquivo);
	getch();
	
	
}
void remover(){
	FILE* arquivo;
	ENDERECO end;
	char nomeevento;
	
	arquivo=fopen("agenda.txt","rb");
	if (arquivo==NULL){
		printf("problema na abertura do arquivo:");
		
	}
	else{
		printf("digite o endereco para excluir:");
		scanf("%s", &nomeevento);
		--nomeevento;
		printf("nome excluido");
		
	}
	
	fclose(arquivo);
	getch();
	
	
	
}
