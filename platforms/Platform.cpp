//
// Created by idu on 16/07/17.
//

#include "Platform.h"

Platform::Platform(){}

Platform::~Platform() {

}

Platform::Platform(Platform const& platf){
    platform=platf.platform;
    width=platf.width;
    height=platf.height;
    type=platf.type;
}

Platform::Platform(float width,float height,sf::Color color, int positionX,int positionY,int type){
    sf::Vector2f platformSize(width, height);
    this->height=height;
    this->width=width;
    this->type=type;
    platform.setSize(platformSize - sf::Vector2f(3, 3));
    platform.setOutlineThickness(3);
    platform.setOutlineColor(sf::Color::Black);
    platform.setFillColor(color);
    platform.setOrigin(platformSize / 2.f);
    platform.setPosition(positionX,positionY);
}

void Platform::move(int dX,int dY){
    platform.move(dX,dY);
}

 sf::RectangleShape &Platform::getPlatform() {
    return platform;
}

float Platform::getWidth() const {
    return width;
}

float Platform::getHeight() const {
    return height;
}
bool Platform::isRedPlatform(){
    if(type==2)
        return true;
    return false;
}
bool Platform::isGreenPlatform(){
    if(type==0)
        return true;
    return false;
}
bool Platform::isBluePlatform(){
    if(type==1)
        return true;
    return false;
}

int Platform::getType() const {
    return type;
}
