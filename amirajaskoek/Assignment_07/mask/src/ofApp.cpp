#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);
	finder.setup("haarcascade_frontalface_default.xml");
    
    pandaMask.load("pandaMask.png");
    
    kitsuneMask.load("kistuneMask.png");
    
    fan.load("fan.png");
}


void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        finder.findHaarObjects(grabber.getPixels());
    }
}


void ofApp::draw()
{
    ofFill();
    ofSetColor(255);
    grabber.draw(0, 0);

    ofNoFill();
    //to find multiple faces
    //finder.blobs.size is number of faces it thinks it found
	for(unsigned int i = 0; i < finder.blobs.size(); i++)
    {
        // Ignore small "faces".
        if (finder.blobs[i].boundingRect.getArea() > 150 * 150)
        {
            ofRectangle rect = finder.blobs[i].boundingRect;

            //appox. where facial features are
            float xNose = rect.getCenter().x;
            float yNose = rect.getCenter().y;
            float yEye = rect.getCenter().y - 0.17 * rect.getHeight();
            float yMouth = rect.getCenter().y + 0.26 * rect.getHeight();
            float xEyeOffset = 0.19 * rect.getWidth();

            float xEyeRight = xNose + xEyeOffset;
            float xEyeLeft  = xNose - xEyeOffset;

            //ofDrawCircle(xEyeRight, yEye, 10);
            //ofDrawCircle(xEyeLeft, yEye, 10);

            //ofDrawCircle(xNose, yNose, 10);
 
            //ofDrawRectangle(xNose - 20, yMouth - 5, 42, 15);

            //ofDrawRectangle(rect);
            
            //pandaMask.draw(rect);
            kitsuneMask.draw(rect);

        }
    }
    
    
    int time = ceil(ofGetElapsedTimef());
    
    float xPos = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, ofGetWidth());
    float yPos = ofMap(cos(ofGetElapsedTimef()), -1, 1, 0, ofGetWidth());
    
            fan.draw(xPos, yPos);

}

