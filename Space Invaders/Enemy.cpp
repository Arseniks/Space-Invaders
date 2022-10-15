#include "Enemy.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Enemy::Enemy(const int id, float sp)
{
    alive = true;

    speed = sp;

    if (!texture.loadFromFile("page.png"))
        throw invalid_argument("Enemy not loaded!");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(32, 11, 15, 12));
    sprite.scale(sf::Vector2f(4, 4));
}

sf::Sprite& Enemy::getSprite() {
    return sprite;
}

void Enemy::setLocation(float xpos, float ypos) {
    sprite.setPosition(xpos, ypos);
}

void Enemy::kill() {
    alive = false;
}

bool Enemy::isAlive() {
    return alive;
}

void Enemy::draw(sf::RenderWindow& win) {
    sprite.setTexture(texture);
    win.draw(sprite);
}

float Enemy::getSpeed() const {
    return speed;
}