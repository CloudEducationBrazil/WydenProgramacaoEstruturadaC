#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40
typedef struct cadastro{
	char nome[max],observacao[max];
	unsigned long int cpf, rg;
	int dia, mes, ano;
	struct cadastro *seguinte;
}hospede;

hospede *inserir(hospede *cabeca);
void mostrar(hospede *cabeca);
void quantidade(hospede *cabeca);
void buscar(hospede *cabeca);
void alterar(hospede *cabeca);
void salvar(hospede *cabeca);
hospede *excluir(hospede *cabeca);
hospede *memoria(hospede *cabeca);

int main(){
	int menu=0,menup=0,carrega=0;
    hospede *cabeca=NULL;

    printf("Deseja carregar os hospedes salvos na memoria? (1-Sim 2-Nao):  ");
    scanf("%d", &carrega);

    if(carrega==1){
      cabeca = memoria(cabeca);
    }
    while(menup==0){
        system("cls");
        printf("Bem vindo ao Sistema de cadastro de Hospedes!");
        printf("\n1 - Cadastrar hospedes");
        printf("\n2 - Exibir hospedes cadastrados");
        printf("\n3 - Quantidade de hospedes cadastrados");
        printf("\n4 - Buscar hospede pelo cpf ");
        printf("\n5 - Alterar dados de um hospede");
        printf("\n6 - Excluir hospede");
        printf("\n7 - Salvar");
        printf("\n8 - Sair\n");
        scanf("%d",&menu);
        if(menu==1){
            cabeca = inserir(cabeca);
        }
        else if(menu==2){
            mostrar(cabeca);
        }
        else if(menu==3){
            quantidade(cabeca);
        }
        else if(menu==4){
            buscar(cabeca);
        }
        else if(menu==5){
            alterar(cabeca);
        }
        else if(menu==6){
            cabeca = excluir(cabeca);
        }
        else if(menu==7){
            salvar(cabeca);
        }
        else if(menu==8){
            menup=1;
        }
        else{
        	printf("Opcao invalida");
		}

    }
     return 0;
}

hospede *inserir(hospede *cabeca){
    char nome[max],observacao[max];
	unsigned long int cpf, rg;
	int dia, mes, ano;
    hospede *novo;

    system("cls");
    printf("Cadastro de hospede\n");
    printf("Nome: ");
    setbuf(stdin, NULL);
    gets(nome);
    printf("Cpf: ");
    scanf("%d", &cpf);
    printf("Rg: ");
    scanf("%d", &rg);
    printf("Data de nascimento (DD MM AAAA): ");
    scanf("%d" "%d" "%d", &dia, &mes, &ano);
    printf("Observacao: ");
    setbuf(stdin, NULL);
    gets(observacao);

    novo = (hospede*)malloc(sizeof(hospede));

    strcpy(novo->nome,nome);
    strcpy(novo->observacao,observacao);
    novo->dia = dia;
    novo->ano = ano;
    novo->mes = mes;
    novo->rg = rg;
    novo->cpf = cpf;

   	if(cabeca == NULL){
        novo->seguinte=NULL;
        cabeca = novo;
    } else {
        novo->seguinte = cabeca;
        cabeca = novo;
    }

    printf("\nCadastrado com sucesso!\n");
    system("pause");
    return (cabeca);
}


void mostrar(hospede *cabeca){
    system("cls");
    while(cabeca!=NULL){
        printf("\nNome: %s", cabeca->nome);
        printf("\nRG: %d",cabeca->rg);
        printf("\nCpf: %d", cabeca->cpf);
        printf("\nData de nascimento %d/%d/%d", cabeca->dia, cabeca->mes, cabeca->ano);
        printf("\nObservacao: %s\n", cabeca->observacao);
        cabeca = cabeca->seguinte;
    }
    system("pause");
}

void quantidade(hospede *cabeca){
 int qt=0;
 system("cls");
 while(cabeca!=NULL){
    qt++;
    cabeca = cabeca->seguinte;
 }
 printf("Existem %d hospedes cadastrados\n",qt);
 system("pause");

}


