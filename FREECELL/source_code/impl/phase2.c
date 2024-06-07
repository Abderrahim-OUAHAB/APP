#include <stdio.h>
#include <stdlib.h>
#include "../header/carte.h"
#include "../header/stack.h"
#include "../header/phase1.h"
int deplacementValide(Pile *sourcePile, Pile *destinationPile) {
    if (sourcePile->taille==0) {
        return 0; // Impossible de déplacer depuis une pile vide
    }
    Carte *sourceCarte = &(sourcePile->cartes[sourcePile->taille-1]);
    Carte *destinationCarte = &(destinationPile->cartes[destinationPile->taille-1]);
     if (destinationPile->taille == 0) {
        // Déplacement autorisé vers une pile vide
         Carte *carteDeplacee = depiler(sourcePile);
        empiler(destinationPile, carteDeplacee);
    }
    // Vérifiez les règles spécifiques de déplacement
    if ((sourceCarte->valeur == (destinationCarte->valeur) - 1) && (((sourceCarte->type == 'C' || sourceCarte->type == 'H') && (destinationCarte->type == 'P' || destinationCarte->type == 'T')) || ((sourceCarte->type == 'P' || sourceCarte->type == 'T') && (destinationCarte->type == 'H' || destinationCarte->type == 'C')))) {
        return 1;
    }

    return 0;
}


void deplacerCarte(JeuFreeCell *jeu, int sourceZone, int sourceColonne, int destinationZone, int destinationColonne) {
    Pile *sourcePile, *destinationPile;

    if ( sourceZone < 1 || sourceZone > 3 || destinationZone < 1 || destinationZone > 3 ||
        sourceColonne < 1 || destinationColonne < 1 ||
        (sourceZone == 1 && (sourceColonne > 8 || destinationColonne > 8)) ||
        ((sourceZone == 2 || sourceZone == 3) && (sourceColonne > 4 || destinationColonne > 8))) {
        printf("Erreur : Cellule invalide.\n");
        return;
    }

    switch (sourceZone) {
        case 1:
            sourcePile = &(jeu->zone1[sourceColonne - 1]);
            break;
        case 2:
            sourcePile = &(jeu->zone2[sourceColonne - 1]);
            break;
        case 3:
            sourcePile = &(jeu->zone3[sourceColonne - 1]);
            break;
        default: printf("caractere inconnu\n");
    }

    switch (destinationZone) {
        case 1:
            destinationPile =&(jeu->zone1[destinationColonne - 1]);
            destinationPile->capacite+=1;
              if (deplacementValide(sourcePile, destinationPile)) {
        Carte *carteDeplacee =depiler(sourcePile);
        empiler(destinationPile, carteDeplacee);
    }
            break;
        case 2:
            destinationPile = &(jeu->zone2[destinationColonne - 1]);
            if (deplacementValide(sourcePile, destinationPile)) {
        Carte *carteDeplacee =depiler(sourcePile);
        empiler(destinationPile, carteDeplacee);
    }
            break;
        case 3:
            destinationPile = &(jeu->zone3[destinationColonne - 1]);
            if (jeu->zone3[destinationColonne - 1].taille == 0) {
        // Si c'est la première carte entrée dans la colonne de la zone 3, elle doit être l'As (valeur 1)
            if (sourcePile->cartes[sourcePile->taille-1].valeur != 1) {
                printf("Erreur : La première carte dans la colonne de la Zone 3 doit être l'As.\n");
                return;
            }
        }
        // ordre
            else if ((sourcePile->cartes[sourcePile->taille-1].valeur!=destinationPile->cartes[destinationPile->taille-1].valeur+1)||(sourcePile->cartes[sourcePile->taille-1].type!=destinationPile->cartes[destinationPile->taille-1].type)||(sourcePile->cartes[sourcePile->taille-1].couleurCarte!=destinationPile->cartes[destinationPile->taille-1].couleurCarte)){
           printf("Erreur : ORDRE.\n");
                return; 
        }
        
             Carte *carteDeplacee =depiler(sourcePile);
             empiler(destinationPile, carteDeplacee); 
            destinationPile->capacite-=1;
            break;
    }
    }
