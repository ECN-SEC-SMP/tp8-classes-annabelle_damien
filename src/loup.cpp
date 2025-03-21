#include "loup.h"

/* Constructors */
Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY) {
    this->nom = NOM_LOUP;
    this->setAttaque();
}

Loup::Loup(int maxX, int maxY, int x, int y) : Animal(maxX, maxY, x, y) {
    this->nom = NOM_LOUP;
    this->setAttaque();
}

/* Setters */
void Loup::setAttaque() {
    this->typeAttaque = Attaque((int) rand() % 3);
}

/* Methods */
void Loup::deplace(int maxX, int maxY) {
    this->setAttaque();
    this->x = rand()%maxX; // random X on the plateau
    this->y = rand()%maxY ; // random Y on the plateau
}