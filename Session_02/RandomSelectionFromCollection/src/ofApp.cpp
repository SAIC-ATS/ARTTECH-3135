#include "ofApp.h"


void ofApp::setup()
{
//    words.push_back("hi");
//    words.push_back("bye");
//    words.push_back("hello");
//    words.push_back("see you later");

    words = { "Hello", "my", "name", "is", "Christopher", "." };
    

}

void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(ofColor::white);
//    ofSetColor(255);
//    ofSetColor(255, 255, 255);
//    ofSetColor(255, 255, 255, 255);

    std::string word = words[currentWordIndex];

    ofDrawBitmapString(word,
                       ofGetWidth() / 2,
                       ofGetHeight() / 2 );

}


void ofApp::keyPressed(int key)
{
    if (key == 'r')
    {
        currentWordIndex = ofRandom(0, words.size());
    }
    else if (key == 'n')
    {
        // currentWordIndex = (currentWordIndex + 1) % words.size();

//        currentWordIndex = currentWordIndex + 1;
//
//        if (currentWordIndex >= words.size())
//        {
//            currentWordIndex = 0;
//        }

    }
}
















