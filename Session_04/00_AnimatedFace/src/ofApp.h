#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;

    /// The fill color of the head.
    ofColor headColor;
    /// The center x of the head.
    float headCenterX;
    /// The center y of the head.
    float headCenterY;
    /// The width of the head.
    float headWidth;
    /// The height of the head.
    float headHeight;

    /// The fill color of the mouth.
    ofColor mouthColor; 
    /// The center x of the mouth.
    float mouthCenterX;
    /// The center y of the mouth.
    float mouthCenterY;
    /// The width of the mouth.
    float mouthWidth;
    /// The height of the mouth.
    float mouthHeight;

    /// The fill color of the nose.
    ofColor noseColor;
    /// The center x of the nose.
    float noseCenterX;
    /// The center y of the nose.
    float noseCenterY;
    /// The width of the nose.
    float noseWidth;
    /// The height of the nose.
    float noseHeight;

    /// The x distance between the eyes. The eyes are assumed to be an equal
    /// distance x from the center of the center of the face.
    float eyeXDistance;
    /// The center y of the eyes.
    float eyeCenterY;
    /// The width of the eyes.
    float eyeWidth;
    /// The height of the eyes.
    float eyeHeight;
    
    /// The color of the iris.
    ofColor irisColor;
    /// The x offset of the iris from the center of the eye.
    float irisCenterOffsetX;
    /// The y offset of the iris from the center of the eye.
    float irisCenterOffsetY;
    /// The width of the iris.
    float irisWidth;
    /// The height of the iris.
    float irisHeight;

    /// The color of the pupil.
    ofColor pupilColor;
    /// The radius of the pupil.
    float pupilRadius;

};
