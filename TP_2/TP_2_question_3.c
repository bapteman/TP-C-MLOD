#include <stdio.h>
#include <stdlib.h>

enum mois {JANVIER=1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DEVEMBRE};

typedef struct{
    enum mois mois;
    int jour;
    int annee;
}date;

void initialiseDate(date *d){
    printf("numéro du jour ? ");
    scanf("%i", &d->jour);
    printf("numéro du mois ? ");
    scanf("%i", &d->mois); 
    printf("numéro de l'année ? ");
    scanf("%i", &d->annee); 

}

void afficheDate(date *d){
    printf("%d/%d/%d", d->jour,d->mois,d->annee);
}

date creerDateParCopie(){
    date acopier;
    initialiseDate(&acopier);
    return acopier;
}

date *newDate(){
    date *new; 
    new = (date *)malloc(sizeof(date));
    initialiseDate(new);
    return new;
}

int main(void){
    /* date d;
    initialiseDate(&d); //le & sert à ce que la fonction modifie bien la variable globale d en utilisant son adresse et pas uniquement la copie locale de la fonction 
    afficheDate(&d); */
    /* date d2;
    d2 = creerDateParCopie();
    afficheDate(&d2); */
    date *date;
    date = newDate();
    afficheDate(date);
    //...
    free(date);

}