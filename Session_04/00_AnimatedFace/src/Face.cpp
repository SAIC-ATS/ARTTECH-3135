#include "Face.h"

void Face::setup()
{
    headColor = ofColor::lightBlue;
    headX = 0;
    headY = 0;
    headWidth = 100;
    headHeight = 100;

    mouthColor = ofColor::pink;
    mouthX = 0;
    mouthY = headHeight * 0.66;
    mouthWidth = headWidth = 0.66;
    mouthHeight = mouthWidth / 2;

    noseColor = ofColor::darkBlue;
    noseX = 0;
    noseY = headHeight / 2;
    noseWidth = headWidth / 6;
    noseHeight = headHeight / 6;

    eyeXDistance = headWidth / 3;
    eyeY = headHeight / 3;
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
    ofDrawEllipse(headX - headWidth / 2, headY - headHeight / 2, headWidth, headHeight);
//    ofDrawEllipse(0, 0, 100, 100);

//
//    ofSetColor(mouthColor);
//    ofDrawRectangle(mouthX - mouthWidth / 2,
//                    mouthY - mouthHeight / 2,
//                    mouthWidth, mouthHeight);
//
//    ofSetColor(noseColor);
//    ofDrawTriangle(noseX,
//                   noseY, noseX + noseWidth / 2,
//                   noseY + noseHeight, noseX - noseWidth / 2, noseY + noseHeight);

//                  eyeXDistance = headWidth / 3;
//                  eyeY = headHeight / 3;
//                  eyeWidth = headWidth / 6;
//                  eyeHeight = headHeight / 8;
//                  irisColor = ofColor::purple;
//                  irisOffsetX = 0;
//                  irisOffsetY = 0;
//                  pupilRadius = eyeWidth * 0.1;


//    std::cout << "in here" << std::endl;

}






