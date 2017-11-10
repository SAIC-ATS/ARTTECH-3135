#include "ofApp.h"

void ofApp::setup()
{
    dataFont.load("consolas.ttf", 18, true, true, true);
    
    grabber.setup(640, 480);
    tracker.setup();
    squarePix.set(255);
    
    squarePix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGBA);
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
    
    if(go && makeSquareCounter>20)
    {
        makePastSquare();
        makeSquareCounter = 0;
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
    
    for(auto it = pastSquareVector.begin(); it < pastSquareVector.end(); ++it)
    {
        //Draw pastSquareTexture at pastSquare coordinates
        it->second.first.draw(it->first.x, it->first.y);
    }
}

void ofApp::keyPressed(int key)
{
    if(key == 'r')
    {
        pastSquareVector.clear();
    }
}

void ofApp::mousePressed(int x, int y, int button)
{
    //Click to stop/start pastSquare generation
    go = !go;
}

void ofApp::makePastSquare()
{
    //Assign random values for dimensions of pastSquare
    int dimX = ofRandom(20, 200);
    int dimY = ofRandom(20, 200);
    
    //Create new ofRectangle pastSquare
    auto pastSquare = ofRectangle((int)ofRandom(640-dimX), (int)ofRandom(480-dimY), dimX, dimY);
    
    //Set squarePix to current grabber pixels
    squarePix = grabber.getPixels();
    
    //Set squarePix to 4 channels (i.e. RGBA)
    squarePix.setNumChannels(4);
    
    if(bgCaptured){
        //Set BG pixel in subsection to white/transparent
        for(int x = pastSquare.getMinX(); x <= pastSquare.getMaxX(); x++)
        {
            for(int y = pastSquare.getMinY(); y <= pastSquare.getMaxY(); y++)
            {
                if(frameToShowPixels.getColor(x, y).getBrightness() < 1)
                {
                    squarePix.setColor(x, y, ofColor(200,200,200,10));
                }
            }
        }
    }
    
    //Get the subsection pixels from the full camera image by cropping the full image to pastSquare's dimensions
    squarePix.crop(pastSquare.x, pastSquare.y, dimX, dimY);
    
    ofTexture pastSquareTexture;
    
    // Allocate space for texture (if necessary?)
    pastSquareTexture.allocate(pastSquare.width, pastSquare.height, GL_RGBA);
    
    //Assign the pixels to texture
    pastSquareTexture.loadData(squarePix);
    
    //Assign texture and pixels to texturePair
    auto texturePair = std::make_pair(pastSquareTexture, squarePix);
    //Assign ofRectangle and texturePair to pair and push to vector
    auto mainPair = std::make_pair(pastSquare, texturePair);
    pastSquareVector.push_back(mainPair);
}


