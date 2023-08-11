#include <stdio.h>
#include <mysql/mysql.h>

main(void)
{
MYSQL conexao;

mysql_init(&conexao);
mysql_real_connect(&conexao, "localhost", "guest", "guest", "teste", 0, NULL, 0);
printf("conectado com sucesso!\n");
mysql_close(&conexao);
}
