# FreeCell Game Implementation


## Réalisé Par:
OUAHAB Abderrahim

---

## Introduction

Ce projet implémente le jeu FreeCell en utilisant des structures de données et des fonctions modulaires. Il offre une expérience interactive (console) pour l'utilisateur, respectant les règles traditionnelles du jeu FreeCell.

## Structures Principales

### Carte
Représente une carte de jeu avec :
- **Valeur** : La valeur de la carte (de 1 à 13).
- **Type** : Le type de la carte (trèfle, carreau, cœur, pique).
- **Couleur** : La couleur de la carte (rouge ou noir), déterminée automatiquement en fonction du type.

### Pile
Représente une pile de cartes avec :
- **Taille** : Le nombre actuel de cartes dans la pile.
- **Capacité** : La capacité maximale de la pile.
- **Tableau de cartes** : Un tableau contenant les cartes.

### JeuFreeCell
Représente l'ensemble du jeu avec :
- **zone1** : La pile centrale.
- **zone2 et zone3** : Deux piles de destination.

## Fonctionnalités

### Initialisation des cartes
La fonction `initCarte` crée une nouvelle carte avec une valeur et un type donnés, et initialise automatiquement la couleur en fonction du type.

### Affichage des cartes
La fonction `afficherCarte` prend une carte en entrée et affiche son symbole avec des couleurs ASCII en fonction de sa valeur, son type et sa couleur.

### Initialisation des piles
La fonction `initialiserPile` prend une pile avec sa capacité en entrée et permet de l'initialiser.

### Ajouter une carte aux piles
La fonction `empiler` permet d’ajouter une carte à la pile.

### Retirer une carte de la pile
La fonction `depiler` permet de retirer une carte de la pile et de la retourner.

### Afficher la pile
La fonction `afficherPile` permet d’afficher la pile.

### Initialisation du jeu
La fonction `initialiserJeu` initialise l'état initial du jeu en créant un jeu complet de cartes, mélange les cartes, puis les distribue aux piles correspondantes.

### Déplacement de cartes
- La fonction `deplacementValide` vérifie si un déplacement de carte d'une pile source vers une pile destination est valide selon les règles du FreeCell.
- La fonction `deplacerCarte` permet de déplacer une carte d'une zone/source à une zone/destination donnée.

### Affichage du jeu
La fonction `afficherJeu` affiche l'état actuel du jeu en affichant les piles de cartes dans chaque zone.

### Vérification des conditions de fin de jeu
- La fonction `joueurGagne` vérifie si le joueur a gagné en ayant toutes les cartes dans la zone3.
- La fonction `partieBloquee` vérifie si la partie est bloquée, c'est-à-dire s'il n'y a aucun mouvement possible.
- La fonction `joueurPerdu` utilise la fonction `partieBloquee` pour déterminer si le joueur a perdu.

### Boucle principale du jeu
La fonction `jouer` contient la boucle principale du jeu, où le joueur peut déplacer des cartes jusqu'à ce qu'il gagne ou perde.

### Main
La fonction `main` initialise le jeu, puis lance la boucle de jeu interactive en appelant la fonction `jouer`.

## Conclusion

Ce projet implémente le jeu FreeCell de manière structurée avec des fonctions modulaires, offrant une expérience interactive pour l'utilisateur. Le jeu respecte les règles du FreeCell et permet au joueur de déplacer les cartes jusqu'à ce qu'il gagne ou perde.

