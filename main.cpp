#include "Puissance4.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int piece = rand() % 2;
    int difficultee;
    
    cout << "Choisissez la difficulté de l'ordinateur (2 simple, 6 complexe, 8 très complexe, etc.)" << endl;
    cout << "WARN = Plus la difficulté est élevée, plus le temps de calcul est long" << endl;
    cin >> difficultee;
    
    if (difficultee % 2 == 1)
    {
        difficultee++;
    }
    
    Puissance4 p(difficultee);
    int jeu = 0; // 0: la partie continue ; 1: l'ordinateur a gagné ; -1: l'humain a gagné ; 2: match nul
    
    while (jeu == 0)
    {
        if (piece == 0)
        {
            cout << "C'est à l'ordinateur de jouer ! (symbole : X)" << endl; 
            if (p.plein())
            {
                jeu = 2;
            }
            else
            {
                int bestMove = 0;
                p.jeuOrdi(bestMove, 1);
                
                if (p.coupgagnant(1, bestMove))
                {
                    jeu = 1;
                }
                
                p.jouer(bestMove, 1);
                p.affichage();
                piece = 1; // Passe au tour du joueur
            }
        }
        else
        {
            if (p.plein())
            {
                jeu = 2;
            }
            else
            {
                cout << "C'est à vous de jouer ! (symbole : O)" << endl;
                cout << "Entrez le numéro de la colonne que vous voulez jouer : ";
                int move;
                cin >> move;
                
                if (p.coupgagnant(-1, move))
                {
                    jeu = -1;
                }
                
                while (!p.jouer(move, -1))
                {
                    cout << "Entrez le numéro de la colonne que vous voulez jouer : ";
                    cin >> move;
                }
                p.affichage();
                piece = 0; // Passe au tour de l'ordinateur
            }
        }
    }

    if (jeu == 1)
    {
        cout << "L'ordinateur a gagné !" << endl;
    }
    else if (jeu == -1)
    {
        cout << "Vous avez gagné !" << endl;
    }
    else if (jeu == 2)
    {
        cout << "Match nul !" << endl;
    }
}