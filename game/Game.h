//
// Created by idu on 17/07/17.
//

#ifndef PROJET_CPP_GAME_H
#define PROJET_CPP_GAME_H


#include "../platforms/Platforms.h"
#include "../player/Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "../platforms/Platforms.h"
#include "../player/Player.h"
#include "../platforms/Platform.h"
class Game {
public:
    Game();

    Game(float platformSpeed=-100.f, int gameWidth= 400, int gameHeight= 600, float ballRadius=10.f);

     ~Game();

    float getPlatformSpeed() const;

    int getGameWidth() const;

    int getGameHeight() const;

    float getBallRadius() const;

    void setPlatformSpeed(float platformSpeed);

    void setGameWidth(int gameWidth);

    void setGameHeight(int gameHeight);

    void setBallRadius(float ballRadius);

    bool isIsPlaying() const;

    int play();
private:
    float platformSpeed;
    int gameWidth ;
    int gameHeight ;
    float ballRadius ;
    Platforms platforms;
    Player player;
    bool isPlaying;
};


#endif //PROJET_CPP_GAME_H
