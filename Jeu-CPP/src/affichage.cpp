#include "../headers/affichage.h"

Affichage::Affichage()
{
    // Créer la fenêtre
    window = new RenderWindow(VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "Jeu-CPP");
    window->setFramerateLimit(60);

    // Créer les boutons
    ignoreButton = RectangleShape(Vector2f(200, 50));
    ignoreButton.setFillColor(Color(200, 0, 0, 255));
    ignoreButton.setPosition(Vector2f(300, 500));

    // Créer le texte
    if (!font.loadFromFile("arial_mt_black/ARIBL0.ttf"))
    {
        exit(1);
    }

    ignoreText = Text("MUDA", font, 30);
    ignoreText.setPosition(Vector2f(355, 505));
    ignoreText.setFillColor(Color::White);

    gameOverText = Text();
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setPosition(Vector2f(250, 300));
    gameOverText.setFillColor(Color::White);
    gameOverText.setString("GAME OVER");

    // Créer la barre de vie
    karma = 1;
    karmaBar = RectangleShape(Vector2f(100, 25));
    karmaBar.setSize(Vector2f(karma * 2, 20));
    karmaBar.setFillColor(Color(255 - karma * 2.55, karma * 2.55, 0));

    // Image de fond
    if (!backgroundTexture.loadFromFile("background.jpg"))
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
    sdfSprite.setPosition(Vector2f(LARGEUR_FENETRE - 500, 100));
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
    bool isGameOverOpen = true;
    RectangleShape bouttonQuit = RectangleShape(Vector2f(200, 50));
    bouttonQuit.setFillColor(Color::Red);
    bouttonQuit.setPosition(Vector2f(150, 500));

    // boutton retry
    RectangleShape bouttonRetry = RectangleShape(Vector2f(200, 50));
    bouttonRetry.setFillColor(Color::Green);
    bouttonRetry.setPosition(Vector2f(350, 500));

    
    Text quitText = Text("Quit", font, 30);
    quitText.setPosition(Vector2f(205, 505));
    quitText.setFillColor(Color::White);

    Text retryText = Text("Retry", font, 30);
    retryText.setPosition(Vector2f(405, 505));
    retryText.setFillColor(Color::White);

    Texture backgroundHellTexture;
    if (!backgroundHellTexture.loadFromFile("backgroundEnfer.png"))
    {
        exit(1);
    }
    Sprite backgroundHell = Sprite(backgroundHellTexture);
    backgroundHell.setPosition(Vector2f(-100, 0));
    backgroundHell.setScale(Vector2f(0.3, 0.3));

    // Afficher le Game Over
    while (isGameOverOpen)
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                isGameOverOpen = false;
                window->close();
            }
        }

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                if (bouttonQuit.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    isGameOverOpen = false;
                    window->close();
                }
            }
        }

        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                if (bouttonRetry.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    toiSprite.setPosition(Vector2f(LARGEUR_FENETRE / 2 - 95, solSprite[0].getPosition().y - 95));
                    // reset position maison
                    maisonSprites[0].setPosition(Vector2f(-100, solSprite[0].getPosition().y - 550));
                    maisonSprites[1].setPosition(Vector2f(800, solSprite[0].getPosition().y - 150));
                    maisonSprites[2].setPosition(Vector2f(1600, solSprite[0].getPosition().y - 200));
                    maisonSprites[3].setPosition(Vector2f(2400, solSprite[0].getPosition().y - 300));
                    maisonSprites[4].setPosition(Vector2f(3200, solSprite[0].getPosition().y - 350));

                    // reset position terrain
                    for (int i = 0; i < 5; i++)
                    {
                        solSprite[i].setPosition(Vector2f(i * 800, 400));
                    }

                    // reset position background
                    background.setPosition(Vector2f(0, 0));

                    // reset karma
                    karma = 1;

                    isGameOverOpen = false;
                }
            }
        }

        window->clear();
        window->draw(backgroundHell);
        window->draw(gameOverText);
        window->draw(bouttonQuit);
        window->draw(bouttonRetry);
        window->draw(quitText);
        window->draw(retryText);
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
            else 
            {
                for (int i = 0; i < 5; i++)
                {
                    if (toiSprite.getGlobalBounds().intersects(maisonSprites[i].getGlobalBounds()))
                    {
                        // Afficher message indicant que le sdf n'est pas dans ce bâtiment
                        isTextShown = true;
                        time = clock.getElapsedTime().asMilliseconds();

                        // Reset random
                        int maisonActuelle = i;
                        random = rand() % 5;
                        while (maisonActuelle == random)
                            random = rand() % 5;
                    }
                }
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
        window->draw(background);
        //window->draw(murSprite);
        //window->draw(sdfSprite);
        //window->draw(karmaBar);

        for (unsigned int i = 0; i < solSprite.size(); i++)
            window->draw(solSprite[i]);
        for (unsigned int i = 0; i < maisonSprites.size(); i++)
            window->draw(maisonSprites[i]);

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

        window->draw(toiSprite);
        window->display();
    }
}

