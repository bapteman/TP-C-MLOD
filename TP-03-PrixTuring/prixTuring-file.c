/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

typedef struct{
	char *name;
	char *annee;
	char *raison;
}winner;

winner *readWinners(int nbGagnants,FILE* turingWinners){
	
	winner *resultat=(winner *)calloc(nbGagnants,sizeof(winner));
	for(int i=0;i<nbGagnants;i++){
		fgets((resultat+i)->annee,200,turingWinners);
		fgets((resultat+i)->name,200,turingWinners);
		fgets((resultat+i)->raison,200,turingWinners);
	};
	return resultat;
}

void printWinners(winner *resultat,int nbGagnants){
	printf("%i\n", nbGagnants);
	for(int i=0;i<nbGagnants;i++){
		printf("%s\n", resultat[i].annee);
		printf("%s\n", resultat[i].name);
		printf("%s\n", resultat[i].raison);
	}
}

void infosAnnees(int nbGagnants, int annee, FILE* turingWinners){
	winner *resultat;
	resultat = readWinners(nbGagnants, turingWinners);
	int i=0;
	int stop =0;
	while (i<nbGagnants && stop != 1){
		if(resultat[i].annee==annee){
			printf("en %s le(s) gagnant(s) ont été %s\nnature des travaux : %s\n", resultat[i].annee, resultat[i].name,resultat[i].raison);
			stop = 1;
		}
		i++;
	}
	free(resultat);
}

int main(void)
{
    FILE* turingWinners;
    turingWinners = fopen("turingWinners.txt", "r");
    /* if(turingWinners==NULL) {
        printf ("Code de l'erreur : %d\n", errno);
        if (errno == ENOENT){
            printf ("Le fichier n'existe pas !\n");
        }else{
            printf ("Erreur inconnue\n");
    }return EXIT_FAILURE;
    } */

	int nbGagnants = 50;
	//printf("nbGagnants = %i\n",nbGagnants);

	winner *resultat;
	resultat = readWinners(nbGagnants,turingWinners);
	printWinners(resultat, nbGagnants); 
	//infosAnnees(nbGagnants, 2008);
    fclose(turingWinners);
	free(resultat); 

	return EXIT_SUCCESS;

}