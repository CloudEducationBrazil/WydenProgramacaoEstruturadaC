#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void listarAlunos(MYSQL *conn) {
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *sql_select = "SELECT * FROM alunos;";

    if (mysql_query(conn, sql_select)) {
        printf("Erro SELECT: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        printf("Erro mysql_store_result(): %s\n", mysql_error(conn));
        return;
    }

    printf("\n--- LISTA DE ALUNOS ---\n");

    while ((row = mysql_fetch_row(res))) {
        printf("ID: %s | Nome: %s | Curso: %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(res);
}

void inserirAluno(MYSQL *conn) {
    char nome[100];
    char curso[100];
    char query[300];

    printf("Digite o nome do aluno: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Digite o curso do aluno: ");
    fgets(curso, sizeof(curso), stdin);
    curso[strcspn(curso, "\n")] = 0;

    snprintf(query, sizeof(query),
             "INSERT INTO alunos (nome, curso) VALUES ('%s', '%s');",
             nome, curso);

    if (mysql_query(conn, query)) {
        printf("Erro INSERT: %s\n", mysql_error(conn));
        return;
    }

    printf("Aluno inserido com sucesso!\n");
}

void atualizarAluno(MYSQL *conn) {
    int id;
    char nome[100];
    char curso[100];
    char query[400];

    printf("Digite o ID do aluno para atualizar: ");
    scanf("%d", &id);
    limparBuffer();

    printf("Digite o novo nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Digite o novo curso: ");
    fgets(curso, sizeof(curso), stdin);
    curso[strcspn(curso, "\n")] = 0;

    snprintf(query, sizeof(query),
             "UPDATE alunos SET nome='%s', curso='%s' WHERE id=%d;",
             nome, curso, id);

    if (mysql_query(conn, query)) {
        printf("Erro UPDATE: %s\n", mysql_error(conn));
        return;
    }

    printf("Aluno atualizado com sucesso!\n");
}

void deletarAluno(MYSQL *conn) {
    int id;
    char query[200];

    printf("Digite o ID do aluno para deletar: ");
    scanf("%d", &id);
    limparBuffer();

    snprintf(query, sizeof(query),
             "DELETE FROM alunos WHERE id=%d;",
             id);

    if (mysql_query(conn, query)) {
        printf("Erro DELETE: %s\n", mysql_error(conn));
        return;
    }

    printf("Aluno deletado com sucesso!\n");
}

int main() {
    system("chcp 65001 > nul");

    MYSQL *conn;

    // mysql://root:nbAWTAWJenwSAtiQtzlMNRtsiDiZZITI@yamabiko.proxy.rlwy.net:43507/railway
    char *server = "yamabiko.proxy.rlwy.net";
    unsigned int port = 43507;    
    char *user = "root";
    char *password = "nbAWTAWJenwSAtiQtzlMNRtsiDiZZITI";
    char *database = "railway";

/*  char *server = "localhost";
    char *user = "root";
    char *password = "123456";
    char *database = "agendadb"; */

    conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("Erro mysql_init(): sem memória\n");
        system("pause");
        return 1;
    }

/*    if (mysql_real_connect(conn, server, user, password, database, 3306, NULL, 0) == NULL) {
        printf("Erro na conexão: %s\n", mysql_error(conn));
        mysql_close(conn);
        system("pause");
        return 1;
    } */

    if (mysql_real_connect(conn, server, user, password, database, port, NULL, 0) == NULL) {
        printf("Erro na conexão: %s\n", mysql_error(conn));
        mysql_close(conn);
        system("pause");
        return 1;
    }    

    printf("Conectado ao MySQL com sucesso!\n");

    const char *sql_create =
        "CREATE TABLE IF NOT EXISTS alunos ("
        "id INT AUTO_INCREMENT PRIMARY KEY,"
        "nome VARCHAR(100) NOT NULL,"
        "curso VARCHAR(100) NOT NULL"
        ");";

    if (mysql_query(conn, sql_create)) {
        printf("Erro CREATE TABLE: %s\n", mysql_error(conn));
        mysql_close(conn);
        system("pause");
        return 1;
    }

    int opcao;

    do {
        printf("\n========= MENU CRUD =========\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Atualizar aluno\n");
        printf("4 - Deletar aluno\n");
        printf("0 - Sair\n");
        printf("=============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                inserirAluno(conn);
                break;
            case 2:
                listarAlunos(conn);
                break;
            case 3:
                atualizarAluno(conn);
                break;
            case 4:
                deletarAluno(conn);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    mysql_close(conn);
    printf("Conexão encerrada.\n");

    system("pause");
    return 0;
}