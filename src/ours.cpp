#include "ours.h"

/* Constructors */
Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY) {
    this->nom = NOM_OURS;
    this->setAttaque();
}

Ours::Ours(int maxX, int maxY, int x, int y) : Animal(maxX, maxY, x, y) {
    this->nom = NOM_OURS;
    this->setAttaque();
}

/* Setters */
void Ours::setAttaque() {
    this->typeAttaque = Attaque(1);
}

/* Methods */
void Ours::deplace(int maxX, int maxY) {
    int moves[] = {-2,-1,1,2} ; // random between -2 and 2 without 0

    this->x += moves[rand()%4];
    this->y += moves[rand()%4];

    if(this->x >= maxX) this->x -= maxX;
    if(this->y >= maxY) this->y -= maxY;
    if(this->x < 0) this->x += maxX;
    if(this->y < 0) this->y += maxY;
}