
#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::update()
{
    // Add a little bit to the position.
    position += 1;

    // When the position exceeds the length of the polyline, reset it.
    if (position > polyline.getPerimeter())
    {
        position = 0;
    }

}
void ofApp::draw()
{
    ofBackground(0);

    polyline.draw();

    ofVec3f point = polyline.getPointAtLength(position);

    ofDrawCircle(point, 20);

    ofDrawBitmapStringHighlight("Click / drag mouse to add a vertices.", 20, 20);
    ofDrawBitmapStringHighlight("Press any key to clear them.", 20, 40);
}



void ofApp::mousePressed(int x, int y, int mouse)
{
    polyline.addVertex(x, y);
}

void ofApp::mouseDragged(int x, int y, int mouse)
{
    polyline.addVertex(x, y);
}


void ofApp::keyPressed(int key)
{
    // Remove all of the polylines if any key is pressed.
    polyline.clear();
}
