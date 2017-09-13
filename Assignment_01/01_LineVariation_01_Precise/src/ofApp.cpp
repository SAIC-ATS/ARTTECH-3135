#include "ofApp.h"


void ofApp::draw()
{
    // Make black background.
    ofBackground(0);

    // Set a few helpful variables.
    float width = 512;
    float height = 512;

    float parallelLineSpacing = 16;
    float rotationAngleDeg = -45;

    // To calculate the true parallel spacing, we have to project the correct
    // spacing based on the angle we are using.
    float trueXSpacing = std::abs(parallelLineSpacing / std::cos(ofDegToRad(90 - rotationAngleDeg)));

    // We start at 0 and go double width to cover most angles.
    for (float x = 0; x <= width * 2; x += trueXSpacing)
    {
        // We know what the starting point for our line should be.
        float x0 = x;
        float y0 = 0;

        // We also know the ending y for our line.
        float y1 = height;

        // But we don't know the ending x! So we can calulate it.
        // We know that the tangent of our angle is
        //
        // tan(Θ) = Δy / Δx;
        //
        // tan(ofDegToRad(rotationAngleDeg)) = Δy / Δx;
        //
        // tan(ofDegToRad(rotationAngleDeg)) = (y1 - y0) / (x1 - x0);
        //
        // (y1 - y0) / tan(ofDegToRad(rotationAngleDeg)) = (x1 - x0);
        //
        // (y1 - y0) / tan(ofDegToRad(rotationAngleDeg)) = (x1 - x0);
        //
        // x1 = (y1 - y0) / tan(ofDegToRad(rotationAngleDeg)) + x0);

        float x1 = (y1 - y0) / std::tan(ofDegToRad(rotationAngleDeg)) + x0;

        ofDrawLine(x0, y0, x1, y1);
    }
}
