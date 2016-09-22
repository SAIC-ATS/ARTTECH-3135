#include "ofApp.h"


void ofApp::setup()
{
    pixels.allocate(256, 256, OF_PIXELS_RGB);
    pixels.set(0);
}

void ofApp::draw()
{
    ofBackground(255);

    for (int x = 0; x < pixels.getWidth(); x++)
    {
        for (int y = 0; y < pixels.getHeight(); y++)
        {
            float scaleX = ofMap(mouseX, 0.1, ofGetWidth(), 0, 1000,  true);
            float scaleY = ofMap(mouseY, 0.1, ofGetHeight(), 0, 1000, true);

            float offsetX = ofMap(mouseX, 0.1, ofGetWidth(), 0, 10,  true);
            float offsetY = ofMap(mouseY, 0.1, ofGetHeight(), 0, 10, true);

            // For each channel, R, G, B we get a slightly different noise value.
            float noiseR = 255 * ofNoise(x / scaleX + offsetX * 1, y / scaleY + offsetY * 1);
            float noiseG = 255 * ofNoise(x / scaleX, y / scaleY);
            float noiseB = 255 * ofNoise(x / scaleX + offsetX * 2, y / scaleY + offsetY * 2);

            ofColor color = ofColor(noiseR, noiseG, noiseB);
            pixels.setColor(x, y, color);
        }
    }

    texture.loadData(pixels);
    texture.draw(0, 0);
}













