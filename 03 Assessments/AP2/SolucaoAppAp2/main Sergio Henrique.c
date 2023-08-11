#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define FinalizarPrograma 2147483646

typedef struct componente
{
	int codigo;
	char nome[20];
	char descricao[200];
	float valor;
} ComponenteEletronico;

typedef struct lista_componentes
{
	ComponenteEletronico componente;
	struct lista_componentes *proximo;
} LISTA_DE_COMPONENTES;

LISTA_DE_COMPONENTES *InicializarLista()
{
	LISTA_DE_COMPONENTES *nova_lista = NULL;
	return nova_lista;
}

void ExecutarPrograma();
void EntradaUsuario(char *string, int length);
bool Inserir(LISTA_DE_COMPONENTES **lista, ComponenteEletronico componente);
ComponenteEletronico *ConsultarComponente(LISTA_DE_COMPONENTES **lista, ComponenteEletronico componente_desejado);
void RegistrarNovoComponente(LISTA_DE_COMPONENTES **lista_componentes);
void ConsultarUmComponente(LISTA_DE_COMPONENTES **lista_componentes);
void AtualizarUmComponente(LISTA_DE_COMPONENTES **lista_componentes);
void RemoverUmComponente(LISTA_DE_COMPONENTES **lista_componentes);
void ExibirTodosComponentes(LISTA_DE_COMPONENTES **lista_componentes);
ComponenteEletronico *NovoComponente();
void TelaOpcoes(LISTA_DE_COMPONENTES **lista_componentes);
int exibirMenu();

int main(int argc, char *argv[])
{
	ExecutarPrograma();
	return 0;
}

void ExecutarPrograma()
{
	LISTA_DE_COMPONENTES *componentes_eletronicos = InicializarLista();
	TelaOpcoes(&componentes_eletronicos);
	ExibirTodosComponentes(&componentes_eletronicos);
}

bool Inserir(LISTA_DE_COMPONENTES **lista, ComponenteEletronico componente)
{
	if ((*lista) == NULL)
	{
		(*lista) = malloc(sizeof(LISTA_DE_COMPONENTES));
		(*lista)->componente = componente;
		(*lista)->proximo = NULL;
		return true;
	}

	LISTA_DE_COMPONENTES *ultimo = (*lista);
	do
	{
		if (ultimo->componente.codigo == componente.codigo)
			return false;

		if (ultimo->proximo == NULL)
			break;

		ultimo = ultimo->proximo;

	} while (true);

	LISTA_DE_COMPONENTES *novo_componente = malloc(sizeof(LISTA_DE_COMPONENTES));
	ultimo->proximo = novo_componente;
	novo_componente->componente = componente;
	novo_componente->proximo = NULL;
	return true;
}

ComponenteEletronico *ConsultarComponente(LISTA_DE_COMPONENTES **lista, ComponenteEletronico componente_desejado)
{
	LISTA_DE_COMPONENTES *atual = (*lista);
	ComponenteEletronico componente_retorno;

	if ((*lista) == NULL)
	{
		return NULL;
	}

	do
	{
		if (atual->componente.codigo == componente_desejado.codigo)
		{
			return &(atual->componente);
		}

		if (atual->proximo != NULL)
		{
			atual = atual->proximo;
		}
		else
		{
			return NULL;
		}
	} while (true);
}

void ExibirTodosComponentes(LISTA_DE_COMPONENTES **lista_componentes)
{
	LISTA_DE_COMPONENTES *atual = (*lista_componentes);

	if (atual == NULL)
		return;
	system("cls");

	int posicao = 0;

	do
	{
		printf("\n\nComponente:\n Codigo: %d\n Nome: %s\n Valor: %.2f\n Descricao: %s \n",
			   atual->componente.codigo,
			   atual->componente.nome,
			   atual->componente.valor,
			   atual->componente.descricao);

		if (atual->proximo == NULL)
			break;
		else
			atual = atual->proximo;
	} while (true);
}

ComponenteEletronico *NovoComponente()
{
	return malloc(sizeof(ComponenteEletronico));
}

void TelaOpcoes(LISTA_DE_COMPONENTES **lista_componentes)
{
	int retorno = -1;
	bool resultado_voto = false;
	ComponenteEletronico *componente_desejado;
	do
	{
		retorno = exibirMenu();
		switch (retorno)
		{
		case 1:
			RegistrarNovoComponente(lista_componentes);
			break;
		case 2:
			ConsultarUmComponente(lista_componentes);
			break;
		case 3:
			AtualizarUmComponente(lista_componentes);
			break;
		case 4:
			RemoverUmComponente(lista_componentes);
			break;
		case 5:
			ExibirTodosComponentes(lista_componentes);
			break;
		default:
			break;
		}
		if (retorno == FinalizarPrograma)
		{
			break;
		}

	} while (true);
}

