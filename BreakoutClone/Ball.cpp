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

bool Ball::ballBrickCollision(Brick brick)
{
    //if (brick.brickCoords[0] < ballCoords[0] + ballWidth && brick.brickCoords[0] + brick.length > ballCoords[0] && brick.brickCoords[1]  < ballCoords[1] + ballWidth && brick.brickCoords[1] + brick.height > ballCoords[1]){ cout << "Brick Collision Detected" << endl; }
    
    return brick.brickCoords[0] < ballCoords[0] + ballWidth && brick.brickCoords[0] + brick.length > ballCoords[0] && brick.brickCoords[1] < ballCoords[1] + ballWidth && brick.brickCoords[1] + brick.height > ballCoords[1];
}

void Ball::bounceBarDirectionCalculation(vector<float> playerBar)
{
    float maxBounceAngle = (5 * std::numbers::pi) / 12;

    float intersect = (playerBar[0] + 56) - ballCoords[0];
    intersect = intersect / 56;

    float bounceAngle = intersect * maxBounceAngle;

    ballCoords[2] = bounceAngle + std::numbers::pi/2;

    cout << (ballCoords[2] * 360) / (2 * std::numbers::pi) << " degrees\n";
}

void Ball::bounceBrickDirectionCalculation(Brick brick)
{
    cout << "Ball X: " << ballCoords[0] << ";  Ball Y: " << ballCoords[1] << endl;
    if (ballCoords[0] < brick.brickCoords[0] && ballCoords[1] >= brick.brickCoords[1] - ballWidth && ballCoords[1] <= brick.brickCoords[1] + brick.height) {
        cout << "Left Brick Collision" << endl;
        ballCoords[2] >= 0 ? ballCoords[2] = std::numbers::pi - ballCoords[2] : ballCoords[2] = -std::numbers::pi - ballCoords[2];
    }

    if (ballCoords[0] + ballWidth > brick.brickCoords[0] + brick.length && ballCoords[1] >= brick.brickCoords[1] - ballWidth && ballCoords[1] <= brick.brickCoords[1] + brick.height) {
        cout << "Right Brick Collision" << endl;
        ballCoords[2] >= 0 ? ballCoords[2] = std::numbers::pi - ballCoords[2] : ballCoords[2] = -std::numbers::pi - ballCoords[2];
    }

    if (ballCoords[0] >= brick.brickCoords[0] - ballWidth && ballCoords[0] <= brick.brickCoords[0] + brick.length && ballCoords[1] < brick.brickCoords[1]) {
        cout << "Top Brick Collision" << endl;
        ballCoords[2] = -ballCoords[2];
    }

    if (ballCoords[0] >= brick.brickCoords[0] - ballWidth && ballCoords[0] <= brick.brickCoords[0] + brick.length && ballCoords[1] + ballWidth > brick.brickCoords[1] + brick.height) {
        cout << "Bottom Brick Collision" << endl;
        ballCoords[2] = -ballCoords[2];
    }

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

// TEMP FUNCTION
void Ball::updateBallPosition(sf::RenderWindow& window) {
    sf::Vector2f acceleration;
    sf::Vector2f velocity;

    // adjust this at will
    const float dAcc = 1.3f;

    // set acceleration
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { acceleration.x -= dAcc; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { acceleration.x += dAcc; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { acceleration.y -= dAcc; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { acceleration.y += dAcc; }

    // update velocity through acceleration
    velocity += acceleration;

    // update position through velocity
    if (ballCoords[0] + velocity.x > 1060) {
        ballCoords[0] = 1060;
    }
    else if (ballCoords[0] + velocity.x < 0) {
        ballCoords[0] = 0;
    }
    else {
        ballCoords[0] += velocity.x;
    }

    if (ballCoords[1] + velocity.y > 1180) {
        ballCoords[1] = 1180;
    }
    else if (ballCoords[1] + velocity.y < 0) {
        ballCoords[1] = 0;
    }
    else {
        ballCoords[1] += velocity.y;
    }

    // apply damping to the velocity
    velocity = 0.10f * velocity;

};

// RENDERING
void Ball::drawBall(sf::RenderWindow& window, bool colision) {

    sf::RectangleShape ball(sf::Vector2f(ballWidth, ballWidth));
    ball.setPosition(ballCoords[0], ballCoords[1]);
    ball.setFillColor(sf::Color::White);

    if (colision) { cout << "Colision happened!" << endl; }

    window.draw(ball);
}