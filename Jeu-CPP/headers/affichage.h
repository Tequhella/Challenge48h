#ifndef __AFFICHAGE_H__
#define __AFFICHAGE_H__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cmath>
#include <iostream>

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600

using namespace std;
using namespace sf;

class Affichage
{
    public:
    /*****************/
    /* CONSTRUCTEURS */
    /*****************/

        Affichage();

    /***************/
    /* DESTRUCTEUR */
    /***************/

        ~Affichage();

    /************/
    /* METHODES */
    /************/

        void afficherMenu();
        void afficherGameOver();
        void afficherKarmaBar();
        void afficherSDFMenu();
        void afficherTerrainDeJeu();

        void moveDecors(float x, float y);
    
    /*************/
    /* ACCESSEUR */
    /*************/

        int getKarma() const { return karma; }
        void setKarma(int karma) { this->karma = karma; }

        RenderWindow* getWindow() const { return window; }
        void setWindow(RenderWindow* window) { this->window = window; }

    private:
    /************/
    /* ATTRIBUTS */
    /************/
        int karma;
        RenderWindow* window;
        RectangleShape ignoreButton;
        RectangleShape helpButton;
        Text ignoreText;
        Text helpText;
        Text gameOverText;
        Font font;
        RectangleShape karmaBar;

        Texture backgroundTexture;
        Sprite background;
        Texture sol;
        vector<Sprite> solSprite;
        Texture mur;
        Sprite murSprite;
        Texture toi;
        Sprite toiSprite;
        Texture sdf;
        Sprite sdfSprite;

        vector<Texture> maisonTextures;
        vector<Sprite> maisonSprites;

}; // class Affichage

#endif // __AFFICHAGE_H__