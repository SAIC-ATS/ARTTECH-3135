#pragma once

#include "ofMain.h"
#include "Blob.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
    
    Blob blob;
    
    std::vector<Blob> blobList;
};
