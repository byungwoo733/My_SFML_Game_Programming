// Here is an example of a basic game loop using SFML in C++
#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        // Draw your game objects here

        // Update the window
        window.display();
    }

    return 0;
}