#pragma once

#ifndef SpriteMove_Enemy_h
#define SpriteMove_Enemy_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy {
public:
    Enemy() {};
    Enemy(const int, float, int);
    sf::Sprite& getSprite();
    void setLocation(float, float);
    void kill();
    bool isAlive();
    float getSpeed() const;
    int getType() const;
    void draw(sf::RenderWindow& win);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool alive;
    float speed;
    int type;
};


#endif
