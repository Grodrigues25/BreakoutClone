#include <iostream>
#include "SFML/graphics.hpp"
#include "PlayerBar.h"
#include "Ball.h"
#include "GameWindow.h"

using namespace std;

int main() {
    PlayerBar playerBar;

    Ball ball;

    GameWindow GameSession;

    GameSession.renderGame(playerBar, ball);

    return 0;
}