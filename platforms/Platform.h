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
    Platform(int width,int height,sf::Color color, int positionX,int positionY);
    void move(int dX,int dY);

    sf::RectangleShape &getPlatform() ;

    int getWidth() const;

    int getHeight() const;

private:
    sf::RectangleShape  platform;
    int width;
    int height;
};


#endif //PROJET_CPP_PLATFORM_H
