#pragma once
#ifndef __SpriteMove__SoundManager__
#define __SpriteMove__SoundManager__

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>
using namespace std;

class SoundManager
{
public:
    SoundManager();
    void playBackgroundMusic();
    void pauseBackgroundMusic();
    void playLazer();
    void playExplosion();
private:
    sf::SoundBuffer lazerBuffer;
    sf::SoundBuffer explosionBuffer;
    sf::SoundBuffer rewardBuffer;
    sf::Music music;
    sf::Sound lazerSound;
    sf::Sound explosionSound;
    sf::Sound rewardSound;
};

#endif