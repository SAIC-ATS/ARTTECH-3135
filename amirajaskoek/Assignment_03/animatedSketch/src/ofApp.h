#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        float xOffset = 0;
        float xIncrement = 0.01;

		};
