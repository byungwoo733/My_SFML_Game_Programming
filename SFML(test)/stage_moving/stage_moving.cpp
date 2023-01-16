// Here's an example of how you might implement a system for moving between stages in a 2D game using C++ and SFML
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>

class Stage {
 public:
  virtual void onEnter() = 0;
  virtual void update(sf::RenderWindow& window) = 0;
  virtual void handleInput(sf::RenderWindow& window) = 0;
  virtual void onExit() = 0;
};

class Menu : public Stage {
 public:
  void onEnter() override {
    std::cout << "Welcome to the Menu!" << std::endl;
  }

  void update(sf::RenderWindow& window) override {
    // Draw menu background
    window.clear();
    window.draw(menuSprite);
    window.display();
  }

  void handleInput(sf::RenderWindow& window) override {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      std::cout << "Exit menu" << std::endl;
      onExit();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      std::cout << "Change to level 1" << std::endl;
      onExit();
    }
  }

  void onExit() override {
    std::cout << "You are leaving the Menu." << std::endl;
  }
 private:
  sf::Sprite menuSprite;
};

class Level1 : public Stage {
 public:
  void onEnter() override {
    std::cout << "Welcome to Level 1!" << std::endl;
  }

  void update(sf::RenderWindow& window) override {
    // Draw Level 1 background
    window.clear();
    window.draw(level1Sprite);
    window.display();
  }

  void handleInput(sf::RenderWindow& window) override {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      std::cout << "Exit level 1" << std::endl;
      onExit();
    }
  }

  void onExit() override {
    std::cout << "You are leaving Level 1." << std::endl;
  }
 private:
  sf::Sprite level1Sprite;
};

class Game {
 public:
  Game() {
    window.create(sf::VideoMode(800, 600), "2D Game");
    stages["menu"] = std::make_unique<Menu>();
    stages["level1"] = std::make_unique<Level1>();
    currentStage = stages["menu"].get();
    currentStage->onEnter();
  }

void changeStage(const std::string& stageName) {
    currentStage->onExit();
    currentStage = stages[stageName].get();
    currentStage->onEnter();
  }

int main() {
  Game game;
  while (game.window.isOpen()) {
    game.currentStage->handleInput(game.window);
    game.currentStage->update(game.window);
  }
  return 0;
}