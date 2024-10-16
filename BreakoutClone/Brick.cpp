#include "Brick.h"

Brick::Brick(int id)
{
    this->id = id;
}

void Brick::drawBrick(sf::RenderWindow& window)
{
    sf::RectangleShape brick(sf::Vector2f(length, 20.f));
    brick.setFillColor(sf::Color::White);
    brick.setPosition(brickCoords[0], brickCoords[1]);

    window.draw(brick);
}