void buscar(hospede *cabeca){
    int achou=0,cpf;
    system("cls");
    printf("Digite o cpf do hospede: ");
    scanf("%d", &cpf);
    while(cabeca!=NULL){
        if(cabeca->cpf == cpf){
        printf("\nNome: %s", cabeca->nome);
        printf("\nRG: %d",cabeca->rg);
        printf("\nCpf: %d", cabeca->cpf);
        printf("\nData de nascimento %d/%d/%d", cabeca->dia, cabeca->mes, cabeca->ano);
        printf("\nObservacao: %s\n", cabeca->observacao);
        achou = 1;
        }
        cabeca = cabeca->seguinte;
    }
    if(achou==0){
        printf("Nao encontrado\n");
    }
    system("pause");
}

void alterar(hospede *cabeca){
    int achou=0,cpf;
    system("cls");
    printf("Digite o cpf do hospede: ");
    scanf("%d", &cpf);
    while(cabeca!=NULL){
        if(cabeca->cpf == cpf){
            printf("Nome: ");
            setbuf(stdin, NULL);
            gets(cabeca->nome);
            printf("Cpf: ");
            scanf("%d", &cabeca->cpf);
            printf("Rg: ");
            scanf("%d", &cabeca->rg);
            printf("Data de nascimento (DD MM AAAA): ");
            scanf("%d" "%d" "%d", &cabeca->dia, &cabeca->mes, &cabeca->ano);
            printf("Observacao: ");
            setbuf(stdin, NULL);
            gets(cabeca->observacao);
            achou = 1;
        }
        cabeca = cabeca->seguinte;
    }
    if(achou==0){
        printf("Nao encontrado\n");
    }
    system("pause");

}

void salvar(hospede *cabeca){
    FILE *arqv;
    system("cls");
    arqv = fopen("hospedes.txt","w");

    if(cabeca==NULL){
        fprintf(arqv,NULL);
    }
    else{
        while(cabeca!=NULL){
            fprintf(arqv,"%s ",cabeca->nome);
            fprintf(arqv,"%d ",cabeca->rg);
            fprintf(arqv,"%d ",cabeca->cpf);
            fprintf(arqv,"%s ",cabeca->observacao);
            fprintf(arqv,"%d ",cabeca->dia);
            fprintf(arqv,"%d ",cabeca->mes);
            fprintf(arqv,"%d\n",cabeca->ano);

            cabeca = cabeca->seguinte;
        }
    }
    fclose(arqv);
}

hospede *memoria(hospede *cabeca){
    char nome[max],observacao[max];
	unsigned long int cpf, rg;
	int dia, mes, ano;
	FILE *arqv;
    hospede *novo;

    arqv = fopen("hospedes.txt","r");
        while(fscanf(arqv," %[^ ]s",&nome)!=EOF){
            fscanf(arqv,"%d",&rg);
            fscanf(arqv,"%d",&cpf);
            fscanf(arqv," %[^ ]s",&observacao);
            fscanf(arqv,"%d",&dia);
            fscanf(arqv,"%d",&mes);
            fscanf(arqv,"%d",&ano);



            novo = (hospede*)malloc(sizeof(hospede));

            strcpy(novo->nome,nome);
            strcpy(novo->observacao,observacao);
            novo->dia = dia;
            novo->ano = ano;
            novo->mes = mes;
            novo->rg = rg;
            novo->cpf = cpf;

            if(cabeca == NULL){
                novo->seguinte=NULL;
                cabeca = novo;
            } else {
                novo->seguinte = cabeca;
                cabeca = novo;
            }
        }
            return(cabeca);
}


hospede *excluir(hospede *cabeca){
int cpf,achou=0;
hospede *ant =cabeca;
hospede *aux = cabeca;

    printf("Digite o cpf do hospede: ");
    scanf("%d", &cpf);

    while(aux!=NULL){
        if(cpf == aux->cpf){
            achou=1;
            if(aux==cabeca){
                cabeca = cabeca->seguinte;
                free(aux);
                break;
            }
            else{
                if(aux->seguinte==NULL){
                    ant->seguinte=NULL;
                    free(aux);
                    break;
                }
                else{
                    ant->seguinte = aux->seguinte;
                    free(aux);
                    break;
                }
            }
        }
        else{
            ant = aux;
            aux=aux->seguinte;
        }

    }
    
	if(achou==0){
		printf("Cpf nao encontrado\n");
		system("pause");
	}
	else if(achou==1){
			printf("excluido com sucesso!\n");
			system("pause");
	}

    return(cabeca);
}

