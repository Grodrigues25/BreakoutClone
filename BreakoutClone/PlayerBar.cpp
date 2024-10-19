#include "PlayerBar.h"

PlayerBar::PlayerBar() {
    PlayerBar::playerCoords = { 500, 1100 };
}

PlayerBar::~PlayerBar() {

}

// CALCULATIONS
void PlayerBar::updateBarPosition(sf::RenderWindow& window) {
    sf::Vector2f acceleration;
    sf::Vector2f velocity;

    // adjust this at will
    const float dAcc = 3.6f;

    // set acceleration
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { acceleration.x -= dAcc; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { acceleration.x += dAcc; }

    // update velocity through acceleration
    velocity += acceleration;

    // update position through velocity
    if (playerCoords[0] + velocity.x > 1020) {
        playerCoords[0] = 1020;
    }
    else if (playerCoords[0] + velocity.x < 20) {
        playerCoords[0] = 20;
    }
    else {
        playerCoords[0] += velocity.x;
    }

    // apply damping to the velocity
    velocity = 0.99f * velocity;

};

// RENDERING
void PlayerBar::drawPlayerBar(sf::RenderWindow& window) {

    sf::RectangleShape playerBar(sf::Vector2f(length, 20.f));
    playerBar.setFillColor(sf::Color::White);
    playerBar.setPosition(playerCoords[0], playerCoords[1]);

    window.draw(playerBar);
}
