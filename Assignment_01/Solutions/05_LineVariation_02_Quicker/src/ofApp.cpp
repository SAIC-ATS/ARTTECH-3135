#include "ofApp.h"


void ofApp::draw()
{
//    angleDeg += angleIncrementDeg;

    if (angleDeg > 45 || angleDeg < 0)
    {
        angleIncrementDeg *= -1;
    }

    // Make black background.
    ofBackground(0);

    // Set a few helpful variables.
    float lineSpacing = 16;
    float width = 512;
    float height = 512;

    ofPushMatrix();
    ofTranslate(width / 2, height / 2);
    ofRotateZDeg(angleDeg);

    // Draw vertical lines to the left (-x direction) startig at the origin.
    for (float x = 0; x >= -width; x -= lineSpacing)
    {
        // -height to ensure vertical overlap after rotation.
        ofDrawLine(x, -height, x, height);
    }

    // Draw vertical lines to the left (-x direction) startig at the origin.
    for (float y = -height; y <= height; y += lineSpacing)
    {
        ofDrawLine(0, y, width, y);
    }

    ofPopMatrix();
}
