#include <iostream>
#include "SFML/graphics.hpp"
#include "PlayerBar.h"
#include "Ball.h"
#include "GameWindow.h"
#include "Brick.h"

using namespace std;

// TODO: Correct the first line of bricks
// TODO: Debug maximum angle for bouncing of the playerBar
// TODO: Show a time to start the game
// TODO: Analyse making ball speed variable depending on the location of the bar it hits.
// TODO: Set a Game Over Screen

int main() {
    PlayerBar playerBar;
    Ball ball;
    GameWindow GameSession;

    GameSession.runGame(playerBar, ball);

    return 0;
}