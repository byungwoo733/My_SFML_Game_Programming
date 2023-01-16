/* Here's an example of how you could move the sprite using the arrow keys
*/
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Editor");
    sf::Texture sprite_texture;
    if (!sprite_texture.loadFromFile("sprite.png")) {
        return -1;
    }

    sf::Sprite sprite(sprite_texture);
    float speed = 200.0f; // pixels per second

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Get the elapsed time since the last frame
        float elapsed = clock.restart().asSeconds();

        // Move the sprite based on the arrow keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(-speed * elapsed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(speed * elapsed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0, -speed * elapsed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0, speed * elapsed);
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

/* Here is an example of how to create a simple sprite editor using the SFML library in C++
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Editor");
    sf::Texture sprite_texture;
    if (!sprite_texture.loadFromFile("sprite.png")) {
        return -1;
    }

    sf::Sprite sprite(sprite_texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

*/