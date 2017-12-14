
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

     ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Image_00
    
    // /*
    
    float perc = .05;
    
    for(perc; perc < ofGetWidth(); perc = perc + .05){
        ofDrawLine(0, (ofGetHeight() * perc), (ofGetWidth() * perc), 0);
    }
    
   // */
    
    
    //------------------------------------------------------------------
    
    //Image_01
    
     /*
    
    ofNoFill();
    ofSetColor(255);
    
    float perc = 0;
    
    float width = 512;
    float height = 512;
    float lineSpacing = 20;
    
    for (float x = -width; x <= width; x += lineSpacing)
    {
        ofDrawLine(x, 0, x + width, height);
    }
    
    // Draw a triangle mask!
    ofFill();
    ofSetColor(0);
    ofDrawTriangle(0, 0, width, 0, 0, height);
     */
    
   /*

    //Top Section
    ofSetColor(255);
    for(perc; perc < 800; perc = perc + 20){
        ofDrawLine(0, (ofGetHeight() - perc), (ofGetWidth() - perc), 0);
    }
    
    */

 
   // for(perc; perc < 800; perc = perc + 20){
   //     ofDrawLine(0, (ofGetHeight() + perc), (ofGetWidth() + perc), 800);
   // }
    
    
    

    //-------------------------------------------------------------------
    //Image_02
     /*
    float start = 1;
    
    float width = 512;
    float height = 512;
    
    
    for(float x = start; x < ofGetWidth(); x = x *2){
        ofDrawLine(x, 0, x - width, height);
    }
    
      */

    
    //--------------------------------------------------------------------
    
    //Image_03
     /*
    
    float lineSpacing = 1;
    float width = 512;
    float height = 512;
    
    ofNoFill();
    ofSetColor(255);
    
    for (float x = lineSpacing; x <= width; x = x * 2)
    {
        ofDrawLine(width - x, 0, 2 * width - x, height);
    }
    
    // triangle mask
    ofFill();
    ofSetColor(0);
    ofDrawTriangle(0, 0, width, 0, 0, height);
    
    ofNoFill();
    ofSetColor(255);
      
    for (float x = lineSpacing; x <= width; x = x * 2)
    {
        ofDrawLine(x, 0, x - width, height);
    }

    */
    
   //---------------------------------------------------------------------
    
    //Image_04
    
    /*
    ofNoFill();
    ofSetColor(255);
    
    float perc = 0;
    
    float width = 512;
    float height = 512;
    float lineSpacing = 20;
    
    for (float x = -width; x <= width; x += lineSpacing)
    {
        
        float grayscale = ofMap(x, 0, width, 0, 255);
        ofSetColor(grayscale);
        ofDrawLine(x, 0, x + width, height);
    }
    
    // Draw a triangle mask!
    ofFill();
    ofSetColor(0);
    ofDrawTriangle(0, 0, width, 0, 0, height);
     
     //Top Section
     //ofSetColor(255);
     for(perc; perc < 800; perc = perc + 20){
         
         float color = ofMap(perc , 0, width, 0, 255);
         ofSetColor(ofColor::fromHsb(color, 255, 255));

     ofDrawLine(0, (ofGetHeight() - perc), (ofGetWidth() - perc), 0);
     }

*/
    
    

}

