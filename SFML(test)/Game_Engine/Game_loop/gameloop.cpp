// Here is an example of a basic game loop using SFML for your own SFML Game engine in C++
#include <SFML/Graphics.hpp>
#include "engine.hpp"

int main()
{
    // Initialize the engine
    if (!Engine::init()) {
        std::cout << "Error initializing engine" << std::endl;
        return 1;
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
            // Pass event to engine
            Engine::handleEvent(event);
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
This example uses a separate engine.hpp file to initialize, update, render, handle events and clean up the game engine.
*/

//======================================
//======================================

// You may need to provide the implementation of these functions in the engine.cpp file for example
bool Engine::init()
{
    // Create window
    m_window.create(sf::VideoMode(800, 600), "My Game");

    // Initialize other engine resources
    // ...

    return true;
}

void Engine::update()
{
    // Update game logic and other engine resources
    // ...
}

void Engine::render()
{
    // Clear screen
    m_window.clear();

    // Render game objects and other engine resources
    // ...

    // Update the window
    m_window.display();
}

void Engine::handleEvent(const sf::Event& event)
{
    // Handle input events and other engine events
    // ...
}

void Engine::cleanup()
{
    // Clean up engine resources
    // ...
}

/*
Keep in mind that this is just a simple example and there are many ways to organize and optimize a game engine depending on the needs of the specific game.
*/