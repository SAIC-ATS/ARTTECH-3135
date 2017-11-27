#include "ofApp.h"
#include <random>
#include <algorithm>


void ofApp::setup()
{
    ofBackground(ofColor::black);

    // Set up the gui parameters.
    gui.setup();
    
    sliders = std::vector<ofxIntSlider>(5);
    
    gui.add(sliders[0].setup("partA", 0, 0, 100));
    gui.add(sliders[1].setup("partB", 0, 0, 100));
    gui.add(sliders[2].setup("partC", 0, 0, 100));
    gui.add(sliders[3].setup("partD", 0, 0, 100));
    gui.add(sliders[4].setup("partE", 0, 0, 100));

}


void ofApp::update()
{
    // Calculate the sum of the sliders.
    int sum = 0;
   
    for (ofxIntSlider& slider: sliders)
    {
        sum += int(slider);
    }

    // This is the difference between 100 and our current sum.
    int diff = 100 - sum;
    // If diff < 0, that means we need to subtract some values from our sliders.
    // If diff > 0, that means we need to add some values to our sliders.
    
    // While the difference is not == 0, adjust the sliders that can be adjusted.
    while (diff != 0)
    {
        for (ofxIntSlider& slider: sliders)
        {
            if (diff < 0 && slider > 0)
            {
                slider = int(slider) - 1;
                diff++;
            }
            else if (diff > 0 && slider < 100)
            {
                slider = int(slider) + 1;
                diff--;
            }
        }
    }

}


void ofApp::draw()
{
    // Draw the gui.
    gui.draw();
}



