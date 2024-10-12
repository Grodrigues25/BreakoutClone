#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include <numbers>
#include <random>
#include "PlayerBar.h"
#include "Ball.h"
#include "Brick.h"

using namespace std;

class GameWindow {
public:

    // SETTINGS
    int windowWidth;
    int windowHeight;

    bool bColidedPlayerBar;
    bool bColidedBrick;
    float colisionDelay;

public:
    GameWindow();
    ~GameWindow();

    void renderGame(PlayerBar player1Bar, Ball ball, Brick brick);

    void collisionChecks(Ball& ball, PlayerBar playerBar, Brick brick);

};