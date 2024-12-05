#pragma once

#include <vector>
#include <string>
#include "Cellule.h"

class Grille {
private:
    int nb_colonnes;
    int nb_lignes;
    std::vector<std::vector<Cellule>> cellules;

public:
    Grille();
    void initialiser(int lignes, int colonnes);
    void setCellule(int x, int y, bool e);
    int getColonnes() const;
    int getLignes() const;
    const Cellule& getCellule(int x, int y) const;
    int countVoisins(int x, int y) const;
    static Grille chargerDepuisFichier(const std::string& cheminFichier);
    void sauvegarderDansFichier(const std::string& dossierBase, int generation) const;
};


