#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <numbers>

using namespace std;

class Brick {
public:
    static const int length = 50;
    static const int height = 10;
    vector<float> brickCoords = { 0,0 };
    sf::SoundBuffer brickColisionSoundObject;

public:
    Brick(int CoordsX, int CoordsY);

    void drawBrick(sf::RenderWindow& window);

    void playBrickDestructionSound(sf::Sound& sound);

};