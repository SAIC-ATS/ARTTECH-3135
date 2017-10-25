#include "ofApp.h"


void ofApp::setup()
{
    ofSetCircleResolution(64);

    grabber.setup(640, 480);
	finder.setup("haarcascade_frontalface_default.xml");

    faceMask.allocate(640, 480, 3);

    ofLoadImage(mask, "A.jpg");
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
    faceMask.begin();
    ofFill();
    ofSetColor(ofColor::black);
    ofDrawRectangle(0, 0, faceMask.getWidth(), faceMask.getHeight());

    for (auto blob: finder.blobs)
    {
        ofRectangle rect = blob.boundingRect;

        // Ignore small "faces".
        if (rect.getArea() > 150 * 150)
        {
            float faceOvalHeight = rect.getWidth() * 1.3;
            float faceOvalWidth = rect.getHeight() * 0.9;
            float faceOvalX = rect.getCenter().x;
            float faceOvalY = rect.getCenter().y;
            ofSetColor(255);
            ofFill();
            ofDrawEllipse(faceOvalX, faceOvalY, faceOvalWidth, faceOvalHeight);
        }
    }

    faceMask.end();

    ofFill();
    ofSetColor(255);
//    grabber.draw(0, 0);

//    faceMask.getTexture().draw(ofGetMouseX(), ofGetMouseY());

//    ofTexture maskedGrabberTexture = grabber.getTexture();
//    maskedGrabberTexture.setAlphaMask(mask);;//faceMask.getTexture());
//    maskedGrabberTexture.draw(ofGetMouseX(), ofGetMouseY());

    mask.setAlphaMask(grabber.getTexture());
    mask.draw(ofGetMouseX(), ofGetMouseY());
}

