#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <numbers>
#include "Brick.h"

using namespace std;

class Ball {
public:
    vector<float> ballCoords;
    float bounceAngle;
    int ballWidth;

public:
    Ball();
    ~Ball();

    void drawBall(sf::RenderWindow& window, bool colision);

    bool ballBarCollision(vector<float> playersBarCoords);

    bool ballBrickCollision(Brick brick);

    void bounceBarDirectionCalculation(vector<float> playerBar);

    void bounceBrickDirectionCalculation(Brick brick);

    void ballMovement(sf::Time time);

    //TEMP FUNCTION
    void updateBallPosition(sf::RenderWindow& window);
};