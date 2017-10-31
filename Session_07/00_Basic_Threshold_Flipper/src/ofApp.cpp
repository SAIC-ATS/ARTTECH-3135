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
                float brightness = grabber.getPixels().getColor(x, y).getBrightness();
                
                if (brightness > threshold)
                {
                    grayscalePixels.setColor(x, y, ofColor(255));
                }
                else
                {
                    float lastBrightness = grayscalePixels.getColor(x, y).getBrightness();
                    lastBrightness = ofClamp(lastBrightness - 0.1, 0, 255);
                    grayscalePixels.setColor(x, y, ofColor(lastBrightness));
                }
            }
        }

        grayscaleTexture.loadData(grayscalePixels);
    }
}

void ofApp::draw()
{
    ofBackground(255, 255, 0);
    for (int x = 0; x < grayscalePixels.getWidth(); x+=40)
    {
        for (int y = 0; y < grayscalePixels.getHeight(); y+=40)
        {
            float brightness = grabber.getPixels().getColor(x, y).getBrightness();
            
            ofPushMatrix();
            ofTranslate(x, y);
            ofRotateYDeg(ofMap(brightness, 0, 255, 0, 180));
            ofSetColor(grabber.getPixels().getColor(x, y));
            ofDrawRectangle(0-40/2, 0-40/2, 40, 40);
            ofPopMatrix();
            
        }
    }
    
    
    ofDrawBitmapStringHighlight("Threshold: " + ofToString(threshold), 14, 14);
}
