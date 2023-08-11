#include <stdio.h>
#include <stdlib.h>
// Incluir a Biblioteca MYSQL do BD - Instalar a inst�ncia do MYSQL SERVER - Criar um BD com suas ENTIDADES.
// Tipo API do MYSQL no c�digo
// Senha:Equipe Ciencia da Computacao
//#include <windows.h>
//#include <winsock2.h> // -lwsock32
#include <mysql.h>

// Vari�veis para especificar a parametriza��o de conex�o com o BD
static char *IP_MYSQL = "localhost"; // Nome do SERVER, a inst�ncia do BD, pondendo ser o IP
static char *USER_MYSQL = "julia"; // Usu�rio DEFAULT
static char *PASS_MYSQL = "julia123@"; // Sennha do BD
static char *DB_MYSQL = "academico"; // Nome do Banco de Dados
unsigned int PORT_MYSQL = 3306; // Porta default

int main(void) {
    // Declara��o da vari�vel conexao, para conectar com o BD
    MYSQL conexao;
    //char script[500]; // Vari�vel controle para instru��o SQL
    // sprintf(script, "SELECT * from %s where nome = '%s';", entidade, dadoFiltroCampo);
    //int sql; // Vari�vel controle para retorno da conex�o

    // Preparar para Inicialiar conex�o com o banco de dados
    mysql_init(&conexao);

 // Aqui tenho um servidor mysql rodando no IP: 127.0.0.1 com usu�rio "dev" sem senha "". ele conecta ao database "test"
    // Realizar conex�o com o banco de dados, se conex�o com SUCESSO... executa uma TRANSA��O
    if ( mysql_real_connect(&conexao, IP_MYSQL, USER_MYSQL, PASS_MYSQL, DB_MYSQL, PORT_MYSQL, NULL, 0) ){
        // printf("\nRegistro inserido com sucesso... %l", (long) mysql_affected_rows(&conexao));
        printf("\n conex�o realizada com sucesso...");

        char *sqlquery = "insert into academico.aluno (mataluno, nomaluno) values (988, 'jane');";
        // Instru��o para transa��o SQL: por exemplo CRUD; script ...
        if ( mysql_query(&conexao, sqlquery) == 0 )
          printf("\n inser��o realizada com sucesso...");

          // Fechar conex�o com o banco de dados
        mysql_close(&conexao);
    } else {
              // Mensagem de Erro - Motivo conex�o n�o realizada com o BD
              printf("\n Erro na Conex�o com o BD");
              printf("\n Erro %d %s", mysql_errno(&conexao), mysql_error(&conexao));
    }
}
