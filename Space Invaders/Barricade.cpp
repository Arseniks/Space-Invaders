#include "Barricade.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Barricade::Barricade(const int id, int hp) {
    alive = true;

    health = hp;

    if (!texture.loadFromFile("page.png"))
        throw invalid_argument("Enemy not loaded!");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(82, 88, 28, 20));
    sprite.scale(sf::Vector2f(4, 4));
}


sf::Sprite& Barricade::getSprite() {
    return sprite;
}

void Barricade::setLocation(float xpos, float ypos) {
    sprite.setPosition(xpos, ypos);
}

void Barricade::kill() {
    alive = false;
}

bool Barricade::isAlive() {
    return alive;
}

void Barricade::destroy() {
    if (health == 3) {
        health--;
        if (!texture.loadFromFile("page.png"))
            throw invalid_argument("Enemy not loaded!");

        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(173, 88, 28, 20));
        sprite.scale(sf::Vector2f(4, 4));
    } else if (health == 2) {
        health--;
        if (!texture.loadFromFile("page.png"))
            throw invalid_argument("Enemy not loaded!");

        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(128, 88, 28, 20));
        sprite.scale(sf::Vector2f(4, 4));
    } else if (health == 1) {
        health--;
        if (!texture.loadFromFile("page.png"))
            throw invalid_argument("Enemy not loaded!");

        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(38, 88, 28, 20));
        sprite.scale(sf::Vector2f(4, 4));
    } else {
        kill();
    }
}

void Barricade::draw(sf::RenderWindow& win) {
    sprite.setTexture(texture);
    win.draw(sprite);
}
