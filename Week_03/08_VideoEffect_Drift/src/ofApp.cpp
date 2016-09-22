#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(320, 240);
    pixels.allocate(320, 240, OF_PIXELS_RGB);
    pixels.set(255);
}

void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                // For each pixel column, except the last one ...
                if (x < grabber.getWidth() - 1)
                {
                    // Get the color to the right from the LAST pixels saved.
                    ofColor lastColorToTheRight = pixels.getColor(x + 1, y);
                    // Get a copy of the current color from the camera.
                    ofColor currentColor = grabber.getPixels().getColor(x, y);

                    // Blend the two colors (0.01 will favor the last, closer to
                    // 1 will favor the current live camera color.
                    ofColor blended = lastColorToTheRight.getLerped(currentColor, 0.01);
                    
                    pixels.setColor(x, y, blended);
                }
                else
                {
                    // Otherwise, just save the raw pixel in the last row
                    // (because otherwise we couldn't access x + 1 because it
                    // wouldn't exist).
                    pixels.setColor(x, y, grabber.getPixels().getColor(x, y));
                }
            }
        }

    }

    texture.loadData(pixels);
}

void ofApp::draw()
{
    grabber.draw(0, 0);
    texture.draw(320, 0);
}
