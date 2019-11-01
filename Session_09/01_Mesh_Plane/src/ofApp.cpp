#include "ofApp.h"


void ofApp::setup()
{
    // In this example, we create a "plane" using an ofMesh and random colors
    // for each vertex.

    // We construct our plane from OF_PRIMITIVE_TRIANGLES. This is not the
    // only way one could construct a plane.
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    float w = ofGetWidth();
    float h = ofGetHeight();

    std::size_t nRows = 10;
    std::size_t nCols = 10;

    // Divide up the rectangle into rows / columns.
    for (std::size_t iy = 0; iy < nRows; iy++)
    {
        for (std::size_t ix = 0; ix < nCols;  ix++)
        {
            // Calculate the x and y coordinate based on the current row / col
            // and the w / h of the desired plane.
            float x = w * ix / (nCols - 1);
            float y = h * iy / (nRows - 1);
            mesh.addVertex({x, y, 0});
            mesh.addColor(ofFloatColor::fromHsb(ofRandom(1), 1, 1));
        }
    }

    // The equation to find the index given x and y.
    // index = y * numCols + x;

    // We don't draw the last row / col (nRows - 1 and nCols - 1) because it was
    // taken care of by the row above and column to the left.
    for (int y = 0; y < nRows - 1; y++)
    {
        for (int x = 0; x < nCols - 1; x++)
        {
            // Two Triangles Comprising a Quad
            //
            //  P0 (x + 0, y + 0)
            //  .___________. P1 (x + 1, y + 0)
            //  |          /|
            //  |         / |
            //  |  T0    /  |
            //  |       /   |
            //  |      /    |
            //  |     /     |
            //  |    /      |
            //  |   /       |
            //  |  /   T1   |
            //  | /         |
            //  |/          |
            //  .___________. P3 (x + 1, y + 1)
            //  P2
            //  (x + 0, y + 1)


            // Draw T0
            // P0
            mesh.addIndex((y + 0) * nCols + (x + 0));
            // P1
            mesh.addIndex((y + 0) * nCols + (x + 1));
            // P2
            mesh.addIndex((y + 1) * nCols + (x + 0));

            // Draw T1
            // P1
            mesh.addIndex((y + 0) * nCols + (x + 1));
            // P3
            mesh.addIndex((y + 1) * nCols + (x + 1));
            // P2
            mesh.addIndex((y + 1) * nCols + (x + 0));

        }
    }
}


void ofApp::draw()
{
    mesh.draw();
}
