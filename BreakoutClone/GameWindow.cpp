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

void GameWindow::brickObjectsCreation()
{
    int CoordY = 200;

    for (int i = -1; i < 20; i++) {
        int CoordX = 22 + i * (50 + 4);       
        if (CoordX + 50 > 1080 && CoordY <= 290) { i = -1; CoordY += 30; }
        brickList.push_back(Brick(CoordX, CoordY));
    }
}

void GameWindow::drawLevel(sf::RenderWindow& window, vector<Brick> brickList) {

    for (int i = 0; i <= brickList.size() - 1; i++) { brickList[i].drawBrick(window); }
}

void GameWindow::renderUI(sf::RenderWindow& window, int& lives, int& score)
{
    sf::RectangleShape outerEdges(sf::Vector2f(1120, 1240));
    outerEdges.setFillColor(sf::Color::White);
    window.draw(outerEdges);

    sf::RectangleShape background(sf::Vector2f(1080, 1220));
    background.setFillColor(sf::Color::Black);
    background.setPosition(20, 20);
    window.draw(background);

    sf::RectangleShape gameplayCeiling(sf::Vector2f(1080, 20));
    gameplayCeiling.setFillColor(sf::Color::White);
    gameplayCeiling.setPosition(20, 120);
    window.draw(gameplayCeiling);

    sf::Font font;
    font.loadFromFile("C:\\Users\\gonca\\source\\repos\\BreakoutClone\\assets\\breakout.ttf");
    
    sf::Text title;
    title.setFont(font);
    title.setString("Breakout");
    title.setCharacterSize(48); // in pixels, not points!
    title.setFillColor(sf::Color::White);
    title.setPosition(450, 25);
    window.draw(title);

    sf::Text Lives;
    Lives.setFont(font);
    Lives.setString("Lives " + std::to_string(lives));
    Lives.setCharacterSize(24); // in pixels, not points!
    Lives.setFillColor(sf::Color::White);
    Lives.setPosition(40, 85);
    window.draw(Lives);

    sf::Text Score;
    Score.setFont(font);
    Score.setString("Score " + std::to_string(score));
    Score.setCharacterSize(24); // in pixels, not points!
    Score.setFillColor(sf::Color::White);
    Score.setPosition(200, 85);
    window.draw(Score);

}

void GameWindow::runGame(PlayerBar playerBar, Ball ball)
{
    // SETTINGS
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // CREATE WINDOW
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Breakout", sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);

    // OBJECT CREATION
    sf::Event event;
    sf::Clock clock;
    sf::Sound sound;

    int lives = 3;
    int score = 0;
    float gameStartDelay = 0;

    brickObjectsCreation();

    // BACKGROUND MUSIC
    sf::Music music;
    if (!music.openFromFile("C:\\Users\\gonca\\source\\repos\\BreakoutClone\\assets\\game-level-music.wav")) { cout << "Music failed to load!" << endl; }      
    music.setLoop(true);
    music.play();

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
        gameStartDelay += clock.getElapsedTime().asSeconds();
        sf::Time deltatime = clock.restart();

        // COLLISIONS
        if (ball.ballBarCollision(playerBar.playerCoords) && colisionDelay > 1) { 
            colisionDelay = 0;
            playerBar.playBallBarColisionSound(sound);
            ball.bounceBarDirectionCalculation(playerBar.playerCoords); 
        }

        for (int i = 0; i <= brickList.size() - 1; i++) {
            if (ball.ballBrickCollision(brickList[i].brickCoords))
            { 
                brickList[0].playBrickDestructionSound(sound);              
                ball.bounceBrickDirectionCalculation(brickList[i]);
                colisionDelay = 0;
                score += 100;
                brickList.erase(brickList.begin() + i);
            }
        }
        
        if (gameStartDelay > 3) {
            ball.ballMovement(deltatime, lives, gameStartDelay, sound);
        }

        // RENDERING
        window.clear();
        renderUI(window, lives, score);

        playerBar.drawPlayerBar(window);
        ball.drawBall(window, bColidedPlayerBar);

        for (int i = 0; i <= brickList.size() - 1; i++) {
            brickList[i].drawBrick(window);
        }
      
        window.display();
    }

}