#include "ofApp.h"


void ofApp::setup()
{
    pixels.allocate(256, 256, OF_PIXELS_RGB);

    for (int x = 0; x < pixels.getWidth(); x++)
    {
        for (int y = 0; y < pixels.getHeight(); y++)
        {
            // Version 1.
            // int redComponent = ofMap(x, 0, pixels.getWidth(), 255, 0);
            // int blueComponent = ofMap(x, 0, pixels.getWidth(), 0, 255);
            // ofColor color(redComponent, 0, blueComponent);

            // Version 2.
            // int redComponent = 255 - x;
            // int blueComponent = x;
            // ofColor color(redComponent, 0, blueComponent);

            // Version 3.
            ofColor startColor(255, 0, 0);
            ofColor endColor(0, 0, 255);
            float amount = ofMap(x, 0, pixels.getWidth(), 0, 1); // 0 - 1;
            // Note that we can get the color "lerped" by the amount.
            // A "lerp" is a linear interpolation between two colors.
            ofColor color = startColor.getLerped(endColor, amount);
            pixels.setColor(x, y, color);
        }
    }

    texture.loadData(pixels);
}

void ofApp::draw()
{

    texture.draw(0, 0);
}