void ConsultarUmComponente(LISTA_DE_COMPONENTES **lista_componentes)
{
	int l_codigo = 0;

	LISTA_DE_COMPONENTES *atual = (*lista_componentes);

	if (atual == NULL)
	{
		printf("Nao existem componentes cadastrados.");
		return;
	}
	printf("\n");

	printf("\nInsira o codigo para pesquisa:");
	scanf("%d", &l_codigo);

	int posicao = 0;
	do
	{
		if (atual->componente.codigo == l_codigo)
		{
			printf("Componente:\n Nome: %s\n Valor: %.2f%%\n Descricao: %s\n",
				   atual->componente.nome,
				   atual->componente.valor,
				   atual->componente.descricao);
			break;
		}
		if (atual->proximo == NULL)
		{
			printf("N�o existe um item para o c�digo solicitado");
			break;
		}
		else
			atual = atual->proximo;
	} while (true);
}

void AtualizarUmComponente(LISTA_DE_COMPONENTES **lista_componentes)
{
	int l_codigo = 0;

	LISTA_DE_COMPONENTES *atual = (*lista_componentes);

	if (atual == NULL)
		return;
	system("cls");

	printf("\nInsira o codigo do componente a ser editado:");
	scanf("%d", &l_codigo);

	int posicao = 0;
	do
	{
		if (atual->componente.codigo == l_codigo)
		{
			printf("Componente\n Nome: %s\n Valor: %.2f%%\n Descricao: %s",
				   atual->componente.nome,
				   atual->componente.valor,
				   atual->componente.descricao);

			printf("\nInsira um novo nome para o componente:");
			EntradaUsuario(atual->componente.nome, 20);
			printf("\nInsira uma nova descricao para este componente:");
			EntradaUsuario(atual->componente.descricao, 200);
			printf("\nInsira um novo valor para este componente:");
			scanf("%f\n", &(atual->componente.valor));
			break;
		}
		if (atual->proximo == NULL)
		{
			printf("Nao existe um item para o codigo solicitado.");
			break;
		}
		else
			atual = atual->proximo;
	} while (true);
}

void RegistrarNovoComponente(LISTA_DE_COMPONENTES **lista_componentes)
{

	ComponenteEletronico l_Componente;
	system("cls");

	printf("\nInsira um codigo para o novo componente:");
	scanf("%d", &l_Componente.codigo);
	printf("\nInsira um nome para o novo componente:");
	EntradaUsuario(l_Componente.nome, 20);
	printf("\nInsira uma descricao para este componente:");
	EntradaUsuario(l_Componente.descricao, 200);
	printf("\nInsira um valor para este componente:");
	scanf("%f", &l_Componente.valor);
	if (ConsultarComponente(lista_componentes, l_Componente) != NULL)
	{
		printf("Ja existe um componente utilizando este codigo.");
		return;
	}
	else
		Inserir(lista_componentes, l_Componente);
}

int exibirMenu()
{
	int l_opcao = -1;

	do
	{
		l_opcao = -1;
		printf("\n");
		printf("\nEscolha uma opcao: ");
		printf("\n0. Sair do Programa.");
		printf("\n1. Registrar um componente eletronico.");
		printf("\n2. Consultar um componente eletronico.");
		printf("\n3. Atualizar um componente eletronico.");
		printf("\n4. Remover um componente eletronico.");
		printf("\n5. Visualizar todos os componentes eletronicos.\n\n");

		scanf("%d", &l_opcao);

	} while (l_opcao > 5 || l_opcao < 0);
	if (l_opcao == 0)
		return FinalizarPrograma;
	else
		return l_opcao;
}

void RemoverUmComponente(LISTA_DE_COMPONENTES **lista_componentes)
{
	int l_codigo;
	printf("\nInsira o codigo do componente a ser editado:");
	scanf("%d", &l_codigo);

	LISTA_DE_COMPONENTES *anterior = NULL;
	LISTA_DE_COMPONENTES *apagar = (*lista_componentes);
	LISTA_DE_COMPONENTES *proximo = apagar->proximo;

	do
	{
		if (apagar->componente.codigo == l_codigo)
		{
			if (anterior != NULL)
			{
				anterior->proximo = apagar->proximo;
				free(apagar);
				return;
			}
			else
			{

				if (proximo == NULL)
				{
					free(apagar);
					(*lista_componentes) = InicializarLista();
				}
				else
				{
					(*lista_componentes) = apagar->proximo;
					free(apagar);
				}
				return;
			}
		}
		anterior = apagar;
		if (apagar->proximo != NULL)
		{
			apagar = apagar->proximo;
		}
		else
		{
			break;
		}

	} while (true);
}

void EntradaUsuario(char *string, int length)
{
	int x = 0;

	fgets(string, length, stdin);
	while (*string)
	{
		if (*string == '\n')
		{
			*string = '\0';
			fflush(stdin);
			return;
		}
		x++;
		if (x == length)
		{
			*string = '\0';
			fflush(stdin);
			return;
		}
		string++;
	}
}
