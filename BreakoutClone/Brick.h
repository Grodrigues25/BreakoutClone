#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <numbers>

using namespace std;

class Brick {
public:
    int length = 100;
    int height = 100;
    int id;
    vector<float> brickCoords = { 0,0 };

public:
    Brick(int id, int CoordsX, int CoordsY);

    void drawBrick(sf::RenderWindow& window);

};