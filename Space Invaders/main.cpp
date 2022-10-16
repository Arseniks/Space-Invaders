#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include "Player.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "LoseScreen.h"
#include "WinScreen.h"
#include "SoundManager.h"

#define WIDTH 800
#define HEIGHT 600
#define NUMBER_OF_ALIENS 7 * 3

using namespace std;

int main() {
    const float shipSpeed = 400.f;
    const int alienSpeed = 1000;
    const float bulletSpeed = 20.f;
    const float enemybulletSpeed = 15.f;
    bool gameOver = false;
    bool winner = false;
    int playerScore = 0;

    sf::Font font; 
    font.loadFromFile("space_invaders.ttf");
    sf::Text text("", font, 25);
    sf::Text score_text("", font, 25);

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Invaders");
    window.setVerticalSyncEnabled(true);

    SoundManager music;
    music.playBackgroundMusic();

    WinScreen win;
    LoseScreen lose;

    Bullet bullet(0, bulletSpeed);
    EnemyBullet enemybullet(0, enemybulletSpeed);

    Ship player(0, shipSpeed);
    player.setLocation((WIDTH / 2) - (player.getSprite().getGlobalBounds().width / 2), HEIGHT - player.getSprite().getGlobalBounds().height);

    Enemy alienArray[NUMBER_OF_ALIENS];
    for (int i = 0; i < NUMBER_OF_ALIENS / 3; i++) {
        Enemy alien(i, alienSpeed, 1);
        alien.setLocation(i * 75, alien.getSprite().getGlobalBounds().height / 2 + 60);
        alienArray[i] = alien;
    }
    for (int i = NUMBER_OF_ALIENS / 3; i < 2 * NUMBER_OF_ALIENS / 3; i++) {
        Enemy alien(i, alienSpeed, 2);
        alien.setLocation((i - NUMBER_OF_ALIENS / 3) * 75, alien.getSprite().getGlobalBounds().height / 2 + 60 + 60);
        alienArray[i] = alien;
    }

    for (int i = 2 * NUMBER_OF_ALIENS / 3; i < NUMBER_OF_ALIENS; i++) {
        Enemy alien(i, alienSpeed, 3);
        alien.setLocation((i - 2 * NUMBER_OF_ALIENS / 3) * 75, alien.getSprite().getGlobalBounds().height / 2 + 90 + 60);
        alienArray[i] = alien;
    }

    bool direction = 1;

    sf::Clock clock;

    sf::Clock alienClock;
    alienClock.restart().asSeconds();

    sf::Clock bulletClock;
    bulletClock.restart().asSeconds();

    sf::Clock enemybulletClock;
    enemybulletClock.restart().asSeconds();

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (!bullet.isAlive() && !gameOver) {
                    bullet.spawn(true);
                    bullet.setLocation(player.getSprite().getPosition().x + 31, player.getSprite().getPosition().y - 15);
                    music.playLazer();
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

        text.setString("SCORE<1>");
        text.setPosition(0, 0);
        window.draw(text);

        score_text.setString(to_string(playerScore));
        score_text.setPosition(30, 40);
        window.draw(score_text);

        sf::Time alienclock = alienClock.getElapsedTime();
        if (direction && alienArray[NUMBER_OF_ALIENS - 1].getSprite().getPosition().x + alienArray[NUMBER_OF_ALIENS - 1].getSprite().getGlobalBounds().width + alienArray[NUMBER_OF_ALIENS - 1].getSpeed() * deltaTime > WIDTH) {
            direction = 0;

            for (size_t i = 0; i < NUMBER_OF_ALIENS; i++) {
                alienArray[i].getSprite().move(0.f, 45.f);
            }
            alienClock.restart();
        }
        else if (!direction && alienArray[0].getSprite().getPosition().x - alienArray[0].getSpeed() * deltaTime < 0) {
            direction = 1;
            for (size_t i = 0; i < NUMBER_OF_ALIENS; i++) {
                alienArray[i].getSprite().move(0.f, 45.f);
            }
            alienClock.restart();
        }

        int shoutingenemy = 0 + rand() % (NUMBER_OF_ALIENS - 1);

        if (alienclock.asSeconds() > 0.7) {
            if (direction == 1 && alienArray[NUMBER_OF_ALIENS - 1].getSprite().getPosition().x < WIDTH) {
                for (size_t i = 0; i < NUMBER_OF_ALIENS; i++) {
                    alienArray[i].getSprite().move(alienArray[i].getSpeed() * deltaTime, 0.f);
                    if (i == shoutingenemy && alienArray[i].isAlive()) {
                        if (!enemybullet.isAlive() && !gameOver) {
                            enemybullet.spawn(true);
                            enemybullet.setLocation(alienArray[i].getSprite().getPosition().x + 31, alienArray[i].getSprite().getPosition().y + 15);
                        }
                    }
                }
                alienClock.restart();
            }
            else if (direction == 0 && alienArray[0].getSprite().getPosition().x > 0) {
                for (size_t i = 0; i < NUMBER_OF_ALIENS; i++) {
                    alienArray[i].getSprite().move(-(alienArray[i].getSpeed() * deltaTime), 0.f);
                    if (i == shoutingenemy && alienArray[i].isAlive()) {
                        if (!enemybullet.isAlive() && !gameOver) {
                            enemybullet.spawn(true);
                            enemybullet.setLocation(alienArray[i].getSprite().getPosition().x + 31, alienArray[i].getSprite().getPosition().y + 15);
                        }
                    }
                }
                alienClock.restart();
            }

        }

        sf::Time enemybulletclock = enemybulletClock.getElapsedTime();
        if (enemybulletclock.asSeconds() > 1.0) {
            if (enemybullet.isAlive() && !gameOver) {
                enemybullet.draw(window);
                enemybullet.getSprite().move(0.f, enemybulletSpeed);
            }
        }

        sf::Time bulletclock = bulletClock.getElapsedTime();
        if (bulletclock.asSeconds() > 1.0) {
            if (bullet.isAlive() && !gameOver) {
                bullet.draw(window);
                bullet.getSprite().move(0.f, -bulletSpeed);
            }
        }

        for (int i = 0; i < NUMBER_OF_ALIENS; i++) {
            if (CollisionManager::collidesWith(player, alienArray[i]) && alienArray[i].isAlive()) {
                if (!gameOver)
                    music.playExplosion();
                player.kill();
                winner = false;
                gameOver = true;
            }
        }
        for (int i = 0; i < NUMBER_OF_ALIENS; i++) {
            if (CollisionManager::collidesWith(bullet, alienArray[i]) && alienArray[i].isAlive() && bullet.isAlive()) {
                if (!gameOver)
                    music.playExplosion();
                alienArray[i].kill();
                bullet.kill();
                if (alienArray[i].getType() == 3) {
                    playerScore += 10;
                } else if (alienArray[i].getType() == 2) {
                    playerScore += 20;
                } else if (alienArray[i].getType() == 1) {
                    playerScore += 30;
                }

            }
        }
        if (CollisionManager::collidesWith(enemybullet, player) && player.isAlive() && enemybullet.isAlive()) {
            music.playExplosion();
            player.kill();
            winner = false;
            gameOver = true;
        }
        int deadAliens = 0;
        for (int i = 0; i < NUMBER_OF_ALIENS; i++) {
            if (!alienArray[i].isAlive()) {
                deadAliens++;
            }
        }
        if (deadAliens == NUMBER_OF_ALIENS) {
            winner = true;
            gameOver = true;
        }
        if (bullet.getSprite().getPosition().y < 0) {
            bullet.kill();
        }
        if (enemybullet.getSprite().getPosition().y > HEIGHT) {
            enemybullet.kill();
        }
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
        } else {
            music.pauseBackgroundMusic();
            if (winner) {
                win.draw(window);
            }
            else {
                lose.draw(window, playerScore);
            }
            window.display();
        }
    }
    return EXIT_SUCCESS;
}
