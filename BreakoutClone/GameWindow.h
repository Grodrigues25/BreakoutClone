#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <numbers>
#include <random>
#include "PlayerBar.h"
#include "Ball.h"

using namespace std;

class GameWindow {
public:

    // SETTINGS
    int windowWidth;
    int windowHeight;

    bool bColided;
    float colisionDelay;

public:
    GameWindow();
    ~GameWindow();

    void renderGame(PlayerBar player1Bar, Ball ball);

    void collisionChecks(Ball& ball, PlayerBar playerBar);

};