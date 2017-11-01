#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    int randX;
    int randY;
    int counterX;
    int counterY;
    int targetX;
    int targetY;
    int counter;
    float fade = 5;
    bool colorUp = true;
    
    void randomCycle();
};
