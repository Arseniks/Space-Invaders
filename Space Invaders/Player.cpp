#include "Player.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Ship::Ship(const int id, float speed) {
    alive = true;

    if (!texture.loadFromFile("page.png"))
        throw invalid_argument("Ship not loaded!");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(111, 112, 20, 20));
    sprite.setScale(sf::Vector2f(4, 4));
}

void Ship::setLocation(float xpos, float ypos)
{
    sprite.setPosition(xpos, ypos);
}

sf::Sprite& Ship::getSprite()
{
    return sprite;
}

void Ship::kill()
{
    alive = false;
}

bool Ship::isAlive()
{
    return alive;
}

void Ship::draw(sf::RenderWindow& win)
{
    sprite.setTexture(texture);
    win.draw(sprite);
}

void Ship::respawn()
{
    alive = true;
}