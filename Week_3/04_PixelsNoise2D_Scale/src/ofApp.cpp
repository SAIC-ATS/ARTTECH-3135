#include "ofApp.h"


void ofApp::setup()
{
    pixels.allocate(256, 256, OF_PIXELS_RGB);

}

void ofApp::draw()
{
    for (int x = 0; x < pixels.getWidth(); x++)
    {
        for (int y = 0; y < pixels.getHeight(); y++)
        {
            float scale = ofMap(mouseX, 0, ofGetWidth(), 0.5, 0.0001,  true);
            float color = 255 * ofNoise(x * scale, y * scale);
            pixels.setColor(x, y, ofColor(color));
        }
    }

    texture.loadData(pixels);

    texture.draw(0, 0);
}













