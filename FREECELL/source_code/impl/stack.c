#include <stdio.h>
#include <stdlib.h>
#include "../header/carte.h"
#include "../header/stack.h"

void initialiserPile(Pile *pile, int capacite) {
    pile->cartes = malloc(capacite * sizeof(Carte));
    pile->taille = 0;
    pile->capacite = capacite;
}

void empiler(Pile *pile, Carte *carte) {
    if (pile->taille < pile->capacite) {
        pile->cartes[pile->taille++] = *carte;
        pile->cartes[pile->taille-1].next=carte;
    } else {
        printf("Erreur : La pile est pleine.\n");
    }
}

Carte *depiler(Pile *pile) {
    if (pile->taille > 0) {
        pile->cartes[pile->taille-1].next=NULL;
        return &(pile->cartes[--pile->taille]);
    } else {
        printf("Erreur : La pile est vide.\n");
        return NULL;
    }
}

void afficherPile(Pile *pile) {
    if(pile->taille!=0){
    for (int i = 0; i < pile->taille; i++) {
        afficherCarte(&(pile->cartes[i]));
    }}
    printf("\n");
}