#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "game/Game.h"

int main()
{

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Define some constants
    const float pi = 3.14159f;
    const int gameWidth = 400;
    const int gameHeight = 600;
    float ballRadius = 10.f;
    float platformSpeed=-100.f;

    Game game(platformSpeed,gameWidth,gameHeight,ballRadius);
    return game.play();
}