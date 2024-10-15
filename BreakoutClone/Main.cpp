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

    Brick brick(1);
    brick.brickCoords[0] = 200;
    brick.brickCoords[1] = 200;

    Brick brick2(2);
    brick2.brickCoords[0] = 450;
    brick2.brickCoords[1] = 400;

    vector<Brick> brickList;
    brickList.push_back(brick);
    brickList.push_back(brick2);

    GameSession.renderGame(playerBar, ball, brickList);

    return 0;
}