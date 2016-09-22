#include "ofApp.h"


void ofApp::setup()
{
    // Allocate the memory for our pixels.
    pixels.allocate(256, 256, OF_PIXELS_RGB);

    // Iterate through the pixels.
    for (int x = 0; x < pixels.getWidth(); x++)
    {
        for (int y = 0; y < pixels.getHeight(); y++)
        {
            // Map the red component to the x values ...
            int redComponent = ofMap(x, 0, pixels.getWidth(), 255, 0);

            // You could also do it like this ...
            // int redComponent = 255 - x;

            // Create a color.
            ofColor color(redComponent, 0, 0);

            // Set the color at the current position.
            pixels.setColor(x, y, color);
        }
    }

    // Load our pixels into a texture.
    texture.loadData(pixels);

}

void ofApp::draw()
{
    // Draw the uploaded texture.
    texture.draw(0, 0);
}













