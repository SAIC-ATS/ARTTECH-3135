#include "ofApp.h"


void ofApp::setup()
{
    ofSetBackgroundColor(80);
    
    // Do initial gui setup stuff.
    gui.setup();
    
    // Add all of our gui "widgets".
    // "name", "starting value", "min value", "max value".
    gui.add(radius.setup("radius", 100, 10, 500));
    
    // Set up our color sliders.
    gui.add(fillColor.setup("fill_color", ofColor::red, ofColor::black, ofColor::white));

    // Set up our position sliders.
    glm::vec2 startingPosition = { ofGetWidth() / 2, ofGetHeight() / 2 };
    glm::vec2 minimumPosition = { 0, 0 };
    glm::vec2 maximumPosition = { ofGetWidth(), ofGetHeight() };
    
    gui.add(position.setup("position", startingPosition, minimumPosition, maximumPosition));
    
    // Set a toggle with the initial value.
    gui.add(fill.setup("fill", true));
    
    // Reset button.
    gui.add(resetButton.setup("reset"));
    
    // Make a connection between the reset button and the resetTheGui() function.
    // When the reset button is pressed, the function will
    // be called.
    resetButton.addListener(this, &ofApp::resetTheGui);
    
}


void ofApp::update()
{
}


void ofApp::draw()
{
    if (fill)
    {
        ofFill();
    }
    else
    {
        ofNoFill();
    }
        
    ofSetColor(fillColor);

    // Draw a circle with the given radius.
    ofDrawCircle(position, radius);
    
    // We only draw the gui if it is visible.
    if (drawGui)
    {
        // Draw the gui on the screen.
        gui.draw();
    }
}


void ofApp::keyPressed(int key)
{
    if (key == 'g')
    {
        drawGui = !drawGui;
    }
}


void ofApp::resetTheGui()
{
    // To create "base_settings.xml", I saved the xml settings
    // with the gui's save button, then renamed it manually
    // in the finder.
    gui.loadFromFile("base_settings.xml");
}
