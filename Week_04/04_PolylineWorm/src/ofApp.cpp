
#include "ofApp.h"


void ofApp::setup()
{
}


void ofApp::update()
{
    updateCounter();


    if (needsResample)
    {
        resampledPolyline = polyline.getResampledBySpacing(2);
        needsResample = false;
    }


////    outerPolyline.
//    for (std::size_t i = 0; i < resampledPolyline.size(); ++i)
//    {
//        float thickness = ofMap(std::abs(i - position), 0, polyline.getPerimeter(), 1, 20);
//
//        
//
//    }


}
void ofApp::draw()
{
    ofBackground(0);

    polyline.draw();

//    ofDrawCircle(point, 20);

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


void ofApp::mouseReleased(int x, int y, int button)
{
    needsResample = true;
}


void ofApp::keyPressed(int key)
{
    if (key == 'c')
    {
        // Remove all of the polylines if any key is pressed.
        polyline.clear();
    }
    else if (key == 'p')
    {
        // Toggle palindrome.
        counterPalindrome = !counterPalindrome;
    }
    else if (key == 'r')
    {
        // Reset the counter.
        counter = 0;
    }
}


void ofApp::updateCounter()
{
    // Add a little bit to the percentage.
    //
    // This percentage value is simply a small counter that we can count on to
    // go between 0 and 1.
    counter += counterIncrement;

    // When the position exceeds the length of the polyline, reset it.
    if (percent > resampledPolyline.size())
    {
        position = 0;
    }
}

