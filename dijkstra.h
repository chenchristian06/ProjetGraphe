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



long* creer_pere(long nb_sommets);
double* creer_poids(long nb_sommets);
double* depart_poids(long i, double* tab_poids);
Liste creation_pas_visite(long nb_sommets);
Liste creation_deja_visite(void);
Liste supprime_liste(Liste l,long x);
long recherche_min(double* l,long nb_sommets, Liste C);
long test_presence(Liste l, long x);


#endif /* dijkstra_h */
