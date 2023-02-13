#include "../headers/affichage.h"

Affichage::Affichage()
{
    // Créer la fenêtre
    window = new RenderWindow(VideoMode(800, 600), "Jeu-CPP");

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
    solSprite = Sprite(sol);
    solSprite.setPosition(Vector2f(0, 400));
    solSprite.setScale(Vector2f(0, 0));

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
    toiSprite.setPosition(Vector2f(0, solSprite.getPosition().y - 100));
    toiSprite.setScale(Vector2f(0, 0));
    
    if (!sdf.loadFromFile("sdf.png"))
    {
        exit(1);
    }
    sdfSprite = Sprite(sdf);
    sdfSprite.setPosition(Vector2f(0, 0));
    sdfSprite.setScale(Vector2f(0, 0));
}

Affichage::~Affichage()
{
    delete window;
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
    bool isSDFMenuOpen = false;
    int toiSpritePositionX = 0;
    int toiSpritePositionY = 0;
    Clock clock;
    Time time;

    background.setScale(Vector2f(1, 1));
    solSprite.setScale(Vector2f(1, 1));
    murSprite.setScale(Vector2f(1, 1));
    toiSprite.setScale(Vector2f(1, 1));
    sdfSprite.setScale(Vector2f(1, 1));

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
            if (toiSprite.getScale().x == -1)
                toiSprite.setPosition(Vector2f(toiSprite.getPosition().x - 144, toiSprite.getPosition().y));
            toiSprite.setScale(Vector2f(1, 1));
            toiSpritePositionY = 2;
            toiSprite.move(-0.5, 0);
            if (clock.getElapsedTime().asMilliseconds() > 100)
            {
                toiSpritePositionX++;
                toiSpritePositionX %= 6;
                clock.restart();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            if (toiSprite.getScale().x == 1)
                toiSprite.setPosition(Vector2f(toiSprite.getPosition().x + 144, toiSprite.getPosition().y));
            toiSprite.setScale(Vector2f(-1, 1));
            toiSpritePositionY = 2;
            toiSprite.move(0.5, 0);
            if (clock.getElapsedTime().asMilliseconds() > 100)
            {
                toiSpritePositionX++;
                toiSpritePositionX %= 6;
                clock.restart();
            }
        }

        if (clock.getElapsedTime().asMilliseconds() > 100)
        {
            toiSpritePositionX = 0;
            toiSpritePositionY = 0;
            clock.restart();
        }

        // Gestion de l'animation de Toi
        toiSprite.setTextureRect(IntRect(toiSpritePositionX * 144, toiSpritePositionY * 144, 144, 144));

        // Gestion de la barre de vie
        if (karmaBar.getSize().x > 0)
        {
            karmaBar.setSize(Vector2f(karmaBar.getSize().x - 0.0001, karmaBar.getSize().y));
        }
        else
        {
            isSDFMenuOpen = true;
            afficherGameOver();
        }

        window->clear();
        //window->draw(background);
        window->draw(solSprite);
        //window->draw(murSprite);
        window->draw(toiSprite);
        //window->draw(sdfSprite);
        //window->draw(karmaBar);
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

