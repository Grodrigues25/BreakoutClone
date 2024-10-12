#include "Brick.h"

Brick::Brick()
{
    Brick::length = 50;
    Brick::height = 10;
}

Brick::~Brick()
{
}

void Brick::drawBrick(sf::RenderWindow& window)
{
    sf::RectangleShape playerBar(sf::Vector2f(length, 20.f));
    playerBar.setFillColor(sf::Color::White);
    playerBar.setPosition(brickCoords[0], brickCoords[1]);

    window.draw(playerBar);
}
