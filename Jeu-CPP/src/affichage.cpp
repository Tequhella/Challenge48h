#include "../headers/affichage.h"

Affichage::Affichage()
{
    // Créer la fenêtre
    window = new RenderWindow(VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "Jeu-CPP");
    window->setFramerateLimit(60);

    // Créer les boutons
    ignoreButton = RectangleShape(Vector2f(200, 50));
    ignoreButton.setFillColor(Color::Red);
    ignoreButton.setPosition(Vector2f(300, 500));

    helpButton = RectangleShape(Vector2f(200, 50));
    helpButton.setFillColor(Color::Green);
    helpButton.setPosition(Vector2f(500, 500));

    // Créer le texte
    if (!font.loadFromFile("arial_mt_black/ARIBL0.ttf"))
    {
        exit(1);
    }

    ignoreText = Text("Ignorer", font, 30);
    ignoreText.setPosition(Vector2f(355, 505));
    ignoreText.setFillColor(Color::White);

    helpText = Text("Aider", font, 30);
    helpText.setPosition(Vector2f(550, 505));
    helpText.setFillColor(Color::White);

    gameOverText = Text();
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setPosition(Vector2f(250, 300));
    gameOverText.setFillColor(Color::White);

    // Créer la barre de vie
    karmaBar = RectangleShape(Vector2f(100, 25));
    karmaBar.setFillColor(Color::Green);
    karmaBar.setPosition(Vector2f(25, 25));

    // Image de fond
    if (!backgroundTexture.loadFromFile("background.png"))
    {
        exit(1);
    }
    background = Sprite(backgroundTexture);
    background.setPosition(Vector2f(0, 0));
    background.setScale(Vector2f(0, 0));

    // Sol
    if (!sol.loadFromFile("sol.png"))
    {
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        solSprite.push_back(Sprite(sol));
        solSprite[i].setPosition(Vector2f(i * 800, 400));
        solSprite[i].setScale(Vector2f(0, 0));
    }

    // Mur
    if (!mur.loadFromFile("mur.png"))
    {
        exit(1);
    }
    murSprite = Sprite(mur);
    murSprite.setPosition(Vector2f(0, 0));
    murSprite.setScale(Vector2f(0, 0));

    // Toi
    if (!toi.loadFromFile("toi.png"))
    {
        exit(1);
    }
    toiSprite = Sprite(toi);
    toiSprite.setPosition(Vector2f(LARGEUR_FENETRE / 2 - 95, solSprite[0].getPosition().y - 95));
    toiSprite.setScale(Vector2f(0, 0));
    
    if (!sdf.loadFromFile("sdf.png"))
    {
        exit(1);
    }
    sdfSprite = Sprite(sdf);
    sdfSprite.setPosition(Vector2f(0, 0));
    sdfSprite.setScale(Vector2f(0, 0));
    
    string nomFichier;
    for (int i = 0; i < 5; i++)
    {
        nomFichier = "maison" + to_string(i) + ".png";
        Texture* tempTexture = new Texture();
        if (!tempTexture->loadFromFile(nomFichier))
        {
            exit(1);
        }
        Sprite tempSprite;
        maisonSprites.push_back(tempSprite);
        maisonSprites[i].setTexture(*tempTexture);
        // doit toucher le sol dynamiquement
        maisonSprites[i].setPosition(Vector2f(i * 800, solSprite[0].getPosition().y- 150));
        maisonSprites[i].setScale(Vector2f(0, 0));
    }

    maisonSprites[0].setPosition(Vector2f(-100, solSprite[0].getPosition().y - 550));
    maisonSprites[2].setPosition(Vector2f(1600, solSprite[0].getPosition().y - 200));
    maisonSprites[3].setPosition(Vector2f(2400, solSprite[0].getPosition().y - 300));
    maisonSprites[4].setPosition(Vector2f(3200, solSprite[0].getPosition().y - 350));
}

Affichage::~Affichage()
{
    delete window;
    maisonSprites.clear();
}

