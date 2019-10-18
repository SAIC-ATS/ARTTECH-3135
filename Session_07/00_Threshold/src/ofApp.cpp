#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(1280, 720);
}


void ofApp::update()
{
    brightnessThreshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    
    
    // Get the latest frame if there is one to get.
    grabber.update();
    
    // If the frame is a new frame, then do something with it.
    if (grabber.isFrameNew())
    {
        // Copy the pixels from my grabber so I can manupulate them with the CPU.
        pixels = grabber.getPixels();
        
        
        for (std::size_t x = 0; x < pixels.getWidth(); x++)
        {
            for (std::size_t y = 0; y < pixels.getHeight(); y++)
            {
                // The brightness @ this particular pixel.
                float brightness = pixels.getColor(x, y).getBrightness();
                
                if (brightness > brightnessThreshold)
                {
                    pixels.setColor(x, y, ofColor::white);
                }
                else
                {
                    pixels.setColor(x, y, ofColor::black);
                }
            }
        }
        
        // Load my manipulated pixels into a texture so that it can be shown on the screen.
        texture.loadData(pixels);
    }
}


void ofApp::draw()
{
    // Avoid initial warnings and error messages by making sure the texture is allocated before we draw it.
    if (texture.isAllocated())
    {
        texture.draw(0, 0);
    }
}

