//
// Created by idu on 16/07/17.
//

#include "Platforms.h"
#include "Platform.h"

Platforms::Platforms() {}

Platform Platforms::generatePlatform(){
    int platformHeight=10;
    int platformWidth=std::rand()%90+30;
    int positionX=std::rand()%(gamewidth-(platformWidth/2))+platformWidth/2;
    int positionY=gameHeight-(platformHeight/2);
    int randomColor=std::rand()%100;
    sf::Color color;
    int type=0;
    if(randomColor<70) {
        color = sf::Color::Green;
        type=0;
    }else
    if(randomColor>=70 && randomColor<90) {
        color = sf::Color::Blue;
        type=1;
    }else {
        color = sf::Color::Red;
        type=2;
    }
    Platform plat=Platform(platformWidth,platformHeight,color,positionX,positionY,type);
    platforms.push_back(plat);
    return plat;
}
Platforms::Platforms(Platforms const & utils){
    gameHeight=utils.gameHeight;
    gamewidth=utils.gamewidth;
}


Platforms::Platforms(int gamewidth, int gameHeight) : gamewidth(gamewidth), gameHeight(gameHeight) {}

int Platforms::getGamewidth() const {
    return gamewidth;
}

void Platforms::setGamewidth(int gamewidth) {
    Platforms::gamewidth = gamewidth;
}

int Platforms::getGameHeight() const {
    return gameHeight;
}

void Platforms::setGameHeight(int gameHeight) {
    Platforms::gameHeight = gameHeight;
}

 std::vector<Platform> &Platforms::getPlatforms() {
    return platforms;
}

void Platforms::setPlatforms(const std::vector<Platform> &platforms) {
    Platforms::platforms = platforms;
}

