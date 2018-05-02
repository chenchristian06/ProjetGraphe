//
//  dijkstra.h
//  Projet1A
//
//  Created by Chen Christian on 02/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#ifndef dijkstra_h
#define dijkstra_h
#include"liste.h"
int* creer_pere(int nb_sommets);
double* creer_poids(int nb_sommets);
double* depart_poids(int i, double* tab_poids);
Liste creation_pas_visite(int nb_sommets);
Liste creation_deja_visite(void);
Liste supprime_liste(Liste l,int x);
int recherche_min(double* l,int nb_sommets, Liste C);
int test_presence(Liste l, int x);
#endif /* dijkstra_h */
