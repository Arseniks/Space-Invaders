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

void LoseScreen::draw(sf::RenderWindow& win, int playerScore) {
    sprite.setTexture(texture);
    win.draw(sprite);

    sf::Font font;
    font.loadFromFile("space_invaders.ttf");
    sf::Text text("", font, 50);
    text.setString("SCORE: " + to_string(playerScore));
    text.setPosition(285, 395);
    win.draw(text);
}