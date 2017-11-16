#include "PastSquare.h"

PastSquare::PastSquare(ofVideoGrabber grabber, ofPixels frameToShowPixels, int pastSquareIndex, bool bgCaptured, ofxFaceTracker2 &tracker)
{
    squarePix.set(255);
    squarePix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGBA);

    ofxFaceTracker2Instance trackerInstance = tracker.getInstances()[0];

    //Assign random values inside bounding box of FaceTracker for dimensions and location of new pastSquare
    int centerX = ofRandom(trackerInstance.getBoundingBox().getMinX(), trackerInstance.getBoundingBox().getMaxX());
    int centerY = ofRandom(trackerInstance.getBoundingBox().getMinY(), trackerInstance.getBoundingBox().getMaxY());
    
    int dimX = ofRandom(trackerInstance.getBoundingBox().width/10, trackerInstance.getBoundingBox().width/2);
    int dimY = ofRandom(trackerInstance.getBoundingBox().height/10, trackerInstance.getBoundingBox().height/2);
    
    //Create new ofRectangle pastSquare
    this->pastSquare = ofRectangle(centerX, centerY, dimX, dimY);
    
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
    
    // Allocate space for texture (if necessary?)
    this->pastSquareTexture.allocate(pastSquare.width, pastSquare.height, GL_RGBA);
    
    //Assign the pixels to texture
    this->pastSquareTexture.loadData(squarePix);
    
    this->squarePixMirrored = squarePix;

//Randomize start image reflection
    if((int)ofRandom(0,2)>0) {
        this->squarePixMirrored.mirror(false, true);
    }
    else {
        this->squarePix.mirror(false, true);
    }

    this->pastSquareIndex = pastSquareIndex;
}


PastSquare::~PastSquare()
{
}

void PastSquare::setup()
{
}


void PastSquare::update()
{

}


void PastSquare::draw(bool go, ofVideoGrabber grabber)
{
    this->pastSquareTexture.draw(this->pastSquare.x, this->pastSquare.y);
    this->blur(go, grabber);
}

void PastSquare::blur(bool go, ofVideoGrabber grabber)
{
    if(go)
    {
        for (int x = 0; x < this->pastSquare.width; x++)
        {
            for (int y = 0; y < this->pastSquare.height; y++)
            {
                
                if (x < this->pastSquare.width-1)
                {
                    ofColor lastColorToTheRight = this->squarePix.getColor(x + 1, y);
                    ofColor currentColor = grabber.getPixels().getColor(this->pastSquare.getMinX() + x, this->pastSquare.getMinY() + y);
                    ofColor blended = lastColorToTheRight.getLerped(currentColor, 0.005);
                    
                    this->squarePix.setColor(x, y, blended);
                }
                else
                {
                    this->squarePix.setColor(x, y, this->squarePixMirrored.getColor(x+this->dirCounter, y));
                }
                
                //fade
                if(dirCounter % 2 == 0)
                {
                    this->squarePix.setColor(x, y, ofColor(squarePix.getColor(x, y).r+1,
                                                           squarePix.getColor(x, y).g+1,
                                                           squarePix.getColor(x, y).b+1,
                                                           squarePix.getColor(x, y).a
                                                           ));
                    
                    this->squarePixMirrored.setColor(x, y, ofColor(squarePixMirrored.getColor(x, y).r+1,
                                                                   squarePixMirrored.getColor(x, y).g+1,
                                                                   squarePixMirrored.getColor(x, y).b+1,
                                                                   squarePixMirrored.getColor(x, y).a
                                                                   ));
                    if(dirCounter % 10 == 0)
                    {
                        this->squarePix.setColor(x, y, ofColor(squarePix.getColor(x, y).r,
                                                               squarePix.getColor(x, y).g,
                                                               squarePix.getColor(x, y).b,
                                                               squarePix.getColor(x, y).a-1
                                                               ));
                        
                        this->squarePixMirrored.setColor(x, y, ofColor(squarePixMirrored.getColor(x, y).r,
                                                                       squarePixMirrored.getColor(x, y).g,
                                                                       squarePixMirrored.getColor(x, y).b,
                                                                       squarePixMirrored.getColor(x, y).a-1
                                                                       ));
                    }
                }
            }
        }
        this->dirCounter++;

        //If dirCounter reaches the width of the image, reverse
        if(dirCounter >= this->pastSquare.width)
        {
            squarePixMirrored.mirror(false, true);
            this->dirCounter = 0;
        }
        
        this->pastSquareTexture.loadData(this->squarePix);
    }
}
