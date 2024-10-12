#include <iostream>
#include "SFML/graphics.hpp"
#include "PlayerBar.h"
#include "Ball.h"
#include "GameWindow.h"
#include "Brick.h"

using namespace std;

// TODO: Colision angled of the bricks and the playerBar are different
// TODO: Check which class is more appropriate to contain the colision functions specific to Bricks and PlayerBar
// TODO: Check why the colision in bottom of the brick does not trigger a bounce
// TODO: Learn more about access modifiers

int main() {
    PlayerBar playerBar;

    Ball ball;

    GameWindow GameSession;

    Brick brick;
    brick.brickCoords[0] = 200;
    brick.brickCoords[1] = 200;

    GameSession.renderGame(playerBar, ball, brick);

    return 0;
}