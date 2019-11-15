#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void keyPressed(int key) override;

    ofMesh meshSphere;
    ofVboMesh vboMeshSphere;

    ofEasyCam cam;

    glm::vec3 noiseOffset;
    glm::vec3 noiseStep;

    bool drawVboMesh = true;

};
