#include "ofApp.h"


void ofApp::setup()
{
    // 1. First we must set the mesh mode. The mesh mode determines how the
    // vertices (and / or indices) will be grouped and rendered. For example,
    // choosing OF_PRIMITIVE_TRIANGLES will cause each group of three vertices
    // to be interpreted as a discrete triangle.
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    // 2. First we must add position data data to the mesh. These vertices
    // define the positions (in 3d space) for each vertex of the mesh. Here we
    // will define a mesh consisting of 6 vertices { V0, V1, V2, V3, V4, V5 }
    //
    //      [V1]    [V3]----[V5]
    //      /  \       \ T1 /
    //     / T0 \       \  /
    //   [V0]---[V2]    [V4]
    //
    // When using OF_PRIMITIVE_TRIANGLES, these 6 points will be interpreted as
    // two triangles made of three vertices each. In other words, the vertices
    // are "grouped" into groups of three where each group creates a single
    // triangle. Thus we end up with two triangles, T0 and T1.
    //
    // Here we add the 6 vertices:

    glm::vec3 V0 = {  50, 125, 0 };
    glm::vec3 V1 = { 100,  50, 0 };
    glm::vec3 V2 = { 150, 125, 0 };

    glm::vec3 V3 = { 175,  50, 0 };
    glm::vec3 V4 = { 225, 125, 0 };
    glm::vec3 V5 = { 275,  50, 0 };

    // Triangle T0
    mesh.addVertex(V0);
    mesh.addVertex(V1);
    mesh.addVertex(V2);

    // Triangle T1
    mesh.addVertex(V3);
    mesh.addVertex(V4);
    mesh.addVertex(V5);
}


void ofApp::draw()
{
    // Draw the mesh.
    mesh.draw();
}
