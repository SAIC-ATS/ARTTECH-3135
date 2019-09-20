#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    
    // Load the brush image.
    gradientBrush.load("puppy_1.jpg");
   
}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    
    ofSetColor(ofColor::fromHsb(hue, 255, 255));

    // Color preview square.
    ofDrawRectangle(0, 0, 20, 20);
    
    if (ofGetMousePressed())
    {
        if (currentBrush == 'c')
        {
            ofDrawCircle(mouseX, mouseY, brushSize);
        }
        else if (currentBrush == 't')
        {
            ofDrawTriangle(mouseX, mouseY,
                           mouseX + 10, mouseY + 10,
                           mouseX - 10, mouseY + 10);
        }
        else if (currentBrush == 's')
        {
            ofDrawRectangle(mouseX - brushSize / 2, mouseY - brushSize / 2,
                            brushSize,
                            brushSize);
        }
        else if (currentBrush == 'r')
        {
            drawRandomBrush();
        }
        else if (currentBrush == 'b')
        {
            gradientBrush.draw(mouseX - brushSize / 2, mouseY - brushSize / 2,
                               brushSize,
                               brushSize);
        }
    }
}


void ofApp::keyPressed(int key)
{
    if (key == '[')
    {
        brushSize -= 1;
        brushSize = ofClamp(brushSize, 1, 100);
    }
    else if (key == ']')
    {
        brushSize += 1;
        brushSize = ofClamp(brushSize, 1, 100);
    }
    else if (key == '-')
    {
        hue -= 1;
        hue = ofWrap(hue, 0, 255);
    }
    else if (key == '=')
    {
        hue += 1;
        hue = ofWrap(hue, 0, 255);
    }
    else if (key == 'b')
    {
        currentBrush = 'b';
    }
    else if (key == 'c')
    {
        currentBrush = 'c';
    }
    else if (key == 't')
    {
        currentBrush = 't';
    }
    else if (key == 's')
    {
        currentBrush = 's';
    }
    else if (key == 'r')
    {
        currentBrush = 'r';
    }
    else if (key == OF_KEY_BACKSPACE)
    {
        ofBackground(0);
    }
}


void ofApp::keyReleased(int key)
{
}



void ofApp::mouseMoved(int x, int y)
{
}


void ofApp::mouseDragged(int x, int y, int button)
{
}


void ofApp::mousePressed(int x, int y, int button)
{
}


void ofApp::mouseReleased(int x, int y, int button)
{
}


void ofApp::mouseEntered(int x, int y)
{
}


void ofApp::mouseExited(int x, int y)
{
}


void ofApp::windowResized(int w, int h)
{
}


void ofApp::gotMessage(ofMessage msg)
{
}


void ofApp::dragEvent(ofDragInfo dragInfo)
{
}


void ofApp::drawRandomBrush()
{
    // The actual code for a random brush goes here.
    for (int i = 0; i < 5; i++)
    {
        float randomAlpha = ofRandom(0, 5);
        ofSetColor(ofColor::fromHsb(hue, 255, 255, randomAlpha));
        
        float x = mouseX + ofRandom(-10, 10);
        float y = mouseY + ofRandom(-10, 10);
        
        gradientBrush.draw(x - brushSize / 2, y - brushSize / 2,
                           brushSize,
                           brushSize);
    }
}
