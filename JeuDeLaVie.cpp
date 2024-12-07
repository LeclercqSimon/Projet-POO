#include "JeuDeLaVie.h"
JeuDeLaVie::JeuDeLaVie(const std::string& fichier, int generations)
    : fichier(fichier), generations(generations) {
    grille = Grille::chargerDepuisFichier(fichier);
}

void JeuDeLaVie::jouerAvecSFML() {
    n_gen = 1;
    int taille_cellule = 10;
    // Récupération de la résolution actuelle de l'écran
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    // Création de la fenêtre en plein écran
    sf::RenderWindow window(desktopMode, "Jeu de la vie", sf::Style::Fullscreen);

    int framerate = 10; // Valeur Fréquence raffraichissement
    window.setFramerateLimit(framerate);

    for (int gen = 0; gen < generations; ++gen) {
        window.clear();

        for (int y = 0; y < grille.getColonnes(); ++y) {
            for (int x = 0; x < grille.getLignes(); ++x) {
                sf::RectangleShape cellShape(sf::Vector2f(taille_cellule - 1, taille_cellule - 1));
                cellShape.setPosition(x * taille_cellule, y * taille_cellule);

                if (grille.getCellule(x, y).estVivante()) {
                    cellShape.setFillColor(sf::Color::Magenta);
                }
                else {
                    cellShape.setFillColor(sf::Color::Black);
                }

                window.draw(cellShape);
            }
        }

        window.display();
        appliquerRegles();

        sf::Event event; // class de la bibiliothèque SFML
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            // Changement de la fréquence de rafraîchissement avec les touches
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) { // Augmenter la fréquence
                    framerate += 10; // Augmente la valeur de la fréquence de rafraîchissement
                    window.setFramerateLimit(framerate);
                }
                else if (event.key.code == sf::Keyboard::Down) { // Diminuer la fréquence
                    framerate = std::max(1, framerate - 10); // Réduit la fréquence mais reste au moins à 1
                    window.setFramerateLimit(framerate);
                }
            }
        }
    }
}      

void JeuDeLaVie::appliquerRegles() {
    Grille grille_suivante;
    grille_suivante.initialiser(grille.getColonnes(), grille.getLignes());

    for (int y = 0; y < grille.getColonnes(); ++y) {
        for (int x = 0; x < grille.getLignes(); ++x) {
            int voisins = grille.countVoisins(x, y);
            bool estVivante = grille.getCellule(x, y).estVivante();

            if (estVivante && (voisins == 2 || voisins == 3)) {
                grille_suivante.setCellule(x, y, true);
            }
            else if (!estVivante && voisins == 3) {
                grille_suivante.setCellule(x, y, true);
            }
            else {
                grille_suivante.setCellule(x, y, false);
            }
        }
    }
    if (n_gen>0){
        if (!grille.difference_grille(grille_suivante)){
            grille.sauvegarderDansFichier(fichier, n_gen);
            throw std::runtime_error("La grille ne bouge plus");
        }
    }
    grille.sauvegarderDansFichier(fichier, n_gen);
    grille = grille_suivante;
    ++n_gen;
}
