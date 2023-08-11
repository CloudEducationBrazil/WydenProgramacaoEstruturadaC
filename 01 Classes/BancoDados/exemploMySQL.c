#include <stdio.h>
#include <stdlib.h>
// Incluir a Biblioteca MYSQL do BD - Instalar a instância do MYSQL SERVER - Criar um BD com suas ENTIDADES.
// Tipo API do MYSQL no código
#include <mysql/mysql.h>

// Variáveis para especificar a parametrização de conexão com o BD
static char *host = "localhost"; // Nome do SERVER, a instância do BD, pondendo ser o IP
static char *user = "root"; // Usuário DEFAULT
static char *pass = "123"; // Sennha do BD
static char *db_name = "DB_ALUNO"; // Nome do Banco de Dados
unsigned int port = "3306"; // Porta default

int main(void) {
    // Declaração da variável conexao, para conectar com o BD
    MYSQL conexao;
    //char script[500]; // Variável controle para instrução SQL
    // sprintf(script, "SELECT * from %s where nome = '%s';", entidade, dadoFiltroCampo);
    //int sql; // Variável controle para retorno da conexão

    // Preparar para Inicialiar conexão com o banco de dados
    mysql_init(&conexao);

    // Realizar conexão com o banco de dados, se conexão com SUCESSO... executa uma TRANSAÇÃO
    if ( mysql_real_connect(&conexao, host, user, pass, db_name, port) ){
        // Instrução para transação SQL: por exemplo CRUD; script ...
        //mysql_query(&conexao, 'insert into tabAluno (mat, nome) values ('123', 'Julia') ); // Tabela tabAluno do BD
        // printf("\nRegistro inserido com sucesso... %l", (long) mysql_affected_rows(&conexao));
        printf("\n conexão realizada com sucesso...");

        // Fechar conexão com o banco de dados
        mysql_close(&conexao);
    } else {
              // Mensagem de Erro - Motivo conexão não realizada com o BD
              printf("\n Erro na Conexão com o BD");
              printf("\n Erro %d %s", mysql_errno(&conexao), mysql_error(&conexao));
    }
}
