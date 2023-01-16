// Here is an example of a player.cpp file that uses the Simple and Fast Multimedia Library (SFML) library to create a player and display an image of it
#include "player.hpp"

Player::Player(){
    if (!texture.loadFromFile("player.png")) {
        std::cout << "Error loading player texture\n";
    }
    sprite.setTexture(texture);
    x = 0;
    y = 0;
    speed = 200;
}

void Player::update(float deltaTime) {
    // handle player input and update player position
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        x += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        y -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        y += speed * deltaTime;
    }
    sprite.setPosition(x, y);
}

void Player::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

/*
This is a simple example, you can expand it to fit your needs.
It will create a player with its texture loaded, and it will move the player based on the arrow keys pressed, and render it on the window.
It uses delta time for smooth movement, you can add more complex behavior like jumping or shooting, it depends on the game you are building.
It uses a class structure to encapsulate the player attributes and methods.
The difference between this and the previous example is the file extensions: .hpp instead of .h this is just a convention.

[번역]
이것은 간단한 예이므로 필요에 맞게 확장할 수 있습니다.
텍스처가 로드된 플레이어를 생성하고 누른 화살표 키를 기준으로 플레이어를 이동하고 창에 렌더링합니다.
부드러운 움직임을 위해 델타 시간을 사용하며, 빌드 중인 게임에 따라 점프나 사격과 같은 더 복잡한 동작을 추가할 수 있습니다.
클래스 구조를 사용하여 플레이어 속성과 메서드를 캡슐화합니다.
이 예제와 이전 예제의 차이점은 파일 확장자입니다. .h 대신 .hpp 이것은 단지 규칙일 뿐입니다.
*/