#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;
    void keyPressed(int key) override;
    void mousePressed(int x, int y, int button) override;

    ofPrimitiveMode currentPrimitiveMode = OF_PRIMITIVE_TRIANGLES;
    
    ofMesh mesh;
    bool drawMeshPoints = false;
    bool drawMeshFill = true;
    bool drawMeshWireframe = false;
    
    ofPolyline polyline;
    bool drawPoly = false;
    bool drawPolyNormals = false;
    bool drawPolyTangents = false;
    bool drawPolyCurves = false;
    
    bool drawVertexIndicies = true;

    std::string makeInfoString() const;
    std::string getPrimitiveModeString(ofPrimitiveMode mode) const;

};
