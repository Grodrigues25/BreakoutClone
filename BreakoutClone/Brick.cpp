#include "Brick.h"

Brick::Brick(int id, int CoordsX, int CoordsY)
{
    this->id = id;
    brickCoords[0] = CoordsX;
    brickCoords[1] = CoordsY;

}

void Brick::drawBrick(sf::RenderWindow& window)
{
    sf::RectangleShape brick(sf::Vector2f(length, height));
    brick.setFillColor(sf::Color::White);
    brick.setPosition(brickCoords[0], brickCoords[1]);

    window.draw(brick);
}
