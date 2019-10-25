#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    void keyPressed(int key) override;

    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;

    // Create an alias / shortcut for a polyline (collection of points).
    typedef std::vector<glm::vec3> Polyline;

    // The current polyline that we are drawing.
    Polyline currentPolyline;
    
    
    
    // ofPolyine
    // std::vector<Polyline> // This is a collection of polyline.
    
};

