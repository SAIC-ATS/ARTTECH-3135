#include "ofApp.h"


void ofApp::setup()
{
    // Load the image, which is in our project's bin/data directory.
    image.load("image.jpg");

    // We can adjust these to make them more Mondrian-like.
    // These were chosen by using the color picker on the image in Photoshop.
    mondrianRed = ofColor(216, 39, 39);
    mondrianBlue = ofColor(2, 91, 159);
    mondrianYellow = ofColor(239, 221, 111);
    mondrianBlack = ofColor(3, 8, 4);
    mondrianWhite = ofColor(228, 226, 227);

}

void ofApp::draw()
{
    // Here we set variables w and h, so we don't have to call
    // ofGetWidth() / ofGetHeight() so often. Basically it just saves space.
    float w = ofGetWidth();
    float h = ofGetHeight();

    // We do the same for mouse x and mouse y.
    float mx = ofGetMouseX();
    float my = ofGetMouseY();

    // These are percentages of the width
    // These were chosen by experimentation.
    float x0 = w * 0.231;
    float x1 = w * 0.905;


    // These are percentages of the height.
    // These were chosen by experimentation.
    float y0 = h * 0.332;
    float y1 = h * 0.74;
    float y2 = h * 0.875;


    // Make one big white rectangle to cover the entire canvas.
    ofSetColor(mondrianWhite);
    ofDrawRectangle(0, 0, w, h);

    // Make the red rectangle.
    ofSetColor(mondrianRed);
    ofDrawRectangle(x0, 0, w - x0, y1);

    // Make the yellow rectangle
    ofSetColor(mondrianYellow);
    ofDrawRectangle(x1, y2, w - x1, h - y2);

    // Make the blue rectangle
    ofSetColor(mondrianBlue);
    ofDrawRectangle(0, y1, x0, h - y1);

    // Make black stripes.
    ofSetColor(mondrianBlack, 255);

    // These black line widths were determinted experimentally.
    float x0Width = w * 0.03;
    float x1Width = w * 0.035;

    ofDrawRectangle(x0 - x0Width / 2, 0, x0Width, h);
    ofDrawRectangle(x1 - x1Width / 2, y1, x1Width, h);

    float y0Height = h * 0.06;
    float y1Height = h * 0.03;
    float y2Height = h * 0.045;

    ofDrawRectangle(0,  y0 - y0Height / 2, x0,     y0Height);
    ofDrawRectangle(0,  y1 - y1Height / 2, w,      y1Height);
    ofDrawRectangle(x1, y2 - y2Height / 2, w - x1, y2Height);


    // If the spacebar is pressed, then extra stuff will be drawn.
    if (ofGetKeyPressed(' '))
    {
        // We set the drawing color of the image.
        ofSetColor(255);

        // We draw the image at 0, 0 and make it the width and height of our window.
        image.draw(0, 0, w, h);

        // Guide lines and labels.
        float labelOffset = 18;

        ofSetColor(127);
        ofDrawLine(x0, 0, x0, h);
        ofDrawBitmapStringHighlight("x0", x0 + labelOffset, labelOffset);

        ofDrawLine(x1, 0, x1, h);
        ofDrawBitmapStringHighlight("x1", x1 + labelOffset, labelOffset);

        ofDrawLine(0, y0, w, y0);
        ofDrawBitmapStringHighlight("y0", labelOffset, y0 + labelOffset);

        ofDrawLine(0, y1, w, y1);
        ofDrawBitmapStringHighlight("y1", labelOffset, y1 + labelOffset);

        ofDrawLine(0, y2, w, y2);
        ofDrawBitmapStringHighlight("y2", labelOffset, y2 + labelOffset);

        ofDrawBitmapStringHighlight("Original Image Overlay", w / 2 -50, h / 2);

        // The following just gives us feedback on the position as a percentage.
        std::string positionInfo = "(";
        // ofToString converts numbers to text, in this case with only 2 decimal places.
        positionInfo += ofToString(mx / w, 3);
        positionInfo += ",";
        positionInfo += ofToString(my / h, 3);
        positionInfo += ")";

        // We offset it just a bit from the mouse so we can see things better.
        ofDrawBitmapStringHighlight(positionInfo, mx + labelOffset, my - labelOffset);
    }
}
