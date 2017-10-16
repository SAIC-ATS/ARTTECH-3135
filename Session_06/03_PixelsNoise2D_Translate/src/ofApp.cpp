#include "ofApp.h"


void ofApp::setup()
{
    pixels.allocate(256, 256, OF_PIXELS_RGB);

}

void ofApp::draw()
{
    // Think of this as a pan/zoom map (like Google Maps) that lets you see the
    // Perlin mountain from various zoom leves and pan offsets. 

    for (int x = 0; x < pixels.getWidth(); x++)
    {
        for (int y = 0; y < pixels.getHeight(); y++)
        {
            // Set the scale.
            float color = 255 * ofNoise((x + mouseX) * scale, (y + mouseY) * scale);
            pixels.setColor(x, y, ofColor(color));
        }
    }

    texture.loadData(pixels);

    texture.draw(0, 0);

    ofDrawBitmapStringHighlight("- / = to scale\n(scale = " + ofToString(scale) + ")", 14, 14);
}



void ofApp::keyPressed(int key)
{
    if (key == '-')
    {
        scale += 0.005;
    }
    else if (key == '=')
    {
        scale -= 0.005;
    }
}









