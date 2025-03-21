#ifndef OURS_H
#define OURS_H

#include "animal.h"

#define NOM_OURS "🐻"

class Ours : public Animal {
    public:
        /* Constructors */
        Ours(int maxX, int maxY);
        Ours(int maxX, int maxY, int x, int y);

        /* Setters */
        void setAttaque();

        /* Methods */
        void deplace(int maxX, int maxY);
};

#endif /* OURS_H */