#include "Puissance4.h"
#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    int piece = rand() % 2;

    Puissance4 p(3);
    int jeu = 0; // 0 : la partie continue ; 1 : l'ordinateur a gagné ; -1 : l'humain a gagné ; 2 : match nul
    
    while (jeu ==0){
        if (piece == 0)
        {
            cout << "C'est à l'ordinateur de jouer ! (symbole : X)" << endl; 
            if (p.plein()){
                jeu = 2;
            } else {
                int bestMove = 0;
                p.jeuOrdi(bestMove, 3);
                if (p.coupgagnant(1, bestMove)){
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
                cout << "Entrez le numero de la colonne que vous voulez jouer : ";
                int move;
                cin >> move;
                while (!p.jouer(move, -1))
                {
                    cout << "Entrez un numero de colonne valide : ";
                    cin >> move;
                }
                p.dejouer(move);
                if (p.coupgagnant(-1, move))
                {
                    jeu = -1;
                }
                p.jouer(move, -1);
                p.affichage();
                piece = 0; // Passe au tour de l'ordinateur
            }
        }
    }

    if (jeu == 1)
    {
        cout << "L'ordinateur a gagné !" << endl;
        p.affichage();
    }
    else if (jeu == -1)
    {
        cout << "Vous avez gagné !" << endl;
        p.affichage();
    }
    else if (jeu == 2)
    {
        cout << "Match nul !" << endl;
        p.affichage();
    }
}