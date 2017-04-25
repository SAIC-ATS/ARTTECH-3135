#include "ofApp.h"


void ofApp::setup()
{
    int numberOfParticles = 100;

    for (std::size_t i = 0; i < numberOfParticles; i++)
    {
        Particle p;
        p.position.x = ofRandom(0, ofGetWidth());
        p.position.y = -50;
        p.velocity.x = 0;
        p.velocity.y = ofRandom(0.1, 4);
        p.drag = 1;
        particles.push_back(p);

        // Define a target.
        targets.push_back(ofVec3f(ofMap(i, 0, numberOfParticles, 0, ofGetWidth()), ofGetHeight() / 2, 0));
    }

}


void ofApp::update()
{
    for (auto& p: particles)
    {
        p.update();

        if (p.position.y > ofGetHeight())
        {
            p.position.y = -50;
            p.previousPosition.x = p.position.x;
            p.previousPosition.y = p.position.y;
        }
    }

    blend = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1, true);
}


void ofApp::draw()
{
    ofBackground(0);

    for (std::size_t i = 0; i < particles.size(); ++i)
    {
        ofPushMatrix();

        ofVec3f blendedPosition = particles[i].position.getInterpolated(targets[i], blend);
        ofTranslate(blendedPosition);

        ofDrawCircle(0, 0, 10, 10);
        ofPopMatrix();
    }

}
