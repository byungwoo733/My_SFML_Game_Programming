/* firwork effect */
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main()
{
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Firework");

    // Create the particle system
    sf::VertexArray particles(sf::Points, 100);
    for (int i = 0; i < 100; ++i)
    {
        particles[i].position = sf::Vector2f(std::rand() % WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT);
        particles[i].color = sf::Color::Red;
    }

    // Create the explosion sprite
    sf::Texture explosionTexture;
    if (!explosionTexture.loadFromFile("firework.jpg"))
    {
        // Error loading texture
        return 1;
    }
    sf::Sprite explosion(explosionTexture);
    explosion.setOrigin(128, 128);

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

        // Update the particle system
        for (int i = 0; i < 100; ++i)
        {
            particles[i].position.y += 1.0f;
            particles[i].color.a = std::max(0, particles[i].color.a - 3);
        }

        // Clear the window
        window.clear();

        // Draw the particle system
        window.draw(particles);

        // Draw the explosion
        window.draw(explosion);

        // Display the window
        window.display();
    }

    return 0;
}