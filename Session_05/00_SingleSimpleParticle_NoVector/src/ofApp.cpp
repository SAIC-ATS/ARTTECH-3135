#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);

    // Set up an initial particle.
    p.x = ofGetWidth() / 2;
    p.y = ofGetHeight() / 2;

    p.vx = 10;
    p.vy = 10;

    p.ay = 5;
}


void ofApp::update()
{
    // Update the particle.
    p.update();

    // Check the right wall.
    if (p.x + p.radius > ofGetWidth())
    {
        p.vx = p.vx * -1;
        p.x = ofGetWidth() - p.radius;
    }

    // Check the left wall.
    if (p.x - p.radius < 0)
    {
        p.vx = p.vx * -1;
        p.x = 0 + p.radius;
    }

    // Check the bottom wall.
    if (p.y + p.radius > ofGetHeight())
    {
        p.vy = p.vy * -1;
        p.y = ofGetHeight() - p.radius;
    }

    // Check the top wall.
    if (p.y - p.radius < 0)
    {
        p.vy = p.vy * -1;
        p.y = 0 + p.radius;
    }

}


void ofApp::draw()
{
    p.draw();
}
