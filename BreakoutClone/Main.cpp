#include <iostream>
#include "SFML/graphics.hpp"
#include "PlayerBar.h"
#include "Ball.h"
#include "GameWindow.h"

using namespace std;

// TODO: Show a time to start the game

int main() {
    PlayerBar playerBar;
    Ball ball;
    GameWindow GameSession;

    GameSession.runGame(playerBar, ball);

    return 0;
}