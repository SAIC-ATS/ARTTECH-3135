#include "ofApp.h"


void ofApp::setup()
{
    ball0.position.y = ofGetHeight() / 3;
    ball0.velocity.x = 10;
    ball0.velocity.y = -10;
    ball0.acceleration.y = 3;

    ball1.position.y = ofGetHeight() / 3 * 2;
    ball1.velocity.x = 2;
    ball0.velocity.y = -10;
    ball1.acceleration.y = 3;

    ball2.position.y = ofGetHeight() / 3 * 2.5;
    ball2.velocity.x = 1;
    ball0.velocity.y = -10;
    ball2.acceleration.y = 3;

}

void ofApp::update()
{
    ball0.update();
    ball1.update();
    ball2.update();
}

void ofApp::draw()
{
    ofBackground(0);
    ball0.draw();
    ball1.draw();
    ball2.draw();
}
