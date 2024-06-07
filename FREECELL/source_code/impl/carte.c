#include <stdio.h>
#include <stdlib.h>
#include "../header/carte.h"


Carte *initCarte(int valeur, char type) {
    Carte *carte = malloc(sizeof(Carte));
    if (carte != NULL) {
        carte->valeur = valeur;
        carte->type = type;

        switch (type) {
            case 'T':
                carte->couleurCarte = 'N'; // Noir
                break;
            case 'P':
                carte->couleurCarte = 'N'; // Noir
                break;
            case 'H':
                carte->couleurCarte = 'R'; // Rouge
                break;
            case 'C':
                carte->couleurCarte = 'R'; // Rouge
                break;
            default:
                break;
        }
    }
     carte->next=NULL;
    return carte;
}

void afficherCarte(Carte *carte) {
    if (carte != NULL) {
        int couleur = carte->couleurCarte == 'N' ? 30 : 31; // ANSI color codes for black and red

       printf("\033[47m\033[%dm  ", couleur); // Set text color

        char *symbole = "";
        switch (carte->type) {
            case 'C':
                symbole = "♦"; // Carreau
                break;
            case 'P':
                symbole = "♠"; // Spade
                break;
            case 'H':
                symbole = "♥"; // Heart
                break;
            case 'T':
                symbole = "♣"; // Diamond
                break;
            default:
                break;
        }

        switch (carte->valeur) {
            case 1:
                printf("[A|%s]   ", symbole);// couleur == 30 ? 'B' : 'R');
                break;
            case 11:
                printf("[J|%s]   ", symbole);// couleur == 30 ? 'B' : 'R');
                break;
            case 12:
                printf("[Q|%s]   ", symbole);// couleur == 30 ? 'B' : 'R');
                break;
            case 13:
                printf("[K|%s]   ", symbole);//(couleur == 30 ? 'B' : 'R');
                break;
            default:
            if(carte->valeur>=10){
                printf("[%d|%s]  ", carte->valeur, symbole);//( couleur == 30 ? 'B' : 'R'));
                break;}
            else {
            printf("[%d|%s]   ", carte->valeur, symbole); 
            }
        }

         printf("\033[0m\033[49m "); // Reset text color
    }
}
