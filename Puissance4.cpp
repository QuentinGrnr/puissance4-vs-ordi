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
    for (int i = 0; i < 7; i++) cout << i << " ";
        cout << endl << "   -";
    for (int i = 0; i < 7; i++) cout << "--";    
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
    if (Col[j] == 5 || j < 0 || j > 7) return false; 
    
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
    int somme = vertical(joueur, j) + horizontal(joueur, j) + diagonaledroite(joueur, j) + diagonalegauche(joueur, j);
    if (joueur == 1) {
        return somme;
    } else {
        return -somme;
    }
}
//----------------------------------------------------------------------------------------//
//--------------------- Méthodes dévaluation des cours celon le sens ---------------------//
//----------------------------------------------------------------------------------------//

// On va évaluer les coups joués par l'ordinateur et l'humain en fonction de leur position sur le plateau
// on parcours dans un premier temps a droite (ou vers le haut) puis a gauche (ou vers le bas) du piont pour calculer la somme sur la ligne
// piont du joueur présent = +5
// piont de l'adversaire présent = stop la recherche
// case vide = +1
// une fois le calcul de la somme terminé on verifie l'état du jeu
// Si le coup permet de gagner on retourne 1000
// Si le coup permet à l'adversaire de gagner au prochain tour on retourne -1000
// Sinon on retourne la somme des pions du joueur sur la ligne


int Puissance4::vertical(int joueur, int j)
{
    int sum = 0;
    int nb_joueur = 0; //nombre de pions du joueur sur la verticale a la suite
    for (int i = 5; i >= 0; i--){ // on parcours la colonne de bas en haut
       if (T[i][j] == joueur) {
        sum += 5;
        nb_joueur++;
        } else if (T[i][j] == -joueur) {
            nb_joueur=0;
            break;
        } else if (T[i][j] == 0) {
            sum++;
        }
        if (nb_joueur >= 4) {
            return 1000; // si le joueur a 4 pions a la suite on retourne 1000 car il gagne
        }
    }
    return sum;
}

int Puissance4::horizontal(int joueur, int j)
{
    int sum = 0;
    int nb_joueur = 0; //nombre de pions du joueur a l'horizontale a la suite
    // on parcours a droite puis a gauche du piont pour calculer la somme sur la ligne
    for (int i = j; i < 7; i++){
       if (T[Col[j]][i] == joueur) {
        sum += 5;
        } else if (T[Col[j]][i] == -joueur) {
            break;
        } else if (T[Col[j]][i] == 0) {
            sum++;
        }
    }
    for (int i = j-1; i >= 0; i--){
       if (T[Col[j]][i] == joueur) {
        sum += 5;
        } else if (T[Col[j]][i] == -joueur) {
            break;
        } else if (T[Col[j]][i] == 0) {
            sum++;
        }
    }

    // on verifie si grace au coup, le joueur gagne
    for (int i = j; i < 7; i++){
       if (T[Col[j]][i] == joueur) {
        nb_joueur++;
        } else if (T[Col[j]][i] == -joueur || T[Col[j]][i] == 0) {
            break;
        }
    }
    for (int i = j-1; i >= 0; i--){
       if (T[Col[j]][i] == joueur) {
        nb_joueur++;
        } else if (T[Col[j]][i] == -joueur || T[Col[j]][i] == 0) {
            break;
        }
    }
    if (nb_joueur >= 4) {
            return 1000; // si le joueur a 4 pions a la suite on retourne 1000 car il gagne
        }
    return sum;
}

int Puissance4::diagonaledroite(int joueur, int j)
{
    int sum = 0;
    int nb_joueur = 0; //nombre de pions du joueur a l'horizontale a la suite
    // on parcours a droite puis a gauche du piont pour calculer la somme sur la ligne
    int k = Col[j];
    int i = j;
    while (k < 6 && i < 7){
       if (T[k][i] == joueur) {
        sum += 5;
        } else if (T[k][i] == -joueur) {
            break;
        } else if (T[k][i] == 0) {
            sum++;
        }
        k++;
        i++;
    }

    k = Col[j]-1;
    i = j-1;
    while (k >= 0 && i >= 0){
       if (T[k][i] == joueur) {
        sum += 5;
        } else if (T[k][i] == -joueur) {
            break;
        } else if (T[k][i] == 0) {
            sum++;
        }
        k--;
        i--;
    }

    // on verifie si grace au coup, le joueur gagne
    k = Col[j];
    i = j;
    while (k < 6 && i < 7){
       if (T[k][i] == joueur) {
        nb_joueur++;
        } else if (T[k][i] == -joueur || T[k][i] == 0) {
            break;
        }
        k++;
        i++;
    }

    k = Col[j]-1;
    i = j-1;
    while (k >= 0 && i >= 0){
       if (T[k][i] == joueur) {
        nb_joueur++;
        } else if (T[k][i] == -joueur || T[k][i] == 0) {
            break;
        }
        k--;
        i--;
    }

    if (nb_joueur == 4) {
            return 1000; // si le joueur a 4 pions a la suite on retourne 1000 car il gagne
        }
    return sum;
}

