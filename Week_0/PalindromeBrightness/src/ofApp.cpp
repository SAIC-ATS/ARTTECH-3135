#include "ofApp.h"


void ofApp::draw()
{
    // Check to see if brightness is increasing.
    if (isBrightnessIncreasing == true)
    {
        // Since it is increasing, then increase brightness by 1.
        brightness = brightness + 1;

        // If our brightness went above our threshold of 255, then set to
        // our maximum and get ready to start decreasing next draw loop.
        if (brightness > 255)
        {
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
        if (brightness < 0)
        {
            brightness = 0;
            isBrightnessIncreasing = true;
        }
    }

    // Tell the drawing system that you want to fill all subsequent shapes.
    ofFill();

    // Set the active color (a grayscale brightness in this case).
    ofSetColor(brightness);

    // Draw a rectangle that fills the whole screen.
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

}
