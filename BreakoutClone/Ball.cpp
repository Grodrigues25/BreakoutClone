#include "Ball.h"

Ball::Ball()
{
    Ball::bounceAngle = sqrt(2) / 2;
    Ball::ballCoords = { 960, 540, bounceAngle };
    Ball::ballWidth = 12;
}

Ball::~Ball()
{
}

// CALCULATIONS
bool Ball::ballBarCollision(vector<float> playersBarCoords)
{
    return playersBarCoords[0] < ballCoords[0] + ballWidth && playersBarCoords[0] + 100 > ballCoords[0] && playersBarCoords[1] < ballCoords[1] + ballWidth && playersBarCoords[1] + ballWidth > ballCoords[1];
}

void Ball::bounceBarDirectionCalculation(vector<float> playerBar)
{
    float maxBounceAngle = (5 * std::numbers::pi) / 12;

    float intersect = (playerBar[0] + 56) - ballCoords[0];
    intersect = intersect / 56;

    float bounceAngle = intersect * maxBounceAngle;

    ballCoords[2] = bounceAngle + std::numbers::pi / 2;

    cout << (ballCoords[2] * 360) / (2 * std::numbers::pi) << " degrees\n";
}

bool Ball::ballBrickCollision(vector<float> brickCoords)
{
    if (brickCoords[0] < ballCoords[0] + ballWidth && brickCoords[0] + 50 > ballCoords[0] && brickCoords[1]  < ballCoords[1] + ballWidth && brickCoords[1] + ballWidth > ballCoords[1]){ cout << "Brick Collision Detected" << endl; }
    
    return brickCoords[0] < ballCoords[0] + ballWidth && brickCoords[0] + 50 > ballCoords[0] && brickCoords[1] < ballCoords[1] + ballWidth && brickCoords[1] + ballWidth > ballCoords[1];
}

void Ball::bounceBrickDirectionCalculation(Brick brick)
{

    if (ballCoords[0] < brick.brickCoords[0] && ballCoords[1] >= brick.brickCoords[1] - ballWidth && ballCoords[1] <= brick.brickCoords[1] + brick.height) {
        cout << "Left Brick Collision" << endl;
        ballCoords[2] >= 0 ? ballCoords[2] = std::numbers::pi - ballCoords[2] : ballCoords[2] = -std::numbers::pi - ballCoords[2];
    }

    else if (ballCoords[0] + ballWidth > brick.brickCoords[0] + brick.length && ballCoords[1] >= brick.brickCoords[1] - ballWidth && ballCoords[1] <= brick.brickCoords[1] + brick.height) {
        cout << "Right Brick Collision" << endl;
        ballCoords[2] >= 0 ? ballCoords[2] = std::numbers::pi - ballCoords[2] : ballCoords[2] = -std::numbers::pi - ballCoords[2];
    }

    else if (ballCoords[0] >= brick.brickCoords[0] - ballWidth && ballCoords[0] <= brick.brickCoords[0] + brick.length && ballCoords[1] < brick.brickCoords[1]) {
        cout << "Top Brick Collision" << endl;
        ballCoords[2] = -ballCoords[2];
    }

    else if (ballCoords[0] > brick.brickCoords[0] - ballWidth && ballCoords[0] < brick.brickCoords[0] + brick.length && ballCoords[1] + ballWidth > brick.brickCoords[1] + brick.height) {
        cout << "Bottom Brick Collision" << endl;
        ballCoords[2] = -ballCoords[2];
    }

}

void Ball::ballMovement(sf::Time time)
{
    float speed = 800;
    float horizontalMovement = speed * cos(ballCoords[2]) * time.asSeconds();
    float verticalMovement = speed * -sin(ballCoords[2]) * time.asSeconds();

    // Horizontal colision checks
    if (ballCoords[0] + horizontalMovement >= 1088 || ballCoords[0] + horizontalMovement <= 20) {
        ballCoords[2] >= 0 ? ballCoords[2] = std::numbers::pi - ballCoords[2] : ballCoords[2] = -std::numbers::pi - ballCoords[2];
    }
    else {
        ballCoords[0] += horizontalMovement;
    }

    // TOP and BOTTOM colision checks
    if (ballCoords[1] + verticalMovement <= 1208 && ballCoords[1] + verticalMovement >= 140) {
        ballCoords[1] += verticalMovement;
    }
    else {
        ballCoords[2] = -ballCoords[2];
        ballCoords[1] += verticalMovement;
    }
}

// RENDERING
void Ball::drawBall(sf::RenderWindow& window, bool colision) {

    sf::RectangleShape ball(sf::Vector2f(ballWidth, ballWidth));
    ball.setPosition(ballCoords[0], ballCoords[1]);
    ball.setFillColor(sf::Color::White);

    if (colision) { cout << "Colision happened!" << endl; }

    window.draw(ball);
}