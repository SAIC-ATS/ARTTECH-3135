#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void setupOnlyVertices();
    void setupVerticesAndColors();
    void setupVerticesColorsAndIndices();

    ofMesh mesh;

};
