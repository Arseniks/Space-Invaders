#pragma once

#ifndef SpriteMove_Bullet_h
#define SpriteMove_Bullet_h


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
public:
    Bullet(const int, float);
    sf::Sprite& getSprite();
    void setLocation(float, float);
    void kill();
    bool isAlive();
    void spawn(bool);
    void draw(sf::RenderWindow& win);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool alive;

};

#endif