#include "ofApp.h"


void ofApp::setup()
{
    // Set up our grabber.
    grabber.setup(640, 480);
}

void ofApp::update()
{
    grabber.update();

    currentAngle += angleIncrement;
}

void ofApp::draw()
{
    ofBackground(255);

    ofPixels pixels = grabber.getPixels();

    int offset = 15;

    for (int x = 0; x < pixels.getWidth(); x += offset)
    {
        for (int y = 0; y < pixels.getHeight(); y+= offset)
        {
            ofVec2f position(x + offset / 2, y + offset / 2);

            // Here we are ONLY using the grabber pixels to find the
            // brightness at a given position on our screen.
            // we aren't even displaying the color anywhere.
            float brightness = pixels.getColor(x, y).getBrightness();

            // Here we map the brightness to an angle.
            float brightnessAngle = ofMap(brightness, 0, 255, 0, 360, true);

            ofPath path;
            path.setColor(ofColor::black);
            path.arc(position,
                     offset / 2 - 1,
                     offset / 2 - 1,
                     currentAngle,
                     currentAngle + brightnessAngle);

            path.draw();
        }
    }
}
