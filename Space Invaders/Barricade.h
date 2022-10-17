#ifndef Barricade_h
#define Barricade_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Barricade {
public:
    Barricade(const int, int);
    sf::Sprite& getSprite();
    void setLocation(float, float);
    void kill();
    bool isAlive();
    void destroy();
    void draw(sf::RenderWindow& win);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool alive;
    int health;
};

#endif