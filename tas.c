#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "tas.h"

void affichage(double* tab,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%lf ",tab[i]);
	}
	puts("\n");
}
//supprime la tête et le fait descendre
void supprime_tete_tas(TAS* tas,long taille_tas,T_SOMMET* g){
    echange_tas(tas, g, 0, taille_tas-1);
    descendretas(tas,g, taille_tas-1, 0);
}

//augmente un élément pour ne pas déranger la structure de tas
TAS* augmentetas(TAS* tas,long i,T_SOMMET* g){
	long ind = (i-1)/2;
	long j = i ;
	while((ind>=0)&&(tas[ind].poids>tas[j].poids)){
            echange_tas(tas, g, ind, j);
			j = ind;
			ind = (ind-1)/2;
		}
	return tas;
}
//fait descendre un élément pour qu'on garde la structure de tas
void descendretas(TAS* tas,T_SOMMET* g, long i, long indice_pere){
    if(i<=0) return;
    
    //selection du fils avec lequel on fera l'echange
    long indice_fils;
    long  fg=2*(indice_pere+1)-1, fd=2*(indice_pere+1);
    
    if(fg>i-1){ //il n'y a pas de fils
        return;
    }
    
    else if(fd>i-1){ //il n'y a qu'un fils
        indice_fils=fg;
    }
    
    else{ //il y a deux fils, on doit trouver le plus grand des deux.
        if(tas[fg].poids<=tas[fd].poids){
            indice_fils=fg;
        }
        
        else{
            indice_fils=fd;
        }
    }
    
    //test pour savoir si on fait l'echange
    double poids_pere=tas[indice_pere].poids, poids_fils=tas[indice_fils].poids;
    if(poids_pere<=poids_fils) return;
    else{
        echange_tas(tas,g, indice_fils, indice_pere);
        descendretas(tas,g, i, indice_fils);
    }
}
//échange 2 éléments dans un tas en renseignant leurs 2 indices
void echange_tas(TAS* tas,T_SOMMET* g,long i,long k){
    double temp_poids = tas[k].poids;
    tas[k].poids = tas[i].poids;
    tas[i].poids = temp_poids;
    g[tas[i].sommet].position_tas = k;
    g[tas[k].sommet].position_tas = i;
    long temp_som = tas[i].sommet;
    tas[i].sommet = tas[k].sommet;
    tas[k].sommet = temp_som;
}

