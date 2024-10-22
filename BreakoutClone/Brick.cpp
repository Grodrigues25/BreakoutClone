#include "Brick.h"

Brick::Brick(int CoordsX, int CoordsY)
{
    brickCoords[0] = CoordsX;
    brickCoords[1] = CoordsY;
    
    if (!brickColisionSoundObject.loadFromFile("C:\\Users\\gonca\\source\\repos\\BreakoutClone\\assets\\brickDestroyedSound.wav")) { cout << "Brick Destroyed Sound failed to load!" << endl; }
}

void Brick::drawBrick(sf::RenderWindow& window)
{
    sf::RectangleShape brick(sf::Vector2f(length, 20.f));
    brick.setFillColor(sf::Color::White);
    brick.setPosition(brickCoords[0], brickCoords[1]);

    window.draw(brick);
}

void Brick::playBrickDestructionSound(sf::Sound& sound)
{
    sound.setBuffer(brickColisionSoundObject);
    sound.play();
}
