#include "JeuDeLaVie.h"
#include <iostream>
#include <string>

int main() {
    std::string fichier;
    std::cout << "Veuillez entrer le nom du fichier : " << std::endl;
    std::cin >> fichier;
    int generations;
    std::cout << "Veuillez entrer le nombre de générations : " << std::endl;
    std::cin >> generations;
    fichier = fichier + ".txt";

    JeuDeLaVie jeu(fichier, generations);
    jeu.jouerAvecSFML();

    return 0;
}
