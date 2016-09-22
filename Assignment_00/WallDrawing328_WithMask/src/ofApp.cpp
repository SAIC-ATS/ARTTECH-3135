#include "ofApp.h"


void ofApp::draw()
{
    ////////////////////////////////////////////////////////////////////////////
    // "On a black wall ..."
    ////////////////////////////////////////////////////////////////////////////
    ofBackground(ofColor::black);

    ////////////////////////////////////////////////////////////////////////////
    // "... within which are white vertical parallel lines ... "
    ////////////////////////////////////////////////////////////////////////////

    // Set the distance between the vertical parallel lines.
    float xLineDistance = 8;

    for (float x = 0; x < ofGetWidth(); x += xLineDistance)
    {
        ofDrawLine(x, 0, x, ofGetHeight());
    }

    ////////////////////////////////////////////////////////////////////////////
    // "...a white circle within which are white vertical parallel lines ..."
    ////////////////////////////////////////////////////////////////////////////

    // Don't fill anything.
    ofNoFill();

    // Set the drawing color to white.
    ofSetColor(ofColor::white);

    // The middle of the window in the x-direction.
    float middleX = ofGetWidth() / 2;

    // The middle of the window in the y-direction.
    float middleY = ofGetHeight() / 2;

    // The height of the trapezoid.
    float size = ofGetHeight() * 0.9;

    // The radius of the circle.
    float radius = size / 2;

    // Construct a mask.
    ofPath circleMask;
    circleMask.setFillColor(ofColor::black);
    circleMask.rectangle(0, 0, ofGetWidth(), ofGetHeight());
    circleMask.setCircleResolution(64);
    circleMask.circle(middleX, middleY, radius);
    circleMask.draw();

    // When drawing large circles, we might want to set a higher resolution.
    ofSetCircleResolution(64);

    // Draw a circle.
    ofDrawCircle(middleX, middleY, radius);

    ////////////////////////////////////////////////////////////////////////////
    /// "... and a white parallelogram within which are white horizontal
    ///      parallel lines. ..."
    ////////////////////////////////////////////////////////////////////////////
    //
    //              p0 (line 0) p1
    //             ______________  _ _ _ _ _ _
    //            /    |        /            |
    //           /     |       /             |
    // (line 3) /------o------/  | (line 1)  |
    //         /       |     /               | height
    //        /________|____/ _ _ _ _ _ _ _ _|
    //     p3    (line 2)   | p2 |
    //
    //      |----total width ----|
    //      |------width----|
    //                      |----| offset
    //
    // Parallelogram points p0, p1, p2, p3.

    // The parallelogram width (see diagram).
    float width = 320;

    // The parallelogram width (see diagram).
    float height = 320;

    // The parallelogram offset (see diagram).
    float offset = 40;

    // The y-position of the top line.
    float topY = middleY - height / 2;

    // The y-position of the bottom line.
    float bottomY = middleY + height / 2;

    // The point p0.
    ofVec2f p0(middleX - width / 2 + offset, topY);

    // The point p1.
    ofVec2f p1(middleX + width / 2 + offset, topY);

    // The point p0.
    ofVec2f p2(middleX + width / 2 - offset, bottomY);

    // The point p1.
    ofVec2f p3(middleX - width / 2 - offset, bottomY);

    // Construct and draw a paralellogram.
    ofPath parallelogram;
    parallelogram.setFillColor(ofColor::black);
    parallelogram.setStrokeColor(ofColor::white);
    parallelogram.setFilled(true);
    parallelogram.setStrokeWidth(1);
    parallelogram.moveTo(p0);
    parallelogram.lineTo(p1);
    parallelogram.lineTo(p2);
    parallelogram.lineTo(p3);
    parallelogram.lineTo(p0);
    parallelogram.draw();

    // Set the distance between the horizontal parallel lines.
    float yLineDistance = xLineDistance;

    for (float y = topY; y < bottomY; y += yLineDistance)
    {
        float xStart = ofMap(y, topY, bottomY, p0.x, p3.x);

        ofVec2f lineStart(xStart, y);
        ofVec2f lineEnd(xStart + width, y);
        ofDrawLine(lineStart, lineEnd);
    }

    ////////////////////////////////////////////////////////////////////////////
    // "... The vertical lines within the circle do not enter the parallelogram,
    ///     and the horizontal lines within the parallelogram do not enter the
    ///     circle."
    ////////////////////////////////////////////////////////////////////////////

    // Yep, did that already.

}
