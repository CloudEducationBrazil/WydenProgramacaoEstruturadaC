#include <iostream>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//using namespace std;

int main() {
	
	int a;
	
	printf("Digite um valor?");
	scanf("%d", &a);
	
	system("pause");

	printf("Valor \n%d\n", a);

	printf("\n");
	
	if ( a == 2 ) { 
	   printf("sim"); 
	}
	else
	{ printf("não");
	}
	
	int b;
	
	for (b = 1; b > 10; ++b)
	{
		printf("%d\n", b);
	}
	
	return 0;
}

int estudo ()
{  int t = 99;
   printf("%d/n", t);
}
