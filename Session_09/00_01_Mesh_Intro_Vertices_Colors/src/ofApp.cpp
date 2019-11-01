#include "ofApp.h"


void ofApp::setup()
{
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    /// ... continued from 00_Mesh_Intro_Vertices/
    ///
    // 3. Next we can add color data to the mesh. Colors are assigned on a
    // "per vertex" basis. Thus each vertex is assigned a color value. The
    // renderer will then fill the space between the vertices with colors that
    // blend between each vertex. If the same colors are used for each vertex,
    // solid the no color interpolation is needed because all colors match.
    // For vertices that have different colors, gradients will result.
    //
    // In additiont o the vertices defined previously, we will also assign
    // 6 colors, one for each vertex. Thus:
    //
    //  V0 -> C0 (Color 0)
    //  V1 -> C1 (Color 1)
    //  V2 -> C2 (Color 2)
    //  V3 -> C3 (Color 3)
    //  V4 -> C4 (Color 4)
    //  V5 -> C5 (Color 5)
    //
    //      [C1]    [C3]----[C5]
    //      /  \       \ T1 /
    //     / T0 \       \  /
    //   [C0]---[C2]    [C4]
    //
    // Here we define the 6 vertices from the previous example.

    glm::vec3 V0 = {  50, 125, 0 };
    glm::vec3 V1 = { 100,  50, 0 };
    glm::vec3 V2 = { 150, 125, 0 };

    glm::vec3 V3 = { 175,  50, 0 };
    glm::vec3 V4 = { 225, 125, 0 };
    glm::vec3 V5 = { 275,  50, 0 };

    // Next we define 6 colors, one for each vertex.

    ofColor C0 = ofColor::yellow; // Will be associated with V0.
    ofColor C1 = ofColor::yellow; // Will be associated with V1.
    ofColor C2 = ofColor::yellow; // Will be associated with V2.

    ofColor C3 = ofColor::red;   // Will be associated with V3.
    ofColor C4 = ofColor::green; // Will be associated with V4.
    ofColor C5 = ofColor::blue;  // Will be associated with V5.


    // Triangle T0
    mesh.addVertex(V0);
    mesh.addVertex(V1);
    mesh.addVertex(V2);

    // Triangle T1
    mesh.addVertex(V3);
    mesh.addVertex(V4);
    mesh.addVertex(V5);

    // Triangle T0
    mesh.addColor(C0);
    mesh.addColor(C1);
    mesh.addColor(C2);

    // Triangle T1
    mesh.addColor(C3);
    mesh.addColor(C4);
    mesh.addColor(C5);

    // NOTE: ofMesh keeps a collection of vertices and a collection of colors.
    // Thus it doesn't matter if you add vertices or colors first. What matters
    // is the order in which they are added. When rendering, ofMesh startes with
    // the first vertex and color and starts building groups based on the mode.
}


void ofApp::draw()
{
    // Draw the mesh.
    mesh.draw();
}
