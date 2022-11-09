#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE_MAX 5

typedef struct{
    char* chunk;
    int chunkSize;
    struct String* next;
}String;

String* string_new(char* texte){
    String* stringResult = malloc(sizeof(String));
    if(strlen(texte)>CHUNK_SIZE_MAX){
        stringResult->chunkSize=CHUNK_SIZE_MAX;
        stringResult->chunk = calloc(CHUNK_SIZE_MAX,sizeof(char));
        for(int i=0;i<CHUNK_SIZE_MAX;i++){
            stringResult->chunk[i]=texte[i];
        }
        stringResult->next = string_new(&texte[CHUNK_SIZE_MAX]);
        return stringResult;
    }else{
        stringResult->chunkSize=strlen(texte);
        stringResult->chunk = calloc(strlen(texte),sizeof(char));
        stringResult->chunk=texte;
        stringResult->next=NULL;
        return stringResult;
        
    }
   
}

void printString(String* toPrint){
    printf("%s ", toPrint->chunk);
    if(toPrint->next != NULL){
        printString(toPrint->next);
    }
    printf("\n");
}

void freeAll(String* toFree){   //obligatoire pour éviter les fuites memoires
    while(toFree->next!=NULL){
        free(toFree->chunk);
        freeAll(toFree->next);  
        toFree->next=NULL;  
    }
    
    free(toFree);
}

int string_length(String* toLength){
    if(toLength->next != NULL){
        return toLength->chunkSize+string_length(toLength->next);
    }else{
        return toLength->chunkSize;
    }
}

/* String* string_insert_at(String* current, int indice, char* toInsert){
    if(indice>current->chunkSize){
        return string_insert_at(current->next, indice-CHUNK_SIZE_MAX, toInsert);
    }else{
        char* memoire; //pour garder en memoire le texte à deplacer
        String* memoire2; // pour garder en memoire la suite du texte aprés l'insertion
        for (int i=0;i<(current->chunkSize-(indice-1));i++){
            memoire[i]=current->chunk[i+indice-1];
            free(current->chunk[i+indice-1]);
            memoire2 = current->next;
        }
    }
} */

int main(void){
    String sTest;  // test de la fonction print
    sTest.chunkSize=4;
    sTest.chunk="test";
    sTest.next = NULL;
    printString(&sTest); 

    String* s = string_new("HELLO !"); //test de la fonction string_new
    printString(s);
    int l = string_length(s);
    printf("%i\n", l);
    freeAll(s);
}