int Puissance4::diagonalegauche(int joueur, int j)
{
    int sum = 0;
    int nb_joueur = 0; //nombre de pions du joueur a l'horizontale a la suite
    // on parcours a droite puis a gauche du piont pour calculer la somme sur la ligne
    int k = Col[j];
    int i = j;
    while (k < 6 && i >= 0){
       if (T[k][i] == joueur) {
        sum += 5;
        } else if (T[k][i] == -joueur) {
            break;
        } else if (T[k][i] == 0) {
            sum++;
        }
        k++;
        i--;
    }

    k = Col[j]-1;
    i = j+1;
    while (k >= 0 && i < 7){
       if (T[k][i] == joueur) {
        sum += 5;
        } else if (T[k][i] == -joueur) {
            break;
        } else if (T[k][i] == 0) {
            sum++;
        }
        k--;
        i++;
    }

    // on verifie si grace au coup, le joueur gagne
    k = Col[j];
    i = j;
    while (k < 6 && i >= 0){
       if (T[k][i] == joueur) {
        nb_joueur++;
        } else if (T[k][i] == -joueur || T[k][i] == 0) {
            break;
        }
        k++;
        i--;
    }

    k = Col[j]-1;
    i = j+1;
    while (k >= 0 && i < 7){
       if (T[k][i] == joueur) {
        nb_joueur++;
        } else if (T[k][i] == -joueur || T[k][i] == 0) {
            break;
        }
        k--;
        i++;
    }

    if (nb_joueur == 4) {
            return 1000; // si le joueur a 4 pions a la suite on retourne 1000 car il gagne
        }
    return sum;
}

int Puissance4::jeuOrdi(int & bestMove, int niveau)
{
    int arg = 0;
    int joueur = 1;
    if (plein()) return 0;
    if (coupgagnant(joueur,bestMove)) {
        return 1000;
    }
    if (niveau == this->hmax){
        int S=0;
        for (int i = 0; i < 7; i++){
            if (jouer(i, joueur)){
                S += evaluation(joueur, i);
                dejouer(i);
            }
        }
        return S;
    }
    int val = -1000;
    int res;
    for (int i = 0; i < 7; i++){
        if (!plein()){
            if (jouer(i, joueur)){
                res = jeuHumain(arg, niveau+1);
                dejouer(i);
                if (res > val){
                    val = res;
                    bestMove = i;
                }
            }
        }
    }
    return val;
}

int Puissance4::jeuHumain(int & bestMove, int niveau)
{

    int joueur = -1;
    if (plein()) return 0;
    if (coupgagnant(joueur,bestMove)) {
        return -1000;
    }
    if (niveau == this->hmax){
        int S=0;
        for (int i = 0; i < 7; i++){
            if (jouer(i, joueur)){
                S += evaluation(joueur, i);
                dejouer(i);
            }
        }
        return S;
    }
    int val = 1000;
    int res;
    int arg = 0;
    for (int i = 0; i < 7; i++){
        if (!plein()){
            if(jouer(i, joueur)){
                res = jeuOrdi(arg, niveau+1);
                dejouer(i);
                if (res < val){
                    val = res;
                    bestMove = i;
                }
            }
        }
    }
    return val;
}

bool Puissance4::plein()
{
    for (int i = 0; i < 7; i++)
        if (Col[i] != 5) return false;
    return true;
}

bool Puissance4::coupgagnant(int joueur, int j)
{
    if (Col[j] == 5) return false;
    
    if (jouer(j, joueur)){
        if (joueur == 1 && evaluation(joueur, j) >= 1000) {
        dejouer(j);
        return true;
    }
    else if (joueur == -1 && evaluation(joueur, j) <= -1000) {
        dejouer(j);
        return true;
    
    }
    dejouer(j);
    }
    return false;
}