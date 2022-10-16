#include "LoseScreen.h"

LoseScreen::LoseScreen() {
    if (!texture.loadFromFile("lose-page.jpg"))
        throw invalid_argument("Game over screen not loaded!");

    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}

sf::Sprite& LoseScreen::getSprite() {
    return sprite;
}

void LoseScreen::setLocation(float xpos, float ypos) {
    sprite.setPosition(xpos, ypos);
}

void LoseScreen::draw(sf::RenderWindow& win) {
    sprite.setTexture(texture);
    win.draw(sprite);
}