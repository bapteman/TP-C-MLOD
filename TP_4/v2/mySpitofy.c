#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linkedListOfMusic.h>


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

Liste readMusic(){
    Music* current;
    Liste readFichier = creer(current);
    char* line;
    char* name;
    char* artiste;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int annee;
    while("pas fin du fichier"){
        line = scanline();
        name = strstep(line, ",");
        artiste = strstep(line, ",");
        album = strstep(line, ",");
        genre = strstep(line, ",");
        discNumber = (int)strstep(line, ",");
        trackNumber = (int)strstep(line, ",");
        annee = (int)strstep(line, ",");
        current= créerMusique(name,artiste,album,genre,discNumber,trackNumber,annee);
        readFichier = ajoutFin_i(current,readFichier);
    }
    return readFichier;
}

int main(void){
    return 0;
}