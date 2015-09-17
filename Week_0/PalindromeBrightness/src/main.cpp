#line 1 "GoingUpAndDown"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "GoingUpAndDown"
// Sequence
// Repetition
// Conditional Branching

// Our single value 0-255 for representing brightness.
int brightness = 0;

// If this is true, then we are increasing in brightness, otherwise decreasing.
bool isBrightnessIncreasing = true;

// The draw function is called repeatedly.
void draw() {
    
    // Check to see if brightness is increasing.
    if (isBrightnessIncreasing == true) {
        // Since it is increasing, then increase brightness by 1.
        brightness = brightness + 1;
        
        // If our brightness went above our threshold of 255, then set to 
        // our maximum and get ready to start decreasing next draw loop.
        if (brightness > 255) {
            brightness = 255;
            isBrightnessIncreasing = false;
        }
    }
    else // ... otherwise our brightness is not increasing - so it is decreasing.
    {
        // Since it is decresing, decrease the brightness by 1.
        brightness = brightness - 1;
        
        // If our brightness went below our threshold of 0, then set to 
        // our minimum and get ready to start increasing next draw loop.
        if (brightness < 0) {
            brightness = 0;
            isBrightnessIncreasing = true;
        }
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

