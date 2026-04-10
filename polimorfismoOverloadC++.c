#include <iostream>

int soma(int a){
    return a + 5;
}

int soma(int a, int b){
    return a + b;
}

int soma(float a){
    return a + 6;
}


int main()
{
    std::cout<< soma(3) << std::endl;
    std::cout<< soma(4,7) << std::endl;
    std::cout<< soma(9.5f) << std::endl;

    return 0;
}
