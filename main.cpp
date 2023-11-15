#include "Puissance4.h"
#include <iostream>
using namespace std;

int main()
{
    Puissance4 p(3);
    p.jouer(0, 1);
    p.jouer(0, -1);
    p.jouer(0, 1);
    p.jouer(0, -1);
    p.jouer(0, 1);
    p.jouer(0, -1);
    p.jouer(5, 1);
    p.jouer(6, -1);
    p.jouer(6, 1);
    p.jouer(8,-1)    ;
    p.affichage();
    p.dejouer(0);
    p.dejouer(0);
    p.dejouer(6);
    p.dejouer(8);
    p.affichage();
}