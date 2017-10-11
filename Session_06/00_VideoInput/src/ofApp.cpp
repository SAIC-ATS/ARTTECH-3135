#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);

}

void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        // Do something if and only if the frame is new and unique.
        // Copy camera pixels to our pixels.
        pixels = grabber.getPixels();

        // Upload pixels to a texture on the graphics card so we can draw it.
        texture.loadData(pixels);
    }
}

void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(pixels.getWidth(), 0, 0);
    ofScale(-1, 1, 1);

    for (int x = 0; x < pixels.getWidth(); x += 30)
    {
        for (int y = 0; y < pixels.getHeight(); y += 30)
        {
            ofColor pixelColor = pixels.getColor(x, y);

            float brightness = pixelColor.getBrightness();

            float radius = ofMap(brightness, 0, 255, 2, 40);

            ofSetColor(pixelColor);
            ofDrawCircle(x, y, radius);
        }
    }

    ofPopMatrix();

}













