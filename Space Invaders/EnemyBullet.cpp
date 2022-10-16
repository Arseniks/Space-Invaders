#include "EnemyBullet.h"
#include <iostream>
#include <stdexcept>
using namespace std;

EnemyBullet::EnemyBullet(const int id, float speed) {
    alive = false;

    if (!texture.loadFromFile("EnemyBullet.png"))
        throw invalid_argument("Bullet not loaded!");

    sprite.setTextureRect(sf::IntRect(550, 475, 120, 190));
    sprite.scale(sf::Vector2f(0.1, 0.1));
}

sf::Sprite& EnemyBullet::getSprite() {
    return sprite;
}

void EnemyBullet::setLocation(float xpos, float ypos) {
    sprite.setPosition(xpos, ypos);
}

void EnemyBullet::kill() {
    alive = false;
}

bool EnemyBullet::isAlive() {
    return alive;
}

void EnemyBullet::spawn(bool bul) {
    alive = bul;
}

void EnemyBullet::draw(sf::RenderWindow& win) {
    sprite.setTexture(texture);
    win.draw(sprite);
}