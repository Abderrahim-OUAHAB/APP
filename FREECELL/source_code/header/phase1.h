#ifndef PILE_FUNCTIONS_H
#define PILE_FUNCTIONS_H

#include "carte.h"
#include "stack.h"

// Structure de jeu FreeCell
typedef struct {
    Pile *zone1;
    Pile zone2[4];
    Pile zone3[4];
} JeuFreeCell;

// Fonction pour initialiser le jeu FreeCell
void initialiserJeu(JeuFreeCell *jeu) ;
// Fonction pour afficher le jeu FreeCell
void afficherJeu(JeuFreeCell *jeu) ;


#endif /* C11B7AD4_F514_42E8_B605_5EDBAECDD993 */
