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
	printf("nombre de gagnants : %i\n", nbGagnants);
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

void sortByYears(winner *resultat,int nbGagnants){
	int tri=1;
	int i=0;
	while(tri != 0){
		tri=0;
		for (int j=0;j<nbGagnants-1;j++){
			if(resultat[j].annee > resultat[j+1].annee){
				winner inversion=resultat[j];
				resultat[j]=resultat[j+1];
				resultat[j+1]=inversion;
				tri++;
			}
		}
	}
}

void addNewWinner(winner *resultat, int nbGagnants){
	winner newWinner;
	/* printf("annee ? : ");
	scanf("%i", &(newWinner.annee)); */
	newWinner.annee=2016;
	newWinner.name = "Baptiste Seneclauze";
	newWinner.raison = "TP sur le prix turing";
	resultat = (winner *)realloc(resultat,(nbGagnants+1)*sizeof(winner));
	resultat[nbGagnants]=newWinner;
}

int main(void)
{
	int nbGagnants = scanLineAsInt();
	//printf("nbGagnants = %i\n",nbGagnants);

	winner *resultat;
	nbGagnants = 3;
	resultat = readWinners(nbGagnants);
	addNewWinner(resultat,nbGagnants);
	nbGagnants++;
	//sortByYears(resultat,nbGagnants);
	printWinners(resultat, nbGagnants);
	//infosAnnees(nbGagnants, 2008);
	for(int i=0;i<nbGagnants;i++){
		free((resultat+i)->name);
		free((resultat+i)->raison);
	}
	free(resultat); 

	return EXIT_SUCCESS;

}