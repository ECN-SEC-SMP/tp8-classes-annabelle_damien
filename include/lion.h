#ifndef LION_H
#define LION_H

#include "animal.h"

#define NOM_LION "🦁"

class Lion : public Animal {
    public:
        /* Constructors */
        Lion(int maxX, int maxY);
        Lion(int maxX, int maxY, int x, int y);
        ~Lion() = default;

        /* Setters */
        void setAttaque();

        /* Methods */
        void deplace(int maxX, int maxY);
};

#endif /* LION_H */