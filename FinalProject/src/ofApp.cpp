#include "ofApp.h"

void ofApp::setup()
{    
    dataFont.load("consolas.ttf", 18, true, true, true);
    
    grabber.setup(640, 480);
    tracker.setup();

    grayscalePixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    binaryPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    frameToShowPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGBA);
    frameToShowTexture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGBA);
    binaryTexture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGBA);
    
    gui.setup();
    gui.add(threshold.set("Threshold", 55, 0, 100));
    gui.add(erosionIterations.set("Erosion Iterations",0, 0, 30));
    gui.add(dilationIterations.set("Dilation Iterations", 0, 0, 30));
    gui.add(invert.set("Invert", true));
    
    ofNoFill();
    ofBackground(255);
}

void ofApp::update()
{
    textSpeed = sin(ofGetFrameNum()/1000)*100;
    makeSquareCounter++;
    grabber.update();
    
    if(go)
    {
        if(makeSquareCounter>20)
        {
            PastSquare newSquare = PastSquare(grabber, frameToShowPixels, pastSquareCount);
            pastSquareVector.push_back(newSquare);
            
            pastSquareCount++;
            makeSquareCounter = 0;
        }
    }
    
    if (grabber.isFrameNew())
    {
        tracker.update(grabber);
        
        ofxCv::convertColor(grabber, binaryPixels, CV_RGB2GRAY);
        ofxCv::threshold(binaryPixels, binaryPixels, threshold, invert);
        ofxCv::erode(binaryPixels, binaryPixels, erosionIterations);
        ofxCv::dilate(binaryPixels, binaryPixels, dilationIterations);

        contourFinder.findContours(binaryPixels);
        grayscaleTexture.loadData(grayscalePixels);
        binaryTexture.loadData(binaryPixels);
    }
}

void ofApp::draw()
{
    gui.draw();
    
    //    tracker.drawDebug();
    //    tracker.drawDebugPose();
    
    frameToShowTexture.draw(320, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    binaryTexture.draw(0, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    
//    auto it = pastSquareVector.begin() - 1;
//    
//    for(auto pastSquare : pastSquareVector)
    for(auto it = pastSquareVector.begin(); it < pastSquareVector.end(); ++it)
    {
//        ++it;

        if(pastSquareMax + it->pastSquareIndex < pastSquareCount)
        {
            pastSquareVector.erase(it);
        }
        else
        {
            it->draw(go, grabber);
        }
    }
}

void ofApp::keyPressed(int key)
{
    if(key == 'r')
    {
        pastSquareVector.clear();
    }
    
    if(key == 'p')
    {
        ofImage img;
        img.setFromPixels(grabber.getPixels());
        img.save("snapshot.jpg", OF_IMAGE_QUALITY_BEST);
        
        string command = "python " + ofToDataPath("google_vision_api.py", true);
        system(command.c_str());
    }
}

void ofApp::mousePressed(int x, int y, int button)
{
    go = !go;
}


