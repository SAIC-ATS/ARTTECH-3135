#include "ofApp.h"


void ofApp::setup()
{
    int numberOfParticles = 100;

    smoke.load("s3.png");

    for (int i = 0; i < numberOfParticles; i++)
    {
        Particle p;
        p.position.x = ofGetWidth() / 2;
        p.position.y = ofGetHeight() / 2;
        p.velocity.x = ofRandom(-10, 10);
        p.velocity.y = ofRandom(-10, 10);
        p.drag = 1;
        particles.push_back(p);
    }
}


void ofApp::update()
{
    if (ofGetMousePressed()) return;


    ofRectangle screenRectangle(0, 0, ofGetWidth(), ofGetHeight());

    for (auto& p: particles)
    {
        p.update();

        if (p.age > ofRandom(10, 50))
        {
            p.position.x = ofGetWidth() / 2;
            p.position.y = ofGetHeight() / 2;

            p.previousPosition.x = p.position.x;
            p.previousPosition.y = p.position.y;

            p.age = 0;
        }


//        if (!screenRectangle.inside(p.position))
//        {
//            p.position.x = ofGetWidth() / 2;
//            p.position.y = ofGetHeight() / 2;
//
//            p.previousPosition.x = p.position.x;
//            p.previousPosition.y = p.position.y;
//        }
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

}
