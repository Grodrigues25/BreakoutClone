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
    sf::SoundBuffer ballLostLifeSoundObject;

public:
    Ball();
    ~Ball();

    void drawBall(sf::RenderWindow& window, bool colision);

    bool ballBarCollision(vector<float> playersBarCoords);

    bool ballBrickCollision(vector<float> brickCoords);

    void bounceBarDirectionCalculation(vector<float> playerBar);

    void bounceBrickDirectionCalculation(Brick brick);

    void ballMovement(sf::Time time, int& lives, float& gameStartDelay, sf::Sound& sound);

    void playLostLifeSound(sf::Sound& sound);
};