#include <stdio.h>

void echangeContenu(int *a, int *b){
    int stockage = *a;
    *a=*b;
    *b=stockage;
}

int main(void){
    int a= 10;
    int b=20;
    echangeContenu(&a,&b);
    printf("a=%i et b=%i", a,b );
    return 0;
}