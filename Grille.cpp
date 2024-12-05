#include "Grille.h"
#include <fstream>
#include <filesystem>

Grille::Grille() : nb_colonnes(0), nb_lignes(0) {}

void Grille::initialiser(int lignes, int colonnes) {
    nb_lignes = lignes;
    nb_colonnes = colonnes;
    cellules = std::vector<std::vector<Cellule>>(lignes, std::vector<Cellule>(colonnes));
}

void Grille::setCellule(int x, int y, bool e) {
    cellules[x][y].definirEtat(e);
}

int Grille::getColonnes() const {
    return nb_colonnes;
}

int Grille::getLignes() const {
    return nb_lignes;
}

const Cellule& Grille::getCellule(int x, int y) const {
    return cellules[x][y];
}

int Grille::countVoisins(int x, int y) const {
    int cpt = 0;
    static const int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for (int i = 0; i < 8; ++i) {
        int nx = (x + directions[i][0] + nb_lignes) % nb_lignes;
        int ny = (y + directions[i][1] + nb_colonnes) % nb_colonnes;
        if (cellules[nx][ny].estVivante()) {
            ++cpt;
        }
    }
    return cpt;
}

Grille Grille::chargerDepuisFichier(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + cheminFichier);
    }

    int lignes, colonnes;
    fichier >> lignes >> colonnes;

    Grille g;
    g.initialiser(lignes, colonnes);

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            int etat;
            fichier >> etat;
            g.setCellule(i, j, etat == 1);
        }
    }
    fichier.close();
    return g;
}

void Grille::sauvegarderDansFichier(const std::string& dossierBase, int generation) const {
    namespace fs = std::filesystem;

    std::string dossierComplet = "out_" + dossierBase;
    if (!fs::exists(dossierComplet)) {
        fs::create_directory(dossierComplet);
    }

    std::string cheminFichier = dossierComplet + "/generation_" + std::to_string(generation) + ".txt";

    std::ofstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible de cr�er le fichier : " + cheminFichier);
    }

    fichier << nb_lignes << " " << nb_colonnes << std::endl;
    for (const auto& ligne : cellules) {
        for (const auto& cell : ligne) {
            fichier << (cell.estVivante() ? "1 " : "0 ");
        }
        fichier << std::endl;
    }
    fichier.close();
}
