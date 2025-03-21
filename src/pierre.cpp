#include "pierre.h"

/* Constructors */
Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY) {
    this->nom = NOM_PIERRE;
    this->setAttaque();
    this->vivant = false;
}

Pierre::Pierre(int maxX, int maxY, int x, int y) : Animal(maxX, maxY, x, y) {
    this->nom = NOM_PIERRE;
    this->setAttaque();
    this->vivant = false;
}

/* Setters */
void Pierre::setAttaque() {
    this->typeAttaque = Attaque(0);
}

/* Methods */
void Pierre::deplace(int maxX, int maxY) {}