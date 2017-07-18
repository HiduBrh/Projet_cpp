//
// Created by idu on 17/07/17.
//

#ifndef PROJET_CPP_PLAYER_H
#define PROJET_CPP_PLAYER_H


#include <SFML/Graphics/CircleShape.hpp>

class Player {
public:
    Player();

    Player(float ballRadius);

    Player(Player const & );

    virtual ~Player();

    sf::CircleShape &getBall() ;

    float getBallRadius() ;

    void setBallRadius(float ballRadius);

private:
    sf::CircleShape ball;
    float ballRadius;
};


#endif //PROJET_CPP_PLAYER_H
