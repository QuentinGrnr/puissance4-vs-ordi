
class Puissance4 {
    int T[6][7];
    int Col[7];
    int hmax;
public :
    Puissance4(int h); //le constructeur de la classe qui permet d’initialiser T à 0, Col à −1, et hmax à h
    void affichage(); //affiche le tableau T
    bool jouer(int j, int joueur); // permet à “joueur” (1 : ordinateur, -1 : humain) de jouer sur la colonne j du plateau; True si le coup est valide, False sinon
    void dejouer(int j); // permet de déjouer le dernier coup joué sur la colonne j du plateau
    int jeuOrdi(int & bestMove, int niveau); // permet à l’ordinateur d'évlaure le meilleur coup à jouer et de le stocker dans bestMove et renvoie la valeur de l’évaluation de ce coup
    int evaluation(int joueur, int j); // permet d’évaluer le coup joué par “joueur” (1 : ordinateur, -1 : humain) sur la colonne j du plateau
    int jeuHumain(int & bestMove, int niveau); // symétrique de jeuOrdi permettant à l'ordinateur de si
    int vertical(int joueur, int j); // permet d’évaluer le coup joué par “joueur” verticallement (1 : ordinateur, -1 : humain) sur la colonne j du plateau
    int horizontal(int joueur, int j); // permet d’évaluer le coup joué par “joueur” horizontalement (1 : ordinateur, -1 : humain) sur la colonne j du plateau
    int diagonaledroite(int joueur, int j); // permet d’évaluer le coup joué par “joueur” diagonalement vers la droite(1 : ordinateur, -1 : humain) sur la colonne j du plateau
    int diagonalegauche(int joueur, int j); // permet d’évaluer le coup joué par “joueur” diagonalement vers la gauche(1 : ordinateur, -1 : humain) sur la colonne j du plateau
    bool plein(); // permet de savoir si le plateau est plein
    bool coupgagnant(int joueur, int j); // permet de savoir si le coup joué par “joueur” (1 : ordinateur, -1 : humain) sur la colonne j du plateau est gagnant
};
