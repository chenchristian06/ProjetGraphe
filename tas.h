//
//  tas.h
//  tritas
//
//  Created by Chen Christian on 14/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//
#include "graphe.h"
#ifndef tas_h
#define tas_h
typedef struct{
    long sommet;
    double poids;
} TAS;
TAS* augmentetas(TAS* tas,long i,T_SOMMET* g);
void supprime_tete_tas(TAS* tas,long taille_tas,T_SOMMET* g);
void echange_tas(TAS* tas,T_SOMMET* g,long i,long k);
void descendretas(TAS* tas,T_SOMMET* g, long i, long indice_pere);
#endif /* tas_h */
