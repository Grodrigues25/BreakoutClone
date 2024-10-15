#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <numbers>

using namespace std;

class Brick {
public:
    static const int length = 50;
    static const int height = 10;
    int id;
    vector<float> brickCoords = { 0,0 };

public:
    Brick(int id);

    void drawBrick(sf::RenderWindow& window);

};