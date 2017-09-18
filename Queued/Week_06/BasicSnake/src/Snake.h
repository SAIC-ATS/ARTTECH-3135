#pragma once


#include "ofMain.h"
#include "Position.h"


class Snake
{
public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    // This function will be called when we update our game.
    void update();

    // This is the current direction of the snake.
    Direction direction = RIGHT;

    // This is the current head of the snake.
    Position head;

    // This is the history of our positions (a.k.a. the body of the snake).
    std::vector<Position> body;

    // This is the maximum length for the current snake.
    // After it eats, it won't instantly be this length, but it can grow to be
    // this "length" big.
    std::size_t targetBodyLength = 0;

    // This is true when it collides with something or has met its death by
    // some other means.
    bool isDead = false;

};
