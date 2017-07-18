//
// Created by idu on 16/07/17.
//

#ifndef PROJET_CPP_PLATFORM_H
#define PROJET_CPP_PLATFORM_H


#include <SFML/Graphics/RectangleShape.hpp>

class Platform {
public:
    Platform();
    Platform(Platform const&);
    virtual ~Platform();
    Platform(float width,float height,sf::Color color, int positionX,int positionY,int type);
    void move(int dX,int dY);

    sf::RectangleShape &getPlatform() ;

    float getWidth() const;

    float getHeight() const;

    int getType() const;

    bool isRedPlatform();
    bool isGreenPlatform();
    bool isBluePlatform();

private:
    sf::RectangleShape  platform;
    float width;
    float height;
    int type; //0=green,1=blue,2=red
};


#endif //PROJET_CPP_PLATFORM_H
