#include "Flower.h"


Flower::Flower()
{
    petalColor = ofColor::fromHsb(ofRandom(255), 255, 255, 80);
    centerColor = ofColor::fromHsb(ofRandom(255), 255, 255, 80);
    numberOfPetals = ofRandom(2, 50);
    petalLength = ofRandom(10, 100);
    petalWidth = ofRandom(10, 50);
    centerRadius = ofRandom(2, 40);
}


void Flower::draw() const
{
    // Draw the center.
    ofFill();
    ofSetColor(centerColor);
    ofDrawCircle(0, 0, centerRadius);

    // Draw each petal on the flower. 
    for (int i = 0; i < numberOfPetals; i++)
    {
        ofPushMatrix();
        float angleDeg = ofMap(i, 0, numberOfPetals, 0, 360);
        ofRotateZDeg(angleDeg);
        ofSetColor(petalColor);
        ofDrawEllipse(centerRadius + petalLength / 2, 0, petalLength, petalWidth);
        ofPopMatrix();
    }
    
}

