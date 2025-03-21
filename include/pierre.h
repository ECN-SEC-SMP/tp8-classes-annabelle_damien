#ifndef PIERRE_H
#define PIERRE_H

#include "animal.h"

#define NOM_PIERRE "🪨 "

class Pierre : public Animal  // heritage de la classe Animal
{
    public:
        /* Constructors */
        Pierre(int maxX, int maxY);
        Pierre(int maxX, int maxY, int x, int y);

        /* Setters */
        void setAttaque();

        /* Methods */
        void deplace(int maxX, int maxY);
};

#endif /* PIERRE_H */