#include "ofApp.h"


// ofBaseApp has a variety of functions that you can override and use.
// draw is a function that draws to the screen and loops over and over again.
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
    // For more about this function see:
    // http://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofFill
    ofFill();

    // Set the active color (a grayscale brightness in this case).
    // For more about this function and its parameters see:
    // http://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofSetColor
    ofSetColor(brightness);

    // Draw a rectangle that fills the whole screen.
    // For more about this function and its parameters see:
    // http://openframeworks.cc/documentation/graphics/ofGraphics/#!show_ofDrawRectangle
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

}
