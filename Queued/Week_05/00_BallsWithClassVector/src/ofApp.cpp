#include "ofApp.h"


void ofApp::setup()
{
    int numberOfBallsToCreate = 10;

    for (int i = 0; i < numberOfBallsToCreate; i++)
    {
        Ball myBall;
        myBall.position.x = ofRandomWidth();
        myBall.position.y = ofRandomHeight();
        myBall.velocity.x = ofRandom(-10, 10);
        myBall.velocity.y = ofRandom(-10, 10);
        crowd.push_back(myBall);
    }
}

void ofApp::update()
{
    for (Ball& ball: crowd)
    {
        ball.update();
    }
}

void ofApp::draw()
{
    ofBackground(0);

    for (Ball& ball: crowd)
    {
        ball.draw();
    }
}
