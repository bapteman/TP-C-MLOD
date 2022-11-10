#pragma once

#include "linkedList.h"

typedef struct{
	char* name;
    char* artiste;
    char* album;
    char* genre;
    char* discNumber;
    char* trackNumber;
    char* annee;
}Music;

Music* créerMusique(char* name, char* artiste, char* album, char* genre, char* discNumber, char* trackNumber, char* annee);