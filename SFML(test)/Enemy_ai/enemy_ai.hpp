// Here is an example of an enemy_ai.hpp file that defines the EnemyAI class and its associated methods
#ifndef ENEMY_AI_HPP
#define ENEMY_AI_HPP

#include "enemy.hpp"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class EnemyAI {
    public:
        EnemyAI();
        void update(Enemy& enemy, float deltaTime);
    private:
        int direction;
        float speed;
};

#endif

/*
This is a simple example, you can expand it to fit your needs.
It moves the enemy randomly around the screen, when the enemy hit the border of the screen it will change the direction randomly.
You can add more complex behavior like following the player, or attacking the player, or even spawning other enemies, it depends on the game you are building.
It uses a class structure to encapsulate the AI behavior and it receives an enemy object as parameter, so you can use this class for multiple enemies.
The difference between this and the previous example is the file extensions: .hpp instead of .h, and the use of a class structure and passing the objects as parameters.

[번역]
이것은 간단한 예이므로 필요에 맞게 확장할 수 있습니다.
그것은 화면 주위에 적을 무작위로 이동하고, 적이 화면의 경계에 부딪히면 무작위로 방향을 바꿀 것입니다.
플레이어를 따르거나, 플레이어를 공격하거나, 심지어 다른 적을 생성하는 것과 같은 더 복잡한 동작을 추가할 수 있습니다. 빌드 중인 게임에 따라 다릅니다.
클래스 구조를 사용하여 AI 동작을 캡슐화하고 적 오브젝트를 매개변수로 수신하므로 여러 적에게 이 클래스를 사용할 수 있습니다.
이 예제와 이전 예제의 차이점은 파일 확장자: .h 대신 .hpp, 클래스 구조 사용 및 개체를 매개 변수로 전달하는 것입니다.
*/