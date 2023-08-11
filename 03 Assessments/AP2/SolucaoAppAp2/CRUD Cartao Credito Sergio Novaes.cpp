#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

#define numeroUSER 100 //define o numero max de usuarios cadastrados

int totaluser = 1;
char nome[numeroUSER][100] = {"ADMINISTRADOR", "S�RGIO NOVAIS"}; //inser��o de 1 usu�rio administrador e 1 usu�rio cliente pr�-definidos
int conta[numeroUSER] = {1,2}; //N�mero da conta
int agencia[numeroUSER] = {1,2}; // N�mero da ag�ncia
float limite[numeroUSER] = {10000,457};// Limite do cart�o
int senha[numeroUSER] = {1234,1234};
int tipo[numeroUSER] = {1,0}; //0 - Cliente / 1 - Administrador

int menu(int id_us);
int logar();
void cadastrarCliente();
void listarAllUser();
void listarUser();
void alterarUser();
void excluirCliente();
void comprar(int id_us);

int main(){
	
    setlocale(LC_ALL,"Portuguese"); //Permite o uso do teclado PTBR.
    int indice = 2;
    int tentativas = 0;
    char res = 'n';
    
    indice = -1; //valor que permite a execu��o da fun��o logar, pois identifica que n�o existe ningu�m logado ainda. 
    while(tentativas<3){
        if(indice == -1){
            indice = logar();
        }
	    if (indice!= -1){
	        if(tipo[indice]==0){
		            switch(menu(indice)){
		            case 1:
		                do{
		                    comprar(indice);
		                    printf("\nDeseja realizar outra compra? (S/N)");
		                    res = getch();
		                }while(res=='s');
		                break;
		            case 2:
		                printf("\nLimite: %.2f\n\n",limite[indice]);
		                system("PAUSE");
		                break;
		            case 0:
		                indice= -1;
		                break;
		            default:
		                printf("\nEscolha Incorreta!");
		            }
		    }else{
				switch(menu(indice)){//aqui chamamos os met�dos de acordo com a inser��o feita pelo usu�rio anteriormente.
		            case 1:
						cadastrarCliente();
		                break;
		            case 2:
		                listarAllUser();
						system("PAUSE");
		                break;
		            case 3:
		                listarUser();
		                system("PAUSE");
		                break;
		          	case 4:
		                alterarUser();
		                break;
		            case 5:
		                excluirCliente();
		                break;
		            case 0:
		                indice= -1;
		                break;
		            default:
		                printf("\nEscolha Incorreta!");	    
				}
	    	}
		}else{
	        printf("\nConta ou Agencia n�o cadastrados");
	        tentativas++;
	    if(tentativas==2){
	        printf("\nVoce so tem mais uma tentativa!");
	        }
        }
    }
    
	return 0;
}

int logar(){
    int contaLOG, agenciaLOG, senhaLOG;
    system("cls");
    printf("\n=================================================\n");
	printf("\n          SISTEMA DE CART�O DE CR�DITO           \n");
	printf("\n=================================================\n");
    printf("\nDIGITE SUA CONTA: ");
    scanf("%d", &contaLOG);
    printf("DIGITE SUA AG�NCIA: ");
    scanf("%d", &agenciaLOG);
    printf("DIGITE SUA SENHA: ");
    scanf("%d", &senhaLOG);

    for(int x=0; x<numeroUSER; x++){
        if(agencia[x] == agenciaLOG && conta[x]==contaLOG && senha[x]==senhaLOG){
            return x;
        }
    }
    return -1;
}

int menu(int id_us){
    char escolha;
    system("cls");
    if(tipo[id_us]==0){
	    printf("\n=================================================\n");
		printf("\n          SEJA BEM VINDO %s", nome[id_us]);
		printf("\n\n=================================================\n");
		//printf("\nCliente: %s", nome[id_us]);
		printf("\n\nSuas Op��es s�o:\n");
		printf("\n\t 1 - Compra");
		printf("\n\t 2 - Limite");
		printf("\n\t 0 - Sair\n");
		printf("\nEscolha: ");
    }else{
    	printf("\n=================================================\n");
		printf("\n            ADMINISTRADOR DE SISTEMA             \n");
		printf("\n=================================================\n");
	    //printf("\nPerfil: %s", nome[id_us]);
	    printf("\n\nSuas Op��es s�o:\n");
	    printf("\n\t 1 - Cadastrar Cliente");
	    printf("\n\t 2 - Listar todos os clientes");
	    printf("\n\t 3 - Listar o �ltimo cliente");
	    printf("\n\t 4 - Alterar Cliente");
	    printf("\n\t 5 - Excluir Cliente");
	    printf("\n\t 0 - Sair\n");
	    printf("\nEscolha: ");	
	}
	escolha = getch();  //pega um caractere sem aparecer no video
    return atoi(&escolha); //converte o caractere em numero
}

