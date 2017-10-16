#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);


}


void ofApp::update()
{
    // std::vector<Particle>::iterator is the same as `auto` in this case.
    auto iter = particles.begin();

    while (iter != particles.end())
    {
        iter->update();

        if (iter->age > 120)
        {
            // Delete the particle from the collection.
            iter = particles.erase(iter);
        }
        else
        {
            iter++;
        }
    }
}


void ofApp::draw()
{
    // A "range-for" loop.
    for (Particle& p: particles)
    {
        int gray = ofMap(p.age, 0, 120, 255, 0);
        ofSetColor(gray, gray, 0);
        p.draw();
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    addParticleAtPosition(x, y);
}


void ofApp::addParticleAtPosition(float x, float y)
{
    Particle p;
    p.position.x = x;
    p.position.y = y;
    p.velocity.x = ofRandom(-10, 10);
    p.velocity.y = ofRandom(-10, 10);

    // Add the particle instance to our collection of particles.
    particles.push_back(p);

}













