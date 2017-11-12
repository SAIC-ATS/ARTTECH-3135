#include "PastSquare.h"

PastSquare::PastSquare(ofVideoGrabber grabber, ofPixels frameToShowPixels, int pastSquareIndex)
{
    squarePix.set(255);
    
    squarePix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGBA);

    //Assign random values for dimensions of pastSquare
    int dimX = ofRandom(20, 200);
    int dimY = ofRandom(20, 200);
    
    //Create new ofRectangle pastSquare
    this->pastSquare = ofRectangle((int)ofRandom(640-dimX), (int)ofRandom(480-dimY), dimX, dimY);
    
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
        //Mirror for smoother/reflecting pastSquareTextures
        //                ofPixels flippedPastSquarePixels = blurredSquarePix;
        //                flippedPastSquarePixels.mirror(true, false);
        
        for (int x = 0; x < this->pastSquare.width; x++)
        {
            for (int y = 0; y < this->pastSquare.height; y++)
            {
                ofColor lastColorToTheRight = this->squarePix.getColor(x + 1, y);
                ofColor currentColor = grabber.getPixels().getColor(this->pastSquare.getMinX() + x, this->pastSquare.getMinY() + y);
                ofColor blended = lastColorToTheRight.getLerped(currentColor, 0.005);
                
                this->squarePix.setColor(x, y, blended);
            }
        }
        
        this->pastSquareTexture.loadData(this->squarePix);
    }
}
