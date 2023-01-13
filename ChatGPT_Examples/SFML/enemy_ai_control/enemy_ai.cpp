// Here is an example of how you might implement an enemy AI that moves towards the player character
#include <SFML/Graphics.hpp>

int main() {
    // Create a player character and an enemy
    sf::CircleShape player(20);
    player.setFillColor(sf::Color::Green);
    player.setPosition(200, 200);

    sf::CircleShape enemy(20);
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(100, 100);

    // Create a window to display the game
    sf::RenderWindow window(sf::VideoMode(800, 600), "Enemy AI Example");

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Move the enemy towards the player
        sf::Vector2f playerPosition = player.getPosition();
        sf::Vector2f enemyPosition = enemy.getPosition();
        sf::Vector2f direction = playerPosition - enemyPosition;
        float distance = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
        direction /= distance;
        enemyPosition += direction * 0.5f;
        enemy.setPosition(enemyPosition);

        window.clear();
        window.draw(player);
        window.draw(enemy);
        window.display();
    }

    return 0;
}