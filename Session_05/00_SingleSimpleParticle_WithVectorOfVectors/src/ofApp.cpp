#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);

    // Load a little sound file.
    sound.load("ball.wav");

    // Do we want multiple sounds to play?
    sound.setMultiPlay(true);

    // Set up an initial particle.
    p.position.x = ofGetWidth() / 2;
    p.position.y = ofGetHeight() / 2;

    p.velocity.x = 10;
    p.velocity.y = 10;

    p.acceleration.y = 1;
}


void ofApp::update()
{
    // Update the particle.
    p.update();

    // Check the right wall.
    if (p.position.x + p.radius > ofGetWidth())
    {
        p.velocity.x = p.velocity.x * -0.98;
        p.position.x = ofGetWidth() - p.radius;
        sound.play();
    }

    // Check the left wall.
    if (p.position.x - p.radius < 0)
    {
        p.velocity.x = p.velocity.x * -0.98;
        p.position.x = 0 + p.radius;
        sound.play();
    }

    // Check the bottom wall.
    if (p.position.y + p.radius > ofGetHeight())
    {
        p.velocity.y = p.velocity.y * -0.98;
        p.position.y = ofGetHeight() - p.radius;
        sound.play();
    }

    // Check the top wall.
    if (p.position.y - p.radius < 0)
    {
        p.velocity.y = p.velocity.y * -0.98;
        p.position.y = 0 + p.radius;
        sound.play();
    }

}


void ofApp::draw()
{
    p.draw();
}
