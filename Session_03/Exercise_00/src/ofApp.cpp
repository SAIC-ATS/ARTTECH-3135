#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(0);
}


void ofApp::draw()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    float halfW = w / 2;
    float halfH = h / 2;

    float radiusLarge = 200;
    float angleLargeDeg = 20;

    float radiusSmall = 30;
    float angleSmallDeg = 360 / 30;

    ofPushMatrix();
    ofTranslate(halfW, halfH);

    for (int i = 0; i < 360; i += angleLargeDeg)
    {
        ofPushMatrix();
        ofRotateZDeg(i);
        ofDrawLine(0, 0, radiusLarge, 0);

        ofPushMatrix();
        ofTranslate(radiusLarge, 0);

        for (int j = 0; j < 360; j += angleSmallDeg)
        {
            ofPushMatrix();
            ofRotateZDeg(j);
            ofDrawLine(0, 0, radiusSmall, 0);
            ofPopMatrix();
        }

        ofPopMatrix();

        ofPopMatrix();
    }

    ofPopMatrix();

}
