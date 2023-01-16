// Here is some sample code for creating a 2D sprite sheet in C++ using the SFML library
#include <SFML/Graphics.hpp>

int main()
{
    // Create a 2D sprite sheet with 3 frames
    sf::Texture spriteSheet;
    spriteSheet.loadFromFile("sprites.png");

    // Create a sprite
    sf::Sprite sprite;
    sprite.setTexture(spriteSheet);

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Sheet Example");

    // Set the current frame to the first frame
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

    // Main game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Update the current frame
        sprite.setTextureRect(sf::IntRect(frame * 64, 0, 64, 64));

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the window
        window.display();
    }

    return 0;
}


/* here's a sample code for handling input controls in C++ using SFML library
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    // Move the sprite left
    sprite.move(-5, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
    // Move the sprite right
    sprite.move(5, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
    // Move the sprite up
    sprite.move(0, -5);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
    // Move the sprite down
    sprite.move(0, 5);
}

*/