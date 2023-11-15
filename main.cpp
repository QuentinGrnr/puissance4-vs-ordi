#include "Puissance4.h"
#include <iostream>
using namespace std;

int main()
{
    Puissance4 p(3);
    p.jouer(0, 1);
    p.jouer(1, 1);
    p.jouer(4, 1);
    p.jouer(5, 1);
    p.jouer(6, 1);

    p.affichage();
    cout << p.vertical(-1, 2) << endl;
    p.affichage();

    p.jouer(2, -1);
    p.jouer(2, -1);
    p.jouer(2, 1);
    p.jouer(2, 1);
    p.jouer(2, 1);
    cout << p.vertical(-1, 2) << endl;
    p.affichage();
}