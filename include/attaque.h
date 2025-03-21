#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <string>
using namespace std;

#define PIERRE 0
#define FEUILLE 1
#define CISEAUX 2
#define WIN 1
#define LOSE 0

class Attaque {
    private: 
        int type ; // 0 :pierre, 1: Feuille, 2:Ciseaux

    public :

        /* Constructors */
        Attaque() ; // cree une attaque random
        Attaque(int a) ; // cree une attaque specifique

        /* Getters */
        const int getTypeAttaque() ; 
        string getNomAttaque() const; 

        /* Methods */
        const bool resoudreAttaque(Attaque &a) ;
};

#endif /* ATTAQUE_H */