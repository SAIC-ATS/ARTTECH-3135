#include "ofApp.h"


void ofApp::setup()
{
    // Set up our grabber.
    grabber.setup(640, 480);

    grayscalePixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    backgroundPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);

    frameToShowPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
}

void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        // Make the grayscale image from the fresh camera image.
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                grayscalePixels.setColor(x, y, grabber.getPixels().getColor(x, y).getBrightness());
            }
        }

        // If the spacebar is pressed, save that image as the background image.
        if (ofGetKeyPressed(' ') == true)
        {
            backgroundPixels = grayscalePixels;
        }

        // Subtract the background from the camera grayscale and create the foreground.
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                int brightnessOfGrayscale = grayscalePixels.getColor(x, y).getBrightness();
                int brightnessOfBackground = backgroundPixels.getColor(x, y).getBrightness();
                int absDiff = std::abs(brightnessOfBackground - brightnessOfGrayscale);

                ofColor color;

                if (absDiff > 10)
                {
                    color = grabber.getPixels().getColor(x, y);
                }
                else
                {
                    color = ofColor(0);
                }

                frameToShowPixels.setColor(x, y, color);
            }
        }

        grayscaleTexture.loadData(grayscalePixels);
        backgroundTexture.loadData(backgroundPixels);
        frameToShowTexture.loadData(frameToShowPixels);
    }
}

void ofApp::draw()
{
    int halfWidth = ofGetWidth() / 2;
    int halfHeight = ofGetHeight() / 2;

    grabber.draw(0, 0, halfWidth, halfHeight);
    ofDrawBitmapString("grabber", 14, 14);
    grayscaleTexture.draw(halfWidth, 0, halfWidth, halfHeight);
    ofDrawBitmapString("grayscaleTexture", halfWidth + 14, 14);
    backgroundTexture.draw(0, halfHeight, halfWidth, halfHeight);
    ofDrawBitmapString("backgroundTexture", 14, halfHeight + 14);
    frameToShowTexture.draw(halfWidth, halfHeight, halfWidth, halfHeight);
    ofDrawBitmapString("frameToShowTexture", halfWidth + 14, halfHeight + 14);
}