int joueurGagne(JeuFreeCell *jeu) {
    for (int i = 0; i < 4; i++) {
        if ((jeu->zone3[i].taille!= 13)) {
            return 0;
        }
    }
    return 1;
}
int partieBloquee(JeuFreeCell *jeu) {
    // Vérifiez si aucune carte ne peut être déplacée entre les colonnes de la zone 1
    for (int i = 0; i < 8; i++) {
        if ((jeu->zone1[i].taille) > 0) {
            for (int j = 0; j < 4; j++) {
                if ((jeu->zone2[j].taille) == 0 || deplacementValide(&(jeu->zone1[i]), &(jeu->zone2[j]))) {
                    return 0;
                }
            }
        }
    }

    // Vérifiez si aucune carte ne peut être déplacée entre les colonnes de la zone 2 et la zone 3
    for (int i = 0; i < 4; i++) {
        if ((jeu->zone2[i].taille) > 0) {
            for (int j = 0; j < 4; j++) {
                if ((jeu->zone3[j].taille) == 0 || deplacementValide(&(jeu->zone2[i]), &(jeu->zone3[j]))) {
                    return 0;
                }
            }
        }
    }

    return 1; // La partie est bloquée
}
int joueurPerdu(JeuFreeCell *jeu) {
    return partieBloquee(jeu);
}
void jouer(JeuFreeCell *jeu) {
    // Boucle principale
    while (!joueurGagne(jeu) && !joueurPerdu(jeu)) {
        // Effacer l'écran avant chaque nouvel affichage
        system("clear");
       
        // Afficher le jeu
        afficherJeu(jeu);
        //choix d'utilisateur
        int x;
        printf("CHOISIR UN CHOIX : \n");
        printf("1- DEPLACER UNE CARTE \n");
        printf("2- QUITTER\n\n");
        int r=scanf("%d",&x);
        if(r!=1){
            printf("Erreur : Veuillez saisir des nombres entiers valides 1 ou 2\n");
                while (getchar() != '\n'); // Clear the input buffer 
        }
        if(x==1){
        // Demander à l'utilisateur la cellule de départ et la cellule d'arrivée
        int sourceZone, sourceColonne, destinationZone, destinationColonne;

        // Saisie sécurisée pour s'assurer que les valeurs sont des entiers
        int sourceInputResult = 0;
        do {
            printf("Cellule de départ (zone colonne) : ");
            sourceInputResult = scanf("%d %d", &sourceZone, &sourceColonne);
            if (sourceInputResult != 2) {
                printf("Erreur : Veuillez saisir des nombres entiers valides.\n");
                while (getchar() != '\n'); // Clear the input buffer
            }
        } while (sourceInputResult != 2);

        int destinationInputResult = 0;
        do {
            printf("Cellule d'arrivée (zone colonne) : ");
            destinationInputResult = scanf("%d %d", &destinationZone, &destinationColonne);
            if (destinationInputResult != 2) {
                printf("Erreur : Veuillez saisir des nombres entiers valides.\n");
                while (getchar() != '\n'); // Clear the input buffer
            }
        } while (destinationInputResult != 2);

        // Déplacer la carte
        deplacerCarte(jeu, sourceZone, sourceColonne, destinationZone, destinationColonne);
    

    // Effacer l'écran avant d'afficher le résultat de la partie
    system("clear");

    // Afficher le résultat de la partie
    if (joueurGagne(jeu)) {
        printf("Félicitations ! Vous avez gagné la partie.\n");
    } else {
        printf("Partie terminée. Vous avez perdu.\n");
    }
    }
        else if(x==2){
            printf("partie terminée!!!!!\n\n");
            return;
    }
    
}}