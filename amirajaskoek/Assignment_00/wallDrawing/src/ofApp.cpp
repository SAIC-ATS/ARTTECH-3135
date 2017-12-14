#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofNoFill();
    ofDrawLine(350, 300, 650, 300);
    ofDrawLine(300, 500, 700, 500);
    ofDrawLine(350, 300, 300, 500);
    ofDrawLine(650, 300, 700, 500);
    

    
    //variables
    int x1 = 350;
    int x2= 650;
    int y1 = 300;
    int y2= 500;
    int z1 = 300;
    int z2 =700;
        
    ofSetColor(255, 255, 255);
    ofDrawRectangle(450, 350, 100, 100);
    
    int sqx1 = 450;
    int sqx2 = 550;
    int sqy1 = 350;
    int sqy2 = 450;
    
    //Vertical Lines
    for(x1; x1< sqx1; x1 = x1 + 10){
        ofDrawLine(x1, y2, x1, y1);
    }
    
    for(x1; x1< sqx2; x1 = x1 + 10){
        ofDrawLine(x1, y1, x1, sqy1);
        ofDrawLine(x1, sqy2, x1, y2);
    }
    
    
     for(sqx2; sqx2 < x2; sqx2 = sqx2 + 10){
        ofDrawLine(sqx2, y1, sqx2, y2);
    } 
    
    
   //Lines under the angle
    ofDrawLine(310, 500, 310, 465);
    ofDrawLine(320, 500, 320, 425);
    ofDrawLine(330, 500, 330, 385);
    ofDrawLine(340, 500, 340, 340);

    ofDrawLine(690, 500, 690, 465);
    ofDrawLine(680, 500, 680, 425);
    ofDrawLine(670, 500, 670, 385);
    ofDrawLine(660, 500, 660, 340);
    ofDrawLine(650, 500, 650, 300);

    
    //Horizontal Lines
    for(sqy1; sqy1 < sqy2; sqy1 = sqy1 +10){
        ofDrawLine(sqx1, sqy1, 550, sqy1);
    }
    
    
    
  }

