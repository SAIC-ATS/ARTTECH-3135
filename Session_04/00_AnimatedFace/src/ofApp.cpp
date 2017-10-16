#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(255);

    // Each of the following default values was determined experimentally.
    headColor = ofColor::lightBlue;
    headCenterX = 0.0;
    headCenterY = 0.0;
    headWidth = 200.0;
    headHeight = 200.0;

    mouthColor = ofColor::pink;
    mouthCenterX = 0;
    mouthCenterY = 40;
    mouthWidth = 132.0;
    mouthHeight = 20.0;

    noseColor = ofColor::blue;
    noseCenterX = 0.0;
    noseCenterY = 0.0;
    noseWidth = 32.0;
    noseHeight = 42.0;

    eyeXDistance = 66;
    eyeCenterY = -25.0;
    eyeWidth = 40.0;
    eyeHeight = 25.0;

    irisColor = ofColor::red;
    irisCenterOffsetX = 0.0;
    irisCenterOffsetY = 0.0;
    irisWidth = 15.0;
    irisHeight = 15.0;

    pupilColor = ofColor::black;
    pupilRadius = 4.0;

}


void ofApp::update()
{
    float eyeRollAmplitude = 5;
    float elapsedTimeSeconds = ofGetElapsedTimef();

    // Set the offset of the iris.
    irisCenterOffsetX = eyeRollAmplitude * std::sin(elapsedTimeSeconds);
    irisCenterOffsetY = eyeRollAmplitude * std::cos(2.0 * elapsedTimeSeconds);

    // Modulate the mouth width.
    mouthWidth = ofMap(ofNoise(elapsedTimeSeconds), 0, 1, 10, 132);
    mouthHeight = ofMap(ofNoise(elapsedTimeSeconds + 5), 0, 1, 10, 40);
}

void ofApp::draw()
{
    ofPushMatrix();
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

    // Draw the head.
    ofFill();
    ofSetColor(headColor);
    ofDrawEllipse(headCenterX,
                  headCenterY,
                  headWidth,
                  headHeight);

    // Draw the mouth.
    ofSetColor(mouthColor);
    ofDrawRectRounded(mouthCenterX - mouthWidth / 2,
                      mouthCenterY - mouthHeight / 2,
                      mouthWidth, mouthHeight,
                      mouthWidth / 2);

    // Calculate the three triangle points for the nose.
    float x0 = noseCenterX;
    float y0 = noseCenterY - noseHeight * 0.5;

    float x1 = noseCenterX + noseWidth * 0.5;
    float y1 = noseCenterY + noseHeight * 0.5;

    float x2 = noseCenterX - noseWidth * 0.5;
    float y2 = noseCenterY + noseHeight * 0.5;

    // Draw the nose.
    ofSetColor(noseColor);
    ofDrawTriangle(x0, y0, x1, y1, x2, y2);

    // Calculate the x / y position of the eyes.
    float eyeXDistanceFromCenter = eyeXDistance * 0.5;
    float rightEyeCenterX = eyeXDistanceFromCenter;
    float rightEyeCenterY = eyeCenterY;

    float leftEyeCenterX = -eyeXDistanceFromCenter;
    float leftEyeCenterY = eyeCenterY;

    // Draw the eye.
    ofSetColor(ofColor::white);
    ofDrawEllipse(rightEyeCenterX, rightEyeCenterY, eyeWidth, eyeHeight);
    ofDrawEllipse(leftEyeCenterX, leftEyeCenterY, eyeWidth, eyeHeight);

    // Calculate the position of the irises.
    float rightIrisCenterX = rightEyeCenterX + irisCenterOffsetX;
    float rightIrisCenterY = rightEyeCenterY + irisCenterOffsetY;

    float leftIrisCenterX = leftEyeCenterX + irisCenterOffsetX;
    float leftIrisCenterY = leftEyeCenterY + irisCenterOffsetY;

    // Draw the irises.
    ofSetColor(irisColor);
    ofDrawEllipse(rightIrisCenterX, rightIrisCenterY, irisWidth, irisHeight);
    ofDrawEllipse(leftIrisCenterX, leftIrisCenterY, irisWidth, irisHeight);

    // Draw the pupils.
    ofSetColor(ofColor::black);
    ofDrawCircle(rightIrisCenterX, rightIrisCenterY, pupilRadius);
    ofDrawCircle(leftIrisCenterX, leftIrisCenterY, pupilRadius);

    ofPopMatrix();

}
