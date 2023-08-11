#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define MAX_CORRETISTA
typedef struct{
    int CPF;
    char nome[100];
    int conta;
    int agencia;
    //char nomedobanco[100];
    int ativo;
    
}Corretista;
Corretista vett[100];
int usuarios = 0;
void menu();
void cadastro();
void excluir();
void editar();
void Buscar();
void salvar();
void carregar();
void listar();
int main(void){

    menu();
    return 0;
}

void menu(){
    int opc;
    do{
    system("cls");
    printf("BEM VINDO AO CRUD CORRETISTA, POR GENTILIZA ESCOLHA UMA OPCAO ");
    printf("\n================================================================");
    printf("\n1- Cadastrar \n2- Excluir\n3- Editar \n4- Buscar \n5- Salvar \n6- Carregar \n7- Listar \n0- Sair");
    printf("\n================================================================\n");
    scanf("%d", &opc);
    getchar();
    switch(opc){
    case 1:
        cadastro();
        break;
    case 4: 
    	Buscar();
    	break;
    case 2:
    	excluir();
    	break;
    case 5:
    	salvar();
    	break;
    case 6:
    	carregar();
    	break;
    case 3:
    	editar();
    	break;
    case 7:
    	listar();
    	break;
    }
	getchar();
    }while(opc != 0);


}
void cadastro(){
    
    //char nomedobanco[100];
    int op;
    int i ;
    
    do{
		printf("\nDigite o nome:");
        scanf("%s", &vett[i].nome);
        printf("Digite o CPF: ");
        scanf("%d", &vett[i].CPF);
        printf("Digite a conta: ");
        scanf("%d",&vett[i].conta);
        printf("Digite o agencia: ");
        scanf("%d",&vett[i].agencia);
        vett[i].ativo = 1;
       	i++;
       	usuarios++;
        printf("\n1- Continuar \n0- Sair\n");
        scanf("%d", &op);
    
    }while(op !=0);
}
void Buscar(){
int i;
char nome[100];
int op;
do{
printf("\n Digite um nome para buscar: ");
scanf("%s",&nome);
for(i = 0; i < 100; i++){
	if(strstr(vett[i].nome,nome)!= 0){
		printf("\n Nome: %s",vett[i].nome );
		printf("\n CPF: %d",vett[i].CPF);
		printf("\n Conta: %d",vett[i].conta);
		printf("\n Agencia: %d",vett[i].agencia);
		}	
	}
	printf("\n Digite 0 pra sair - 1 para nova pesquisa ");
	scanf("%d", &op);
	getchar();
	}while(op !=0);
}
void listar(){
	system("cls");
	int i;
	//corretistas[100];
	for( i=0; i <100 ; i++){
		if(vett[i].ativo ==1){
		printf("\nCod: %d", i+1);
		printf("\n Nome: %s",vett[i].nome );
		printf("\n CPF: %d",vett[i].CPF);
		printf("\n Conta: %d",vett[i].conta);
		printf("\n Agencia: %d",vett[i].agencia);
			}
		}
	}
void excluir(){
	char nome[100];
	int i;
	int op;
	fflush(stdin);
	do{
		printf("\n Digite nome que deseja excluir: ");
		gets(nome);
		for(i = 0; i < 100; i++){
			if(strstr(vett[i].nome,nome)){
			vett[i].nome[i] = NULL;
				}
			}
			printf("\n Dados Excluido com sucesso ");
			printf("\n Digite 0 para sair - 1 para nova exclusao");
			scanf("%d", &op);
			getchar();
		}while(op !=0);
	}
	
void salvar(){
	int i;
	FILE *arquivo;
	arquivo = fopen("Teste.txt","a");
	if(arquivo == NULL){
		printf("\nErro ao criar o arquivo");
	}
	for(i = 0; i < 3; i++){
		//if(vett[i].ativo != 0){
		fprintf(arquivo, "%s\t %d\t %d\t %d\t\n",vett[i].nome, vett[i].CPF, vett[i].conta, vett[i].agencia);
	//	}
	}
	printf("\n Arquivo gerado com sucesso");
	fclose(arquivo);
}
void carregar(){
	int i;
	FILE *arquivo;
	char leitura[50];
     char *result;
     
	arquivo = fopen("Teste.txt","r");
	
	
	  if(arquivo == NULL){
         printf("Erro ao abrir arquivo");
     }

     while(!feof(arquivo)){
          result = fgets(leitura,50,arquivo);

          if(result){
              printf("%s",leitura);
         // fscanf(arquivo, "%s\t %d\t %d\t %d", vett[i].nome, vett[i].CPF, vett[i].conta, vett[i].agencia);
          //fprintf("%s\t %d\t %d\t %d\t",corretistas[i].nome, corretistas[i].CPF, corretistas[i].conta, corretistas[i].agencia);
          }

     }


	
	printf("Dados recarregados");
	fclose(arquivo);
	//return(i);
}
void editar(){
int edit;
int i;
//char nome[100];
int conta;
int op;
do{
printf("\n Digite um nome para buscar: ");
scanf("%d",&conta);
for(i = 0; i < usuarios; i++){
	if(vett[i].conta == conta){
		printf("\n Digite novo nome: ");
		fflush(stdin);
		scanf("%d",&edit);			
		vett[i].conta = edit;
		

		}	
	}
	printf("\n Digite 0 pra sair - 1 para nova pesquisa ");
	scanf("%d", &op);
	getchar();
	}while(op !=0);
}



