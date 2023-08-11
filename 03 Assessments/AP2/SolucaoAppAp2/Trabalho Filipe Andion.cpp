#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#define tam 50

FILE *file;

typedef struct{
	int num;
	char nome[30];
	float alt; 
	float peso;
	char tipo[30]; 
	char weak[30];
	char evo[30];
	int livre;
} Poke;

Poke pokemon[tam];

void menu();
void cadastro();
void excluir();
void update();
void busca();
void exibir();

int main(void){
	setlocale(LC_ALL, "");
	file = fopen("teste.txt", "r");
	int g=0;
	while(fscanf(file, "%s", pokemon)!=EOF){
		fscanf(file, "%d", &pokemon[g].num);
		fgets(pokemon[g].nome,sizeof(pokemon[g].nome),file);
		fgets(pokemon[g].tipo,sizeof(pokemon[g].tipo),file);
		fscanf(file, "%f", &pokemon[g].alt);
		fscanf(file, "%f", &pokemon[g].peso);
		fgets(pokemon[g].weak,sizeof(pokemon[g].weak),file);
		fgets(pokemon[g].evo,sizeof(pokemon[g].evo),file);
		pokemon[g].livre=1;
		g++;
	}
	fclose(file);
	menu();
	file = fopen("teste.txt", "w");
	if(pokemon[0].livre==1){
		for(int i=0;i<tam;i++){
			if(pokemon[i].livre==1){
				fprintf(file, "%d\t%s%s\t%.1f\t%.1f%s%s\t\n", pokemon[i].num, pokemon[i].nome, pokemon[i].tipo, pokemon[i].alt, pokemon[i].peso, pokemon[i].weak, pokemon[i].evo);
			}
		}
	}
}

void menu(){
	int x;
	do{
		system("cls");
		printf("\n");
		printf("Escolha a op��o desejada:\n");
		printf("\n");
		printf("1. Cadastrar novo Pok�mon\n");
		printf("2. Excluir Pok�mon cadastrado\n");
		printf("3. Atualizar dados do Pok�mon cadastrado\n");
		printf("4. Encontrar Pok�mon\n");
		printf("5. Exibir Pok�mons cadastrados\n");
		printf("6. Salvar e Sair\n");
		printf("\n");
		scanf("%d", &x);
		switch(x){
			case 1:
				cadastro();
				break;
			case 2:{
				excluir();
				break;
			}
			case 3:{
				update();
				break;
			}
			case 4: {
				busca();
				break;
			}	
			case 5: {
				exibir();
				break;
			}
		}
		printf("\n");
		system("pause");
	}while(x!=6);
}

void cadastro(){
	int num;
	char nome[30];
	float alt; 
	float peso;
	char tipo[30]; 
	char weak[30];
	char evo[30];
	char resp;
	do{
		system("cls");
		printf("\n");
		printf("Cadastro de novo Pok�mon\n");
		printf("\n");
		printf("N�mero: ");
		scanf("%d", &num);
		setbuf(stdin, NULL);
		printf("Nome: ");
		fgets(nome, sizeof(nome), stdin);
		setbuf(stdin, NULL);
		printf("Tipo: ");
		fgets(tipo, sizeof(tipo), stdin);
		printf("Altura: ");
		scanf("%f", &alt);
		printf("Peso: ");
		scanf("%f", &peso);
		setbuf(stdin, NULL);
		printf("Fraquezas: ");
		fgets(weak, sizeof(weak), stdin);
		setbuf(stdin, NULL);
		printf("Evolu��o: ");
		fgets(evo, sizeof(evo), stdin);
		setbuf(stdin, NULL);
		int erro=0;
		for(int i=0;i<tam;i++){
			if((pokemon[i].livre==1)&&(pokemon[i].num==num)){
				printf("\n");
				printf("Tentativa de cadastro insucedida. N�mero de Pok�mon j� cadastrado!\n");
				printf("\n");
				erro=1;
				break;	
			}
		}
		for(int i=0;i<tam;i++){
			if((pokemon[i].livre==0)&&(erro==0)){
				pokemon[i].num = num;
				strcpy(pokemon[i].nome, nome);
				strcpy(pokemon[i].tipo, tipo);
				pokemon[i].alt = alt;
				pokemon[i].peso = peso;
				strcpy(pokemon[i].weak, weak);
				strcpy(pokemon[i].evo, evo);
				pokemon[i].livre=1;
				printf("\n");
				printf("Pok�mon cadastrado com sucesso!\n");
				printf("\n");
				break;
			}
		}
		printf("Deseja cadastrar outro Pok�mon?(s/n)\n");
		scanf("%c", &resp);
	}while(resp=='s'||resp=='S');
}

