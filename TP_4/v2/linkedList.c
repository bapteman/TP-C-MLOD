#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
    Liste res = malloc(sizeof(Cellule));
    if(!estVide(res)){
        res->val=v;
        res->suiv=NULL;
    }
	return res;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
    Liste l2=creer(v);
    l2->suiv=l;
	return l2;
}


void afficheElement(Element e);


// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
    if(estVide(l)){
        printf("liste vide");
    }
    else{
        while(!estVide(l)){
            afficheElement(l->val);
            printf(" ");
            l=(*l).suiv;
        }
    }printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
    if(estVide(l)){
        printf(" \n");
    }else{
        afficheElement(l->val);
        afficheListe_r((*l).suiv);
    }
}

void detruireElement(Element e);

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
    Liste suivant;
    Liste courant = l;
	if(estVide(l)){
        printf("liste vide");
    }
    else{
        while(courant->suiv != NULL){
            suivant=courant->suiv;
            detruireElement(courant->val);
            free(courant);
            courant=suivant;
        }
    }
}

// version récursive
void detruire_r(Liste l) {
    Liste suivant; 
    Liste courant = l;
	if(!estVide(courant)){
        
        suivant =courant->suiv;
        detruireElement((*courant).val);
        free(courant);
        detruire_r(suivant);
    }
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste c=l;
    if(estVide(c)){
        return creer(v);
    }
    while(c->suiv!=NULL){
            c=(c->suiv);
    }
    c->suiv=creer(v);
    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l->suiv)){
        l->suiv = creer(v);
    }else{
        ajoutFin_r(v,l->suiv);
    }
    return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2);


// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
    Liste c = l;
    while(!estVide(c)){
        if(equalsElement(v, c->val)){
            return c;
        }else{
            c = c->suiv;
        }
    }return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(equalsElement(v, l->val)){
        return l;
    }else if( !estVide(l->suiv) )
    {
        return cherche_r(v,l->suiv);
    }else{
        return NULL;
    }
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste c=l;
    if(estVide(l)){
        return l;
    }
    Liste p= l->suiv;
    if (equalsElement(c->val, v)){
        l->suiv = NULL;
        detruire_r(l);
        return p;
    }
    while(!estVide(p->suiv)){
	    if(equalsElement(p->val, v)){
                
                c->suiv = p->suiv;
                p->suiv = NULL;
                detruire_r(p);
                return l;
        } else{
            c=p;
            p=p->suiv;  
        }
    }
    if(equalsElement(p->val,v)){
        c->suiv = NULL;
        detruire_r(p);
        return l;
    }
    return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
    Liste c=cherche_r(v,l);
    if (!estVide(c)){
	    detruireElement(c->val);
    }
    return l;
}


void afficheEnvers_r(Liste l) {
	Liste c=l;
    if(!estVide(c->suiv)){
        afficheEnvers_r(c->suiv);
        afficheElement(c->val);
    }else{afficheElement(c->val);}
    
}