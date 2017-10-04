#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);

    int numParticles = 100;

    for (int i = 0; i < numParticles; i++)
    {
        Particle p;
        // Set initial positions.
        p.position.x = ofGetWidth() / 2;
        p.position.y = ofGetHeight() / 2;
        p.position.z = 0;

        // Set initial velocities.
        p.velocity.x = ofRandom(-10, 10);
        p.velocity.y = ofRandom(-10, 10);
        p.velocity.z = 0;

        // Set inital accelerations.
        p.acceleration.x = 0;
        p.acceleration.y = 0;
        p.acceleration.z = 0;

        // Set radius.
        p.radius = ofRandom(10, 30);

        // Set color.
        p.color = ofColor::fromHsb(ofRandom(255), 255, 255);

        // Add a copy to our vector.
        particles.push_back(p);
    }
}


void ofApp::update()
{
    for (Particle& particle: particles)
    {
        particle.update();

        // Challenge 1) if the particle goes off the screen ...
        // set its position back to the center.

    }
}


void ofApp::draw()
{
    for (Particle& particle: particles)
    {
        particle.draw();
    }
}
