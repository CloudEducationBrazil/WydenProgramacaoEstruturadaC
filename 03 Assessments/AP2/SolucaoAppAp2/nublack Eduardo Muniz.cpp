#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

#define numeroUSER 100 //define o numero max de usuarios cadastrados

int totaluser = 1;
char nome[numeroUSER][100] = {"Gabriel Alves", "Luis Eduardo"}; //inserção de 1 usuário gerente e 1 usuário cliente pré-definidos
int conta[numeroUSER] = {20189,0}; //as contas
int agencia[numeroUSER] = {155,0}; // as agencias
float limite[numeroUSER] = {1500,0};// o limite disponível para cada um
int senha[numeroUSER] = {1234,1234};
int tipo[numeroUSER] = {0,1}; //0 significa Cliente e 1 Gerente

int menu(int id_us);
int logar();
void compra(int id_us);
void cadastrarCliente();
void listarAllUser();
void listarUser();
void alterarUser();
void excluirCliente();


int main(){
	
    setlocale(LC_ALL,"Portuguese"); //Adaptamos as inserções do teclado para o PT-BR, validando caracteres e acentuações específicas.
    int indice = 2;
    int tentativas = 0;
    char res = 'n';
    
    indice = -1; //valor que permite a execução da função logar, pois identifica que não existe ninguém logado ainda. 
    while(tentativas<3){
        if(indice == -1){
            indice = logar();
        }
	    if (indice!= -1){
	        if(tipo[indice]==0){
		            switch(menu(indice)){
		            case 1:
		                do{
		                    compra(indice);
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
				switch(menu(indice)){//aqui chamamos os metódos de acordo com a inserção feita pelo usuário anteriormente.
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
	        printf("\nConta ou Agencia não cadastrados");
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
    printf("\n-------SISTEMA DE CARTÃO DE CRÉDITO - NUBLACK-------\n");
    printf("\nDIGITE SUA CONTA: ");
    scanf("%d", &contaLOG);
    printf("DIGITE SUA AGÊNCIA: ");
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
		printf("\nCliente: %s", nome[id_us]);
		printf("\n\nSuas Opções são:\n");
		printf("\n\t 1 - Compra");
		printf("\n\t 2 - Limite");
		printf("\n\t 0 - Sair\n");
		printf("\nEscolha: ");
    }else{
	    printf("\nGerente: %s", nome[id_us]);
	    printf("\n\nSuas Opções são:\n");
	    printf("\n\t 1 - Cadastrar Cliente");
	    printf("\n\t 2 - Listar todos os clientes");
	    printf("\n\t 3 - Listar o último cliente");
	    printf("\n\t 4 - Alterar o limite do cliente");
	    printf("\n\t 5 - Excluir Cliente");
	    printf("\n\t 0 - Sair\n");
	    printf("\nEscolha: ");	
	}
	escolha = getch();  //pega um caractere sem aparecer no video
    return atoi(&escolha); //converte o caractere em numero
}

void compra(int id_us){
    float valor_sq = 0;
    system("cls");
    printf("\nCompra\n");
    printf("\n\tDigite o Valor:");
    scanf("%f", &valor_sq);
    	if(valor_sq>limite[id_us]){
        printf("\n\tSeu limite é insuficiente");
    	}else{
        limite[id_us] -= valor_sq;
        printf("\n\tCompra realizada com sucesso");
    	}
}

void cadastrarCliente(){
	FILE *Nublack;
	system("cls");
	char n_nome[100];
	int n_conta;
	int n_agencia;
	float n_limite;
	int n_senha;
	int n_tipo;
	int tam;

	totaluser++;
	
	printf("\nCadastro de Novo Cliente\n");
	printf("\n\tDigite nome do novo usuário: ");
	fflush(stdin);
	gets(nome[totaluser]);
	printf("\tDigite um número de conta: ");
	scanf("%d", &n_conta);
	printf("\tDigite um número de agência: ");
	scanf("%d", &n_agencia);
	printf("\tDigite o limite a ser aplicado: ");
	scanf("%f", &n_limite);
	printf("\tDigite um número de senha: ");
	scanf("%d", &n_senha);
	printf("\tDigite um número de tipo (0 - CLIENTE, 1 - GERENTE): ");
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

	Nublack = fopen("nublack.txt", "a"); // w; r; a

	fprintf(Nublack, "%s \t ", 	nome[totaluser]);
	fprintf(Nublack, "%i \t", n_conta);
	fprintf(Nublack, "%i \t", n_agencia);
	fprintf(Nublack, "%.2f \t", n_limite);
	fprintf(Nublack, "%i \t \n", n_tipo);
	fclose(Nublack);
	return;
}
void listarAllUser(){
	system("cls");
	int i;
	printf("\n");
	printf("\t| NOME | CONTA	| AGENCIA| LIMITE | TIPO |\n\n");
	for(i=0;i<totaluser+1;i++){
			printf("\t| %s | %d | %d | %.02f | %d |\n", nome[i], conta[i], agencia[i], limite[i], tipo[i]);
	}
	printf("\n");
}
void listarUser(){
	system("cls");
	printf("\nUltimo cliente cadastrado:\n");
	printf("\n \t Nome: %s", nome[totaluser]);
	printf("\n \t Conta: %d", conta[totaluser]);
	printf("\n \t Agência: %d", agencia[totaluser]);
	printf("\n \t Limite: %.2f", limite[totaluser]);
	printf("\n \t Senha: %d", senha[totaluser]);
	printf("\n \t Tipo: %d\n\n", tipo[totaluser]);
}

void alterarUser(){
	int altconta, altagencia;
	float altlimite;
    system("cls");
    printf("\nAlteração de Limite do cartão \n");
    printf("\n\tDigite a Conta: ");
    scanf("%d", &altconta);
    printf("\n\tDigite a Agência: ");
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
        printf("\nExclusão de Conta\n");
        printf("\n\tDigite a conta: ");
        scanf("%d", &num_conta);
        printf("\n\tDigite a Agência: ");
    	scanf("%d", &num_agencia);
        for(i=0;i<numeroUSER;i++){
            if(conta[i]==num_conta&&agencia[i]==num_agencia){
                strcpy(nome[i], "*");
				limite[i]=0.0;
				conta[i]=-1;
				agencia[i]=-1;
				printf("\n\tUsuário %s exluído com sucesso.\n\n", nome[i]);
				system("pause");
        	}
   		}
}
