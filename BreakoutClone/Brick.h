#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <numbers>

using namespace std;

class Brick {
public:
    int length;
    int height;
    vector<float> brickCoords = { 0,0 };

public:
    Brick();
    ~Brick();

    void drawBrick(sf::RenderWindow& window);

};