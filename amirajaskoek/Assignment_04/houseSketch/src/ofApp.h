#pragma once

#include "ofMain.h"
#include "house.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
    std::vector<House> myHouses;
};
