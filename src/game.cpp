#include <iostream>
#include <algorithm>

#include "game.h"
#include "lion.h"
#include "ours.h"
#include "pierre.h"
#include "loup.h"
#include "attaque.h"

using namespace std;

Game::Game() {
    cout << endl << "====== Nouvelle partie ======" << endl << endl;

    /* Naissance des animaux */
    for (int nb_lions = 0; nb_lions < NB_LIONS; nb_lions++) {
        this->animaux.push_back(new Lion(TAILLE_PLATEAU, TAILLE_PLATEAU));
    }

    for (int nb_loups = 0; nb_loups < NB_LOUPS; nb_loups++) {
        this->animaux.push_back(new Loup(TAILLE_PLATEAU, TAILLE_PLATEAU));
    }

    for (int nb_ours = 0; nb_ours < NB_OURS; nb_ours++) {
        this->animaux.push_back(new Ours(TAILLE_PLATEAU, TAILLE_PLATEAU));
    }

    for (int nb_pierres = 0; nb_pierres < NB_PIERRES; nb_pierres++) {
        this->animaux.push_back(new Pierre(TAILLE_PLATEAU, TAILLE_PLATEAU));
    }

    for (int row=0; row<TAILLE_PLATEAU; row++) {
        for (int col=0; col<TAILLE_PLATEAU; col++) {
            this->plateau[row][col] = vector<Animal*>();
        }
    }

    remplirPlateau();
}


/* Getters */
vector <Animal*> Game::getAnimaux() {
    return this->animaux;
}


/* Methods */
void Game::resoudreConflits() {
    /* Itération dans les cases du plateau */
    for (int row=0; row<TAILLE_PLATEAU; row++) {
        for (int col=0; col<TAILLE_PLATEAU; col++) {
            vector<Animal*>& square = this->plateau[row][col]; // utilisation d'une référence pour modifier réellement la case et pas créer une copie
            bool fights_in_square;

            /* Affichage des animaux présents dans la case s'il y en a plusieurs */
            if (square.size() > 1 && (SHOW_FIGHTS || SHOW_LOG)) {
                fights_in_square = true;
                cout << "Animals in (" << row << "," << col << "): ";
                for (auto animal_it = square.begin(); animal_it != square.end(); animal_it++)
                {
                    cout << (*animal_it)->getNom();
                }
                cout << endl;
            } else fights_in_square = false;

            /* Combats tant qu'il y a plusieurs animaux sur la case */
            while (square.size() > 1) {
                /* Combat entre animal_1 et animal_2 */
                auto animal_1 = square[0];
                auto animal_2 = square[1];
                bool animal_1_won = animal_1->attaque(*animal_2) == WIN;

                /* Affichage de l'attaque */
                if (SHOW_FIGHTS) {
                    /* Affichage des deux animaux qui se battent */
                    cout << "Fight: " << animal_1->getNom() << "(";
                    cout << animal_1->getAttaque().getNomAttaque() << ") vs ";
                    cout << animal_2->getNom() << "(" << animal_2->getAttaque().getNomAttaque() << ") → ";
                    
                    /* Affichage du vainqueur */
                    if (animal_1_won) cout << animal_1->getNom() << endl;
                    else cout << animal_2->getNom() << endl;
                }
                
                /* Suppression de l'animal vaincu dans la case et dans le vecteur animaux */
                if (animal_1_won) {
                    /* Suppression de l'animal 2 */
                    this->animaux.erase(find(this->animaux.begin(), this->animaux.end(), animal_2));
                    square.erase(square.begin()+1);
                } else {
                    /* Suppression de l'animal 1 */
                    this->animaux.erase(find(this->animaux.begin(), this->animaux.end(), animal_1));
                    square.erase(square.begin());
                }
            }

            if (fights_in_square) cout << endl;
        }
    }
}

void Game::nettoyerPlateau() {
    for (int row=0; row<TAILLE_PLATEAU; row++) {
        for (int col=0; col<TAILLE_PLATEAU; col++) {
            this->plateau[row][col].clear();
        }
    }
}

void Game::remplirPlateau() {
    for(Animal* animal : this->animaux) {
        if (animal != nullptr) {
            this->plateau[animal->getX()][animal->getY()].push_back(animal);
        }
    }
}

void Game::deplacerAnimaux() {
    /* Nettoyage du plateau */
    nettoyerPlateau();

    /* Ajout des animaux */
    for(Animal* animal : this->animaux) {
        if (animal != nullptr) {
            if (SHOW_LOG && animal->getNom() != NOM_PIERRE) cout << "[log]" << animal->getNom() << " moved from (" << animal->getX() << "," << animal->getY() << ") to (";
            animal->deplace(TAILLE_PLATEAU, TAILLE_PLATEAU);
            if (SHOW_LOG && animal->getNom() != NOM_PIERRE) cout << animal->getX() << "," << animal->getY() << ")" << endl;
            // this->plateau[animal->getX()][animal->getY()].push_back(animal);
        }
    }
    if (SHOW_LOG) cout << endl;

    remplirPlateau();

    /* Résolution des conflits */
    resoudreConflits();
}

void Game::afficherPlateau() {
    /* Itération dans le tableau ligne par ligne */
    for (int row=0; row<TAILLE_PLATEAU; row++) {
        /* Affichage de la délimitation horizontale */
        for (int square=0; square<TAILLE_PLATEAU; square++) {
            cout << "|----";
        }
        cout << "|" << endl;

        /* Affichage de chaque case de la ligne */
        for (int col=0; col<TAILLE_PLATEAU; col++) {
            if (!this->plateau[row][col].empty()) {
                if (this->plateau[row][col][0] != nullptr) {
                    cout << "| " << this->plateau[row][col][0]->getNom() << " ";
                }
            } else {
                cout << "|    ";
            }
        }
        cout << "|" << endl;
    }

    /* Affichage du bord inférieur du plateau */
    for (int square=0; square<TAILLE_PLATEAU; square++) {
        cout << "|----";
    }
    cout << "|" << endl;

    cout << "Animaux en jeu : " << this->animaux.size() << endl << endl;
}

bool Game::resteQueDesPierres() {
    for (auto && animal : animaux) {
        if (animal != nullptr && animal->getNom() != NOM_PIERRE) return false;
    }
    return true;
}