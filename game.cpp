////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "utils/Utils.h"

int main()
{

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Define some constants
    const float pi = 3.14159f;
    const int gameWidth = 400;
    const int gameHeight = 600;
    float ballRadius = 10.f;

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "4IBD cpp",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);


    // Create the player
    sf::CircleShape player;
    player.setRadius(ballRadius - 3);
    player.setOutlineThickness(3);
    player.setOutlineColor(sf::Color::Black);
    player.setFillColor(sf::Color::Red);
    player.setOrigin(ballRadius / 2, ballRadius / 2);

    // Load the text font
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(20);
    pauseMessage.setPosition(80.f, 150.f);
    pauseMessage.setColor(sf::Color::White);
    pauseMessage.setString("Welcome to 4IBD game!\nPress space to start the game");

    // Define the player properties
    sf::Clock AITimer;
    const sf::Time AITime   = sf::seconds(0.1f);
    const float playerSpeed = 600.f;
    //initialiser la classe utils
    Utils utils(gameWidth,gameHeight);
    sf::Clock clock;
    sf::Clock clockPlatforms;
    bool isPlaying = false;
    Platform platform;
    int precTime=0,platforms_apparition_speed=2;
    float platformSpeed=-100.f;
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            // Space key pressed: play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                if (!isPlaying)
                {
                    // (re)start the game
                    isPlaying = true;
                    clock.restart();
                    clockPlatforms.restart();
                    player.setPosition(gameWidth / 2, gameHeight / 5);
                    utils.getPlatforms().clear();


                }
            }
        }

        if (isPlaying)
        {
            float deltaTime = clock.restart().asSeconds();
            sf::Time elapsed=clockPlatforms.getElapsedTime();
            if(elapsed.asSeconds()>(precTime+platforms_apparition_speed)){
                precTime+=2;
                utils.generatePlatform();
            }
            // Move the player's paddle
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
                (player.getPosition().x - ballRadius> 0.f))
            {
                player.move(-playerSpeed * deltaTime,0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
                (player.getPosition().x + ballRadius < gameWidth))
            {
                player.move(playerSpeed * deltaTime,0.f);
            }

            // Check collisions between the player and the screen
            if (player.getPosition().y - ballRadius < 0.f)
            {
                isPlaying = false;
                pauseMessage.setString("You lost!\nPress space to restart or\nescape to exit");
            }
            if (player.getPosition().y + ballRadius > gameHeight)
            {
                isPlaying = false;
                pauseMessage.setString("You lost!\nPress space to restart or\nescape to exit");
            }
            //check collisons between the player and the platforms
            for(int i=0;i<utils.getPlatforms().size();i++) {
                Platform pla=utils.getPlatforms()[i];
                sf::RectangleShape pl=utils.getPlatforms()[i].getPlatform();
                if (player.getPosition().x < pl.getPosition().x + pla.getWidth() / 2 &&
                        player.getPosition().x > pl.getPosition().x- pla.getWidth() / 2&&
                        player.getPosition().y + ballRadius >= pl.getPosition().y - pla.getHeight() / 2 &&
                        player.getPosition().y + ballRadius <= pl.getPosition().y + pla.getHeight() / 2) {
                    float ajust=player.getPosition().y + ballRadius-pl.getPosition().y - pla.getHeight() / 2;
                    utils.getPlatforms()[i].getPlatform().move(0.f, platformSpeed*deltaTime);
                    player.move(0.f, platformSpeed*deltaTime+ajust);
                }else{
                    utils.getPlatforms()[i].getPlatform().move(0.f, platformSpeed*deltaTime);
                    player.move(0.f, -platformSpeed*deltaTime);
                }

            }
        }

        // Clear the window
        window.clear(sf::Color(128, 128, 128));

        if (isPlaying)
        {
            // Draw the paddles and the player
            window.draw(player);
            for(int i=0;i<utils.getPlatforms().size();i++){
                if(utils.getPlatforms()[i].getPlatform().getPosition().y<0)
                    utils.getPlatforms().erase(utils.getPlatforms().begin()+i);
                window.draw(utils.getPlatforms()[i].getPlatform());
            }

        }
        else
        {
            // Draw the pause message
            window.draw(pauseMessage);
        }

        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}