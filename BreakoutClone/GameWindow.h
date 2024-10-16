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
    static const int windowWidth = 1080;
    static const int windowHeight = 1200;

    bool bColidedPlayerBar;
    bool bColidedBrick;
    float colisionDelay;
    vector<Brick> brickList;

public:
    GameWindow();
    ~GameWindow();

    void renderGame(PlayerBar player1Bar, Ball ball);

    void collisionChecks(Ball& ball, PlayerBar playerBar, Brick brick);

    void brickObjectsCreation();

    void drawLevel(sf::RenderWindow& window, vector<Brick> brickList);

};