void excluir(){
	int x;
	int cont;
	int num;
	char nome[30];
	do{
		system("cls");
		printf("\n");
		printf("Escolha a op��o de busca para exclus�o:\n");
		printf("\n");
		printf("1. Buscar e excluir por n�mero\n");
		printf("2. Buscar e excluir por nome\n");
		printf("3. Voltar ao menu anterior\n");
		printf("\n");
		scanf("%d", &x);
		switch(x){
			case 1:{
				cont=0;
				printf("Digite o n�mero do Pok�mon: ");
				scanf("%d", &num);
				int i=0;
				while(pokemon[i].livre==1){
					if(pokemon[i].num==num){
						for(int j=i;j<tam;j++){
							pokemon[j].num=pokemon[j+1].num;
							strcpy(pokemon[j].nome, pokemon[j+1].nome);
							strcpy(pokemon[j].tipo, pokemon[j+1].tipo);
							pokemon[j].alt = pokemon[j+1].alt;
							pokemon[j].peso = pokemon[j+1].peso;
							strcpy(pokemon[j].weak, pokemon[j+1].weak);
							strcpy(pokemon[j].evo, pokemon[j+1].evo);
							pokemon[j].livre = pokemon[j+1].livre;
						}
						cont=1;
					}
					i++;
				}
				if(cont==1){	
					printf("\n");
					printf("Pok�mon excluido com sucesso!\n");
					printf("\n");
				}
				else{
					printf("\n");
					printf("Pok�mon n�o encontrado!\n");
					printf("\n");
				}
				system("pause");
				break;
			}
			case 2:{
				cont=0;
				setbuf(stdin, NULL);
				printf("Digite o nome do Pok�mon: ");
				fgets(nome, sizeof(nome), stdin);
				int i=0;
				while(pokemon[i].livre==1){
					if(strcmp(nome, pokemon[i].nome)==0){
						for(int j=i;j<tam;j++){
							pokemon[j].num=pokemon[j+1].num;
							strcpy(pokemon[j].nome, pokemon[j+1].nome);
							strcpy(pokemon[j].tipo, pokemon[j+1].tipo);
							pokemon[j].alt = pokemon[j+1].alt;
							pokemon[j].peso = pokemon[j+1].peso;
							strcpy(pokemon[j].weak, pokemon[j+1].weak);
							strcpy(pokemon[j].evo, pokemon[j+1].evo);
							pokemon[j].livre = pokemon[j+1].livre;
						}
						cont=1;
					}
					i++;
				}
				if(cont==1){	
					printf("\n");
					printf("Pok�mon excluido com sucesso!\n");
					printf("\n");
				}
				else{
					printf("\n");
					printf("Pok�mon n�o encontrado!\n");
					printf("\n");
				}
				system("pause");
				break;
			}
		}
	}while(x!=3);
}

