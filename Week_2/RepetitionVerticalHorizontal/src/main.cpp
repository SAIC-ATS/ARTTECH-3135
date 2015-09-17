#line 1 "RepetitionVerticalHorizontal"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "RepetitionVerticalHorizontal"
void setup() {
    ofSetWindowShape(512, 512); // Set the initial window size.
    ofBackground(0); // Set the background to 0 (black).
}

void draw() {
    // Set the drawing color to white.
    ofSetColor(255);

    // Draw vertical lines every 5 pixels while 'x' is less than the window width.
    for (int x = 0; x < ofGetWidth(); x += 5)
    {
	    ofLine(x, 0, x, ofGetHeight());
    }
    
    // Draw horizontal lines every 5 pixels while 'y' is less than the window height.
    for (int y = 0; y < ofGetHeight(); y += 5)
    {
	    ofLine(0, y, ofGetWidth(), y);
    }
    
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

