#pragma once
#include "Grille.h"
#include <string>
#include <SFML/Graphics.hpp>

class JeuDeLaVie {
private:
    const std::string fichier;
    int generations;
    int n_gen;
    Grille grille;

public:
    JeuDeLaVie(const std::string& fichier, int generations);
    void jouerAvecSFML();
    void appliquerRegles();
};

