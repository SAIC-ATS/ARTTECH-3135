#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);

    selectedColor = ofColor(255, 127, 0);
}

void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        // Do something if and only if the frame is new and unique.
        // Copy camera pixels to our pixels.
        pixels = grabber.getPixels();

        for (int x = 0; x < pixels.getWidth(); x++)
        {
            for (int y = 0; y < pixels.getHeight(); y++)
            {
                ofColor currentColor = pixels.getColor(x, y);

                float colorDistance = ofDist(currentColor.r,
                                             currentColor.g,
                                             currentColor.b,
                                             selectedColor.r,
                                             selectedColor.g,
                                             selectedColor.b);


                float colorThreshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 1000);

                if (colorDistance > colorThreshold)
                {
                    pixels.setColor(x, y, ofColor::black);
                }
            }
        }


        // Upload pixels to a texture on the graphics card so we can draw it.
        texture.loadData(pixels);
    }
}

void ofApp::draw()
{
    ofSetColor(255);
    ofFill();
    texture.draw(0, 0);

    ofSetColor(selectedColor);
    ofFill();
    ofDrawRectangle(0, 0, 30, 30);

}













