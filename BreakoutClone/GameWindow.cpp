#include "GameWindow.h"

GameWindow::GameWindow()
{
    GameWindow::bColidedPlayerBar = false;
    GameWindow::bColidedBrick = false;
    GameWindow::colisionDelay = 0;
    GameWindow::brickList;
}

GameWindow::~GameWindow()
{
}

void GameWindow::playerBarCollisionChecks(Ball& ball, PlayerBar playerBar)
{


}

void GameWindow::brickCollisionCheck(Ball& ball, Brick brick) {


}

void GameWindow::brickObjectsCreation()
{
    int id = 0;
    int CoordY = 200;

    for (int i = 0; i <= 20; i++) {
        int CoordX = 2 + i * (50 + 4);       
        if (CoordX + 50 > 1080 && CoordY <= 290) { i = -1; CoordY += 30; }
        brickList.push_back(Brick(id, CoordX, CoordY));
        id++;
    }
}

void GameWindow::drawLevel(sf::RenderWindow& window, vector<Brick> brickList) {

    for (int i = 0; i <= brickList.size() - 1; i++) { brickList[i].drawBrick(window); }
}

void GameWindow::renderGame(PlayerBar playerBar, Ball ball)
{
    // SETTINGS
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // CREATE WINDOW
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Breakout", sf::Style::Close, settings);
    sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
    background.setFillColor(sf::Color::Black);

    // OBJECT CREATION
    sf::Event event;
    sf::Clock clock;

    brickObjectsCreation();

    while (window.isOpen()) {

        window.pollEvent(event);
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { playerBar.updateBarPosition(window); }

        // OBJECTS MOVEMENT CALCULATIONS
        colisionDelay += clock.getElapsedTime().asSeconds();
        sf::Time elapsed = clock.restart();

        // COLLISIONS
        if (ball.ballBarCollision(playerBar.playerCoords) && colisionDelay > 1) { colisionDelay = 0; ball.bounceBarDirectionCalculation(playerBar.playerCoords); }

        for (int i = 0; i <= brickList.size() - 1; i++) {
            if (ball.ballBrickCollision(brickList[i].brickCoords) && colisionDelay > 1)
            { 
                colisionDelay = 0; 
                ball.bounceBrickDirectionCalculation(brickList[i]);
                brickList.erase(brickList.begin() + i);
            }
        }
        
        ball.ballMovement(elapsed);

        // RENDERING
        window.clear();
        window.draw(background);

        playerBar.drawPlayerBar(window);
        ball.drawBall(window, bColidedPlayerBar);

        for (int i = 0; i <= brickList.size() - 1; i++) {
            brickList[i].drawBrick(window);
        }
      
        window.display();
    }

}