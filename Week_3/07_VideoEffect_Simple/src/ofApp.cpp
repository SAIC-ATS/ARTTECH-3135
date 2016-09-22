#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(320, 240);
    pixels.allocate(320, 240, OF_PIXELS_RGB);
    // Set all of the pixels to black.
    pixels.setColor(ofColor::black);
    texture.loadData(pixels);
}

void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        // This is where we can modify the pixels.
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                // Get the color at the current pixel from the grabber.
                ofColor color = grabber.getPixels().getColor(x ,y);

                // By default, we will just use the pixel from the camera.
                ofColor colorToUse = color;

                // Set pixels based on a few tests.
                // We do these tests for each pixels because we are iterating
                // through all of the pixels.
                float brightness = color.getBrightness();

                if (brightness > 127)
                {
                    colorToUse = ofColor::white;
                }
                else if (x > grabber.getWidth() / 2)
                {
                    colorToUse.invert();
                }
                else if (y > grabber.getHeight() / 2)
                {
                    // Set the r channel to zero!
                    colorToUse.r = 0;
                }

                // Now we send our color into our pixels.
                pixels.setColor(x, y, colorToUse);

            }
        }

        texture.loadData(pixels);
    }
}

void ofApp::draw()
{
    grabber.draw(0, 0);
    texture.draw(320, 0);
}
