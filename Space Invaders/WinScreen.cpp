#include "WinScreen.h"

WinScreen::WinScreen() {
    if (!texture.loadFromFile("win-page.jpg"))
        throw invalid_argument("Game over screen not loaded!");

    sprite.setPosition(0, 0);
}

sf::Sprite& WinScreen::getSprite() {
    return sprite;
}

void WinScreen::setLocation(float xpos, float ypos) {
    sprite.setPosition(xpos, ypos);
}

void WinScreen::draw(sf::RenderWindow& win) {
    sprite.setTexture(texture);
    win.draw(sprite);
}
