//
// Created by idu on 16/07/17.
//

#include "Platform.h"

Platform::Platform(){}

Platform::~Platform() {

}

Platform::Platform(Platform const& platf){
    platform=platf.platform;
}

Platform::Platform(int width,int height,sf::Color color, int positionX,int positionY){
    sf::Vector2f platformSize(width, height);
    this->height=height;
    this->width=width;
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

int Platform::getWidth() const {
    return width;
}

int Platform::getHeight() const {
    return height;
}
