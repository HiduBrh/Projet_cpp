//
// Created by idu on 17/07/17.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>
#include <iostream>
#include "Game.h"

Game::Game() {}

Game::Game(float platformSpeed, int gameWidth, int gameHeight, float ballRadius) : platformSpeed(platformSpeed),
                                                                                   gameWidth(gameWidth),
                                                                                   gameHeight(gameHeight),
                                                                                   ballRadius(ballRadius),
                                                                                   player(ballRadius),
                                                                                   platforms(gameWidth,gameHeight),
                                                                                   isPlaying(false),score(0){}
Game::~Game() {

}

float Game::getPlatformSpeed() const {
    return platformSpeed;
}

int Game::getGameWidth() const {
    return gameWidth;
}

int Game::getGameHeight() const {
    return gameHeight;
}

float Game::getBallRadius() const {
    return ballRadius;
}

void Game::setPlatformSpeed(float platformSpeed) {
    Game::platformSpeed = platformSpeed;
}

void Game::setGameWidth(int gameWidth) {
    Game::gameWidth = gameWidth;
    platforms.setGamewidth(gameWidth);
    platforms.setGameHeight(gameHeight);
}

void Game::setGameHeight(int gameHeight) {
    Game::gameHeight = gameHeight;
}

void Game::setBallRadius(float ballRadius) {
    Game::ballRadius = ballRadius;
    player.setBallRadius(ballRadius);
}
int Game::play() {

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "4IBD cpp",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);


    // Create the player
    Player player(ballRadius);

    // Load the text font
    sf::Font font;
    if (!font.loadFromFile("../resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(20);
    pauseMessage.setPosition(80.f, 150.f);
    pauseMessage.setColor(sf::Color::White);
    pauseMessage.setString("Welcome to 4IBD game!\nPress space to start the game");


    // Initialize score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setPosition(20.f, 20.f);
    scoreText.setColor(sf::Color::Green);
    scoreText.setString(std::to_string(score));

    // Define the player properties
    sf::Clock AITimer;
    const sf::Time AITime = sf::seconds(0.1f);
    const float playerSpeed = 600.f;
    //initialiser la classe platforms
    Platforms platforms(gameWidth, gameHeight);
    sf::Clock clock;
    sf::Clock clockPlatforms;
    Platform platform;
    float precTime = 0.f, platforms_apparition_speed = 1.5;
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                window.close();
                break;
            }

            // Space key pressed: play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) {
                if (!isPlaying) {
                    // (re)start the game
                    isPlaying = true;
                    clock.restart();
                    clockPlatforms.restart();
                    player.getBall().setPosition(gameWidth / 2, gameHeight / 5);
                    platforms.getPlatforms().clear();
                }
            }
        }

        if (isPlaying) {
            float deltaTime = clock.restart().asSeconds();
            sf::Time elapsed = clockPlatforms.getElapsedTime();
            if (elapsed.asSeconds() > (precTime + platforms_apparition_speed)) {
                precTime += platforms_apparition_speed;
                platforms.generatePlatform();
            }
            // Move the player's paddle
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                (player.getBall().getPosition().x - ballRadius > 0.f)) {
                player.getBall().move(-playerSpeed * deltaTime, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
                (player.getBall().getPosition().x + ballRadius < gameWidth)) {
                player.getBall().move(playerSpeed * deltaTime, 0.f);
            }

            // Check collisions between the player and the screen
            if (player.getBall().getPosition().y - ballRadius < 0.f) {
                isPlaying = false;
                pauseMessage.setString("You lost!\nPress space to restart or\nescape to exit");
            }
            if (player.getBall().getPosition().y + ballRadius > gameHeight) {
                isPlaying = false;
                pauseMessage.setString("You lost!\nPress space to restart or\nescape to exit");
            }
            //check collisons between the player and the Platforms
            for(int i=0;i<platforms.getPlatforms().size();i++) {
                Platform *pla=&platforms.getPlatforms()[i];
                sf::RectangleShape pl=platforms.getPlatforms()[i].getPlatform();
                if (player.getBall().getPosition().x< pl.getPosition().x + pla->getWidth() / 2 &&
                    player.getBall().getPosition().x> pl.getPosition().x- pla->getWidth() / 2&&
                    player.getBall().getPosition().y + ballRadius >= pl.getPosition().y - pla->getHeight() / 2 &&
                    player.getBall().getPosition().y + ballRadius <= pl.getPosition().y + pla->getHeight() / 2) {

                    if(platforms.getPlatforms()[i].isRedPlatform()){
                        isPlaying = false;
                        pauseMessage.setString("You lost!\nPress space to restart or\nescape to exit");
                    }
                    float ajust=player.getBall().getPosition().y + ballRadius-pl.getPosition().y - pla->getHeight() / 2;
                    player.getBall().move(0.f, platformSpeed*deltaTime+ajust);
                    pla->getPlatform().move(0.f, platformSpeed*deltaTime);
                }else{
                    pla->getPlatform().move(0.f, platformSpeed*deltaTime);
                    player.getBall().move(0.f, -platformSpeed*deltaTime);
                }

            }
            //update score
            score=clock.getElapsedTime().asSeconds();
            scoreText.setString(std::to_string(score));
//update game speed
            platformSpeed*=1.0002;
        }

        // Clear the window
        window.clear(sf::Color(128, 128, 128));

        if (isPlaying) {
            // Draw the paddles and the player
            window.draw(player.getBall());
            window.draw(scoreText);
            for (int i = 0; i < platforms.getPlatforms().size(); i++) {
                if (platforms.getPlatforms()[i].getPlatform().getPosition().y < 0)
                    platforms.getPlatforms().erase(platforms.getPlatforms().begin() + i);
                window.draw(platforms.getPlatforms()[i].getPlatform());
            }

        } else {
            // Draw the pause message
            window.draw(pauseMessage);
        }

        // Display things on screen
        window.display();
    }
}

bool Game::isIsPlaying() const {
    return isPlaying;
}

int Game::getScore() const {
    return score;
}


