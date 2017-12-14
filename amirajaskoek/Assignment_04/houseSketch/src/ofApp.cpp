#include "ofApp.h"
#include "house.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    
    for(int i = 0; i < 16; i++){
        
        House theHouse;
        theHouse.setup();
        theHouse.roof = ofColor::fromHsb(ofRandom(255), ofRandom(255), ofRandom(255));
        theHouse.house = ofColor::fromHsb(ofRandom(255), 255, 255);
        

        myHouses.push_back(theHouse);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    for(std::size_t i = 0; i < myHouses.size(); i++){
       
        myHouses[i].update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
   /*
    ofSetColor(ofColor::grey);
    ofDrawCircle(smokeBottomX, smokeBottomY, randomBottomRad);
    ofDrawCircle(smokeMiddleX, smokeMiddleY, randomMiddleRad);
    ofDrawCircle(smokeTopX, smokeTopY, randomTopRad);
*/
    
    ofPushMatrix();
    ofTranslate(100, 100);
    for (std::size_t i = 0; i < myHouses.size(); i++)
    {
        float x = i / 4;
        float y = i % 4;
        
        ofPushMatrix();
        ofTranslate(x * 200, y * 200);
        myHouses[i].draw();
        ofPopMatrix();
    }
    ofPopMatrix();
    
    
    
}

//--------------------------------------------------------------
