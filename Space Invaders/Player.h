#pragma once

#ifndef SpriteMove_Ship_h
#define SpriteMove_Ship_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Ship
{
public:
    Ship(const int, float);
    sf::Sprite& getSprite();

    void setLocation(float, float);
    void kill();
    bool isAlive();
    void respawn();
    void draw(sf::RenderWindow& win);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool alive;
};

#endif