# https://youtu.be/3hNWZ3zOqdA - buffer stdin
#include <stdio.h>
#include <locale.h>
#include <string.h>

# define MAX 10

void limparBuffer();

void limparBuffer(){
    char c;
    do {
	    c = getchar();
    } while ( c != '\n' && c != EOF );
} 

int main(void)
{
    setlocale(LC_ALL, "Portuguese.Brasil");
    int idade;
    char nome[MAX];
    char cidade[MAX];
    float altura;
    char sexo;
    
    system("clear");
    
    //setbuf(stdin, NULL);
    printf("Idade: "); scanf("%d", &idade);
    limparBuffer();
    
    printf("Nome: "); fgets(nome, MAX, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    //printf("%d", strlen(nome));
    if ( strlen(nome) >= 9 )
      limparBuffer();

    printf("Cidade: "); fgets(cidade, MAX, stdin);
    cidade[strcspn(cidade, "\n")] = '\0';
    
    //printf("tamanho %d", strlen(cidade));
    if ( strlen(cidade) >= 9 )
      limparBuffer();

    printf("Altura: "); scanf("%f", &altura);
    limparBuffer();
    
    printf("Sexo: "); sexo = getchar();

    system("clear");

    printf("Idade=> %d\n", idade);
    printf("Nome=> %s\n", nome);
    printf("Cidade=> %s\n", cidade);
    printf("Altura=> %f\n", altura);
    printf("Sexo=> %c", sexo);
    
    return 0;
}