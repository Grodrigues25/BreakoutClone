#include "Ball.h"

Ball::Ball()
{
    Ball::bounceAngle = sqrt(2) / 2;
    Ball::ballCoords = { 960, 540, bounceAngle };
}

Ball::~Ball()
{
}

// CALCULATIONS
bool Ball::ballBarCollision(vector<float> playersBarCoords)
{
    return playersBarCoords[0] < ballCoords[0] + 12 && playersBarCoords[0] + 100 > ballCoords[0] && playersBarCoords[1] < ballCoords[1] + 12 && playersBarCoords[1] + 12 > ballCoords[1];
}

bool Ball::ballBrickCollision(vector<float> brickCoords)
{
    return brickCoords[0] < ballCoords[0] + 12 && brickCoords[0] + 50 > ballCoords[0] && brickCoords[1] < ballCoords[1] + 12 && brickCoords[1] + 12 > ballCoords[1];
}

void Ball::bounceDirectionCalculation(vector<float> playerBar)
{
    float maxBounceAngle = (5 * std::numbers::pi) / 12;

    float intersect = (playerBar[0] + 56) - ballCoords[0];
    intersect = intersect / 56;

    float bounceAngle = intersect * maxBounceAngle;

    ballCoords[2] = bounceAngle + std::numbers::pi/2;

    cout << (ballCoords[2] * 360) / (2 * std::numbers::pi) << " degrees\n";
}

void Ball::ballMovement(sf::Time time)
{
    float speed = 800;

    // Horizontal colision checks
    if (ballCoords[0] + speed * cos(ballCoords[2]) * time.asSeconds() >= 1080 || ballCoords[0] + speed * cos(ballCoords[2]) * time.asSeconds() <= 0) {
        ballCoords[2] >= 0 ? ballCoords[2] = std::numbers::pi - ballCoords[2] : ballCoords[2] = -std::numbers::pi - ballCoords[2];
    }
    else {
        ballCoords[0] += speed * cos(ballCoords[2]) * time.asSeconds();
    }

    // TOP and BOTTOM colision checks
    if (ballCoords[1] + speed * -sin(ballCoords[2]) * time.asSeconds() <= 1180 && ballCoords[1] + speed * -sin(ballCoords[2]) * time.asSeconds() >= 0) {
        ballCoords[1] += speed * -sin(ballCoords[2]) * time.asSeconds();
    }
    else {
        ballCoords[2] = -ballCoords[2];
        ballCoords[1] += speed * -sin(ballCoords[2]) * time.asSeconds();
    }
}

// RENDERING
void Ball::drawBall(sf::RenderWindow& window, bool colision) {

    sf::RectangleShape ball(sf::Vector2f(12, 12));
    ball.setPosition(ballCoords[0], ballCoords[1]);
    ball.setFillColor(sf::Color::White);

    if (colision) { cout << "Colision happened!" << endl; }

    window.draw(ball);
}