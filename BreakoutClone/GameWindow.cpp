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
    int CoordX = 22;

    for (int i = 0; i <= 20; i++) {             
        if (CoordX + 50 > 1080 && CoordY <= 290) { i = 0; CoordY += 30; }
        CoordX = 22 + i * (50 + 4);
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

void GameWindow::renderPlayAgainBox(sf::RenderWindow& window) {

    sf::Text playAgainQuestion;
    sf::Text Yes;
    sf::Text No;
    sf::Font font;
    font.loadFromFile("C:\\Users\\gonca\\source\\repos\\BreakoutClone\\assets\\breakout.ttf");

    int boxXposition = 290;
    int boxYposition = 500;

    sf::RectangleShape boxOutline(sf::Vector2f(500, 240));
    boxOutline.setPosition(boxXposition, boxYposition);
    boxOutline.setFillColor(sf::Color::White);

    sf::RectangleShape boxContents(sf::Vector2f(490, 230));
    boxContents.setPosition(boxXposition+5, boxYposition+5);
    boxContents.setFillColor(sf::Color::Black);

    sf::RectangleShape yesBoxOutline(sf::Vector2f(70, 50));
    yesBoxOutline.setPosition(boxXposition + 150, boxYposition + 120);
    yesBoxOutline.setFillColor(sf::Color::White);

    sf::RectangleShape yesBoxContents(sf::Vector2f(66, 46));
    yesBoxContents.setPosition(boxXposition + 152, boxYposition + 122);
    yesBoxContents.setFillColor(sf::Color::Black);

    sf::RectangleShape noBoxOutline(sf::Vector2f(70, 50));
    noBoxOutline.setPosition(boxXposition + 270, boxYposition+120);
    noBoxOutline.setFillColor(sf::Color::White);

    sf::RectangleShape noBoxContents(sf::Vector2f(66, 46));
    noBoxContents.setPosition(boxXposition + 272, boxYposition+122);
    noBoxContents.setFillColor(sf::Color::Black);

    playAgainQuestion.setFont(font);
    playAgainQuestion.setString("Would like to play again?");
    playAgainQuestion.setCharacterSize(30); // in pixels, not points!
    playAgainQuestion.setFillColor(sf::Color::White);
    playAgainQuestion.setPosition(boxXposition + 60, boxYposition + 60);

    Yes.setFont(font);
    Yes.setString("Yes");
    Yes.setCharacterSize(25); // in pixels, not points!
    Yes.setFillColor(sf::Color::White);
    Yes.setPosition(boxXposition + 160, boxYposition + 130);

    No.setFont(font);
    No.setString("No");
    No.setCharacterSize(25); // in pixels, not points!
    No.setFillColor(sf::Color::White);
    No.setPosition(boxXposition + 289, boxYposition + 130);

    window.draw(boxOutline);
    window.draw(boxContents);
    window.draw(playAgainQuestion);
    window.draw(yesBoxOutline);
    window.draw(yesBoxContents);
    window.draw(Yes);
    window.draw(noBoxOutline);
    window.draw(noBoxContents);
    window.draw(No);
}

void GameWindow::renderGameOverScreen(sf::RenderWindow& window) {

    sf::Text gameOver;
    sf::Font font;
    font.loadFromFile("C:\\Users\\gonca\\source\\repos\\BreakoutClone\\assets\\breakout.ttf");

    gameOver.setFont(font);
    gameOver.setString("GAME OVER");
    gameOver.setCharacterSize(70); // in pixels, not points!
    gameOver.setFillColor(sf::Color::White);
    gameOver.setStyle(sf::Text::Bold);
    gameOver.setPosition(350, 500);

    window.draw(gameOver);

}

void GameWindow::InteractWithPlayAgainBox(sf::RenderWindow& window, int mouseClickX, int mouseClickY, int& lives, bool& gameRunning, int& score) {

    // YES BOX CLICKED
    if (mouseClickX > 440 && mouseClickX < 510 && mouseClickY>620 && mouseClickY < 670) {
        lives = 3;
        brickList.resize(0);
        brickObjectsCreation();
        score = 0;
    }

    // NO BOX CLICKED
    if (mouseClickX > 560 && mouseClickX < 630 && mouseClickY>620 && mouseClickY < 670) {
        gameRunning = false;
    }
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
    bool gameRunning = true;

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
        
        if (lives > 0) {

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

            drawLevel(window, brickList);

            window.display();

        }
        else {

            window.clear();
            renderUI(window, lives, score);
            drawLevel(window, brickList);

            if (gameRunning) {
                renderPlayAgainBox(window);
                if (event.mouseButton.button == sf::Mouse::Left) { InteractWithPlayAgainBox(window, event.mouseButton.x, event.mouseButton.y, lives, gameRunning, score); }
            }
            else {
                renderGameOverScreen(window);
            }
            
            window.display();
        }
    }

}