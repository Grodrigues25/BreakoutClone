#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <numbers>
#include <random>
#include "PlayerBar.h"
#include "Ball.h"
#include "Brick.h"

using namespace std;

class GameWindow {
public:

    // SETTINGS
    static const int windowWidth = 1120;
    static const int windowHeight = 1240;

    bool bColidedPlayerBar;
    bool bColidedBrick;
    float colisionDelay;
    vector<Brick> brickList;

public:
    GameWindow();
    ~GameWindow();

    void runGame(PlayerBar player1Bar, Ball ball);

    void brickObjectsCreation();

    void drawLevel(sf::RenderWindow& window, vector<Brick> brickList);

    void renderUI(sf::RenderWindow& window, int& lives, int& score);

    void renderPlayAgainBox(sf::RenderWindow& window);

    void renderGameOverScreen(sf::RenderWindow& window);

    void InteractWithPlayAgainBox(sf::RenderWindow& window, int mouseClickX, int mouseClickY, int& lives, bool& gameRunning, int& score);

};