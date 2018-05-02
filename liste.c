//
//  listes.c
//  TD9
//
//  Created by Chen Christian on 23/01/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
Liste creer_liste(void){
    return NULL;
}

int liste_vide(Liste l){
    if(l) return 1;
    else return 0;
}
//affiche les éléments de la liste
void visualiser(Liste l){
    Liste p=l;
    while(p!=NULL){
        affiche(&(p->val));
        p=p->suiv;
    }
puts("\n");
}
//Ajoute un élément en tête de la liste
Liste ajout_tete(int k,Liste l){
    Liste nv_liste = malloc(sizeof(*nv_liste));
    nv_liste->val = k;
    nv_liste->suiv = l;
    return nv_liste;
}
//supprime un élément en tête de liste
Liste supprimer_tete(Liste l){
    if(liste_vide(l)==1){
        Liste p=l->suiv;
        free(l);
        return p;
    }
    else return NULL;
}
//libère la liste
void liberer(Liste l){
    if(l!=NULL){
        liberer(supprimer_tete(l));
    }
}
// ajoute un élément en queue
Liste ajout_queue(int k, Liste l){
    Liste p = l;
    Liste nv = malloc(sizeof(*nv));
    nv->val = k;
    nv->suiv = NULL;
    if(liste_vide(l)==1){
        while(p->suiv!=NULL){
            p=p->suiv;
        }
        p->suiv = nv;
        return l;
    }
    else return nv;
}
// concatène 2 listes
Liste concat(Liste l1, Liste l2){
    Liste p = l1;
    if(liste_vide(l1)){
    while(p->suiv!=NULL){
        p=p->suiv;
    }
    p->suiv = l2;
    return l1;
    }
    else return l2;
}
// copie une liste 
Liste copie(Liste l1){
    Liste l2 = NULL;
    Liste p = l1;
    if(liste_vide(l1)){
    while(p!=NULL){
        l2 = ajout_queue(p->val, l2);
	p=p->suiv;
    }
    return l2;
    }
    return NULL;
}

Liste supprimen(int n, Liste l){
    int p = n;
    Liste q1 = l;
    while(p!=1){
        p-=1;
        q1 = q1->suiv;
	if(q1==NULL){
		puts("Vous avez dépassé la taille de la liste");
		exit(0);
	}
    }
    Liste q2 = q1->suiv;
    free(q1->suiv);
    q1->suiv = q2->suiv;
    return l;
}
