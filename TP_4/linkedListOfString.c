#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

bool equalsElement(Element e1, Element e2){
    return (e1==e2);
}

void afficheElement(Element v){
    printf("%s", v);
}

void detruireElement(Element v){

}

int main(void){
   Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("a",l);
	l = ajoutTete("h",l);
	l = ajoutTete("g",l);
	l = ajoutTete("f",l);
	l = ajoutTete("e",l);
	l = ajoutTete("d",l);
	l = ajoutTete("c",l);
	l = ajoutTete("b",l);
	l = ajoutTete("a",l);

	afficheListe_i(l);

	ajoutFin_i(" ajout1",l);
	afficheListe_i(l);

	ajoutFin_r(" ajout2",l);
	afficheListe_i(l);

	 p = cherche_i("w",l);
	printf("cherche_i(w) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i(" ajout2",l);
	if(estVide(p))
		printf("cherche_i( ajout2) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i( ajout2) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("w",l);
	printf("cherche_r(w) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("a",l);
	if(estVide(p))
		printf("cherche_r(a) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(a) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(a)   : ");
	l = retirePremier_i("a",l);
	afficheListe_r(l);

	printf("retirePremier_i(a)   : ");
	l = retirePremier_i("a",l);
	afficheListe_r(l);

	 printf("retirePremier_i(g) : ");
	l = retirePremier_i("g",l);
	afficheListe_r(l);

	/* printf("retirePremier_r(4)   : ");
	l = retirePremier_r(4,l);
	afficheListe_r(l);

	printf("retirePremier_r(4)   : ");
	l = retirePremier_r(4,l);
	afficheListe_r(l);

	printf("retirePremier_r(99)  : ");
	l = retirePremier_r(99,l);
	afficheListe_r(l);  */

	afficheEnvers_r(l);

	detruire_r(l); 
	//afficheListe_i(l);

	

	return EXIT_SUCCESS;
}