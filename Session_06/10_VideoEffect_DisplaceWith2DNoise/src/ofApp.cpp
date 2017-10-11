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
                // Here we use perlin noise to figure out how to offset our pixels.

                float theNoise = ofNoise((x + mouseX) * scale, (y + mouseY) * scale);

                int xDisplace = grabber.getWidth() * theNoise;
                int yDisplace = grabber.getHeight() * theNoise;

                xDisplace = ofWrap(xDisplace, 0, grabber.getWidth());
                yDisplace = ofWrap(yDisplace, 0, grabber.getHeight());

                // So when we set our color, we don't get the color from
                // the x, y position in the grabber, we get it from somewhere
                // a position determined by the perlin noise field.
                ofColor theDisplacedColorFromTheGrabber = grabber.getPixels().getColor(xDisplace, yDisplace);

                // Save that color to our pixels!
                pixels.setColor(x, y, theDisplacedColorFromTheGrabber);
            }
        }
    }

    texture.loadData(pixels);
}

void ofApp::draw()
{
    grabber.draw(0, 0);
    texture.draw(320, 0);

    ofDrawBitmapStringHighlight("- / = to scale\n(scale = " + ofToString(scale) + ")", 14, 14);
}


void ofApp::keyPressed(int key)
{
    if (key == '-')
    {
        scale += 0.001;
    }
    else if (key == '=')
    {
        scale -= 0.001;
    }
}
