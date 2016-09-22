#include "ofApp.h"


void ofApp::setup()
{
    // We must allocate the pixels.
    pixels.allocate(256, 256, OF_PIXELS_RGB);

    // Iterate through the pixels.
    for (int x = 0; x < pixels.getWidth(); x++)
    {
        for (int y = 0; y < pixels.getHeight(); y++)
        {
            // Create a color based on the position!
            // Red corresponds to X
            // Green corresponds to Y
            ofColor color = ofColor(x, 0, 0);
            pixels.setColor(x, y, color);
        }
    }

    // Load our pixels into a texture to draw.
    texture.loadData(pixels);
}

void ofApp::draw()
{
    // Draw the texture!
    texture.draw(0, 0);
}
