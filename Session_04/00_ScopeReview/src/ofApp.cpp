#include "ofApp.h"

// Things declared here, are in a "global" ... there are not curly brackets surrounding them.
//

float myClassScopedVariable = 0;

void ofApp::setup()
{
    int a = 0;
    
//    {
//        int b = 1;
//        {
//            int c = 2;
//            int d = a + b + c;
//        }
//
//        // int e = a + b + c; // c is not accessible in this scope because it was declared in a sub-scope.
//    }

    
}


void ofApp::update()
{
    //myClassScopedVariable = myClassScopedVariable + 1;
}


void ofApp::draw()
{
    ofDrawBitmapString(ofToString(myClassScopedVariable), 100, 100);
}


void ofApp::keyPressed(int key)
{
    myClassScopedVariable = myClassScopedVariable + 1;
}
