#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main()
{   char nome[14], cidade[20];
    int idade;
    float altura;
    char sexo;

    //strcpy(nome, "julia cardoso");
    printf("nome: "); fgets(nome, 14, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    if ( strlen(nome) >= 13 )
      flush_in();

    printf("idade: "); scanf("%d", &idade);
    flush_in();
    
    printf("sexo: "); sexo = fgetc(stdin);

    printf("altura: "); scanf("%f", &altura);
    flush_in();

    printf("cidade: "); scanf("%20[^\n]", cidade);

    system("clear");
    printf("%s \n", nome);
    printf("%s \n", cidade);

    return 0;
}
