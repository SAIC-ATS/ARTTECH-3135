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
        // Ignore small v
        if (finder.blobs[i].boundingRect.getArea() > 150 * 150)
        {
            ofRectangle rect = finder.blobs[i].boundingRect;

            float xNose = rect.getCenter().x;
            float yNose = rect.getCenter().y;

            float yEye = rect.getCenter().y - 0.12 * rect.getHeight();

            ofDrawRectangle(rect);

            ofDrawLine(xNose, 0, xNose, ofGetHeight());
            ofDrawLine(0, yEye, ofGetWidth(), yEye);
        }
    }
}

