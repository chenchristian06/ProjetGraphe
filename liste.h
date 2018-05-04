//
//  listes.h
//  TD9
//
//  Created by Chen Christian on 23/01/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//
#define liste_h
struct cellule {
    long val;
    struct cellule * suiv;} ;

typedef struct cellule* Liste;

Liste creer_liste(void);
long liste_vide(Liste l);
Liste ajout_tete(long k,Liste l);
Liste supprimer_tete(Liste l);
void  liberer(Liste  l);
Liste ajout_queue(long k , Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l1);
Liste supprimen(long n, Liste l);
void affichage(Liste l);


