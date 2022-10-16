#include "SoundManager.h"

SoundManager::SoundManager() {
    if (!lazerBuffer.loadFromFile("shoot.wav"))
        throw invalid_argument("Lazer sound not loaded!");

    if (!explosionBuffer.loadFromFile("ship_explode.wav"))
        throw invalid_argument("Explosion sound not loaded!");

    
    if (!music.openFromFile("background.ogg"))
        throw invalid_argument("Explosion sound not loaded!");
}

void SoundManager::playBackgroundMusic() {
    music.setLoop(true);
    music.play();
}

void SoundManager::pauseBackgroundMusic() {
    music.pause();
}

void SoundManager::playLazer() {
    lazerSound.setBuffer(lazerBuffer);
    lazerSound.play();
}

void SoundManager::playExplosion() {
    explosionSound.setBuffer(explosionBuffer);
    explosionSound.play();
}
