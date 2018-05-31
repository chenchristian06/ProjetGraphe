//
//  dijkstra.c
//  Projet1A
//
//  Created by Chen Christian on 13/04/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//
#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

//Dijkstra
long* creer_pere(long nb_sommets){
/*on créer un tableau de pere ou l'indice est le pere et le contenu est l'antécédent*/
    long* tab_pere;
    tab_pere = calloc(nb_sommets,sizeof(long));
    long i = 0;
    for(;i<nb_sommets;i++){
        *(tab_pere+i) = -1;
    }
    return tab_pere;
}

TAS* creer_poids(long nb_sommets,long depart,T_SOMMET* graphe){
    /*on crée le tas des poids ou à l'indice 0 on a le départ */
    TAS* tab_poids;
    tab_poids = calloc(nb_sommets,sizeof(*tab_poids));
    long i;
    long indice_tas = 1;
    for(i=0;i<nb_sommets;i++){
        if(i == depart){
            tab_poids[0].poids=0;
            tab_poids[0].sommet=i;
            graphe[i].position_tas=0;
        }
        else{
            tab_poids[indice_tas].poids = 0xffffffff;
            tab_poids[indice_tas].sommet = i;
            graphe[i].position_tas = indice_tas;
            indice_tas += 1;
            
        }
    }
    return tab_poids;
}





    




