#include "ofApp.h"


void ofApp::draw()
{
    ////////////////////////////////////////////////////////////////////////////
    // "On a black wall ..."
    ////////////////////////////////////////////////////////////////////////////
    ofBackground(ofColor::black);

    ////////////////////////////////////////////////////////////////////////////
    // "... a white trapezoid ..."
    ////////////////////////////////////////////////////////////////////////////
    //
    //          p0 (line 0) p1
    //             _________
    //            /         \
    //           /           \
    // (line 3) /             \ (line 1)
    //         /               \
    //        /                 \
    //       /___________________\
    //    p3        (line 2)       p2
    //
    // Trapezoid points p0, p1, p2, p3.

    // Don't fill anything.
    ofNoFill();

    // Set the drawing color to white.
    ofSetColor(ofColor::white);

    // The height of the trapezoid.
    float height = ofGetHeight() * 0.9;

    // The width of the top line.
    float topWidth = ofGetWidth() * 0.5;

    // The width of the bottom line.
    float bottomWidth = ofGetWidth() * 0.9;

    // The middle of the window in the x-direction.
    float middleX = ofGetWidth() / 2;

    // The middle of the window in the y-direction.
    float middleY = ofGetHeight() / 2;

    // The y-position of the top line.
    float topY = middleY - height / 2;

    // The y-position of the bottom line.
    float bottomY = middleY + height / 2;

    // The point p0.
    glm::vec2 p0(middleX - topWidth / 2, topY);

    // The point p1.
    glm::vec2 p1(middleX + topWidth / 2, topY);

    // The point p0.
    glm::vec2 p2(middleX + bottomWidth / 2, bottomY);

    // The point p1.
    glm::vec2 p3(middleX - bottomWidth / 2, bottomY);

    // Draw the four trapezoid lines.
    ofDrawLine(p0, p1);
    ofDrawLine(p1, p2);
    ofDrawLine(p2, p3);
    ofDrawLine(p3, p0);

    ////////////////////////////////////////////////////////////////////////////
    // "... within which are white vertical parallel lines ... "
    ////////////////////////////////////////////////////////////////////////////

    // Figure out if the top or bottom is wider.
    float maximumWidth = std::max(topWidth, bottomWidth);

    // Set the distance between the vertical parallel lines.
    float xLineDistance = 8;

    // We will cycle through all vertical lines at spacing xLineDistance and
    // deterimne where they intersect our four trapezoid lines.
    for (int x = 0; x < ofGetWidth(); x += xLineDistance)
    {
        glm::vec2 lineStart(x, 0);
        glm::vec2 lineEnd(x, ofGetHeight());

        glm::vec2 intersection;

        // We will search for the minimum and maximum Y values representing
        // intersections with our vertical lines.
        float minY = ofGetHeight();
        float maxY = 0;

        // Test line 0
        if (ofLineSegmentIntersection(lineStart, lineEnd, p0, p1, intersection))
        {
            minY = std::min(minY, intersection.y);
            maxY = std::max(maxY, intersection.y);
        }

        // Test line 1
        if (ofLineSegmentIntersection(lineStart, lineEnd, p1, p2, intersection))
        {
            minY = std::min(minY, intersection.y);
            maxY = std::max(maxY, intersection.y);
        }

        // Test line 2
        if (ofLineSegmentIntersection(lineStart, lineEnd, p2, p3, intersection))
        {
            minY = std::min(minY, intersection.y);
            maxY = std::max(maxY, intersection.y);
        }

        // Test line 3
        if (ofLineSegmentIntersection(lineStart, lineEnd, p3, p0, intersection))
        {
            minY = std::min(minY, intersection.y);
            maxY = std::max(maxY, intersection.y);
        }

        if (maxY > 0 and minY < ofGetHeight())
        {
            ofDrawLine(x, minY, x, maxY);
        }
    }


    ////////////////////////////////////////////////////////////////////////////
    // "... and a white square ... "
    ////////////////////////////////////////////////////////////////////////////

    // We DO want to fill this square with black to cover up our vertical lines.
    ofFill();

    // Set the drawing color to white.
    ofSetColor(ofColor::black);

    // Set the size of the square.
    float squareSize = 350;

    // Figure out half the size for convenience.
    float halfSquareSize = squareSize / 2;

    // Draw the black filled square.
    ofDrawRectangle(middleX - halfSquareSize, middleY - halfSquareSize, squareSize, squareSize);

    // No back to just drawing outlines.
    ofNoFill();

    // Set the drawing color to white.
    ofSetColor(ofColor::white);

    // Draw the the same square as an outline.
    ofDrawRectangle(middleX - halfSquareSize, middleY - halfSquareSize, squareSize, squareSize);

    ////////////////////////////////////////////////////////////////////////////
    // "... within which are white horizontal parallel lines."
    ////////////////////////////////////////////////////////////////////////////

    // Set the distance between the horizontal parallel lines.
    float yLineDistance = xLineDistance;

    for (float y = middleY - halfSquareSize; y < middleY + halfSquareSize; y += yLineDistance)
    {
        glm::vec2 lineStart(middleX - halfSquareSize, y);
        glm::vec2 lineEnd(middleX + halfSquareSize, y);
        ofDrawLine(lineStart, lineEnd);
    }

    ////////////////////////////////////////////////////////////////////////////
    // ... The vertical lines within the trapezoid do not enter the square ...
    // ... and the horizontal lines within the square do not enter the ...
    // ... trapezoid."
    ////////////////////////////////////////////////////////////////////////////

    // Yep, did that already.
}
