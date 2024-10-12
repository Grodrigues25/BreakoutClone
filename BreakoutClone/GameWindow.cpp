#include "GameWindow.h"

GameWindow::GameWindow()
{
    // SETTINGS
    GameWindow::windowWidth = 1080;
    GameWindow::windowHeight = 1200;

    // VARIABLES
    GameWindow::bColided = false;
    GameWindow::colisionDelay = 0;
}

GameWindow::~GameWindow()
{
}

void GameWindow::collisionChecks(Ball& ball, PlayerBar playerBar)
{
    bColided = ball.ballBarCollision(playerBar.playerCoords);

    if (bColided && colisionDelay > 1) {
        colisionDelay = 0;
        ball.bounceDirectionCalculation(playerBar.playerCoords);
    }
}



void GameWindow::renderGame(PlayerBar player1Bar, Ball ball)
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

        collisionChecks(ball, player1Bar);

        ball.ballMovement(elapsed);

        // Rendering
        window.clear();
        window.draw(background);

        player1Bar.drawPlayerBar(window);

        ball.drawBall(window, bColided);

        window.display();
    }

}