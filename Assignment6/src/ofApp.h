#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void makePastSquare();

    ofVideoGrabber grabber;
    ofPixels pixels;
    ofPixels blurPixels;
    ofPixels squarePix;
    ofTexture texture;
    ofTexture pastSquareTexture;
    ofRectangle pastSquare;
        
//    std::pair<ofTexture, ofPixels> texturePair;
//    std::pair<ofRectangle, std::pair<ofTexture, ofPixels>> mainPair;
    std::vector<std::pair<ofRectangle, std::pair<ofTexture, ofPixels>>> pastSquareVector;

    bool go = true;
    int makeSquareCounter = 0;
};
