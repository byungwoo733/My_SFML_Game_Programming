// Here's an example of how you can create a logo rotation animation that rotates 360 degrees using C++ and the SFML library
#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("logo.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Set the initial position of the sprite
    sprite.setPosition(200, 150);

    // Create a clock for measuring the elapsed time
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Update the window
        window.display();

        // Measure the elapsed time
        sf::Time elapsed = clock.restart();

        // Update the sprite's rotation
        float rotationSpeed = 360.f; // 360 degrees per second
        sprite.rotate(rotationSpeed * elapsed.asSeconds());

        // Check if the sprite has completed a full rotation
        if (sprite.getRotation() >= 360)
            sprite.setRotation(0);
    }

    return EXIT_SUCCESS;
}