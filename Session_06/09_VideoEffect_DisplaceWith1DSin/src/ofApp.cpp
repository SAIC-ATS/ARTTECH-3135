#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);
    pixels.allocate(640, 480, OF_PIXELS_RGB);
    pixels.set(255);
}


void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        // timeScaler goes between -1 and 1 over and over again.
        float timeScaler = sin(ofGetElapsedTimef());
        
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            // We calculate this sin offset based ont he x position, the scale and the timeScaler.
            
            float sinOffset = sin(x * scale * timeScaler);

            for (int y = 0; y < grabber.getHeight(); y++)
            {
                int xDisplace = x + grabber.getWidth() * sinOffset;
                int yDisplace = y; // None.

                // We "wrap" the values to make sure they are accessing
                // legitimate pixel x / y values.  This is kind of like doing a
                // modulo, but takes care of negative numbersÊand floating
                // point as well.
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
    texture.draw(grabber.getWidth(), 0);

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
