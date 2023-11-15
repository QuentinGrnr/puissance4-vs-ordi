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
    return 0;
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
    jouer (j, joueur);
    int sum = 0;
    int nb_adv = 0; //nombre de pions de l'adversaire sur la verticale a la suite
    int nb_joueur = 0; //nombre de pions du joueur sur la verticale a la suite
    for (int i = Col[j]+1; i < 6; i++){
       if (T[i][j] == joueur) {
        sum += 5;
        } else if (T[i][j] == -joueur) {
            break;
        } else if (T[i][j] == 0) {
            sum++;
        } 
    }
    for (int i = Col[j]-1; i > -1; i--){
       if (T[i][j] == joueur) {
        sum += 5;
        } else if (T[i][j] == -joueur) {
            break;
        } else if (T[i][j] == 0) {
            sum++;
        } 
    }
    for (int i = 0; i < 6; i++){
       if (T[i][j] == joueur) {
            nb_joueur++;
            nb_adv=0;
        } else if (T[i][j] == -joueur) {
            nb_adv++;
            nb_joueur=0;
        } else if (T[i][j] == 0) { // si la case suivante est vide on réinitialise les compteurs car logiquement il n'y a plus de pions a la suite
            nb_joueur=0;
            nb_adv=0;
            break;
        }
        if (nb_adv == 3 && i < 5 && T[i+1][j] != joueur) {
            dejouer(j);
            return -1000; // si l'adversaire a 3 pions a la suite et qu'il peut jouer au prochain tour on retourne -1000
        } 
        if (nb_joueur == 4) {
            dejouer(j);
            return 1000; // si le joueur a 4 pions a la suite on retourne 1000 car il gagne
        }
    }
    dejouer(j);
    return sum;
}

int Puissance4::horizontal(int joueur, int j)
{
    jouer (j, joueur);
    int sum = 0;
    int nb_adv = 0; //nombre de pions de l'adversaire sur l'horizontale a la suite
    int nb_joueur = 0; //nombre de pions du joueur sur l'horizontale a la suite
    for (int i = j+1; i < 7; i++){
       if (T[Col[j]][i] == joueur) {
        sum += 5;
        } else if (T[Col[j]][i] == -joueur) {
            break;
        } else if (T[Col[j]][i] == 0) {
            sum++;
        } 
    }
    for (int i = j-1; i > -1; i--){
       if (T[Col[j]][i] == joueur) {
        sum += 5;
        } else if (T[Col[j]][i] == -joueur) {
            break;
        } else if (T[Col[j]][i] == 0) {
            sum++;
        } 
    }
    for (int i = 0; i < 7; i++){
       if (T[Col[j]][i] == joueur) {
            nb_joueur++;
            nb_adv=0;
        } else if (T[Col[j]][i] == -joueur) {
            nb_adv++;
            nb_joueur=0;
        } else if (T[Col[j]][i] == 0) {
            if (T[Col[j]][i+1] == 0) { // si la case suivante est vide on réinitialise les compteurs
                nb_joueur=0;
                nb_adv=0;
            } else { // sinon on incrémente le compteur de l'adversaire car il peut potentiellement jouer ici et gagner au prochain tour
                nb_adv++;
            } 
        } 
        if (nb_adv == 3 && i < 6 && T[i][j+1] != joueur) {
            dejouer(j);
            return -1000; // si l'adversaire a 3 pions a la suite et qu'il peut jouer au prochain tour on retourne -1000
        }
        if (nb_joueur == 4) {
            dejouer(j);
            return 1000; // si le joueur a 4 pions a la suite on retourne 1000 car il gagne
        }
    }
    dejouer(j);
    return sum;
}

int Puissance4::diagonaledroite(int joueur, int j)
{
    return 0;
}

int Puissance4::diagonalegauche(int joueur, int j)
{
    return 0;
}
