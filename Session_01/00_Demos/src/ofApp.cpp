#include "ofApp.h"


void ofApp::draw()
{
    ofBackground(0);

    float w = ofGetWidth();
    float h = ofGetHeight();
    float cx = w / 2;
    float cy = h / 2;

    // Declare an instance of the ofPath class.
    ofPath path;

    path.setCircleResolution(64);

    // Define the drawing operations.
    path.lineTo(0, 0);
    path.lineTo(w, 0);
    path.lineTo(w, h);
    path.lineTo(0, h);

    path.circle(cx, cy, 256);
    path.circle(cx, cy, 128);
    path.circle(cx, cy, 64);

    // Draw it.
    path.draw();

}
