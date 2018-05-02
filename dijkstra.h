//
//  dijkstra.h
//  Projet1A
//
//  Created by Chen Christian on 02/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#ifndef dijkstra_h
#define dijkstra_h
#include "liste.h"
int* creer_pere(int nb_sommets);
int* creer_poids(int nb_sommets);
void depart_poids(int i, int* tab_poids);
Liste creation_pas_visite(int nb_sommets);
Liste creation_deja_visite(void);
Liste supprime_liste(Liste l,int x);
int recherche_min(int* l,int nb_sommets);
int test_presence(Liste l, int x);
#endif /* dijkstra_h */
