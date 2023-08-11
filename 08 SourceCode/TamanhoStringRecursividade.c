#include <stdio.h>
int tamanhoString(char texto[]);

int main(void)
{   int qtdCaracteres;
    char texto[100];
    
    printf("Digite o texto? "); scanf("%s", texto);
    qtdCaracteres = tamanhoString(texto);
    printf("qtd Caracteres: %d", qtdCaracteres);
}

int tamanhoString(char texto[]){
    if ( texto[0] == '\0' ) return 0;

    return 1 + tamanhoString( &texto[1] );
}

