//
//  main.c
//  Projet1A
//
//  Created by Chen Christian on 01/05/2018.
//  Copyright © 2018 Chen Christian. All rights reserved.
//

#include "graphe.h"


main(){
    T_SOMMET* g;
    char* nom_fichier;
    printf("Veuillez spécifier le nom de fichier où extraire le graphe \n ");
    //scanf("%s",nom_fichier);
    nom_fichier="/Users/chenchristian/Desktop/Projet1A/Projet1A/graphe1.txt";
    g = creer_graphe();
    int nb_sommets;
    int nb_arcs;
    g=creation_graphe(g, nom_fichier,&nb_sommets,&nb_arcs);
    visualiser_graphe(g,&nb_sommets,&nb_arcs);
    printf("le graphe crée");
}
