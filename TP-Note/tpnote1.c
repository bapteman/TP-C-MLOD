//Baptiste SENECLAUZE

#include <stdio.h>
#include <stdlib.h>

int *repeat(int t1[], int t2[], int taille){
    int sommet1=0;
    for( int i=0; i<taille ; i++){
        sommet1 += t1[i];
    };
    int *tabResultat = (int *)calloc(sommet1, sizeof(int));
    int compteur = 0;
    for( int i=0; i<taille ; i++){
        for (int j=0;j< t1[i];j++){
            tabResultat[compteur]=t2[i];
            compteur++;
            //printf("%i", *(tabResultat + compteur));
        }
    }
    return tabResultat;
}

int main(void){
    int taille =3;
    int t1[3] = {1,2,4};
    int t2[3] = {10,3,8};
    int *tabResult = repeat(t1,t2,taille);
    int sommet1=0;
    for( int i=0; i<taille ; i++){
        sommet1 += t1[i];
    };
    for (int i=0;i<sommet1; i++){
        printf("%i \n", tabResult[i]);
    }
       


}