#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My GUI");

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // Error loading font
        return 1;
    }

    // Create a button
    sf::Text buttonText("Click me!", font, 24);
    buttonText.setFillColor(sf::Color::White);
    sf::RectangleShape button(sf::Vector2f(100, 50));
    button.setFillColor(sf::Color::Blue);
    button.setOutlineColor(sf::Color::White);
    button.setOutlineThickness(2.0f);
    button.setPosition(sf::Vector2f(10, 10));

    // Create a text box
    sf::RectangleShape textBox(sf::Vector2f(200, 50));
    textBox.setFillColor(sf::Color::White);
    textBox.setOutlineColor(sf::Color::Black);
    textBox.setOutlineThickness(2.0f);
    textBox.setPosition(sf::Vector2f(10, 70));
    sf::Text textBoxLabel("Enter your name:", font, 18);
    textBoxLabel.setFillColor(sf::Color::Black);
    textBoxLabel.setPosition(sf::Vector2f(15, 75));

    // Run the main loop
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
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if the button was clicked
                if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // Button was clicked, do something...
                }
            }
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the button and text box
        window.draw(button);
        window.draw(textBox);
        window.draw(buttonText);
        window.draw(textBoxLabel);

        // Display the window
        window.display();
    }

    return 0;
}