void Affichage::afficherMenu()
{
    RectangleShape bouttonStart = RectangleShape(Vector2f(200, 50));
    bouttonStart.setFillColor(Color::Green);
    bouttonStart.setPosition(Vector2f(300, 500));

    Text startText = Text("Start", font, 30);
    startText.setPosition(Vector2f(355, 505));
    startText.setFillColor(Color::White);

    bool isTerrainDeJeuOpen = false;

    // Afficher le menu
    while (!isTerrainDeJeuOpen)
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window->close();
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (bouttonStart.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        isTerrainDeJeuOpen = true;
                    }
                }
            }
        }

        window->clear();
        window->draw(bouttonStart);
        window->draw(startText);
        window->display();
    }
}

void Affichage::afficherGameOver()
{
    // Afficher le Game Over
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window->close();
            }
        }

        window->clear();
        window->draw(gameOverText);
        window->display();
    }
}

void Affichage::afficherTerrainDeJeu()
{
    srand(time(NULL));
    bool isSDFMenuOpen  = false;
    bool isTextShown    = false;
    int toiSpritePositionX = 0;
    int toiSpritePositionY = 0;
    int random = rand() % 5;
    Clock clock;
    Int32 time  = 0;
    Int32 time2 = 0;
    Int32 time3 = 0;
    Int32 time4 = 0;
    Text sdfText = Text("Le SDF n'est pas dans cette maison...", font, 30);
    sdfText.setPosition(Vector2f(100, 100));
    sdfText.setFillColor(Color::White);
    sdfText.setScale(Vector2f(0, 0));

    background.setScale(Vector2f(1, 1));
    murSprite.setScale(Vector2f(1, 1));
    toiSprite.setScale(Vector2f(1, 1));
    sdfSprite.setScale(Vector2f(1, 1));

    for (unsigned int i = 0; i < solSprite.size(); i++)
    {
        solSprite[i].setScale(Vector2f(1, 1));
    }

    for (unsigned int i = 0; i < maisonSprites.size() - 1; i++)
    {
        maisonSprites[i].setScale(Vector2f(0.2, 0.2));
    }

    maisonSprites[4].setScale(Vector2f(0.75, 0.75));

    // Afficher le terrain de jeu
    while (!isSDFMenuOpen)
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                isSDFMenuOpen = true;
                window->close();
            }
        }

        

        // Gestion du déplacement de Toi
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (toiSprite.getPosition().x >= maisonSprites[0].getGlobalBounds().left + maisonSprites[0].getGlobalBounds().width)
            {
                time2 = (time2 == 0) ? clock.getElapsedTime().asMilliseconds() : time2;
                if (toiSprite.getScale().x == -1)
                    toiSprite.setPosition(Vector2f(toiSprite.getPosition().x - 144, toiSprite.getPosition().y));
                toiSprite.setScale(Vector2f(1, 1));
                toiSpritePositionY = 2;
                moveDecors(5, 0);
                if (clock.getElapsedTime().asMilliseconds() - time2 > 100)
                {
                    toiSpritePositionX++;
                    toiSpritePositionX %= 6;
                    time2 = 0;
                }
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (toiSprite.getPosition().x <= maisonSprites[4].getGlobalBounds().left)
            {
                time3 = (time3 == 0) ? clock.getElapsedTime().asMilliseconds() : time3;
                if (toiSprite.getScale().x == 1)
                    toiSprite.setPosition(Vector2f(toiSprite.getPosition().x + 144, toiSprite.getPosition().y));
                toiSprite.setScale(Vector2f(-1, 1));
                toiSpritePositionY = 2;
                moveDecors(-5, 0);
                if (clock.getElapsedTime().asMilliseconds() - time3 > 100)
                {
                    toiSpritePositionX++;
                    toiSpritePositionX %= 6;
                    time3 = 0;
                }
            }
        }
        else
        {
            time4 = (time4 == 0) ? clock.getElapsedTime().asMilliseconds() : time4;
            if (clock.getElapsedTime().asMilliseconds() - time4 > 100)
            {
                toiSpritePositionX = 0;
                toiSpritePositionY = 0;
                time4 = 0;
            }
        }
        

        // Gestion de l'animation de Toi
        toiSprite.setTextureRect(IntRect(toiSpritePositionX * 144, toiSpritePositionY * 144, 144, 144));

        
        // Interaction avec les maisons
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            if (toiSprite.getGlobalBounds().intersects(maisonSprites[random].getGlobalBounds()))
            {
                isSDFMenuOpen = true;
            }
            else if (toiSprite.getGlobalBounds().intersects(maisonSprites[0].getGlobalBounds()) ||
                toiSprite.getGlobalBounds().intersects(maisonSprites[1].getGlobalBounds()) ||
                toiSprite.getGlobalBounds().intersects(maisonSprites[2].getGlobalBounds()) ||
                toiSprite.getGlobalBounds().intersects(maisonSprites[3].getGlobalBounds()) ||
                toiSprite.getGlobalBounds().intersects(maisonSprites[4].getGlobalBounds()))
            {
                // Afficher message indicant que le sdf n'est pas dans ce bâtiment
                isTextShown = true;
                time = clock.getElapsedTime().asMilliseconds();
            }
        }


        // Gestion de la barre de vie
        /*
        if (karmaBar.getSize().x > 0)
        {
            karmaBar.setSize(Vector2f(karmaBar.getSize().x - 0.0001, karmaBar.getSize().y));
        }
        else
        {
            isSDFMenuOpen = true;
            afficherGameOver();
        }
        */

        window->clear();
        //window->draw(background);
        //window->draw(murSprite);
        //window->draw(sdfSprite);
        //window->draw(karmaBar);

        if (isTextShown)
        {
            sdfText.setScale(Vector2f(1, 1));
            // Disparition du texte sur 2 secondes
            sdfText.setFillColor(Color(255, 255, 255, 255 - (clock.getElapsedTime().asMilliseconds() - time) / 8));
            window->draw(sdfText);
            
            if (clock.getElapsedTime().asMilliseconds() - time > 2000)
            {
                isTextShown = false;
                sdfText.setScale(Vector2f(0, 0));
            }
        }

        for (unsigned int i = 0; i < solSprite.size(); i++)
            window->draw(solSprite[i]);
        for (unsigned int i = 0; i < maisonSprites.size(); i++)
            window->draw(maisonSprites[i]);

        window->draw(toiSprite);
        window->display();
    }
}

