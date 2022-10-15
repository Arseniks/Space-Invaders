#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#define WIDTH 800
#define HEIGHT 600
#define NUMBER_OF_ALIENS 11

using namespace std;

int main() {
    const float shipSpeed = 400.f;
    const int alienSpeed = 700;
    const float bulletSpeed = 500.f;
    bool gameOver = false;
    bool winner = false;

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Invaders");
    window.setVerticalSyncEnabled(true);

    Bullet bullet(0, bulletSpeed);

    Ship player(0, shipSpeed);
    player.setLocation((WIDTH / 2) - (player.getSprite().getGlobalBounds().width / 2), HEIGHT - player.getSprite().getGlobalBounds().height);

    Enemy alienArray[NUMBER_OF_ALIENS];
    for (int i = 0; i < NUMBER_OF_ALIENS; i++) {
        Enemy alien(i, alienSpeed);
        alien.setLocation(i * (alien.getSprite().getGlobalBounds().width + (WIDTH - NUMBER_OF_ALIENS * alien.getSprite().getGlobalBounds().width) / NUMBER_OF_ALIENS), alien.getSprite().getGlobalBounds().height / 2);
        alienArray[i] = alien;
    }
    
    sf::Clock clock;

    sf::Clock alienClock;
    alienClock.restart().asSeconds();

    sf::Clock bulletClock;
    bulletClock.restart().asSeconds();

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (gameOver) {
                    // (re)start the game
                    gameOver = false;
                    winner = false;
                    clock.restart();

                    for (int i = 0; i < NUMBER_OF_ALIENS; i++) {
                        Enemy alien(i, alienSpeed);
                        alien.setLocation(i * (alien.getSprite().getGlobalBounds().width + (WIDTH - NUMBER_OF_ALIENS * alien.getSprite().getGlobalBounds().width) / NUMBER_OF_ALIENS), alien.getSprite().getGlobalBounds().height / 2);
                        alienArray[i] = alien;
                    }
                    player.setLocation((WIDTH / 2) - (player.getSprite().getGlobalBounds().width / 2), HEIGHT - player.getSprite().getGlobalBounds().height);
                    player.respawn();
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (!bullet.isAlive() && !gameOver) {
                    bullet.spawn(true);
                    bullet.setLocation(player.getSprite().getPosition().x + 31, player.getSprite().getPosition().y - 15);
                }
            }
        }

        window.clear(sf::Color::Black);

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
            if (player.getSprite().getPosition().x + player.getSprite().getGlobalBounds().width < WIDTH) {
                player.getSprite().move(shipSpeed * deltaTime, 0.f);
            }
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
            if (player.getSprite().getPosition().x > 0.f) {
                player.getSprite().move(-shipSpeed * deltaTime, 0.f);
            }
        }

        sf::Time alienclock = alienClock.getElapsedTime();
        if (alienclock.asSeconds() > 0.5) {
            for (size_t i = 0; i < NUMBER_OF_ALIENS; i++) {
                alienArray[i].getSprite().move(0.f, alienArray[i].getSpeed() * deltaTime);
            }
            alienClock.restart();
        }
        sf::Time bulletclock = bulletClock.getElapsedTime();
        if (bulletclock.asSeconds() > 1.0)
        {
            if (bullet.isAlive() && !gameOver)
            {
                bullet.draw(window);
                bullet.getSprite().move(0.f, -20);
            }
        }
        //test collisions between aliens and ships
        /*for (int i = 0; i < NUMBER_OF_ALIENS; i++)
        {
            if (CollisionManager::collidesWith(myShip, alienArray[i]) && alienArray[i].isAlive())
            {
                if (!gameOver)
                    music.playExplosion();
                myShip.kill();
                winner = false;
                gameOver = true;
            }
        }
        */
        //test collisions between aliens and bottom of screen
        /*for (int i = 0; i < NUMBER_OF_ALIENS; i++)
        {
            if (alienArray[i].getSprite().getPosition().y + alienArray[i].getSprite().getGlobalBounds().height > HEIGHT && alienArray[i].isAlive())
            {
                if (!gameOver)
                    music.playExplosion();
                winner = false;
                gameOver = true;
            }
        }
        */
        //test collisions between bullet and aliens
        /*for (int i = 0; i < NUMBER_OF_ALIENS; i++)
        {
            if (CollisionManager::collidesWith(bullet, alienArray[i]) && alienArray[i].isAlive())
            {
                alienArray[i].kill();
                bullet.kill();
            }
        }
        */
        // int deadAliens = 0;
        //test for a winner
        /*for (int i = 0; i < NUMBER_OF_ALIENS; i++)
        {
            if (!alienArray[i].isAlive())
                deadAliens++;

            if (deadAliens == NUMBER_OF_ALIENS)
            {
                if (!gameOver)
                    //music.playReward();
                    winner = true;
                gameOver = true;
            }
        }
        */
        if (bullet.getSprite().getPosition().y < 0)
            bullet.kill();

        if (!gameOver) {
            for (size_t i = 0; i < NUMBER_OF_ALIENS; i++) {
                if (alienArray[i].isAlive()) {
                    alienArray[i].draw(window);
                }
            }
            if (player.isAlive()) {
                player.draw(window);
            }

            window.display();
        }
        /*else {
            if (winner)
                win.draw(window);
            else
                lose.draw(window);

            window.display();
        }
        */
    }

    return EXIT_SUCCESS;
}