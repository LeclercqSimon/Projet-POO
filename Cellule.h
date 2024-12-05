#pragma once
class Cellule {
private:
    bool etat;
public:
    Cellule();
    void definirEtat(bool e);
    bool estVivante() const;
};

