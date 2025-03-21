#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "attaque.h"

using namespace std;

class Animal {
    protected:
        string nom;
        int x; // abscisse de l'animal
        int y; // ordonnée de l'animal
        bool vivant;
        Attaque typeAttaque;
    
    public:
        /* Constructors */
        Animal(int maxX, int maxY);
        Animal(int maxX, int maxY, int x, int y);
        virtual ~Animal() = default;
        
        /* Getters */
        const string getNom();
        const int getX();
        const int getY();
        const bool getVivant();
        const Attaque getAttaque();

        /* Setters */
        void setVivant(bool v);
        virtual void setAttaque() = 0; 

        /* Methods */
        bool attaque(Animal &a);
        virtual void deplace(int maxX, int maxY) = 0;
};

#endif /* ANIMAL_H */