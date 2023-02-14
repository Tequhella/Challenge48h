#include "../headers/affichage.h"

using namespace std;
using namespace sf;

int karma = 1;

int main()
{
    bool menu     = true;
    bool sdfMenu  = false;
    bool gameOver = false;
    // Créer la fenêtre
    Affichage affichage;

    // Boucle de jeu
    while (affichage.getWindow()->isOpen())
    {
        if (menu)
        {
            affichage.afficherMenu();
            menu = false;
        }
        else if (sdfMenu)
        {
            affichage.afficherSDFMenu();
            sdfMenu  = false;
            gameOver = true;
        }
        else if (gameOver)
        {
            affichage.afficherGameOver();
            gameOver = false;
        }
        else
        {
            affichage.afficherTerrainDeJeu();
            sdfMenu = true;
        }
    }

    return 0;
}