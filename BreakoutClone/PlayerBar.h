#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;

class PlayerBar {
public:
    
    static const int length = 100;
    vector<float> playerCoords;

public:
    PlayerBar();
    ~PlayerBar();

    void drawPlayerBar(sf::RenderWindow& window);

    void updateBarPosition(sf::RenderWindow& window);

};