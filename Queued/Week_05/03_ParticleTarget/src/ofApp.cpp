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

    if (goingUp)
    {
        blend += 0.01;
    }
    else
    {
        blend -= 0.01;
    }

    blend = ofClamp(blend, 0, 1);
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

void ofApp::keyPressed(int key)
{
    goingUp = !goingUp;
}

