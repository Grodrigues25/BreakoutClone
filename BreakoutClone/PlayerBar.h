#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace std;

class PlayerBar {
public:
    
    static const int length = 100;
    vector<float> playerCoords;
    sf::SoundBuffer barColisionSoundObject;

public:
    PlayerBar();
    ~PlayerBar();

    void drawPlayerBar(sf::RenderWindow& window);

    void updateBarPosition(sf::RenderWindow& window);

    void playBallBarColisionSound(sf::Sound& sound);

};