#include "ofApp.h"


void ofApp::setup()
{
    // Set up our grabber.
    grabber.setup(640, 480);

    grayscalePixels.allocate(640, 400, OF_PIXELS_GRAY);
    backgroundPixels.allocate(640, 400, OF_PIXELS_GRAY);
    frameToShowPixels.allocate(640, 400, OF_PIXELS_GRAY);
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


        motionCount = 0;

        // Subtract the background from the camera grayscale and create the foreground.
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                int brightnessOfGrayscale = grayscalePixels.getColor(x, y).getBrightness();
                int brightnessOfBackground = backgroundPixels.getColor(x, y).getBrightness();
                int absDiff = std::abs(brightnessOfBackground - brightnessOfGrayscale);

                if (absDiff > 10)
                {
                    absDiff = 255;
                    motionCount++;
                }
                else
                {
                    absDiff = 0;
                }

                frameToShowPixels.setColor(x, y, ofColor(absDiff));
            }
        }

        // motionCount = motionCount / (grabber.getWidth() * grabber.getHeight());

        motionCount /= (grabber.getWidth() * grabber.getHeight());

        backgroundPixels = grayscalePixels;

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
    grayscaleTexture.draw(halfWidth, 0, halfWidth, halfHeight);

    backgroundTexture.draw(0, halfHeight, halfWidth, halfHeight);
    frameToShowTexture.draw(halfWidth, halfHeight, halfWidth, halfHeight);

    ofDrawBitmapStringHighlight(ofToString(motionCount), 25, 25);

}
