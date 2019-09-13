#include "ofApp.h"


void ofApp::draw()
{
    ////////////////////////////////////////////////////////////////////////////
    // "On a black wall ..."
    ////////////////////////////////////////////////////////////////////////////
    ofBackground(ofColor::black);

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

    // When drawing large circles, we might want to set a higher resolution.
    ofSetCircleResolution(64);

    // Draw a circle.
    ofDrawCircle(middleX, middleY, radius);

    // Set the distance between the vertical parallel lines.
    float xLineDistance = 8;

    // Cycle through vertical lines in circle.
    for (float x = 0; x < radius; x += xLineDistance)
    {
        // We already know the x value, so we calculate the y-height at x and
        // and then mirror to the bottom half.

        // A function y(x) to find the y-height (from the origin) of a circle at
        // a given x.
        float y = radius * std::sin(std::acos(x / radius));

        // Draw lines to the right.
        ofDrawLine(x + middleX, middleY - y, x + middleX, middleY + y);

        // Draw lines to the left.
        ofDrawLine(middleX - x, middleY - y, middleX - x, middleY + y);

    }

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
    glm::vec2 p0(middleX - width / 2 + offset, topY);

    // The point p1.
    glm::vec2 p1(middleX + width / 2 + offset, topY);

    // The point p0.
    glm::vec2 p2(middleX + width / 2 - offset, bottomY);

    // The point p1.
    glm::vec2 p3(middleX - width / 2 - offset, bottomY);

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

        glm::vec2 lineStart(xStart, y);
        glm::vec2 lineEnd(xStart + width, y);
        ofDrawLine(lineStart, lineEnd);
    }

    ////////////////////////////////////////////////////////////////////////////
    // "... The vertical lines within the circle do not enter the parallelogram,
    ///     and the horizontal lines within the parallelogram do not enter the
    ///     circle."
    ////////////////////////////////////////////////////////////////////////////

    // Yep, did that already.

}
