#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>

#define IP_MYSQL "127.0.0.1"
#define USER_MYSQL "root"
#define PASS_MYSQL ""
#define DB_MYSQL "debsys"

#define CADASTRAR 1
#define REMOVER 2
#define LISTAR 3
#define LIMPAR 4
#define SAIR 0

#define TAM 2000

void consulta_tabela();
int conecta_ao_db();
int menu();
void cadastra_funcionario();
void remove_funcionario();
void lista_funcionario();
void protege_contra_sql_injection();

MYSQL conexao;
char comando_para_tratar[TAM], comando[TAM], op_menu[TAM];
char nome[TAM], telefone[TAM], cpf[TAM], cargo[TAM], salario[TAM], filhos[TAM];


//-----------------------------   MAIN ------------------------------------------
int main() {
  int menu_op = 5;

  while (menu_op != SAIR) {
    menu_op = menu();

    if (menu_op == CADASTRAR)
      cadastra_funcionario();
    else if (menu_op == REMOVER)
      remove_funcionario();
    else if (menu_op == LISTAR)
      lista_funcionario();
    else if (menu_op >= LIMPAR)
      system("cls");
  }

  printf("\n");
  mysql_close(&conexao);
  system("PAUSE");
  return(0);
}
//-------------------------------FIM MAIN--------------------------------------
void consulta_tabela() {
  int i;

// Faz uma busca na tabela
  if (mysql_query(&conexao, "SELECT * FROM pessoa") != 0) {
    printf("Falha de cconsulta\n");
  }

  MYSQL_RES *result = mysql_store_result(&conexao);

  if (result == NULL) {
    printf("Falha no result\n");
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result))) {
    for(i = 0; i < num_fields; i++) {
      printf("%s ", row[i] ? row[i] : "NULL");
    }
    printf("\n");
  }

  mysql_free_result(result);
}


int conecta_ao_db() { // retorna 1 se conectou com sucesso
                      // retorna 0 caso tenha dado falha na conexão

  // Aqui tenho um servidor mysql rodando no IP: 127.0.0.1 com usuário "dev" sem senha "". ele conecta ao database "test"
  if ( mysql_real_connect(&conexao, IP_MYSQL, USER_MYSQL, PASS_MYSQL, DB_MYSQL, 0, NULL, 0) ) {
    return 1;
  } else {
    printf("\nFalha de conexao");
    printf("\nErro %d : %s", mysql_errno(&conexao), mysql_error(&conexao));
    return 0;
  }

}

int menu() {
  int valida = 1, op, i;

  printf("\n\n\n##  1   | Cadastra funcionario");
  printf("\n##  2   | Remove funcionario");
  printf("\n##  3   | Lista funcionarios");
  printf("\n##  4+  | Limpa tela");
  printf("\n##  0   | EXIT");
  printf("\n\n##  Selecione uma opcao: ");

  do {
    valida = 1;
    scanf("%s", op_menu);

    for (i = 0; op_menu[i] != '\0'; i++)
      if( isdigit(op_menu[i]) == 0 )
        valida = 0;

    if (valida == 0)
      printf("\nSomente numeros positivos: ");

  } while (valida != 1);

  op = atoi(op_menu);

  system("cls");
  return op;
}

void cadastra_funcionario() {
  int i, j;

  mysql_init(&conexao);

  if(conecta_ao_db() == 1) {

    printf("\nDigite o nome: ");
    getchar();
    scanf("%[^\n]s", nome);
    getchar();
    printf("Digite o telefone: ");
    scanf("%[^\n]s", telefone);
    getchar();
    printf("Digite o cpf: ");
    scanf("%[^\n]s", cpf);
    getchar();
    printf("Digite o cargo: ");
    scanf("%[^\n]s", cargo);
    getchar();
    printf("Digite o salario: ");
    scanf("%[^\n]s", salario);
    getchar();
    printf("Quantos dependentes: ");
    scanf("%[^\n]s", filhos);
    getchar();

    //cria a query com os dados inseridos
    sprintf(comando,"insert into funcionario(nome, cpf, telefone, cargo, salario, filhos) values('%s', '%s', '%s', '%s', '%s', '%s')", nome, cpf, telefone, cargo, salario, filhos);
    protege_contra_sql_injection(); // no sql injection ;)

    system("cls");


    //retorna 0 se conseguir inserir, retorna 1 se não conseguir inserir
    if (mysql_query(&conexao, comando) == 0 )
      printf("\nInseriu com sucesso");
    else
      printf("\nErro ao Inserir dados no DB");
  }

  mysql_close(&conexao);
}


void remove_funcionario()  {
 mysql_init(&conexao);

  if(conecta_ao_db() == 1) {

    printf("\nDigite o nome do funcionario: ");
    getchar();
    scanf("%[^\n]s", nome);
    getchar();

    //cria a query com os dados inseridos
    sprintf(comando,"delete from funcionario where nome='%s'", nome);
    protege_contra_sql_injection(); // no sql injection ;)

    system("cls");

    //retorna 0 se conseguir inserir, retorna 1 se não conseguir inserir
    if (mysql_query(&conexao, comando) == 0 )
      printf("\nRemoveu com sucesso");
    else {
      printf("\nErro ao remover dados do DB");
      printf("\nErro %d : %s", mysql_errno(&conexao), mysql_error(&conexao));
    }
  }

  mysql_close(&conexao);
}

void lista_funcionario() {
  MYSQL_RES *result;
  MYSQL_ROW row;
  int i, num_fields;

  mysql_init(&conexao);

  if(conecta_ao_db() == 1) {

    if (mysql_query(&conexao, "SELECT * FROM funcionario") != 0) {
      printf("\nFalha de cconsulta");
    }
    result = mysql_store_result(&conexao);
    if (result == NULL) {
      printf("\nFalha no result");
    }

    num_fields = mysql_num_fields(result);

    printf("\n|     NOME     |     CPF    |    TELEFONE    |   CARGO   |  SALARIO  | FILHOS |\n");
    while ((row = mysql_fetch_row(result))) {
      for( i = 0; i < num_fields; i++) {
        printf("%s ", row[i] ? row[i] : "NULL");
        printf(" | ");
      }

      printf("\n");
    }
    printf("\n################# LISTA ####################\n");
    mysql_free_result(result);
  }
  mysql_close(&conexao);
}

void protege_contra_sql_injection() {
  int i;

  for (i = 0; i < strlen(nome) || nome[i] != '\0'; i++)
    if (nome[i] == '\'' || nome[i] == '\"')
      nome[i] = ' ';

  for (i = 0; i < strlen(cpf) || cpf[i] != '\0'; i++)
    if (cpf[i] == '\'' || cpf[i] == '\"')
      cpf[i] = ' ';

  for (i = 0; i < strlen(telefone) || telefone[i] != '\0'; i++)
    if (telefone[i] == '\'' || telefone[i] == '\"')
      telefone[i] = ' ';

  for (i = 0; i < strlen(cargo) || cargo[i] != '\0'; i++)
    if (cargo[i] == '\'' || cargo[i] == '\"')
      cargo[i] = ' ';

  for (i = 0; i < strlen(salario) || salario[i] != '\0'; i++)
    if (salario[i] == '\'' || salario[i] == '\"')
      salario[i] = ' ';

  for (i = 0; i < strlen(filhos) || filhos[i] != '\0'; i++)
    if (filhos[i] == '\'' || filhos[i] == '\"')
      filhos[i] = ' ';
}
