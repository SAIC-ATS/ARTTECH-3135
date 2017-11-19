#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(ofColor::black);

    // Set up the gui parameters.
    gui.setup();
    gui.add(startAngleDeg.setup("startAngleDeg", 0, -180, 180));
    gui.add(endAngleDeg.setup("endAngleDeg", 15, -180, 180));
    gui.add(startLength.setup("startLength", 50, 0, 100));
    gui.add(endLength.setup("endLength", 50, 0, 100));
    gui.add(numSegments.setup("numSegments", 10, 1, 100));
}


void ofApp::update()
{
    // Construct a tendril based on the current gui parameters.
    
    // Remove all old segments.
    tendril.segments.clear();
    
    // Set the start position of the tendril.
    tendril.position.x = ofGetWidth() / 2;
    tendril.position.y = ofGetHeight() / 2;
    
    // Add tendril segments.
    for (std::size_t i = 0; i < numSegments; i++)
    {
        TendrilSegment segment;
        segment.angle = ofMap(i, 0, numSegments, startAngleDeg, endAngleDeg);
        segment.length = ofMap(i, 0, numSegments, startLength, endLength);
        tendril.segments.push_back(segment);
    }
}

void ofApp::draw()
{
    // Draw the tendril.
    ofSetColor(ofColor::white);
    
    ofPushMatrix();
    ofTranslate(tendril.position);
    
    for (const TendrilSegment& segment: tendril.segments)
    {
        // Rotate the segment to its angle.
        ofRotateZDeg(segment.angle);
        // Draw a line to the next segment.
        ofSetColor(ofColor::white);
        ofDrawLine(0, 0, segment.length, 0);
        // Draw a little yellow circle at the joint.
        ofSetColor(ofColor::yellow, 127);
        ofDrawCircle(0, 0, 4);
        
        // Translate to the beginning of the next segment.
        ofTranslate(segment.length, 0);
    }
    
    // Draw a nice little circle on the end.
    ofDrawCircle(0, 0, 6);
    
    ofPopMatrix();
    
    // Draw the gui.
    gui.draw();
}
