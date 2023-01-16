// Here is an example of a "map.hpp" file that defines the structure of the map
#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Map {
public:
    // The size of each tile (in pixels)
    static constexpr int TILE_SIZE = 32;

    // The number of rows and columns in the map
    static constexpr int ROWS = 10;
    static constexpr int COLS = 10;

    // The map data, represented as a 2D array of integers
    std::vector<std::vector<int>> data;

    // The SFML Texture and Sprite used to render the map
    sf::Texture texture;
    sf::Sprite sprite;

    // Initializes the map with data from a file
    void load(const std::string& filename);

    // Draws the map to the window
    void draw(sf::RenderWindow& window);
};

#endif

/*
You will need to have SFML library installed in your system to use this code, and also you may need to adapt the code to match your specific requirements.

[번역]
이 코드를 사용하려면 시스템에 SFML 라이브러리를 설치해야 하며 특정 요구 사항에 맞게 코드를 조정해야 할 수도 있습니다.
*/