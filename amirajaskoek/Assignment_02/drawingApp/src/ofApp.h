#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
        void draw();
        void circleRotate();
        void flamesBrush();
        void starBrush();
        void lines();
        void eraser();
        void randomBoi();
        void gude();
    
        ofImage flameBrush;
        ofImage star;
        ofImage gudetama;
    
		};
