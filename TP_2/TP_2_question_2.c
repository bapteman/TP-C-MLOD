#include <stdint.h>
#include <stdlib.h>*

#define SIZE 5
typedef int matrice;


void matrix_mult(matrice resultat[][SIZE], matrice matrice1[][SIZE], matrice matrice2[][SIZE]){     //taille fixée
    int stockage = 0;
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            for (int k=0;k<SIZE;k++){
                stockage += matrice1[k][i] * matrice2[j][k];
            }
            resultat[i][j]=stockage;
            stockage=0;
        }
    }
}

typedef struct{
    int ligne;
    int colonne;
    int **valeur;
}Matrix;


void matrix_mult_2(Matrix resultat, Matrix matrice1, Matrix matrice2){      //taille quelconque
    int stockage = 0;
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            for (int k=0;k<SIZE;k++){
                stockage += matrice1.valeur[k][i] * matrice2.valeur[j][k];
            }
            resultat.valeur[i][j]=stockage;
            stockage=0;
        }
    }
}

void matrix_print(matrice matrice_resultat[][SIZE]){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            printf("%i ", matrice_resultat[i][j]);
        }
        printf("\n \n");
    }
}

int main(void) {
    //matrices en ligne * colonne
    matrice matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    matrice matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    matrice matriceResultat[SIZE][SIZE];
    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);
    return EXIT_SUCCESS;
}

