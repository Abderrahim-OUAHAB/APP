#ifndef F993965F_C20C_41BA_A6F3_C76FB8DB54FA
#define F993965F_C20C_41BA_A6F3_C76FB8DB54FA
typedef struct carte {
    int valeur;       // 1 pour l'As, 2-10 pour les cartes numérotées, 11 pour Valet, 12 pour Dame, 13 pour Roi
    char type;     // 'C' pour carreau, 'P' pour pique, 'H' pour cœur, 'T' pour trèfle
    char couleurCarte; // 'N' pour noir, 'R' pour rouge
    struct carte *next;
} Carte;

// Fonction pour initialiser une carte
Carte *initCarte(int valeur, char couleur);
// Fonction pour afficher une carte
void afficherCarte(Carte *carte) ;
#endif /* F993965F_C20C_41BA_A6F3_C76FB8DB54FA */
