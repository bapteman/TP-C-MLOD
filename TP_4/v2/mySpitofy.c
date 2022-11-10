#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListOfMusic.h"

#define MAX_LENGTH 100;


Liste readMusic(FILE* file){
    char* ligne =malloc(350);
    fgets(ligne,350,file);
    char* txt=ligne;
    Music* en_cours;
    char* name;
    char* artist;
    char* album;
    char* genre;
    char* Disc_number;
    char* Track_number;
    char* Year;
        name = strsep(&txt,",");
        artist = strsep(&txt,",");
        album = strsep(&txt,",");
        genre = strsep(&txt,",");
        Disc_number = strsep(&txt,",");
        Track_number = strsep(&txt,",");
        Year = strsep(&txt,",");
        en_cours=créerMusique(name,artist,album,genre,Disc_number,Track_number,Year);
        Liste music=creer(en_cours);
        Liste debut=music;
        while(!feof(file)){
            fgets(ligne,350,file);
            txt=ligne;
            name = strsep(&txt,",");
            artist = strsep(&txt,",");
            album = strsep(&txt,",");
            genre = strsep(&txt,",");
            Disc_number = strsep(&txt,",");
            Track_number = strsep(&txt,",");
            Year = strsep(&txt,",");
            en_cours=créerMusique(name,artist,album,genre,Disc_number,Track_number,Year);
            ajoutFin_i(en_cours,music);
        }
        free(ligne);
        //free(music);
        return debut;
}

char* annee(Element v){
    Music* v1=(Music *)v;
    return v1->annee;
}

Liste triParAnnee(Liste l){
    int compteur=1;
    Liste c=l;
    Liste next=c->suiv;
    Liste nextnext=next->suiv;
    Liste triplenext=nextnext->suiv;
     while(compteur!=0){
        c=l;
        compteur=0;
      for(int i=0;i<2700;i++){

            next=c->suiv;
            nextnext=next->suiv;
            triplenext=nextnext->suiv;
            if(strcmp(annee(next->val),annee(nextnext->val))>0){

                compteur=1;
                c->suiv=nextnext;
                nextnext->suiv=next;
                next->suiv=triplenext;

            }
            c=c->suiv;
        }
    }
    return l;
}

int main(void){
    FILE* f = fopen("music.csv", "r");
    Liste l = readMusic(f);
    l=triParAnnee(l);
    afficheListe_i(l);
    detruire_i(l);
    return 0;
}