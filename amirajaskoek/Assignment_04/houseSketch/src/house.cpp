//
//  house.cpp
//  houseClassSystem
//
//  Created by Suzanne D Kosek on 11/13/17.
//
//

#include "house.h"


House::House(){
    
    window.set(ofColor::yellow);
    door.set(ofColor::brown);
    dWay.set(ofColor::black);
    chimney.set(ofColor::brown);
    smoke.set(ofColor::grey);
    
    houseH = 20;
    houseW = 20;
    houseX = 50;
    houseY = 50;
    
    roofAX = 40;
    roofAY = 50;
    roofBX = 60;
    roofBY = 30;
    roofCX = 80;
    roofCY = 50;
    
    windowX = 53;
    windowY = 54;
    windowH = 5;
    windowW = 3;
    
    dWayX = 57;
    dWayY = 60;
    dWayW = 7;
    dWayH = 10;
    
    doorX = 57;
    doorY = 60;
    doorW = 7;
    doorH = 10;
    
    chimneyX = 65;
    chimneyY = 30;
    chimneyW = 4;
    chimneyH = 10;
    
    smokeBottomX = 67;
    smokeBottomY = 22;
    smokeBottomRad = 2;
    
    smokeMiddleX = 69;
    smokeMiddleY = 22;
    smokeMiddleRad = 4;
    
    smokeTopX = 68;
    smokeTopY = 19;
    smokeTopRad = 6;
    
    noiseOffSet = ofRandom(255);
}

House::~House(){
    
}

void House::setup(){

    
}

//------------------------------------------------
void House::update(){
    
    //Door
    dWayW = ofMap(ofNoise(ofGetElapsedTimef() - noiseOffSet), 0, 1, 0, 7);
    
    
    //Smoke
    smokeBottomRad = ofMap(ofNoise(ofGetElapsedTimef() - noiseOffSet), 0, 1, 2, 8);
    smokeMiddleRad = ofMap(ofNoise(ofGetElapsedTimef() - noiseOffSet), 0, 1, 5, 10);
    smokeTopRad = ofMap(ofNoise(ofGetElapsedTimef() - noiseOffSet), 0, 1, 7, 14);

}


//------------------------------------------------
void House::draw(){
    
    //chimney
    ofSetColor(chimney);
    ofDrawRectangle(chimneyX, chimneyY, chimneyW, chimneyH);
    //house
    ofSetColor(house);
    ofDrawRectangle(houseX, houseY, houseW, houseH);
    //roof
    ofSetColor(roof);
    ofDrawTriangle(roofAX, roofAY, roofBX, roofBY, roofCX, roofCY);
    //door
    ofSetColor(door);
    ofDrawRectangle(doorX, doorY, doorW, doorH);
    //door way
    ofSetColor(dWay);
    ofDrawRectangle(dWayX, dWayY, dWayW, dWayH);
    //window
    ofSetColor(window);
    ofDrawRectangle(windowX, windowY, windowW, windowH);
    //smoke
    ofSetColor(smoke);
    ofDrawCircle(smokeBottomX, smokeBottomY, smokeBottomRad);
    ofDrawCircle(smokeMiddleX, smokeMiddleY, smokeMiddleRad);
    ofDrawCircle(smokeTopX, smokeTopY, smokeTopRad);
    
    
    
    
}
//------------------------------------------------








