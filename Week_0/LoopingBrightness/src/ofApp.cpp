#include "ofApp.h"


void ofApp::draw()
{
	// Since it is increasing, then increase brightness by 1.
	brightness = brightness + 1;

	// If our brightness went above our threshold of 255, then set it back to
	// our minimum.
	if (brightness > 255)
	{
		brightness = 0;
	}

	// Tell the drawing system that you want to fill all subsequent shapes.
	ofFill();

	// Set the active color (a grayscale brightness in this case).
	ofSetColor(brightness);

	// Draw a rectangle that fills the whole screen.
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}
