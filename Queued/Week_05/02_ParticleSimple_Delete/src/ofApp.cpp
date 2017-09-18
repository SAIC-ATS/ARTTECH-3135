#include "ofApp.h"


void ofApp::setup()
{
    smoke.load("s3.png");
}


void ofApp::update()
{
    auto particleIterator = particles.begin();

    while (particleIterator != particles.end())
    {
        particleIterator->update();

        if (particleIterator->age > ofRandom(10, 50))
        {
            particleIterator = particles.erase(particleIterator);
        }
        else
        {
            ++particleIterator;
        }
    }
}


void ofApp::draw()
{
    ofBackground(0);

    ofEnableBlendMode(OF_BLENDMODE_ADD);

    for (auto& p: particles)
    {
        smoke.draw(p.position);
        // p.draw();
    }

    ofDisableBlendMode();

    ofDrawBitmapString(ofToString(particles.size()), 20, 20);

}



void ofApp::mousePressed(int x, int y, int button)
{
    int numberOfParticles = 100;

    for (int i = 0; i < numberOfParticles; i++)
    {
        Particle p;
        p.position.x = x;
        p.position.y = y;
        p.velocity.x = ofRandom(-10, 10);
        p.velocity.y = ofRandom(-10, 10);
        p.drag = 1;
        particles.push_back(p);
    }

    std::cout << "mouse pressed" << std::endl;

}



