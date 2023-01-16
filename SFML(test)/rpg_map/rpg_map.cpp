// Here is an example of a "map.cpp" file that implements the functions defined in the header file
#include "map.hpp"

#include <fstream>
#include <iostream>

void Map::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open map file " << filename << std::endl;
        return;
    }

    data.resize(ROWS);
    for (int i = 0; i < ROWS; i++) {
        data[i].resize(COLS);
        for (int j = 0; j < COLS; j++) {
            file >> data[i][j];
        }
    }

    if (!texture.loadFromFile("tiles.png")) {
        std::cerr << "Error: Unable to load tile texture" << std::endl;
        return;
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));
}

void Map::draw(sf::RenderWindow& window) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sprite.setPosition(j * TILE_SIZE, i * TILE_SIZE);
            window.draw(sprite);
        }
    }
}

/*
You will need to have SFML library installed in your system to use this code, and also you may need to adapt the code to match your specific requirements.

[번역]
이 코드를 사용하려면 시스템에 SFML 라이브러리를 설치해야 하며 특정 요구 사항에 맞게 코드를 조정해야 할 수도 있습니다.
*/