void listarAllUser(){
	system("cls");
	int i;
   	printf("\n\t=================================================\n");
	printf("\t| NOME | CONTA | AGENCIA | LIMITE | TIPO |\n\n");
	for(i=0;i<totaluser+1;i++){
		printf("\t| %s | %d | %d | %.02f | %d |\n", nome[i], conta[i], agencia[i], limite[i], tipo[i]);
	}
	printf("\n");
}

void cadastrarCliente(){
	FILE *crud;
	system("cls");
	char n_nome[100];
	int n_conta;
	int n_agencia;
	float n_limite;
	int n_senha;
	int n_tipo;
	int tam;

	totaluser++;
	
	printf("\n=================================================\n");
	printf("\n            CADASTRO DE NOVO USU�RIO             \n");
	printf("\n=================================================\n");
	printf("\n\tDigite nome do novo usu�rio: ");
	fflush(stdin);
	gets(nome[totaluser]);
	printf("\tDigite um n�mero de conta: ");
	scanf("%d", &n_conta);
	printf("\tDigite um n�mero de ag�ncia: ");
	scanf("%d", &n_agencia);
	printf("\tDigite um n�mero de limite: ");
	scanf("%f", &n_limite);
	printf("\tDigite um n�mero de senha: ");
	scanf("%d", &n_senha);
	printf("\tDigite um n�mero de tipo (0 - CLIENTE, 1 - ADMINISTRADOR): ");
	scanf("%d", &n_tipo);
	
	nome[totaluser][100] = *n_nome;
	conta[totaluser] = n_conta;
	agencia[totaluser] = n_agencia;
	limite[totaluser] = n_limite;
	senha[totaluser] = n_senha;
	tipo[totaluser] = n_tipo;
	
	                               
    tam = strlen(n_nome)-1;
    if( n_nome[tam] == '\n')
      n_nome[tam] = '\0';

	system("cls || clear");

	crud = fopen("crud.txt", "a"); // write; read; alter

	fprintf(crud, "%s \t ", nome[totaluser]);
	fprintf(crud, "%i \t", n_conta);
	fprintf(crud, "%i \t", n_agencia);
	fprintf(crud, "%.2f \t \n", n_limite);
	fclose(crud);
	return;
}

void listarUser(){
	system("cls");
    printf("\n=================================================\n");
	printf("\n            �LTIMO CLIENTE CADASTRADO             \n");
	printf("\n=================================================\n");
	printf("\n \t Nome: %s", nome[totaluser]);
	printf("\n \t Conta: %d", conta[totaluser]);
	printf("\n \t Ag�ncia: %d", agencia[totaluser]);
	printf("\n \t Limite: %.2f", limite[totaluser]);
	printf("\n \t Senha: %d", senha[totaluser]);
	printf("\n \t Tipo: %d\n\n", tipo[totaluser]);
}

void alterarUser(){
	int altconta, altagencia;
	float altlimite;
    system("cls");
	printf("\n=================================================\n");
	printf("\n              ALTERA��O DE LIMITE               \n");
	printf("\n=================================================\n");
	printf("\n\tDigite a Conta: ");
    scanf("%d", &altconta);
    printf("\n\tDigite a Ag�ncia: ");
    scanf("%d", &altagencia);

    for(int x=0; x<numeroUSER; x++){
        if(agencia[x] == altagencia && conta[x]==altconta){
            printf("\n\tDigite novo Limite:\n");
            scanf("%f", &altlimite);
            limite[x] = altlimite;
        }
    }
}

void excluirCliente(){
	system("cls");
	int num_conta, num_agencia;
	//char temp[100] = {"*"};
	int i;
    	printf("\n=================================================\n");
		printf("\n                 EXCLUIR CONTA                  \n");
		printf("\n=================================================\n");
        printf("\n\tDigite a conta: ");
        scanf("%d", &num_conta);
        printf("\n\tDigite a Ag�ncia: ");
    	scanf("%d", &num_agencia);
        for(i=0;i<numeroUSER;i++){
            if(conta[i]==num_conta&&agencia[i]==num_agencia){
                strcpy(nome[i], "*");
				limite[i]=0.0;
				conta[i]=-1;
				agencia[i]=-1;
				printf("\n\tUsu�rio %s exlu�do com sucesso.\n\n", nome[i]);
				system("pause");
        	}
   		}
}

void comprar(int id_us){
    float valor_sq = 0;
    system("cls");
    printf("\n=================================================\n");
	printf("\n              REALIZA��O DE COMPRA               \n");
	printf("\n=================================================\n");
    printf("\n\tDigite o Valor:");
    scanf("%f", &valor_sq);
    	if(valor_sq>limite[id_us]){
        printf("\n\tLimite insuficiente");
    	}else{
        limite[id_us] -= valor_sq;
        printf("\n\tCompra realizada com sucesso");
    	}
}
