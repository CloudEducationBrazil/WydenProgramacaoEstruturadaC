#include <stdio.h>
#define constAltura 20

typedef struct {
	int peso;
	int altura;
} PesoAltura;

typedef int CHAVE;

int main()
{   PesoAltura pessoa;
    pessoa.altura = 10;
    pessoa.peso = 20;
    int x = 25;
    int *y = &x;
    
	printf("Endereco X :%p -> Endereco Y :%p \n", &x, &y);

	printf("Altura:%d -> Peso:%d", pessoa.altura, pessoa.peso);
	
	if ( pessoa.altura > constAltura )
	  printf("\nAltura maior do que a constante definida");
	else
	  printf("\nAltura NAO eh maior do que a constante definida");
	  
	return 0;
}
