#include "GameWindow.h"

GameWindow::GameWindow()
{
    // SETTINGS
    GameWindow::windowWidth = 1080;
    GameWindow::windowHeight = 1200;

    // VARIABLES
    GameWindow::bColidedPlayerBar = false;
    GameWindow::bColidedBrick = false;
    GameWindow::colisionDelay = 0;
}

GameWindow::~GameWindow()
{
}

void GameWindow::collisionChecks(Ball& ball, PlayerBar playerBar, Brick brick)
{
    bColidedPlayerBar = ball.ballBarCollision(playerBar.playerCoords);
    bColidedBrick = ball.ballBrickCollision(brick.brickCoords);

    if (bColidedPlayerBar && colisionDelay > 1) {
        colisionDelay = 0;
        ball.bounceDirectionCalculation(playerBar.playerCoords);
    }

    if (bColidedBrick && colisionDelay > 1) {
        colisionDelay = 0;
        ball.bounceDirectionCalculation(brick.brickCoords);
    }
}



void GameWindow::renderGame(PlayerBar player1Bar, Ball ball, Brick brick)
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "TicTacToe");
    sf::Event event;
    sf::Clock clock;
    sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
    background.setFillColor(sf::Color::Black);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {

        window.pollEvent(event);

        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { player1Bar.updateBarPosition(window); }

        colisionDelay += clock.getElapsedTime().asSeconds();
        sf::Time elapsed = clock.restart();

        collisionChecks(ball, player1Bar, brick);

        ball.ballMovement(elapsed);

        // Rendering
        window.clear();
        window.draw(background);

        player1Bar.drawPlayerBar(window);

        ball.drawBall(window, bColidedPlayerBar);

        brick.drawBrick(window);

        window.display();
    }

}