#include "ofApp.h"


void ofApp::setup()
{
    int numParticles = 100;

    for (int i = 0; i < numParticles; i++)
    {
        addParticle();
        addParticle3D();
        addParticleCube();
    }
}


void ofApp::update()
{
    for (auto& p: particles)
    {
        p->update();
    }
}


void ofApp::draw()
{
    cam.begin();

    for (auto& p: particles)
    {
        p->draw();
    }

    cam.end();
}


void ofApp::addParticle()
{
    // new / delete
    auto p = std::make_shared<Particle>();

    p->position.x = ofRandomWidth();
    p->position.y = ofRandomHeight();
    p->velocity.x = ofRandom(-10, 10);
    p->velocity.y = ofRandom(-10, 10);

    particles.push_back(p);
}


void ofApp::addParticle3D()
{
    // new / delete
    auto p = std::make_shared<Particle3D>();

    p->velocity.x = ofRandom(-10, 10);
    p->velocity.y = ofRandom(-10, 10);
    p->velocity.z = ofRandom(-10, 10);

    p->angularVelocity.x = ofRandom(-2, 2);
    p->angularVelocity.y = ofRandom(-2, 2);
    p->angularVelocity.z = ofRandom(-2, 2);

    particles.push_back(p);

}


void ofApp::addParticleCube()
{
    auto p = std::make_shared<ParticleCube>();

    p->velocity.x = ofRandom(-10, 10);
    p->velocity.y = ofRandom(-10, 10);
    p->velocity.z = ofRandom(-10, 10);

    p->angularVelocity.x = ofRandom(-2, 2);
    p->angularVelocity.y = ofRandom(-2, 2);
    p->angularVelocity.z = ofRandom(-2, 2);

    particles.push_back(p);
}



void ofApp::mousePressed(int x, int y, int button)
{

}
































