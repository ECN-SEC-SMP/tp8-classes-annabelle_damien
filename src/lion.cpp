#include "lion.h"

/* Constructors */
Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY) {
    this->nom = NOM_LION;
    this->setAttaque();
}

Lion::Lion(int maxX, int maxY, int x, int y) : Animal(maxX, maxY, x, y) {
    this->nom = NOM_LION;
    this->setAttaque();
}

/* Setters */
void Lion::setAttaque() {
    this->typeAttaque = Attaque((int) rand() % 2 + 1);
}

/* Methods */
void Lion::deplace(int maxX, int maxY) {
    int moves[] = {-1, 1};
    this->x += moves[rand()%2];
    this->y += moves[rand()%2];
    if(this->x >= maxX) this->x -= maxX;
    if(this->y >= maxY) this->y -= maxY;
    if(this->x < 0) this->x += maxX;
    if(this->y < 0) this->y += maxY;
}