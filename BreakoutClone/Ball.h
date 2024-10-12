#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <numbers>

using namespace std;

class Ball {
public:
    vector<float> ballCoords;
    float bounceAngle;

public:
    Ball();
    ~Ball();

    void drawBall(sf::RenderWindow& window, bool colision);

    bool ballBarCollision(vector<float> playersBarCoords);

    bool ballBrickCollision(vector<float> brickCoords);

    void bounceDirectionCalculation(vector<float> playerBar);

    void ballMovement(sf::Time time);
};