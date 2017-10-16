#pragma once


#include "ofMain.h"


class Face
{
public:
    /// A Face constructor sets all of the default values for our variables.
    /// This function is called when a new Face is instantiated.
    Face();

    /// A Face destructor is called hen a Face instance is destroyed.
    ~Face();

    /// The setup function will set up any additional variables not already
    /// set in the constructor above.
    void setup();

    /// The update function will update any variables that change over time.
    void update();

    /// The draw function will render all of our variables to the screen.
    void draw();

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

    /// This will be randomized for each instance so the animations aren't
    /// all exactly the same.
    float noiseOffset;

};
