#include "ofApp.h"

void ofApp::setup()
{
    grabber.setup(640, 480);
    pastSquareTexture.allocate(640, 480, GL_RGBA);
    pixels.allocate(640, 480, OF_PIXELS_RGB);
    pixels.set(255);
    ofNoFill();
}

void ofApp::update()
{
    makeSquareCounter++;
    grabber.update();

    if(go && makeSquareCounter>20)
    {
        makePastSquare();
        makeSquareCounter = 0;
//        go = false;
    }
    
    if (grabber.isFrameNew() && makeSquareCounter%5==0 && makeSquareCounter != 0)
    {
        for(auto it = pastSquareVector.begin(); it < pastSquareVector.end(); ++it)
        {
            ofRectangle blurredPastSquare = it->first;
            ofTexture &blurredPastSquareTexture = it->second.first;
            ofPixels &blurredSquarePix = it->second.second;
            
            //randomize blur start points?
            for (int x = blurredPastSquare.getMinX(); x < blurredPastSquare.getMaxX(); x++)
            {
                for (int y = blurredPastSquare.getMinY(); y < blurredPastSquare.getMaxY(); y++)
                {
                    // For each pixel column, except the last one ...
                    if (x < blurredPastSquare.getMaxX() - 1)
                    {
                        // Get the color to the right from the LAST set pixels saved in the pastSquareTexture
                        ofColor lastColorToTheRight = blurredSquarePix.getColor(x + 1, y);
                        // Get a copy of the current color from the camera.
                        ofColor currentColor = grabber.getPixels().getColor(x, y);
                        
                        // Blend the two colors (0.01 will favor the last, closer to
                        // 1 will favor the current live camera color.
                        ofColor blended = lastColorToTheRight.getLerped(currentColor, 0.01);
                        
                        blurredSquarePix.setColor(x, y, blended);
                    
                    }
                    else
                    {
                        // Otherwise, just save the raw pixel in the last row
                        // (because otherwise we couldn't access x + 1 because it
                        // wouldn't exist).
                        
                        blurredSquarePix.setColor(x, y, grabber.getPixels().getColor(x, y));
                    }
                }
            }
            cout<<"minY: "<<it->first.getMinY()<<endl;
            cout<<"maxY: "<<it->first.getMaxY()<<endl;
            
            blurredPastSquareTexture.loadData(blurredSquarePix);
            //look into putting on mobile/musical element/putting it other places
        }
    }
}

void ofApp::draw()
{
    ofDrawBitmapStringHighlight("click to pause, r to reset", ofGetWidth()/2-100, ofGetHeight()-20);

    
    for(auto it = pastSquareVector.begin(); it < pastSquareVector.end(); ++it)
    {
        //Allocate pixels for texture
        pastSquareTexture.allocate(it->first.x, it->first.y, GL_RGBA);
        
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
    //Click to stop pastSquare generation
    go = false;
    cout<<y<<endl;
}

void ofApp::makePastSquare()
{
    //Assign random values for dimensions of pastSquare
    int dimX = ofRandom(20, 200);
    int dimY = ofRandom(20, 200);
    
    //Create new ofRectangle pastSquare
    pastSquare = ofRectangle(ofRandom(640), ofRandom(480), dimX, dimY);
    
    //Get the subsection pixels from the full camera image by cropping the full image to pastSquare's proportions
    squarePix = grabber.getPixels();
    squarePix.crop(pastSquare.x, pastSquare.y, dimX, dimY);
    
    //Assign the pixels to a texture
    pastSquareTexture.loadData(squarePix);
    
    //Assign ofRectangle and ofTextures to pair and push to vector
    auto texturePair = std::make_pair(pastSquareTexture, squarePix);
    auto mainPair = std::make_pair(pastSquare, texturePair);
    
    pastSquareVector.push_back(mainPair);
}


