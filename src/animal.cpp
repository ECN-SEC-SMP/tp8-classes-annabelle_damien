#include "stdlib.h"
#include "animal.h"
#include "attaque.h"

/* Constructors */
Animal::Animal(int maxX, int maxY) {
    this->vivant = true;
    this->x = rand() % maxX;
    this->y = rand() % maxY;
}

Animal::Animal(int maxX, int maxY, int x, int y) {
    this->vivant = true;
    if (x > maxX) {
        this->x = maxX;
    }
    else if (x < 0) {
        this->x = 0;
    }
    else {
        this->x = x;
    }

    if (y > maxY) {
        this->y = maxY;
    }
    else if (y < 0) {
        this->y = 0;
    }
    else {
        this->y = y;
    }    
}


/* Getters */
const string Animal::getNom() {
    return this->nom;
}

const int Animal::getX() {
    return this->x;
}

const int Animal::getY() {
    return this->y;
}

const bool Animal::getVivant() {
    return this->vivant;
}

const Attaque Animal::getAttaque() {
    return this->typeAttaque;
}


/* Setters */
void Animal::setVivant(bool v) {
    this->vivant = v;
}


/* Methods */
bool Animal::attaque(Animal &a) {
    return this->typeAttaque.resoudreAttaque(a.typeAttaque);
}
