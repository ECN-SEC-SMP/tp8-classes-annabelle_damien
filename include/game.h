#ifndef GAME_H
#define GAME_H

#include <vector>
#include "animal.h"

#define TAILLE_PLATEAU 10
#define SHOW_LOG false
#define SHOW_FIGHTS true

#define NB_LIONS 1
#define NB_LOUPS 30
#define NB_OURS 10
#define NB_PIERRES 20

class Game {
    private:
        vector <Animal*> plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
        vector <Animal*> animaux;
        void nettoyerPlateau();
        void remplirPlateau();
    
    public:
        /* Constructors */
        Game();

        /* Getters */
        vector <Animal*> getAnimaux();

        /* Methods */
        void resoudreConflits();
        void deplacerAnimaux();
        void afficherPlateau();
        bool resteQueDesPierres();
};

#endif /* GAME_H */