void Affichage::afficherSDFMenu()
{
    srand (time(NULL));
    bool isGameOverOpen = false;
    bool isMUDAAAAAAAAAAPlayed = false;
    bool isWilhemPlayed = false;

    // Jouer le son
    SoundBuffer bufferCyber;
    SoundBuffer MUDA;
    SoundBuffer MUDAAAAAAAAAA;
    SoundBuffer bufferWilhelm;
    SoundBuffer bufferBruitCoup[3];
    if (!bufferCyber.loadFromFile("Cyberpunk 2077 music.wav"))
    {
        exit(1);
    }
    if (!MUDA.loadFromFile("MUDA.wav"))
    {
        exit(1);
    }
    if (!MUDAAAAAAAAAA.loadFromFile("MUDAAAAAAAAAA.wav"))
    {
        exit(1);
    }
    if (!bufferWilhelm.loadFromFile("Wilhelm.wav"))
    {
        exit(1);
    }
    if (!bufferBruitCoup[0].loadFromFile("bruitCoup0.wav"))
    {
        exit(1);
    }
    if (!bufferBruitCoup[1].loadFromFile("bruitCoup1.wav"))
    {
        exit(1);
    }
    if (!bufferBruitCoup[2].loadFromFile("bruitCoup2.wav"))
    {
        exit(1);
    }
    Sound soundCyber;
    Sound soundMUDA;
    Sound soundMUDAAAAAAAAAA;
    Sound soundWilhelm;
    Sound soundBruitCoups[3];
    soundCyber.setBuffer(bufferCyber);
    soundMUDA.setBuffer(MUDA);
    soundMUDAAAAAAAAAA.setBuffer(MUDAAAAAAAAAA);
    soundWilhelm.setBuffer(bufferWilhelm);
    soundBruitCoups[0].setBuffer(bufferBruitCoup[0]);
    soundBruitCoups[1].setBuffer(bufferBruitCoup[1]);
    soundBruitCoups[2].setBuffer(bufferBruitCoup[2]);

    soundMUDA.setVolume(100);
    soundMUDAAAAAAAAAA.setVolume(100);
    soundWilhelm.setVolume(100);
    soundBruitCoups[0].setVolume(10);
    soundBruitCoups[1].setVolume(10);
    soundBruitCoups[2].setVolume(10);
    soundCyber.play();
    soundCyber.setLoop(true);
    soundCyber.setVolume(50);

    Clock clock;
    
    Text karmaText = Text("Karma : " + to_string(karma), font, 30);
    karmaText.setPosition(Vector2f(50, 50));
    karmaText.setFillColor(Color::White);

    sdfSprite.setScale(Vector2f(0.1, 0.1));
    
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

            if (event.type == Event::MouseButtonPressed && karma < 100)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    ignoreButton.setFillColor(Color(180, 0, 0, 255));
                    if (ignoreButton.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        int random = rand() % 3;
                        karma += 2;
                        soundMUDA.play();
                        soundBruitCoups[random].play();
                        sdfSprite.setColor(Color(255, 0, 0, 255));
                    }
                }
            }
            else
            {
                ignoreButton.setFillColor(Color(255, 0, 0, 255));
                sdfSprite.setColor(Color(255, 255, 255, 255));
            }
        }

        if (clock.getElapsedTime().asMilliseconds() > 200 && karma < 100)
        {
            karma -= 1;
            clock.restart();
        }

        if (karma >= 100 && clock.getElapsedTime().asMilliseconds() > 500)
        {
            if (clock.getElapsedTime().asMilliseconds() > 3500)
            {
                isGameOverOpen = true;
            }
            if (clock.getElapsedTime().asMilliseconds() > 1500 && !isWilhemPlayed)
            {
                soundWilhelm.play();
                isWilhemPlayed = true;
            }
            if (!isMUDAAAAAAAAAAPlayed)
            {
                soundMUDAAAAAAAAAA.play();
                isMUDAAAAAAAAAAPlayed = true;
            }
        }

        karmaText.setString("Karma : " + to_string(karma));

        afficherKarmaBar();

        window->clear();
        window->draw(sdfSprite);
        window->draw(ignoreButton);
        window->draw(ignoreText);
        window->draw(karmaBar);
        window->draw(karmaText);
        window->display();
    }
}

void Affichage::afficherKarmaBar()
{
    // gestion karma bar
    if (karma < 0)
        karma = 0;
    if (karma > 100)
        karma = 100;
    karmaBar.setSize(Vector2f(karma * 8, 20));
    karmaBar.setFillColor(Color(255 - karma * 2.55, karma * 2.55, 0));
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

    background.move((int)x % 4, y);
}