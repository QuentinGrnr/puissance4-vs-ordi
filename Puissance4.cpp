#include "Puissance4.h"
#include <iostream>
using namespace std;

Puissance4::Puissance4(int h)
{
    hmax = h;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            T[i][j] = 0;
    for (int j = 0; j < 7; j++)
        Col[j] = -1;
}

void Puissance4::affichage()
{
    cout << "ordinateur : X humain : O" << endl << endl;

    cout << "    ";
    for (int i = 0; i < 7; i++)
        cout << i << " ";
        cout << endl << "   -";
    for (int i = 0; i < 7; i++)
        cout << "--";    
        cout << endl;
    for (int i = 5; i >= 0; i--)
    {
        cout << i << " | ";
        for (int j = 0; j < 7; j++) {
        if (T[i][j] == 1) {
            cout << "X ";
            } else if (T[i][j] == -1){
                cout << "O ";
            } else cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Puissance4::jouer(int j, int joueur)
{
    if (Col[j] == 5|| j < 0 || j > 6) return false;
    Col[j]++;
    this->T[Col[j]][j] = joueur;   
    return true; 
}

void Puissance4::dejouer(int j)
{
    if (Col[j] == -1 || j < 0 || j > 7) return;
    this->T[Col[j]][j] = 0;
    Col[j]--;
}

int Puissance4::evaluation(int joueur, int j)
{
    
}
