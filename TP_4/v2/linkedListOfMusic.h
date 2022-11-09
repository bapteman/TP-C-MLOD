#pragma once

#include <linkedList.h>

typedef struct{
	char* name;
    char* artiste;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int annee;
}Music;

Music* créerMusique(char* name, char* artiste, char* album, char* genre, int discNumber, int trackNumber, int annee);