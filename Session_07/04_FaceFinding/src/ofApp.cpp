#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);
	finder.setup("haarcascade_frontalface_default.xml");
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
	for(unsigned int i = 0; i < finder.blobs.size(); i++)
    {
        // Ignore small "faces".
        if (finder.blobs[i].boundingRect.getArea() > 150 * 150)
        {
            ofRectangle rect = finder.blobs[i].boundingRect;

            float xNose = rect.getCenter().x;
            float yNose = rect.getCenter().y;
            
            float yEye = rect.getCenter().y - 0.11 * rect.getHeight();
            float yMouth = rect.getCenter().y + 0.24 * rect.getHeight();
            float xEyeOffset = 0.18 * rect.getWidth();

            float xEyeRight = xNose + xEyeOffset;
            float xEyeLeft  = xNose - xEyeOffset;

            ofDrawCircle(xEyeRight, yEye, 10);
            ofDrawCircle(xEyeLeft, yEye, 10);
            
            ofDrawCircle(xNose, yNose, 10);

            ofDrawRectangle(xNose - 20, yMouth - 5, 40, 10);

            ofDrawRectangle(rect);

        }
    }
}

