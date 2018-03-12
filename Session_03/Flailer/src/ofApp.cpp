#include "ofApp.h"


void ofApp::setup()
{
    femurBone.load("femur.png");

    images = { femurBone, femurBone, femurBone, femurBone, femurBone, femurBone, femurBone, femurBone };
    angles = { 0, 0, 0, 0, 0, 0, 0, 0 };
    anglesMinimum = { -360, -270, -180, -90, -80, -70, -60, -45 };
    anglesMaximum = { 360, 270, 180, 90, 80, 70, 60, 45 };
    anglesNoiseIncrement = { 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01  };
    anglesNoiseOffsets = { ofRandom(100), ofRandom(100), ofRandom(100), ofRandom(100), ofRandom(100), ofRandom(100), ofRandom(100), ofRandom(100) };
    anglesNoiseScales = { 2, 2, 2, 2, 2, 2, 2, 2 };
    isNewSegment = { false, false, true, false, false, false, true, true };
}


void ofApp::update()
{
    // Loop through all of the images!
    for (std::size_t i = 0; i < images.size(); ++i)
    {
        // This is how we move through the Perlin noise. We adjust the offset
        // just a tiny bit to get the next value in the neighborhood of noise.
        anglesNoiseOffsets[i] += anglesNoiseIncrement[i];

        // ... next we ask for the noise at the current offset. It will be a
        // value between -1 and 1 for ofSignedNoise.
        float noiseAtOffset = ofSignedNoise(anglesNoiseOffsets[i]);

        // ... next we scale the noise by multiplying it by a scaler.
        noiseAtOffset *= anglesNoiseScales[i];

        // Now add some noise to the angle.
        angles[i] = angles[i] + noiseAtOffset;

        // Now clamp the angle values to keep them in a reasonable range.
        angles[i] = ofClamp(angles[i], anglesMinimum[i], anglesMaximum[i]);
    }
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

    ofDrawBitmapString("Press spacebar for debug mode", 20, 20);

    // Move our canvas (translate)

    ofPushMatrix();

    int x = ofGetMouseX();
    int y = ofGetMouseY();

    ofTranslate(x, y);

    // Loop through all o fthe images.
    for (std::size_t i = 0; i < images.size(); ++i)
    {
        // If we want to have different attachment points, we must push (or not
        // push) a new transoformation matrix.
        if (isNewSegment[i])
        {
            ofPushMatrix();
        }

        ofRotateZDeg(angles[i]);

        images[i].draw(-images[i].getWidth() / 2,
                       -images[i].getWidth() / 2);

        // We draw the debugging here so that it is on top of our image.
        if (showGrid)
        {
            drawGrid(80, 80, 10);
            ofDrawBitmapString(ofToString("Transform: " + ofToString(i)), 14, 14);
        }

        ofTranslate(0, images[i].getHeight());

        // If we pushed a new matrix, go ahead and pop it off again.
        if (isNewSegment[i])
        {
            ofPopMatrix();
        }
    }

    ofPopMatrix();

}


void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        showGrid = !showGrid;
    }
}


void ofApp::drawGrid(float width, float height, float size)
{
    ofPushStyle();
    ofNoFill();
    ofSetColor(255, 60);
    
    for (int x = 0; x < width; x += size)
    {
        ofDrawLine(x, 0, x, height);
    }

    for (int y = 0; y < height; y += size)
    {
        ofDrawLine(0, y, width, y);
    }

    ofDrawRectangle(0, 0, width, height);

    ofSetColor(ofColor::green);
    ofDrawLine(0, 0, width / 2, 0);

    ofSetColor(ofColor::red);
    ofDrawLine(0, 0, 0, height / 2);

    ofPopStyle();
}

