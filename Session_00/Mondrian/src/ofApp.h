#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    // This is an image of the Mondrian painting that will be our guide.
    // we will draw it in the background of our sketch.
    //
    // We will load this image in the void ofApp::setup() function.
    ofImage image;

    // These are our custom Mondian colors. We will define them
    //
    // We will set these colors in the void ofApp::setup() function.
    ofColor mondrianRed;
    ofColor mondrianBlue;
    ofColor mondrianYellow;
    ofColor mondrianBlack;
    ofColor mondrianWhite;

};
