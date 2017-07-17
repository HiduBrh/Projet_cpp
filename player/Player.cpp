//
// Created by idu on 17/07/17.
//

#include "Player.h"

Player::Player() {}

Player::Player(float ballRadius) : ballRadius(ballRadius) {

    ball.setRadius(ballRadius - 3);
    ball.setOutlineThickness(3);
    ball.setOutlineColor(sf::Color::Black);
    ball.setFillColor(sf::Color::Red);
    ball.setOrigin(ballRadius / 2, ballRadius / 2);
}

Player::~Player() {

}

sf::CircleShape &Player::getBall() {
    return ball;
}

float Player::getBallRadius()  {
    return ballRadius;
}

void Player::setBallRadius(float ballRadius) {
    Player::ballRadius = ballRadius;
    ball.setRadius(ballRadius);
}
