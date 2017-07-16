//
// Created by idu on 16/07/17.
//

#include "Utils.h"
#include "../platforms/Platform.h"

Utils::Utils() {}

Platform Utils::generatePlatform(){
    int platformHeight=10;
    int platformWidth=std::rand()%90+30;
    int positionX=std::rand()%(gamewidth-(platformWidth/2))+platformWidth/2;
    int positionY=gameHeight-(platformHeight/2);
    int randomColor=std::rand()%100;
    sf::Color color;
    if(randomColor<70)
        color=sf::Color::Green;
    else
    if(randomColor>=70 && randomColor<90)
        color=sf::Color::Blue;
    else
        color=sf::Color::Red;
    Platform plat=Platform(platformWidth,platformHeight,color,positionX,positionY);
    platforms.push_back(plat);
    return plat;
}
Utils::Utils(Utils const & utils){
    gameHeight=utils.gameHeight;
    gamewidth=utils.gamewidth;
}


Utils::Utils(int gamewidth, int gameHeight) : gamewidth(gamewidth), gameHeight(gameHeight) {}

int Utils::getGamewidth() const {
    return gamewidth;
}

void Utils::setGamewidth(int gamewidth) {
    Utils::gamewidth = gamewidth;
}

int Utils::getGameHeight() const {
    return gameHeight;
}

void Utils::setGameHeight(int gameHeight) {
    Utils::gameHeight = gameHeight;
}

 std::vector<Platform> &Utils::getPlatforms() {
    return platforms;
}

void Utils::setPlatforms(const std::vector<Platform> &platforms) {
    Utils::platforms = platforms;
}

