#pragma once


#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"


class SimpleParticle: public ofVec3f
{
public:
    SimpleParticle(const ofVec3f& position, const ofVec3f& velocity):
        ofVec3f(position),
        velocity(velocity),
        born(ofGetElapsedTimeMillis())
    {
    }

    ofVec3f lastPosition;

    ofVec3f velocity;
    uint64_t born;
};


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    ofxAssimpModelLoader model;

    std::vector<ofVec3f> velocities;

    std::size_t currentBuffer = 0;
    ofMesh doubleBuffer[2];

    std::vector<SimpleParticle> particles;

    ofMesh m0;
    ofMesh m1;
    ofMesh m3;

    ofMesh particleMesh;

    ofEasyCam cam;

    bool firstTime = true;
};
