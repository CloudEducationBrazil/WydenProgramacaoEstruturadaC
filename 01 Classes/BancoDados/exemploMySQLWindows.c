// Instalação : https://www.youtube.com/watch?v=rr2x_QGyoZo
// https://dev.mysql.com/downloads/connector/c/
// https://downloads.mysql.com/archives/c-c/?version=6.1.2&amp;os=src

#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
//#include <windows.h>
// Incluir a Biblioteca MYSQL do BD - Instalar a instância do MYSQL SERVER - Criar um BD com suas ENTIDADES.
// Tipo API do MYSQL no código
//#include <mysql/mysql.h> // Versao 12.04 Ubuntu
//#include <my_global.h>
//#include <C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h>

#include <windows.h>
#include <winsock2.h>
#include <mysql.h>

//#include <my_global.h>
//#if USE_MYSQL
//#include <mysql.h>
//#endif
//#include <C:/Program Files/MySQL/MySQL Server 8.0/include/mysql.h>
// mysql --version
// Variáveis para especificar a parametrização de conexão com o BD
//  mysql --user=root -password=
//  mysql -u username -p
// gcc mysql-teste.c -rdynamic -L/usr/lib64/mysql -lmysqlclient -lz -lcrypt -lnsl -lm -lssl -lcrypto -o exec-mysql mysql-teste.o

static char *host = "localhost"; //"localhost"; // Nome do SERVER, a instância do BD, pondendo ser o IP
static char *user = "root"; // Usuário DEFAULT
static char *password = "";//"123456"; // Sennha do BD
static char *database = "db_aluno"; // Nome do Banco de Dados
unsigned int port = 3306; // Porta default

int main (){
//int main (int argc, char *argv[]){
    // Declaração da variável conexao, para conectar com o BD
    MYSQL *conexao;
    MYSQL_RES *results;
    MYSQL_ROW row;
    printf("\n aqui...");

    mysql_init(conexao);
    //mysql_options(conexao, MYSQL_SET_CLIENT_IP, "127.0.0.1");
    //conexao = mysql_init(NULL);
    printf("\n aqui...");
    //char script[500]; // Variável controle para instrução SQL
    // sprintf(script, "SELECT * from %s where nome = '%s';", entidade, dadoFiltroCampo);
    //int sql; // Variável controle para retorno da conexão

    // Preparar para Inicialiar conexão com o banco de dados
    //gcc -o output-file $(mysql_config --cflags) mysql-c-api.c $(mysql_config --libs)
    // API http://www.dba86.com/docs/mysql/5.5/connectors-apis.html
    mysql_init(conexao);
    printf("\n aqui...");

    //mysql_options(mysql, MYSQL_SET_CLIENT_IP, "10.1.1.2");
    //results = mysql_store_result(mysql);

    // Realizar conexão com o banco de dados, se conexão com SUCESSO... executa uma TRANSAÇÃO
//if (!mysql_real_connect(conn, server,user2, password2, database2, 0, NULL, 0))
//    if ( mysql_real_connect(conexao, host, user, password, database, port, NULL, 0) ){
        // Instrução para transação SQL: por exemplo CRUD; script ...
        //mysql_query(&conexao, 'insert into tabAluno (mat, nome) values ('123', 'Julia') ); // Tabela tabAluno do BD
        // printf("\nRegistro inserido com sucesso... %l", (long) mysql_affected_rows(&conexao));
 //       printf("\n conexão realizada com sucesso...");

        // Fechar conexão com o banco de dados
   //     mysql_close(conexao);
   // } else {
              // Mensagem de Erro - Motivo conexão não realizada com o BD
    //          printf("\n Falha na Conexão com o BD");
     //         printf("\n Erro %d %s \n", mysql_errno(conexao), mysql_error(conexao));
   // }
}
