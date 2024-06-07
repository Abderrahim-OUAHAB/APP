#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header/phase1.h"
#include "header/carte.h"
#include "header/stack.h"
#include "impl/phase1.c"
#include "impl/carte.c"
#include "impl/stack.c"
#include "header/phase2.h"
#include "impl/phase2.c"
int main() {
    system("osascript -e 'tell application \"Terminal\" to set current settings of first window to settings set \"Grass\"'");

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Initialisation du jeu
    JeuFreeCell jeu;
    initialiserJeu(&jeu);

    // Lancer le jeu interactif
    jouer(&jeu);

    return 0;
}
