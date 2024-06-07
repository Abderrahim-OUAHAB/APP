#ifndef ECC9C85E_D913_455D_97F7_48A54BBFA198
#define ECC9C85E_D913_455D_97F7_48A54BBFA198
#include "carte.h"
#include "stack.h"
#include "phase1.h"
int deplacementValide(Pile *sourcePile, Pile *destinationPile) ;
void deplacerCarte(JeuFreeCell *jeu, int sourceZone, int sourceColonne, int destinationZone, int destinationColonne) ;
int joueurGagne(JeuFreeCell *jeu) ;
int partieBloquee(JeuFreeCell *jeu) ;
int joueurPerdu(JeuFreeCell *jeu) ;
void jouer(JeuFreeCell *jeu);

#endif /* ECC9C85E_D913_455D_97F7_48A54BBFA198 */
