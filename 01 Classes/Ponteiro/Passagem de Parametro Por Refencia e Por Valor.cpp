#include <stdio.h>

int teste(int *a);

int main(){
    int a=5;
    printf("%d aqui 1 \n", a);	
    teste(&a);
    printf("%d aqui 3 \n", a);	
    
	int x=19;
	int *p;
	p = &x;
	printf("%p \n", &x);
	printf("%p \n", &p);
	printf("%d \n", *p);
    
	return 0;
}


int teste(int *a){
    *a = 8;
    printf("%d aqui 2 \n", *a);	
	return *a;
}
