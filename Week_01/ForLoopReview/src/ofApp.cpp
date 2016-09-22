#include "ofApp.h"


void ofApp::setup()
{
    int ourMaximum = 10;

    for (int i = 0; i < ourMaximum; i+=2)
    {
        std::cout << i << std::endl;
    }

}

void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);

//    for (/* INITIAL CONDITIONS */; /* CONDITION FOR CONITNUING */; /* WHAT IS DONE AFTER EACH LOOP */)
//    {
//        // ALL THE STUFF THAT GETS DONE EACH "LOOP"
//    }


    for (int x = 0; x < ofGetWidth(); x++)
    {
        // in the for loop x = x + 2 ... x +=2
        // if (x % 2 == 0)

        if (x > ofGetWidth() / 2)
        {
            if (x % 4 == 0)
            {
                ofDrawLine(x, 0, x, ofGetHeight());
            }
        }
        else
        {
            if (x % 8 == 0)
            {
                ofDrawLine(x, 0, x, ofGetHeight());
            }
        }

    }

}













