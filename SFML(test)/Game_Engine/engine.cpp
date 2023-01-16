// Here is an example of a main.cpp file for an SFML game engine
#include <SFML/Graphics.hpp>
#include "engine.hpp"

int main() {
    // Initialize the engine
    if (!Engine::init()) {
        // Handle initialization error
    }

    // Main loop flag
    bool quit = false;

    // Event handler
    sf::Event event;

    // While application is running
    while (!quit) {
        // Handle events on queue
        while (Engine::getWindow().pollEvent(event)) {
            // User requests quit
            if (event.type == sf::Event::Closed) {
                quit = true;
            }
        }

        // Update the engine
        Engine::update();

        // Render the engine
        Engine::render();
    }

    // Clean up the engine
    Engine::cleanup();

    return 0;
}

/*
This example uses a separate engine.hpp file to initialize, update, and render the game engine. 

Keep in mind that, These examples are just a simple example and there are many ways to organize and optimize a game engine depending on the needs of the specific game.
*/