#include "ofApp.h"


void ofApp::setup()
{
    restart();
}


void ofApp::update()
{
    uint64_t now = ofGetElapsedTimeMillis();
    uint64_t timeSinceLastUpdate = now - lastRefresh;

    if (timeSinceLastUpdate > updateInterval)
    {
        snake.isDead = didSnakeCollide(snake);
        mealTimeForSnake(snake);
        snake.update();

        lastRefresh = now;
    }
}


void ofApp::draw()
{
    ofBackground(0);
    drawSnake(snake);

    ofPushStyle();
    ofSetColor(ofColor::red);
    drawSquare(food);
    ofPopStyle();
}


void ofApp::drawSquare(const Position& position)
{
    float x = ofMap(position.column, 0, boardColumns, 0, ofGetWidth());
    float y = ofMap(position.row, 0, boardRows, 0, ofGetHeight());

    float w = ofGetWidth() / boardColumns;
    float h = ofGetHeight() / boardRows;

    ofDrawRectangle(x, // this is my x
                    y, // this is my y
                    w,
                    h);
}


void ofApp::drawSnake(const Snake& snake)
{
    ofPushStyle();
    ofSetColor(ofColor::white);
    // what do i do to draw this snake?
    drawSquare(snake.head);
    ofPopStyle();

    ofPushStyle();
    ofSetColor(ofColor::yellow);
    for (Position p: snake.body)
    {
        drawSquare(p);
    }

    ofPopStyle();
}


void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_UP)
    {
        if (snake.direction != Snake::DOWN)
        {
            snake.direction = Snake::UP;
        }
    }
    else if (key == OF_KEY_DOWN)
    {
        if (snake.direction != Snake::UP)
        {
            snake.direction = Snake::DOWN;
        }
    }
    else if (key == OF_KEY_LEFT)
    {
        if (snake.direction != Snake::RIGHT)
        {
            snake.direction = Snake::LEFT;
        }
    }
    else if (key == OF_KEY_RIGHT)
    {
        if (snake.direction != Snake::LEFT)
        {
            snake.direction = Snake::RIGHT;
        }
    }
    else if (key == 'r')
    {
        restart();
    }
}


bool ofApp::didSnakeCollide(const Snake& snake)
{
    bool result = false;

    std::size_t minRow = 0;
    std::size_t maxRow = boardRows - 1;

    std::size_t minColumn = 0;
    std::size_t maxColumn = boardColumns - 1;

    if (snake.head.column == minColumn or
        snake.head.column == maxColumn or
        snake.head.row == minRow or
        snake.head.row == maxRow)
    {
        result = true;
    }
    else
    {
        for (Position p: snake.body)
        {
            if (p.row == snake.head.row and p.column == snake.head.column)
            {
                result = true;
                break;
            }
        }
    }

    return result;
}


void ofApp::mealTimeForSnake(Snake& snake)
{
    if (snake.head.row == food.row and snake.head.column == food.column)
    {
        // Grow the snake body length.
        snake.targetBodyLength += 4;

        if (updateInterval > 100)
        {
            updateInterval -= 50;
        }

        // Place the food in a new location.
        food.row = ofRandom(1, boardRows - 1);
        food.column = ofRandom(1, boardColumns - 1);
    }
}


void ofApp::restart()
{
    snake.head.row = boardRows / 2;
    snake.head.column = boardColumns / 2;
    snake.body.clear();
    snake.targetBodyLength = 0;

    food.row = ofRandom(1, boardRows - 1);
    food.column = ofRandom(1, boardColumns - 1);

    updateInterval = 200;

}

