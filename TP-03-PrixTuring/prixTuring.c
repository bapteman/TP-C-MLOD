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
typedef struct{
	char *name;
	int annee;
	char *raison;
}winner;

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}


winner *readWinners(int nbGagnants){
	
	winner *resultat=(winner *)calloc(nbGagnants,sizeof(winner));
	for(int i=0;i<nbGagnants;i++){
		(resultat+i)->annee=scanLineAsInt();
		(resultat+i)->name=scanLine();
		(resultat+i)->raison=scanLine();
	};
	return resultat;
}

void printWinners(winner *resultat,int nbGagnants){
	printf("%i\n", nbGagnants);
	for(int i=0;i<nbGagnants;i++){
		printf("%i\n", resultat[i].annee);
		printf("%s\n", resultat[i].name);
		printf("%s\n", resultat[i].raison);
	}
}

void infosAnnees(int nbGagnants, int annee){
	winner *resultat;
	resultat = readWinners(nbGagnants);
	int i=0;
	int stop =0;
	while (i<nbGagnants && stop != 1){
		if(resultat[i].annee==annee){
			printf("en %i le(s) gagnant(s) ont été %s\nnature des travaux : %s\n", resultat[i].annee, resultat[i].name,resultat[i].raison);
			stop = 1;
		}
		i++;
	}
	free(resultat);
}

int main(void)
{
	int nbGagnants = scanLineAsInt();
	//printf("nbGagnants = %i\n",nbGagnants);

	/* winner *resultat;
	resultat = readWinners(nbGagnants);
	printWinners(resultat, nbGagnants); */
	infosAnnees(nbGagnants, 2008);
	//free(resultat); 

	return EXIT_SUCCESS;

}