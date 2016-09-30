#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void setup() override;
	void update() override;
    void draw() override;

    void mousePressed(int x, int y, int mouse) override;
    void mouseDragged(int x, int y, int mouse) override;
    void mouseReleased(int x, int y, int mouse) override;
    void keyPressed(int key) override;

    void updateCounter();


    ofPolyline polyline;

    ofPolyline resampledPolyline;
    ofPolyline outerPolyline;
    ofPolyline innerPolyline;

    float counter = 0;
    float counterIncrement = 0.01;
    bool counterPalindrome = false;
    
    bool needsResample = false;

};
