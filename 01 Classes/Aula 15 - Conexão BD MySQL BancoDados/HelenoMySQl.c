#include <stdio.h>
#include <stdlib.h>
// Incluir a Biblioteca MYSQL do BD - Instalar a instância do MYSQL SERVER - Criar um BD com suas ENTIDADES.
// Tipo API do MYSQL no código
// Senha:Equipe Ciencia da Computacao
//#include <windows.h>
//#include <winsock2.h> // -lwsock32
#include <mysql.h>

// Variáveis para especificar a parametrização de conexão com o BD
static char *IP_MYSQL = "localhost"; // Nome do SERVER, a instância do BD, pondendo ser o IP
static char *USER_MYSQL = "julia"; // Usuário DEFAULT
static char *PASS_MYSQL = "julia123@"; // Sennha do BD
static char *DB_MYSQL = "academico"; // Nome do Banco de Dados
unsigned int PORT_MYSQL = 3306; // Porta default

int main(void) {
    // Declaração da variável conexao, para conectar com o BD
    MYSQL conexao;
    //char script[500]; // Variável controle para instrução SQL
    // sprintf(script, "SELECT * from %s where nome = '%s';", entidade, dadoFiltroCampo);
    //int sql; // Variável controle para retorno da conexão

    // Preparar para Inicialiar conexão com o banco de dados
    mysql_init(&conexao);

 // Aqui tenho um servidor mysql rodando no IP: 127.0.0.1 com usuário "dev" sem senha "". ele conecta ao database "test"
    // Realizar conexão com o banco de dados, se conexão com SUCESSO... executa uma TRANSAÇÃO
    if ( mysql_real_connect(&conexao, IP_MYSQL, USER_MYSQL, PASS_MYSQL, DB_MYSQL, PORT_MYSQL, NULL, 0) ){
        // printf("\nRegistro inserido com sucesso... %l", (long) mysql_affected_rows(&conexao));
        printf("\n conexão realizada com sucesso...");

        char *sqlquery = "insert into academico.aluno (mataluno, nomaluno) values (988, 'jane');";
        // Instrução para transação SQL: por exemplo CRUD; script ...
        if ( mysql_query(&conexao, sqlquery) == 0 )
          printf("\n inserção realizada com sucesso...");

          // Fechar conexão com o banco de dados
        mysql_close(&conexao);
    } else {
              // Mensagem de Erro - Motivo conexão não realizada com o BD
              printf("\n Erro na Conexão com o BD");
              printf("\n Erro %d %s", mysql_errno(&conexao), mysql_error(&conexao));
    }
}
