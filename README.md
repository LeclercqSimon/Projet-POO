## Projet-POO-JeuDeLaVie par Leclercq Simon et Jaidane Elyesse

# Description

Cette implémentation du Jeu de la Vie de Conway est un simulateur en C++ utilisant la bibliothèque graphique SFML pour une représentation visuelle interactive des évolutions des cellules dans une grille. Le programme permet de charger une configuration initiale depuis un fichier texte, d'appliquer les règles du jeu sur plusieurs générations, et de visualiser l'évolution des cellules en temps réel.

# Fonctionnalités

- Chargement d'une configuration initiale à partir d'un fichier texte.
- Simulation de plusieurs générations selon les règles du Jeu de la Vie.
- Affichage graphique des évolutions en utilisant SFML.
- Ajustement interactif de la vitesse de simulation avec les touches Up et Down.
- Sauvegarde de chaque état généré dans des fichiers texte.
- Détection des cycles stables pour arrêter la simulation lorsque la grille devient statique.

# Structure du Code

Classes principales : 

__Cellule__
    Gère l'état (vivante/morte) d'une cellule individuelle.
    Fonctions principales :
    - definirEtat(bool e) : Définit l'état de la cellule.
    - estVivante() const : Retourne l'état actuel de la cellule.

__Grille :__ 
    Représente une grille de cellules et gère les opérations associées.
    Fonctions principales :
    - initialiser(int lignes, int colonnes) : Initialise la grille.
    - setCellule(int x, int y, bool e) : Modifie l'état d'une cellule.
    - countVoisins(int x, int y) const : Compte les voisins vivants d'une cellule.
    - chargerDepuisFichier(const std::string& cheminFichier) : Charge une grille depuis un fichier texte.
    - sauvegarderDansFichier(const std::string& dossierBase, int generation) : Sauvegarde l'état actuel de la grille.
    - difference_grille(Grille grille2) : Compare deux grilles pour détecter les changements.
    
__JeuDeLaVie :__
  Contrôle la logique de simulation et l'affichage.
  Fonctions principales :
  - jouerAvecSFML() : Lance la simulation avec affichage graphique.
  - appliquerRegles() : Applique les règles du Jeu de la Vie pour une génération.

__Fonction main :__
- Gère l'entrée utilisateur pour charger le fichier de configuration et le nombre de générations.
- Lance l'exécution de la simulation avec l'affichage graphique SFML.

# Utilisation
Installez SFML. Par exemple, sur Ubuntu :
*sudo apt-get install libsfml-dev*
Compilez le projet :
*g++ -std=c++17 -o jeu_de_la_vie main.cpp Cellule.cpp Grille.cpp JeuDeLaVie.cpp -lsfml-graphics -lsfml-window -lsfml-system*
Lancez le programme :
*./jeu_de_la_vie*
Entrez le nom du fichier de configuration (sans extension). Exemple :
*Veuillez entrer le nom du fichier : glider*
Entrez le nombre de générations à simuler :
*Veuillez entrer le nombre de générations : 100*
Regardez l'évolution des cellules dans la fenêtre SFML.

# Format du fichier de configuration
Le fichier texte doit avoir le format suivant :
- Première ligne : dimensions de la grille (lignes colonnes).
- Lignes suivantes : 0 pour une cellule morte, 1 pour une cellule vivante.

Exemple :
5 5
0 0 0 0 0
0 1 1 1 0
0 1 0 1 0
0 1 1 1 0
0 0 0 0 0

# Commandes Interactives
- Touche Up : Augmente la vitesse de simulation.
- Touche Down : Diminue la vitesse de simulation.

# Notes
Si la grille devient statique, la simulation s'arrête automatiquement avec un message.
Les états de chaque génération sont sauvegardés dans le répertoire out_<nom_fichier>.

Auteur
Projet réalisé dans le cadre de l'apprentissage du C++ et de la bibliothèque SFML par LECLERCQ Simon et JAIDANE Elyesse, élèves de CPI A2 INFORMATIQUE au CESI.
