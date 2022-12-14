#pragma once
#ifndef SpriteMove_LoseScreen_h
#define SpriteMove_LoseScreen_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class LoseScreen {
public:
    LoseScreen();
    sf::Sprite& getSprite();
    void setLocation(float, float);
    void draw(sf::RenderWindow& win, int playerScore);
private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif