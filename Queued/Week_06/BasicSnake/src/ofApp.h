#pragma once


#include "ofMain.h"
#include "Snake.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void drawSquare(const Position& position);

    void drawSnake(const Snake& snake);

    void keyPressed(int key);

    bool didSnakeCollide(const Snake& snake);

    void mealTimeForSnake(Snake& snake);

    void restart();

    // Board variables.
    int boardRows = 30;
    int boardColumns = 40;

    Snake snake;
    Position food;

    uint64_t updateInterval = 200;
    uint64_t lastRefresh = 0;

};
