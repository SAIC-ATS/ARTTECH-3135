#pragma once


#include "ofMain.h"
#include "ofxAssimpModelLoader.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void updateModel();
    void updateCamera();

    ofxAssimpModelLoader model;

    ofLight	light;

    ofCamera camera;

    ofVec3f noiseOffset;

    float rotationOffset;


    float alpha;
    ofVec3f smoothedModelCentroid;

};