void Affichage::afficherSDFMenu()
{
    bool isGameOverOpen = false;


    // Jouer le son
    SoundBuffer buffer;
    if (!buffer.loadFromFile("Cyberpunk 2077 music.wav"))
    {
        exit(1);
    }
    Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    // Afficher le menu SDF
    while (!isGameOverOpen)
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                isGameOverOpen = true;
                window->close();
            }
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (ignoreButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        karma -= 10;
                        afficherTerrainDeJeu();
                    }
                    if (helpButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        karma += 10;
                        afficherTerrainDeJeu();
                    }
                }
            }
        }

        window->clear();
        window->draw(ignoreButton);
        window->draw(ignoreText);
        window->draw(helpButton);
        window->draw(helpText);
        window->display();
    }
}

void Affichage::afficherKarmaBar()
{
    Event event;
    while (window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window->close();
        }
    }

    window->clear();
    window->draw(karmaBar);
    window->display();
}

void Affichage::moveDecors(float x, float y)
{
    for (unsigned int i = 0; i < solSprite.size(); i++)
    {
        solSprite[i].move(x, y);
    }

    for (unsigned int i = 0; i < maisonSprites.size(); i++)
    {
        maisonSprites[i].move(x, y);
    }

    //murSprite.move(x, y);
    //toiSprite.move(x, y);
    //sdfSprite.move(x, y);
}