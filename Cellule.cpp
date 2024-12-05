#include "Cellule.h"

Cellule::Cellule() : etat(false) {}

void Cellule::definirEtat(bool e) {
    etat = e;
}

bool Cellule::estVivante() const {
    return etat;
}
