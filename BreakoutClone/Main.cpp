#include <iostream>
#include "SFML/graphics.hpp"
#include "PlayerBar.h"
#include "Ball.h"
#include "GameWindow.h"
#include "Brick.h"

using namespace std;

// TODO: Review ball brick collision to check why there are edge cases where the colision detection and resulting bounce does not work properly. -> 
// TODO: Colision angles of the bricks and the playerBar are different -> IN PROGRESS
// TODO: Check which class is more appropriate to contain the colision functions specific to Bricks and PlayerBar
// TODO: Check why the colision in bottom of the brick does not trigger a bounce -> The collision was being detected, the bounce calculations was just not done correctly for the bottom edge of the player bar.
// TODO: Learn more about access modifiers -> Analyse each class and start applying access modifiers appropriately.

int main() {
    PlayerBar playerBar;

    Ball ball;

    GameWindow GameSession;

    //Brick brick(1);
    //brick.brickCoords[0] = 200;
    //brick.brickCoords[1] = 200;

    //Brick brick2(2);
    //brick2.brickCoords[0] = 450;
    //brick2.brickCoords[1] = 400;

    //Brick brick3(3);
    //brick3.brickCoords[0] = 750;
    //brick3.brickCoords[1] = 400;

    //Brick brick4(4);
    //brick4.brickCoords[0] = 450;
    //brick4.brickCoords[1] = 700;

    //vector<Brick> brickList;
    //brickList.push_back(brick);
    //brickList.push_back(brick2);
    //brickList.push_back(brick3);
    //brickList.push_back(brick4);

    GameSession.renderGame(playerBar, ball);

    return 0;
}