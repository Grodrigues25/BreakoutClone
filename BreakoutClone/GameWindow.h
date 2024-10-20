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

    void barColisionSound(sf::SoundBuffer& barColisionSound);

    void renderUI(sf::RenderWindow& window, int& lives, int& score);

};