void update(){
	int x;
	int num;
	char nome[30];
	float alt; 
	float peso;
	char tipo[30]; 
	char weak[30];
	char evo[30];
	int cont;
	do{
		system("cls");
		printf("\n");
		printf("Escolha a op��o de busca para atualiza��o:\n");
		printf("\n");
		printf("1. Buscar por n�mero\n");
		printf("2. Buscar por nome\n");
		printf("3. Voltar ao menu anterior\n");
		printf("\n");
		scanf("%d", &x);
		switch(x){
			case 1:{
				cont=0;
				printf("Digite o n�mero do Pok�mon: ");
				scanf("%d", &num);
				int i=0;
				while(pokemon[i].livre==1){
					if(pokemon[i].num==num){
						do{
							system("cls");
							printf("\n");
							printf("Pok�mon n�mero %d encontrado\n", num);
							printf("\n");
							printf("Escolha o que deseja atualizar:\n");
							printf("\n");
							printf("1. Atualizar o n�mero\n");
							printf("2. Atualizar o nome\n");
							printf("3. Atualizar a altura\n");
							printf("4. Atualizar o peso\n");
							printf("5. Atualizar o tipo\n");
							printf("6. Atualizar as fraquezas\n");
							printf("7. Atualizar a evolu��o\n");
							printf("8. Voltar ao menu anterior\n");
							printf("\n");
							scanf("%d", &x);
							switch(x){
								case 1:{
									system("cls");
									printf("\n");
									printf("Digite o novo n�mero do Pok�mon\n");
									printf("\n");
									printf("N�mero: ");
									scanf("%d", &num);
									pokemon[i].num=num;
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 2:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite o novo nome do Pok�mon\n");
									printf("\n");
									printf("Nome: ");
									fgets(nome, sizeof(nome), stdin);
									strcpy(pokemon[i].nome, nome);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 3:{
									system("cls");
									printf("\n");
									printf("Digite a nova altura do Pok�mon\n");
									printf("\n");
									printf("Altura: ");
									scanf("%f", &alt);
									pokemon[i].alt=alt;
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 4:{
									system("cls");
									printf("\n");
									printf("Digite o novo peso do Pok�mon\n");
									printf("\n");
									printf("Peso: ");
									scanf("%f", &peso);
									pokemon[i].peso=peso;
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 5:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite o novo tipo do Pok�mon\n");
									printf("\n");
									printf("Tipo: ");
									fgets(tipo, sizeof(tipo), stdin);
									strcpy(pokemon[i].tipo, tipo);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 6:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite as novas fraquezas do Pok�mon\n");
									printf("\n");
									printf("Fraquezas: ");
									fgets(weak, sizeof(weak), stdin);
									strcpy(pokemon[i].weak, weak);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 7:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite a nova evolu��o do Pok�mon\n");
									printf("\n");
									printf("Evolu��o: ");
									fgets(evo, sizeof(evo), stdin);
									strcpy(pokemon[i].evo, evo);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
							}
						}while(x!=8);
						cont=1;
					}
					i++;
				}
				if(cont==0){
					printf("\n");
					printf("Pok�mon n�o encontrado!\n");
					printf("\n");
				}
				system("pause");
				break;
			}
			case 2:{
				cont=0;
				setbuf(stdin, NULL);
				printf("Digite o nome do Pok�mon: ");
				fgets(nome, sizeof(nome), stdin);
				int i=0;
				while(pokemon[i].livre==1){
					if(strcmp(nome, pokemon[i].nome)==0){
						do{
							system("cls");
							printf("\n");
							printf("Pok�mon encontrado\n");
							printf("\n");
							printf("Escolha o que deseja atualizar:\n");
							printf("\n");
							printf("1. Atualizar o n�mero\n");
							printf("2. Atualizar o nome\n");
							printf("3. Atualizar a altura\n");
							printf("4. Atualizar o peso\n");
							printf("5. Atualizar o tipo\n");
							printf("6. Atualizar as fraquezas\n");
							printf("7. Atualizar a evolu��o\n");
							printf("8. Voltar ao menu anterior\n");
							printf("\n");
							scanf("%d", &x);
							switch(x){
								case 1:{
									system("cls");
									printf("\n");
									printf("Digite o novo n�mero do Pok�mon\n");
									printf("\n");
									printf("N�mero: ");
									scanf("%d", &num);
									pokemon[i].num=num;
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 2:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite o novo nome do Pok�mon\n");
									printf("\n");
									printf("Nome: ");
									fgets(nome, sizeof(nome), stdin);
									strcpy(pokemon[i].nome, nome);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 3:{
									system("cls");
									printf("\n");
									printf("Digite a nova altura do Pok�mon\n");
									printf("\n");
									printf("Altura: ");
									scanf("%f", &alt);
									pokemon[i].alt=alt;
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 4:{
									system("cls");
									printf("\n");
									printf("Digite o novo peso do Pok�mon\n");
									printf("\n");
									printf("Peso: ");
									scanf("%f", &peso);
									pokemon[i].peso=peso;
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 5:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite o novo tipo do Pok�mon\n");
									printf("\n");
									printf("Tipo: ");
									fgets(tipo, sizeof(tipo), stdin);
									strcpy(pokemon[i].tipo, tipo);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 6:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite as novas fraquezas do Pok�mon\n");
									printf("\n");
									printf("Fraquezas: ");
									fgets(weak, sizeof(weak), stdin);
									strcpy(pokemon[i].weak, weak);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
								case 7:{
									system("cls");
									setbuf(stdin, NULL);
									printf("\n");
									printf("Digite a nova evolu��o do Pok�mon\n");
									printf("\n");
									printf("Evolu��o: ");
									fgets(evo, sizeof(evo), stdin);
									strcpy(pokemon[i].evo, evo);
									printf("\n");
									printf("Pok�mon atualizado com sucesso!\n");
									printf("\n");
									system("pause");
									break;
								}
							}
						}while(x!=8);
						cont=1;
					}
					i++;
				}
				if(cont==0){
					printf("\n");
					printf("Pok�mon n�o encontrado!\n");
					printf("\n");
				}
				system("pause");
				break;
			}
		}
	}while(x!=3);
}

void busca(){
	int x;
	int cont;
	int num;
	char nome[30];
	do{
		system("cls");
		printf("\n");
		printf("Escolha a op��o de busca:\n");
		printf("\n");
		printf("1. Buscar por n�mero\n");
		printf("2. Buscar por nome\n");
		printf("3. Voltar ao menu anterior\n");
		printf("\n");
		scanf("%d", &x);
		switch(x){
			case 1:{
				cont=0;
				printf("Digite o n�mero do Pok�mon: ");
				scanf("%d", &num);
				int i=0;
				while(pokemon[i].livre==1){
					if(pokemon[i].num==num){
						printf("\n");
						printf("Pok�mon encontrado:\n");
						printf("\n");
						printf("N�mero: %d\n", pokemon[i].num);
						printf("Nome: %s", pokemon[i].nome);
						printf("Tipo: %s", pokemon[i].tipo);
						printf("Altura: %.1fm\n", pokemon[i].alt);
						printf("Peso: %.1fkg\n", pokemon[i].peso);
						printf("Fraquezas: %s", pokemon[i].weak);
						printf("Evolu��o: %s", pokemon[i].evo);
						cont=1;
					}
					i++;
				}
				if(cont==0){	
					printf("\n");
					printf("Pok�mon n�o encontrado!\n");
					printf("\n");
				}
				system("pause");
				break;
			}
			case 2:{
				cont=0;
				setbuf(stdin, NULL);
				printf("Digite o nome do Pok�mon: ");
				fgets(nome, sizeof(nome), stdin);
				int i=0;
				while(pokemon[i].livre==1){
					if(strcmp(nome, pokemon[i].nome)==0){
						printf("\n");
						printf("Pok�mon encontrado:\n");
						printf("\n");
						printf("N�mero: %d\n", pokemon[i].num);
						printf("Nome: %s", pokemon[i].nome);
						printf("Tipo: %s", pokemon[i].tipo);
						printf("Altura: %.1fm\n", pokemon[i].alt);
						printf("Peso: %.1fkg\n", pokemon[i].peso);
						printf("Fraquezas: %s", pokemon[i].weak);
						printf("Evolu��o: %s", pokemon[i].evo);
						cont=1;
					}
					i++;
				}
				if(cont==0){	
					printf("\n");
					printf("Pok�mon n�o encontrado!\n");
					printf("\n");
				}
				system("pause");
				break;
			}
		}
	}while(x!=3);
}

void exibir(){
	system("cls");
	if(pokemon[0].livre==0){
		printf("\n");
		printf("N�o existem Pok�mons cadastrados!\n");
		printf("\n");
	}
	else{
		printf("\n");
		printf("Pok�mons cadastrados:\n");
		for(int i=0;i<tam;i++){
			if(pokemon[i].livre==1){
				printf("\n");
				printf("N�mero: %d\n", pokemon[i].num);
				printf("Nome: %s", pokemon[i].nome);
				printf("Tipo: %s", pokemon[i].tipo);
				printf("Altura: %.1fm\n", pokemon[i].alt);
				printf("Peso: %.1fkg\n", pokemon[i].peso);
				printf("Fraquezas: %s", pokemon[i].weak);
				printf("Evolu��o: %s", pokemon[i].evo);
			}
		}
	}
}
