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

    // Width between the horizontal and vertical lines.
    float lineSpacing = 8;

    // The height of the trapezoid.
    float height = ofGetHeight() * 0.9;

    // The width of the bottom line.
    float bottomWidth = ofGetWidth() * 0.9;

    // The width of the top line.
    float topWidth = ofGetWidth() * 0.5;

    // The middle of the window in the x-direction.
    float middleX = ofGetWidth() / 2;

    // The middle of the window in the y-direction.
    float middleY = ofGetHeight() / 2;

    // The y-position of the top line.
    float topY = middleY - height / 2;

    // The y-position of the bottom line.
    float bottomY = middleY + height / 2;

    // The point p0.
    float p0x = middleX - topWidth / 2;
    float p0y = topY;

    // The point p1.
    float p1x = middleX + topWidth / 2;
    float p1y = topY;

    // The point p0.
    float p2x = middleX + bottomWidth / 2;
    float p2y = bottomY;

    // The point p1.
    float p3x = middleX - bottomWidth / 2;
    float p3y = bottomY;

    // Draw the four trapezoid lines.
    ofDrawLine(p0x, p0y, p1x, p1y);
    ofDrawLine(p1x, p1y, p2x, p2y);
    ofDrawLine(p2x, p2y, p3x, p3y);
    ofDrawLine(p3x, p3y, p0x, p0y);

    ////////////////////////////////////////////////////////////////////////////
    // "... within which are white vertical parallel lines ... "
    ////////////////////////////////////////////////////////////////////////////

    for (float x = p3x; x <= p2x; x += lineSpacing)
    {
        // We have three conditions, the right triangle ...
        if (x <= p0x)
        {
            // The slope-intercept form of a line!

            // y = m * x + b; where m = Δy / Δx = (y1 - y0) / (x1 - x0)

            // Calculate the slope `m` of the line that connects p0 and p3
            float Δy = p3y - p0y;
            float Δx = p3x - p0x;

            float m = Δy / Δx;

            // Calculate the intercept `b`.
            //
            // b = y - m * x
            //
            // Choose either point, p0 or p3 to solve for b.
            float b = p0y - m * p0x;

            // Now calculate y for our current x;
            float y = m * x + b;

            // Now draw the line!
            ofDrawLine(x, bottomY, x, y);
        }
        // ... the middle box ...
        else if (x <= p1x)
        {
            // A simple line.
            ofDrawLine(x, bottomY, x, topY);
        }
        // ... and the left triangle.
        else
        {
            // The slope-intercept form of a line!

            // y = m * x + b; where m = Δy / Δx = (y1 - y0) / (x1 - x0)

            // Calculate the slope `m` of the line that connects p1 and p2
            float Δy = p1y - p2y;
            float Δx = p1x - p2x;

            float m = Δy / Δx;

            // Calculate the intercept `b`.
            //
            // b = y - m * x
            //
            // Choose either point, p0 or p3 to solve for b.
            float b = p1y - m * p1x;

            // Now calculate y for our current x;
            float y = m * x + b;

            // Now draw the line!
            ofDrawLine(x, bottomY, x, y);
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
    for (float y = middleY - halfSquareSize; y < middleY + halfSquareSize; y += lineSpacing)
    {
        ofDrawLine(middleX - halfSquareSize, y, middleX + halfSquareSize, y);
    }

    ////////////////////////////////////////////////////////////////////////////
    // ... The vertical lines within the trapezoid do not enter the square ...
    // ... and the horizontal lines within the square do not enter the ...
    // ... trapezoid."
    ////////////////////////////////////////////////////////////////////////////

    // Yep, did that already.
}
