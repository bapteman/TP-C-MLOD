#include <stdio.h>

// typedef short TypeEntier; 
// on observe que à partir de factorielle 8 (40320) les valeurs ne sont plus les bonnes car la valeur dépasse le maximum du type short (32 767).
typedef unsigned long TypeEntier;
//on observe que les résultats sont corrects jusque factorielle 13 (6227020800) car cette valeur dépasse le maximum des unsigned long (4 294 967 295)
TypeEntier factorielle(TypeEntier n){
    TypeEntier f=1;
    for (TypeEntier i =1;i<=n;i++){
        f=f*i;
    }
    return f;
};



int main(void){
    TypeEntier i=0;
    /* scanf("%i", &i); */
    TypeEntier x = factorielle(13);
    printf("%i \n", x);
};