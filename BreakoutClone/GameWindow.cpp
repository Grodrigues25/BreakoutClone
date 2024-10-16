#include "GameWindow.h"

GameWindow::GameWindow()
{
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
        ball.bounceBarDirectionCalculation(playerBar.playerCoords);
    }

    if (bColidedBrick && colisionDelay > 0.001) {
        colisionDelay = 0;
        ball.bounceBrickDirectionCalculation(brick);
    }
}

void GameWindow::drawLevel(sf::RenderWindow& window, vector<Brick> brickList) {

    int i;
    for (i = 0; i <= brickList.size() - 1; i++) {
        brickList[i].drawBrick(window);
    }

}

void GameWindow::renderGame(PlayerBar player1Bar, Ball ball, vector<Brick> brickList)
{

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Breakout", sf::Style::Close, settings);
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
        for (int i = 0; i <= brickList.size() - 1; i++) {
            collisionChecks(ball, player1Bar, brickList[i]);
        }
        
        ball.ballMovement(elapsed);

        // Rendering
        window.clear();
        window.draw(background);

        player1Bar.drawPlayerBar(window);

        ball.drawBall(window, bColidedPlayerBar);

        for (int i = 0; i <= brickList.size() - 1; i++) {
            brickList[i].drawBrick(window);
        }
      
        window.display();
    }

}