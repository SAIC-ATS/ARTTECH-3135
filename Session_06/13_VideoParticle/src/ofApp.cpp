#include "ofApp.h"


void ofApp::setup()
{
    // Set up our grabber.
    grabber.setup(640, 480);
    
    int subsectionWidth = 80;
    int subsectionHeight = 60;
    
    for (int x = 0; x < grabber.getWidth(); x += subsectionWidth)
    {
        for (int y = 0; y < grabber.getHeight(); y += subsectionHeight)
        {
            Particle p;
            p.position.x = x;
            p.position.y = y;
            p.color = ofColor::white;
            p.texture = grabber.getTexture();
            p.subSection = ofRectangle(x, y, subsectionWidth, subsectionHeight);
            particles.push_back(p);
        }
    }
}


void ofApp::update()
{
    grabber.update();
    
    for (Particle& particle: particles)
    {
        particle.texture = grabber.getTexture();
        particle.update();
    }
}


void ofApp::draw()
{
    for (Particle& particle: particles)
    {
        particle.draw();
    }
}


void ofApp::keyPressed(int key)
{
    for (Particle& particle: particles)
    {
        particle.velocity.x = ofRandom(-1, 1);
        particle.velocity.y = ofRandom(-1, 1);
        
        particle.angularAcceleration.x = ofRandom(-0.1, 0.1);
        particle.angularAcceleration.y = ofRandom(-0.1, 0.1);
        particle.angularAcceleration.z = ofRandom(-0.1, 0.1);
        
        particle.acceleration.y = 0.1;
    }
}
