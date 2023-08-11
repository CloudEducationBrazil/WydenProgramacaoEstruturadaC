//Aluno: ilmar Macedo Alves Junior
//Disciplina: Linguagem de Programação
//Matrícula; 181030275
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<malloc.h>
int Menugeral();
int Menualterar();
void Motivoviagem(int escolha);
void Transporte(int escolha);
void Escolha(int*p);
typedef struct{
	int dia;
	int mes;
	int ano;
}data;
typedef struct{
	int numero;
	char tipo[50];
	char orgaoexp[10];
}documento;
typedef struct{
	int motivo;
	int transporte;
}viagem;
typedef struct{
	char Nome[50];
	data Nascimento;
	char Profissao[30];
	char Nacionalidade[30];
	documento Identidade;
	char Endereco[150];
	int Telefone;
	int Cep;
	char Cidade[30];
	char Estado[30];
	char Pais[50];
	char Ultdestino[100];
	char Proxdestino[100];
	viagem Detalhes;
	char Email[40];	
}cadastro;
#define Maxhospedes 3
int main(void){
	setlocale(LC_ALL,"");
	cadastro Hospede[Maxhospedes];
	int x,y=0, registro=0, cont=0;;
	int opcao, escolha1, escolha2, opcao2, escolha3;
	char chave1[50], chave2[50], chave3[50];
	FILE *Arquivo, *Arquivo2;
	do{
		opcao=Menugeral();
		switch(opcao){
			case 1:{ //Incluir
				for(x=y;x<Maxhospedes;x++){
					system("cls||clear");
					printf("--------------------CADASTRO DE HÓSPEDES--------------------");
					printf("\nQual o nome do hóspede? "); scanf(" %s",&Hospede[x].Nome);
					printf("\nQual o dia de nascimento do hóspede? "); scanf("%d", &Hospede[x].Nascimento.dia);
					printf("\nQual o mes de nascimento do hóspede? "); scanf("%d", &Hospede[x].Nascimento.mes);
					printf("\nQual o ano de nascimento do hóspede? "); scanf("%d", &Hospede[x].Nascimento.ano);
					printf("\nQual a profissão do hóspede? "); scanf(" %s",&Hospede[x].Profissao);
					printf("\nQual a nacionalidade do hóspede? "); scanf(" %s",&Hospede[x].Nacionalidade);
					system("cls||clear");
					printf("\nDocumento de Identidade");
					printf("\nQual o numero do documento?(somente números): "); scanf("%d", &Hospede[x].Identidade.numero);
					printf("\nQual o  tipo do documento? ");scanf(" %s", &Hospede[x].Identidade.tipo);
					printf("\nQual o órgão expeditor? ");scanf(" %s", &Hospede[x].Identidade.orgaoexp);
					printf("\nQual o endereço do hóspede? "); scanf(" %s",&Hospede[x].Endereco);
					printf("\nQual o telefone do hóspede? "); scanf("%d",&Hospede[x].Telefone);
					printf("\nQual o CEP do hóspede? "); scanf("%d",&Hospede[x].Cep);
					printf("\nCidade do hóspede? "); scanf(" %s",&Hospede[x].Cidade);
					printf("\nEstado do hóspede? "); scanf(" %s",&Hospede[x].Estado);
					printf("\nPaís do hóspede? "); scanf(" %s",&Hospede[x].Pais);
					system("cls||clear");
					printf("\nQual foi o último destino do hóspede? "); scanf(" %s",&Hospede[x].Ultdestino);
					printf("\nQual o próximo destino do hóspede? "); scanf(" %s",&Hospede[x].Proxdestino);
					system("cls||clear");
					printf("\nQual o motivo da viagem do hóspede?");
					printf("\n1-Férias;\n2-Negócios;\n3-Congresso;\n3-Estudos\n4-Saúde\n5-Outro:\n"); scanf("%d",&Hospede[x].Detalhes.motivo);
					printf("\nQual o meio de transporte utilizado pelo hóspede?");
					printf("\n1-Automóvel;\n2-Avião;\n3-Navio;\n3-Ônibus\n4-Trem\n5-Outro:\n"); scanf("%d",&Hospede[x].Detalhes.transporte);
					printf("\nQual o email do hóspede? "); scanf(" %s",&Hospede[x].Email);
					registro ++;y++;cont++;
					Escolha(&x);
					}getchar();system("cls||clear");
				break;
			}
			case 2:{//Altera
				printf("\nQual o nome do hóspede que será alterado? "); scanf(" %s",&chave1);
				for(x=0;x<Maxhospedes;x++){
					if (strcmp (Hospede[x].Nome, chave1) == 0){
						system("cls||clear");
						opcao2=Menualterar();
						switch(opcao2){
							case 1:{ printf("\nQual o nome do hóspede? "); scanf(" %s",&Hospede[x].Nome);
								break;
							}
							case 2:{
								printf("\nQual o dia de nascimento do hóspede? "); scanf("%d", &Hospede[x].Nascimento.dia);
								printf("\nQual o mes de nascimento do hóspede? "); scanf("%d", &Hospede[x].Nascimento.mes);
								printf("\nQual o ano de nascimento do hóspede? "); scanf("%d", &Hospede[x].Nascimento.ano);
								break;
							}
							case 3:{printf("\nQual a profissão do hóspede? "); scanf(" %s",&Hospede[x].Profissao);
								break;
							}
							case 4:{printf("\nQual a nacionalidade do hóspede? "); scanf(" %s",&Hospede[x].Nacionalidade);
								break;
							}
							case 5:{printf("\nQual o numero do documento?(somente números) "); scanf("%d", &Hospede[x].Identidade.numero);
								break;
							}
							case 6:{printf("\nQual o  tipo do documento? ");scanf(" %s",& Hospede[x].Identidade.tipo);
								break;
							}
							case 7:{printf("\nQual o órgão expeditor? ");scanf(" %s",& Hospede[x].Identidade.orgaoexp);
								break;
							}
							case 8:{printf("\nQual o endereço do hóspede? "); scanf(" %s",&Hospede[x].Endereco);
								break;
							}
							case 9:{printf("\nQual o telefone do hóspede? "); scanf("%d",&Hospede[x].Telefone);
								break;
							}
							case 10:{printf("\nQual o CEP do hóspede? "); scanf("%d",&Hospede[x].Cep);
								break;
							}
							case 11:{printf("\nCidade do hóspede? "); scanf(" %s",&Hospede[x].Cidade);
								break;
							}
							case 12:{printf("\nEstado do hóspede? "); scanf(" %s",&Hospede[x].Estado);
								break;
							}
							case 13:{printf("\nPaís do hóspede? "); scanf(" %s",&Hospede[x].Pais);
								break;
							}
							case 14:{printf("\nQual foi o último destino do hóspede? "); scanf(" %s",&Hospede[x].Ultdestino);
								break;
							}
							case 15:{printf("\nQual o próximo destino do hóspede? "); scanf(" %s",&Hospede[x].Proxdestino);
								break;
							}
							case 16:{	printf("\nQual o motivo da viagem do hóspede?");
								printf("\n1-Férias;\n2-Negócios;\n3-Congresso;\n4-Estudos\n5-Saúde\n6-Outro:\n"); scanf("%d",&Hospede[x].Detalhes.motivo);
								break;
							}
							case 17:{printf("\nQual o meio de transporte utilizado pelo hóspede?");
								printf("\n1-Automóvel;\n2-Avião;\n3-Navio;\n4-Ônibus\n5-Trem\n6-Outro:\n"); scanf("%d",&Hospede[x].Detalhes.transporte);
								break;
							}
							case 18:{printf("\nQual o email do hóspede? "); scanf(" %s",&Hospede[x].Email);
								break;
							}
							default: printf("\nOpção inválida!");
						}
					}
				}system("cls||clear");
				break;
			}
			case 3:{//Excluir
				printf("\nQual o nome do hóspede que deve ser excluido? "); gets(chave2);
				for(x=0;x<Maxhospedes;x++){
					if (strcmp (Hospede[x].Nome, chave2) == 0){
						strcpy(Hospede[x].Nome,"Vazio");
						Hospede[x].Cep=0;
						Hospede[x].Telefone=0;
						Hospede[x].Nascimento.dia=0;
						Hospede[x].Nascimento.mes=0;
						Hospede[x].Nascimento.ano=0;
						Hospede[x].Detalhes.motivo=0;
						Hospede[x].Detalhes.transporte=0;
						Hospede[x].Identidade.numero=0;
						strcpy(Hospede[x].Identidade.tipo,"0");
						strcpy(Hospede[x].Identidade.orgaoexp,"0");
						strcpy(Hospede[x].Cidade,"0");
						strcpy(Hospede[x].Email,"0");
						strcpy(Hospede[x].Endereco,"0");
						strcpy(Hospede[x].Estado,"0");
						strcpy(Hospede[x].Nacionalidade,"0");
						strcpy(Hospede[x].Pais,"0");
						strcpy(Hospede[x].Profissao,"0");
						strcpy(Hospede[x].Proxdestino,"0");
						strcpy(Hospede[x].Ultdestino,"0");
						registro--;
					}
				}
				getchar();	system("cls||clear");	
				break;
			}
			case 4:{//Consulta
				printf("\nQual o nome do hóspede a ser consultado? "); scanf(" %s",chave3);getchar();
				for(x=0;x<Maxhospedes;x++){
					if (strcmp (Hospede[x].Nome, chave3) == 0){
						printf("---------------REGISTRO DO HÓSPEDE---------------");
						printf("\nNome: %s", Hospede[x].Nome);
						printf("\tData de Nascimento: %d/%d/%d",Hospede[x].Nascimento.dia, Hospede[x].Nascimento.mes, Hospede[x].Nascimento.ano);
						printf("\nProfissão: %s", Hospede[x].Profissao);
						printf("\tNacionalidade: %s",Hospede[x].Nacionalidade);
						printf("\nNúmero do documento: %d", Hospede[x].Identidade.numero);
						printf("\tTipo do documento: %s",Hospede[x].Identidade.tipo);
						printf("\tOrgão expeditor: %s",Hospede[x].Identidade.orgaoexp);
						printf("\nEndereço: %s",Hospede[x].Endereco);
						printf("\nTelefone: %d",Hospede[x].Telefone);
						printf("\tCEP: %d",Hospede[x].Cep);
						printf("\nCidade: %s",Hospede[x].Cidade);
						printf("\tEstado: %s",Hospede[x].Estado);
						printf("\tPaís: %s",Hospede[x].Pais);
						printf("\nÚltimo destino: %s",Hospede[x].Ultdestino);
						printf("\nPróximo destino: %s",Hospede[x].Proxdestino);
						Motivoviagem(Hospede[x].Detalhes.motivo);
						Transporte(Hospede[x].Detalhes.transporte);
						printf("\nEmail: %s\n",Hospede[x].Email); getchar();
					}
				}
				system("cls||clear");
				break;
			}
			case 5:{ //Salvar num arquivo tx
				Arquivo=fopen("Cadastro.txt", "wt");
			 	if ( Arquivo == NULL ) { 
			 		printf("Erro ao criar o arquivo"); 
					return 0; };
					for(x=0;x<Maxhospedes;x++){
						fprintf(Arquivo,"\n%s\t%d \t%d \t%d \t%s \t%s \t%d \t%s \t%s \t%s \t%d \t%d \t%s \t%s \t%s \t%s \t%s \t%d \t%d \t%s \t%d", Hospede[x].Nome, Hospede[x].Nascimento.dia, Hospede[x].Nascimento.mes, Hospede[x].Nascimento.ano, Hospede[x].Profissao, Hospede[x].Nacionalidade, Hospede[x].Identidade.numero,Hospede[x].Identidade.tipo, Hospede[x].Identidade.orgaoexp,Hospede[x].Endereco,Hospede[x].Telefone,Hospede[x].Cep,Hospede[x].Cidade,Hospede[x].Estado,Hospede[x].Pais,Hospede[x].Ultdestino,Hospede[x].Proxdestino,Hospede[x].Detalhes.motivo,Hospede[x].Detalhes.transporte,Hospede[x].Email);
						}
						fclose(Arquivo); printf("\nDados exportados com sucesso");
						getchar();system("cls||clear");
						break;
					}
					case 6:{//carregar um arquivo txt
						Arquivo=fopen("Cadastro.txt", "rt");
						if ( Arquivo == NULL ) { 
			 				printf("Erro ao ler o arquivo");
			 				return 0;};
			 				x=0;
			 				while(!feof(Arquivo)){
								fscanf(Arquivo,"\n%s\t%d \t%d \t%d \t%s \t%s \t%d \t%s \t%s \t%s \t%d \t%d \t%s \t%s \t%s \t%s \t%s \t%d \t%d \t%s", &Hospede[x].Nome, &Hospede[x].Nascimento.dia, &Hospede[x].Nascimento.mes, &Hospede[x].Nascimento.ano, &Hospede[x].Profissao, &Hospede[x].Nacionalidade, &Hospede[x].Identidade.numero,&Hospede[x].Identidade.tipo, &Hospede[x].Identidade.orgaoexp,&Hospede[x].Endereco,&Hospede[x].Telefone,&Hospede[x].Cep,&Hospede[x].Cidade,&Hospede[x].Estado,&Hospede[x].Pais,&Hospede[x].Ultdestino,&Hospede[x].Proxdestino,&Hospede[x].Detalhes.motivo,&Hospede[x].Detalhes.transporte,&Hospede[x].Email);
								x++;
							 }
							  fclose(Arquivo);
							 	printf("\nDados importados com sucesso"); getchar(); system("cls||clear");
						break;
					}
					case 7:{//Listar
					Arquivo2=fopen("C:/Users/Ilmar/Downloads/Registros.txt", "wt");
			 		if ( Arquivo2 == NULL ) { 
			 			printf("Erro ao criar o arquivo"); 
						return 0; };
					fprintf(Arquivo2,"---------------REGISTROS DOS HÓSPEDES---------------");
					for(x=0;x<Maxhospedes;x++){
						fprintf(Arquivo2,"\n[%d]", x);
						fprintf(Arquivo2,"\nNome: %s", Hospede[x].Nome);
						fprintf(Arquivo2,"\tData de Nascimento: %d/%d/%d",Hospede[x].Nascimento.dia, Hospede[x].Nascimento.mes, Hospede[x].Nascimento.ano);
						fprintf(Arquivo2,"\nProfissão: %s", Hospede[x].Profissao);
						fprintf(Arquivo2,"\tNacionalidade: %s",Hospede[x].Nacionalidade);
						fprintf(Arquivo2,"\nNúmero do documento: %d", Hospede[x].Identidade.numero);
						fprintf(Arquivo2,"\tTipo do documento: %s",Hospede[x].Identidade.tipo);
						fprintf(Arquivo2,"\tOrgão expeditor: %s",Hospede[x].Identidade.orgaoexp);
						fprintf(Arquivo2,"\nEndereço: %s",Hospede[x].Endereco);
						fprintf(Arquivo2,"\nTelefone: %d",Hospede[x].Telefone);
						fprintf(Arquivo2,"\tCEP: %d",Hospede[x].Cep);
						fprintf(Arquivo2,"\nCidade: %s",Hospede[x].Cidade);
						fprintf(Arquivo2,"\tEstado: %s",Hospede[x].Estado);
						fprintf(Arquivo2,"\tPaís: %s",Hospede[x].Pais);
						fprintf(Arquivo2,"\nÚltimo destino: %s",Hospede[x].Ultdestino);
						fprintf(Arquivo2,"\nPróximo destino: %s",Hospede[x].Proxdestino);
						switch(Hospede[x].Detalhes.motivo){
							case 1:{fprintf(Arquivo2,"\nMotivo da viagem: Férias");
								break;
							}
							case 2:{fprintf(Arquivo2,"\nMotivo da viagem: Negócios");
								break;
							}
							case 3:{fprintf(Arquivo2,"\nMotivo da viagem: Congresso");
								break;
							}
							case 4:{fprintf(Arquivo2,"\nMotivo da viagem: Estudo");
								break;
							}
							case 5:{fprintf(Arquivo2,"\nMotivo da viagem: Saúde");
								break;
							}
							default: fprintf(Arquivo2,"\nMotivo da viagem: Outro");
							}
						switch(Hospede[x].Detalhes.transporte){
							case 1:{fprintf(Arquivo2,"\nTransporte da viagem: Automóvel");
								break;
							}
							case 2:{fprintf(Arquivo2,"\nTransporte da viagem: Avião");
								break;
							}
							case 3:{fprintf(Arquivo2,"\nTransporte da viagem: Navio");
								break;
							}
							case 4:{fprintf(Arquivo2,"\nTransporte da viagem: Ônibus");
								break;
							}
							case 5:{fprintf(Arquivo2,"\nTransporte da viagem: Trem");
								break;
							}
							default:fprintf(Arquivo2,"\nTransporte da viagem: Outro");
							}
						fprintf(Arquivo2,"\nEmail: %s",Hospede[x].Email);
						}
						fclose(Arquivo2);getchar();
						break;
					}
					case 8:{//Listar na tela
					system("cls||clear");
					printf("---------------REGISTROS DOS HÓSPEDES---------------");
					for(x=0;x<Maxhospedes;x++){
						printf("\n[%d]",x+1),
						printf("\nNome: \t%s", Hospede[x].Nome);
						printf("\tData de Nascimento: %d/%d/%d",Hospede[x].Nascimento.dia, Hospede[x].Nascimento.mes, Hospede[x].Nascimento.ano);
						printf("\nProfissão: %s", Hospede[x].Profissao);
						printf("\tNacionalidade: %s",Hospede[x].Nacionalidade);
						printf("\nNúmero do documento: %d", Hospede[x].Identidade.numero);
						printf("\tTipo do documento: %s",Hospede[x].Identidade.tipo);
						printf("\tOrgão expeditor: %s",Hospede[x].Identidade.orgaoexp);
						printf("\nEndereço: %s",Hospede[x].Endereco);
						printf("\nTelefone: %d",Hospede[x].Telefone);
						printf("\tCEP: %d",Hospede[x].Cep);
						printf("\nCidade: %s",Hospede[x].Cidade);
						printf("\tEstado: %s",Hospede[x].Estado);
						printf("\tPaís: %s",Hospede[x].Pais);
						printf("\nÚltimo destino: %s",Hospede[x].Ultdestino);
						printf("\nPróximo destino: %s",Hospede[x].Proxdestino);
						Motivoviagem(Hospede[x].Detalhes.motivo);
						Transporte(Hospede[x].Detalhes.transporte);
						printf("\nEmail: %s\n",Hospede[x].Email);
						} getchar();
						system("cls||clear");
						break;
					}
			}
		setbuf(stdin, NULL);
		}while(opcao!= 0);
	system("pause");
	return 0;
}
int Menugeral(){
	int opcao;
		printf("\n Menu de Opções:\t");
		printf("\n 0-Sair ");
		printf("\n 1-Incluir um hóspede\n 2-Editar Dados\n 3-Excluir um hóspede\n 4-Consultar dados de um hóspede");
		printf("\n 5-Exportar registros\n 6-Importar registros");
		printf("\n 7-Listar Registros em um arquivo texto\n 8-Listar registros na tela");	 
		printf("\n Digite um numero para a opção desejada: ");
		scanf("%d",&opcao);
		setbuf(stdin, NULL);
		system("cls||clear");
		return opcao;
}
int Menualterar(){
	int opcao2;
	printf("\nQual dado deve ser alterado?");
	printf("\n1-Nome"); printf("\t\t\t10-CEP");
	printf("\n2-Nascimento"); printf("\t\t11-Cidade"); 
	printf("\n3-Profissão"); printf("\t\t12-Estado");
	printf("\n4-Nacionalidade"); printf("\t\t13-País");
	printf("\n5-Número do documento"); printf("\t14-Ultimo destino");
	printf("\n6-Tipo do documento"); printf("\t15-Próximo destino");
	printf("\n7-O orgão expeditor"); printf("\t16-Motivo da Viagem");
	printf("\n8-Endereço"); printf("\t\t17-Transporte utilizado na viagem");
	printf("\n9-Telefone"); printf("\t\t18-Email\n ");						
	scanf("%d",&opcao2);
	system("cls||clear");
	return opcao2;
}
void Escolha(int *p){
	int escolha;
	printf("\n1-Cadastrar mais\n2-Voltar para o menu: ");scanf("%d",&escolha);
	if(escolha==2) *p=Maxhospedes;
}
void Motivoviagem(int escolha){
	switch(escolha){
		case 1:{printf("\nMotivo da viagem: Férias");
			break;
		}
		case 2:{printf("\nMotivo da viagem: Negócios");
			break;
		}
		case 3:{printf("\nMotivo da viagem: Congresso");
			break;
		}
		case 4:{printf("\nMotivo da viagem: Estudo");
			break;
		}
		case 5:{printf("\nMotivo da viagem: Saúde");
			break;
		}
		default: printf("\nMotivo da viagem: Outro");
	}
}
void Transporte(int escolha){
	switch(escolha){
		case 1:{printf("\nTransporte da viagem: Automóvel");
			break;
		}
		case 2:{printf("\nTransporte da viagem: Avião");
			break;
		}
		case 3:{printf("\nTransporte da viagem: Navio");
			break;
		}
		case 4:{printf("\nTransporte da viagem: Ônibus");
			break;
		}
		case 5:{printf("\nTransporte da viagem: Trem");
			break;
		}
		default:printf("\nTransporte da viagem: Outro");
	}
}
