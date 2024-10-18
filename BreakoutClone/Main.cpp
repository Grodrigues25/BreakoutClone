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

    GameSession.renderGame(playerBar, ball);

    return 0;
}