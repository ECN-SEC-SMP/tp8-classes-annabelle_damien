#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "game.h"
#include "lion.h"
#include "ours.h"
#include "pierre.h"
#include "loup.h"

using namespace std;

int main() {
    srand(time(NULL));

    Game game = Game();
    game.afficherPlateau();

    int round = 0;
    // while (round < 10)
    while (game.getAnimaux().size() > 1 && !game.resteQueDesPierres())
    {
        game.deplacerAnimaux();
        game.afficherPlateau();
        round++;
    }

    cout << "Partie finie en " << round << " rounds" << endl;
    cout << "Winner : " << game.getAnimaux()[0]->getNom() << endl << endl;
    
    return 0;
}
