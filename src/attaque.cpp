#include "attaque.h"
#include "stdlib.h"

/* Constructors */
Attaque::Attaque()
{
    this->type = rand()%3;
}

Attaque::Attaque(int a)
{
    if (a >= 0 && a <= 2) this->type = a;
}

/* Getters */
const int Attaque::getTypeAttaque()
{
    return this->type;
}

string Attaque::getNomAttaque() const
{
    string type_str[3] = {"🪨 ", "🍃", "✂️ "};
    return type_str[type];
}

/* Methods */
const bool Attaque::resoudreAttaque(Attaque &a) 
{
    int ATTAQUE1 = this->type;
    int ATTAQUE2 = a.type;

    if(ATTAQUE1 == ATTAQUE2)
    {
        return rand()%2 ? WIN : LOSE;
    }

    switch(ATTAQUE1) {
        case PIERRE:
            if(ATTAQUE2 == FEUILLE) return LOSE;
            else return WIN;
            break;
        case FEUILLE:
            if(ATTAQUE2 == CISEAUX) return LOSE;
            else return WIN;
            break;
        case CISEAUX:
            if(ATTAQUE2 == PIERRE) return LOSE;
            else return WIN;
            break;
        default:
            return LOSE;
            break;
      }
}