# Hand Gesture Volume Control

Ce projet permet de contrôler le volume de votre système en utilisant des gestes de la main capturés par une caméra. Le projet utilise OpenCV et MediaPipe pour la détection et le suivi des mains, et ajuste le volume en fonction de la distance entre le pouce et l'index.

## Table des matières
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Dépendances](#dépendances)
- [Crédits](#crédits)

## Fonctionnalités

- Détection en temps réel des mains et des doigts à l'aide de MediaPipe.
- Calcul de la distance entre le pouce et l'index pour ajuster le volume.
- Affichage du volume actuel sous forme de barre graphique et pourcentage.

## Installation

1. Clonez ce dépôt sur votre machine locale :
   ```bash
   git clone https://github.com/Abderrahim-OUAHAB/hand-gesture-volume-control.git
   cd hand-gesture-volume-control
   
2. Installez les dépendances nécessaires :

pip install opencv-python mediapipe numpy

## Utilisation

1.Exécutez le script principal :

python VolumeHandControl.py

-Une fenêtre de caméra ouvrira. Assurez-vous que votre caméra est bien connectée et visible par le script.

-Utilisez votre pouce et votre index pour ajuster le volume. La distance entre ces deux doigts sera utilisée pour contrôler le volume :

        -Une distance courte diminue le volume.
        -Une distance longue augmente le volume.

## Dépendances

Python 3.11
OpenCV
MediaPipe
NumPy

## Crédits
Ce projet utilise les bibliothèques suivantes :

OpenCV
MediaPipe
NumPy


### Développé par  Abderrahim OUAHAB.
