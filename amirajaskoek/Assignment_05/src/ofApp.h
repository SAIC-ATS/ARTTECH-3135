#pragma once

#include "ofMain.h"
#include "snow.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    std::vector<snow> snows;
};
