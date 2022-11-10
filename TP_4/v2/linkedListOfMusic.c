#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



bool equalsElement(Element e1, Element e2){
    Music *m1 = (Music *)e1;
    Music *m2 = (Music *)e2;
    return (strcmp(m1->name,m2->name)==0 && strcmp(m1->artiste,m2->artiste)==0 && strcmp(m1->album,m2->album)==0 && strcmp(m1->genre,m2->genre)==0 && strcmp(m1->discNumber,m2->discNumber)==0 && strcmp(m1->annee,m2->annee)==0 && strcmp(m1->trackNumber,m2->trackNumber)==0);
}

void afficheElement(Element v){
    Music* v1=(Music *)v;
    printf("%s ,", v1->name);
    printf("%s ,", v1->artiste);
    printf("%s ,", v1->album);
    printf("%s ,", v1->genre); 
    printf("%s ,", v1->discNumber);
    printf("%s ,", v1->trackNumber);
    printf("%s\n", v1->annee); 
}

void detruireElement(Element v){
    Music* v1=(Music *)v;
    free(v1->name);
    free(v1->album);
    free(v1->genre);
    free(v1->artiste);
    free(v1->discNumber);
    free(v1->trackNumber);
    free(v1->annee);
    free(v1);
}

Music* créerMusique(char* name,char* artist,char* album,char* genre,char* Disc_number,char* Track_number, char* Year){
    Music* newM = malloc(sizeof(Music));
    newM->name=strdup(name);
    newM->artiste=strdup(artist);
    newM->album=strdup(album);
    newM->genre=strdup(genre);
    newM->discNumber=strdup(Disc_number);
    newM->trackNumber=strdup(Track_number);
    newM->annee=strdup(Year);
    return newM;
}