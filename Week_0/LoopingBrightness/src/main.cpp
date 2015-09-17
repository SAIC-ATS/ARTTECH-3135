#line 1 "LoopingBrightness"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "LoopingBrightness"
// Our single value 0-255 for representing brightness.
int brightness = 0;

// The draw function is called repeatedly.
void draw() {
    // Since it is increasing, then increase brightness by 1.
    brightness = brightness + 1;
        
    // If our brightness went above our threshold of 255, then set it back to 
    // our minimum.
    if (brightness > 255) {
        brightness = 0;
    }
    
    // Tell the drawing system that you want to fill all subsequent shapes.
	ofFill();
	
	// Set the active color (a grayscale brightness in this case).
	ofSetColor(brightness);
	
	// Draw a rectangle that fills the whole screen.
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

