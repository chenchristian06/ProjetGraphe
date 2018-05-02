//
//  listes.h
//  TD9
//
//  Created by Chen Christian on 23/01/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//
#define liste_h
struct cellule {
    int val;
    struct cellule * suiv;} ;

typedef struct cellule* Liste;

Liste creer_liste(void);
int liste_vide(Liste l);
void visualiser(Liste l);
Liste ajout_tete(int k,Liste l);
Liste supprimer_tete(Liste l);
void  liberer(Liste  l);
Liste ajout_queue(int k , Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l1);
Liste supprimen(int n, Liste l);


