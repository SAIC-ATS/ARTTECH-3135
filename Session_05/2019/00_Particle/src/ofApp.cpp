#include "ofApp.h"


void ofApp::setup()
{
    // ofSetFrameRate(1)
    
    ofBackground(80);
    position.x = ofGetWidth() / 2;
    position.y = 0;
    position.z = 0;
    
    // Alternative syntax.
    velocity = { 0, 0, 0 };

    // Acceleration due to gravity.
    // We only accelerate in the +y direction (down on screen).
    acceleration = { 0, .5, 0 };

}


void ofApp::update()
{
    //    position.x = position.x + velocity.x;
    //    position.y = position.y + velocity.y;
    //    position.z = position.z + velocity.z;
    
    // is ...
    
    // position = position + velocity;

    // is ...
    
    velocity += acceleration;
    position += velocity;

    // "Bounce on the bottom condition."
    if (position.y + ballRadius > ofGetHeight())
    {
        // Change its direction!
        velocity.y = velocity.y * -1;
        
        // Steal some of its velocity.
        velocity.y = velocity.y * 0.90;
        
        // Reset the ball to the "correct" position.
        position.y = ofGetHeight() - ballRadius;
    }
}


void ofApp::draw()
{
    ofDrawCircle(position, ballRadius);
}

