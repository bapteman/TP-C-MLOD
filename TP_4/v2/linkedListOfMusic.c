#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char* name;
    char* artiste;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int annee;
}Music;

bool equalsElement(Element e1, Element e2){
    Music *m1 = (Music *)e1;
    Music *m2 = (Music *)e2;
    return (strcmp(m1->name,m2->name)==0 && strcmp(m1->artiste,m2->artiste)==0 && strcmp(m1->album,m2->album)==0 && strcmp(m1->genre,m2->genre)==0 && m1->discNumber==m2->discNumber && m1->annee==m2->annee && m1->trackNumber==m2->trackNumber);
}

void afficheElement(Element v){
    Music* v1=(Music *)v;
    printf("%s, ", v1->name);
    printf("%s, ", v1->artiste);
    printf("%s, ", v1->album);
    printf("%s, ", v1->genre);
    printf("%i, ", v1->discNumber);
    printf("%i, ", v1->trackNumber);
    printf("%i\n", v1->annee);
}

void detruireElement(Element v){
    Music* v1=(Music *)v;
    free(v1->name);
    free(v1->album);
    free(v1->genre);
    free(v1->artiste);
    free(v1);
}

Music* créerMusique(char* name, char* artiste, char* album, char* genre, int discNumber, int trackNumber, int annee){
    Music* newMusic = malloc(sizeof(Music));
    newMusic->name = calloc(strlen(name), sizeof(char));
    newMusic->name = name;
    newMusic->artiste = calloc(strlen(artiste), sizeof(char));
    newMusic->artiste = artiste;
    newMusic->album = calloc(strlen(album), sizeof(char));
    newMusic->album = album;
    newMusic->genre = calloc(strlen(genre), sizeof(char));
    newMusic->genre = genre;
    newMusic->discNumber=discNumber;
    newMusic->trackNumber=trackNumber;
    newMusic->annee=annee;
}