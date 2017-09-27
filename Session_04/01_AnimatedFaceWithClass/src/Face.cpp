#include "Face.h"

void Face::setup()
{
    headColor = ofColor::lightBlue;
    headX = 0;
    headY = 0;
    headWidth = 200;
    headHeight = 200;

    mouthColor = ofColor::pink;
    mouthX = 0;
    mouthY = headY + headHeight * 0.2;
    mouthWidth = headWidth * 0.66;
    mouthHeight = mouthWidth * 0.25;

    noseColor = ofColor::darkBlue;
    noseX = 0;
    noseY = headY;
    noseWidth = headWidth / 6;
    noseHeight = headHeight / 10;

    eyeXDistance = headWidth / 3;
    eyeY = - headHeight / 8;
    eyeWidth = headWidth / 6;
    eyeHeight = headHeight / 8;
    irisColor = ofColor::purple;
    irisOffsetX = 0;
    irisOffsetY = 0;
    pupilRadius = eyeWidth * 0.1;
}


void Face::draw()
{
    ofFill();
    ofSetColor(headColor);

    ofDrawEllipse(headX,
                  headY,
                  headWidth,
                  headHeight);

    ofSetColor(mouthColor);
    ofDrawRectangle(mouthX - mouthWidth / 2,
                    mouthY - mouthHeight / 2,
                    mouthWidth, mouthHeight);

    ofSetColor(noseColor);
    ofDrawTriangle(noseX, noseY,
                   noseX + noseWidth / 2,
                   noseY + noseHeight,
                   noseX - noseWidth / 2,
                   noseY + noseHeight);

    ofSetColor(ofColor::white);
    ofDrawEllipse(eyeXDistance / 2, eyeY, eyeWidth, eyeHeight);
    ofDrawEllipse(-eyeXDistance / 2, eyeY, eyeWidth, eyeHeight);

    ofSetColor(irisColor);
    ofDrawEllipse(eyeXDistance / 2, eyeY, eyeWidth * 0.5, eyeWidth * 0.5);
    ofDrawEllipse(-eyeXDistance / 2, eyeY, eyeWidth * 0.5, eyeWidth * 0.5);

    ofSetColor(ofColor::black);
    ofDrawCircle(eyeXDistance / 2, eyeY, pupilRadius);
    ofDrawCircle(-eyeXDistance / 2, eyeY, pupilRadius);

}






