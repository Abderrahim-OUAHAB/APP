#include <stdio.h>
#include <stdlib.h>
#include "../header/phase1.h"


void initialiserJeu(JeuFreeCell *jeu) {
    int i, j;

    jeu->zone1 = malloc(8 * sizeof(Pile));

    for (i = 0; i < 8; i++) {
        initialiserPile(&(jeu->zone1[i]), i < 4 ? 7 : 6);
    }

    for (i = 0; i < 4; i++) {
        initialiserPile(&(jeu->zone2[i]), 1);
        initialiserPile(&(jeu->zone3[i]), 13);
    }

    Carte *jeuComplet = malloc(52 * sizeof(Carte));
    int k = 0;

    for (i = 0; i < 4; i++) {
        for (j = 1; j <= 13; j++) {
            jeuComplet[k++] = *initCarte(j, i == 0 ? 'C' : (i == 1 ? 'P' : (i == 2 ? 'H' : 'T')));
        }
    }

    for (i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Carte temp = jeuComplet[i];
        jeuComplet[i] = jeuComplet[j];
        jeuComplet[j] = temp;
    }

    k = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < jeu->zone1[i].capacite; j++) {
            empiler(&(jeu->zone1[i]), initCarte(jeuComplet[k].valeur, jeuComplet[k].type));
            k++;
        }
    }

    free(jeuComplet);
}

void afficherJeu(JeuFreeCell *jeu) {
    printf("Zone1:\n\n");
    for (int i = 0; i < 8; i++) {
        printf("Colonne %d: ", i + 1);
        afficherPile(&(jeu->zone1[i]));
        printf("\n");
    }

    printf("\nZone2:\n\n");
    for (int i = 0; i < 4; i++) {
        printf("Temp %d: ", i + 1);
        afficherPile(&(jeu->zone2[i]));
        printf("\n");
    }

    printf("\nZone3:\n\n");
    for (int i = 0; i < 4; i++) {
        printf("Suit %d: ", i + 1);
        afficherPile(&(jeu->zone3[i]));
        printf("\n");
    }
}