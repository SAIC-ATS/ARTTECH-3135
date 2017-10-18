#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);

    grayscalePixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
}

void ofApp::update()
{
    threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);

    grabber.update();

    if (grabber.isFrameNew())
    {
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                if (grabber.getPixels().getColor(x, y).getBrightness() > threshold)
                {
                    grayscalePixels.setColor(x, y, ofColor(0));
                }
                else
                {
                    grayscalePixels.setColor(x, y, ofColor(255));
                }
            }
        }

        grayscaleTexture.loadData(grayscalePixels);
    }
}

void ofApp::draw()
{
    grayscaleTexture.draw(0, 0);

    ofDrawBitmapStringHighlight("Threshold: " + ofToString(threshold), 14, 14);
}
