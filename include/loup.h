#ifndef LOUP_H
#define LOUP_H

#include "animal.h"

#define NOM_LOUP "🐺"

class Loup : public Animal {
    public:
        /* Constructors */
        Loup(int maxX, int maxY);
        Loup(int maxX, int maxY, int x, int y);

        /* Setters */
        void setAttaque();

        /* Methods */
        void deplace(int maxX, int maxY);
};

#endif /* LOUP_H */