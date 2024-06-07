#ifndef C0D5F3AA_0E13_46B1_89D5_2601EF5A799E
#define C0D5F3AA_0E13_46B1_89D5_2601EF5A799E
#include "carte.h"

// Structure de pile
typedef struct {
    Carte *cartes;
    int taille;
    int capacite;
} Pile;
// Fonction pour initialiser une pile vide
void initialiserPile(Pile *pile, int capacite);
// Fonction pour empiler une carte sur une pile
void empiler(Pile *pile, Carte *carte) ;

// Fonction pour dépiler une carte d'une pile
Carte *depiler(Pile *pile) ;

// Fonction pour afficher une pile
void afficherPile(Pile *pile) ;
#endif /* C0D5F3AA_0E13_46B1_89D5_2601EF5A799E */
