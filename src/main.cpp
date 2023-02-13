#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

int karma = 0;
int health = 100;

int main()
{
    // Créer la fenêtre
    RenderWindow window(VideoMode(800, 600), "Ignorer ou aider ?");

    // Créer les boutons
    RectangleShape ignoreButton(Vector2f(200, 50));
    ignoreButton.setFillColor(Color::Red);
    ignoreButton.setPosition(Vector2f(300, 500));

    RectangleShape helpButton(Vector2f(200, 50));
    helpButton.setFillColor(Color::Green);
    helpButton.setPosition(Vector2f(500, 500));

    // Créer le texte
    Font font;
    if (!font.loadFromFile("arial_mt_black/ARIBL0.ttf"))
    {
        return -1;
    }

    Text ignoreText("Ignorer", font, 30);
    ignoreText.setPosition(Vector2f(355, 505));
    ignoreText.setFillColor(Color::White);

    Text helpText("Aider", font, 30);
    helpText.setPosition(Vector2f(550, 505));
    helpText.setFillColor(Color::White);

    Text gameOverText = Text();
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
    gameOverText.setPosition(Vector2f(250, 300));
    gameOverText.setFillColor(Color::White);

    // Créer la barre de vie
    RectangleShape healthBar(Vector2f(100, 25));
    healthBar.setFillColor(Color::Green);
    healthBar.setPosition(Vector2f(25, 25));

    // Image de fond
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("index.jpeg"))
    {
        return -1;
    }
    Sprite background(backgroundTexture);
    background.setPosition(Vector2f(0, 0));
    background.setScale(Vector2f(0, 0));

    // Boucle de jeu
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseButtonPressed)
            {
                Vector2i mousePos = Mouse::getPosition(window);

                if (ignoreButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    karma -= 10;
                    health -= 10;
                }
                else if (helpButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    karma += 10;
                    health += 10;
                    health = (health > 100) ? 100 : health + 10;
                }
            }
        }

        // Mettre à jour la barre de vie
        healthBar.setSize(Vector2f(health, 25));
        if (health > 100)
        {
            health = 100;
        }
        if (health > 75)
        {
            healthBar.setFillColor(Color::Green);
        }
        else if (health > 50)
        {
            healthBar.setFillColor(Color::Yellow);
        }
        else if (health > 25)
        {
            healthBar.setFillColor(Color::Red);
        }
        else if (health <= 0)
        {
            healthBar.setFillColor(Color::Black);
            gameOverText.setString("Why are you geh ?");
            background.setScale(Vector2f(1, 1));
        }

        // Dessiner les objets
        window.clear();
        window.draw(ignoreButton);
        window.draw(ignoreText);
        window.draw(helpButton);
        window.draw(helpText);
        window.draw(healthBar);
        window.draw(gameOverText);
        window.draw(background);
        window.display();
    }

    return 0;
}