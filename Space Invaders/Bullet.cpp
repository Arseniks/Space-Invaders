#include "Bullet.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Bullet::Bullet(const int id, float speed) {
    alive = false;

    if (!texture.loadFromFile("page.png"))
        throw invalid_argument("Bullet not loaded!");

    sprite.setTextureRect(sf::IntRect(118, 105, 5, 6));
    sprite.scale(sf::Vector2f(4, 4));
}

sf::Sprite& Bullet::getSprite() {
    return sprite;
}

void Bullet::setLocation(float xpos, float ypos) {
    sprite.setPosition(xpos, ypos);
}

void Bullet::kill() {
    alive = false;
}

bool Bullet::isAlive() {
    return alive;
}

void Bullet::spawn(bool bul) {
    alive = bul;
}

void Bullet::draw(sf::RenderWindow& win) {
    sprite.setTexture(texture);
    win.draw(sprite);
}