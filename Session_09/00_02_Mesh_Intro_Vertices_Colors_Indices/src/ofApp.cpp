#include "ofApp.h"


void ofApp::setup()
{
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    /// ... continued from 01_Mesh_Intro_Vertices_Colors/
    ///
    // 4. As, we create increasingly complex mesh geometries and surfaces, we
    // will notice that the same coordinates vertices are used for multiple mesh
    // triangles. Building from the previous example, we might want to create
    // two additional triangles WITHOUT adding additional vertices. In this case
    // we want to add triangles T2 and T3.
    //
    //      [V1]----[V3]----[V5]
    //      /  \ T2 /  \ T1 /
    //     / T0 \  / T3 \  /
    //   [V0]---[V2]----[V4]
    //
    // With this goal in mind, we introduce the concept of "indices". Instead of
    // duplicating V1, V2 and V3 to create T2, we can "re-use" the original
    // vertices V1, V2 and V3 and address them by "index". The index corresponds
    // the their original insertion order. Thus the first vertex added to the
    // mesh is is I0. The second vertex added to the mesh is I1, the third I2,
    // etc. When using indices, we can address an existing vertex AND its
    // associated color. So, using existing vertices, we can create 2 additional
    // triangles without additional data.

    // First we add the vertices and colors as in previous examples.
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

    // (Formerly triangle T0)
    mesh.addVertex(V0); // Index 0
    mesh.addColor(C0);  // Color associated with Index 0

    mesh.addVertex(V1); // Index 1
    mesh.addColor(C1);  // Color associated with Index 1

    mesh.addVertex(V2); // Index 2
    mesh.addColor(C2);  // Color associated with Index 2


    // (Formerly triangle T1)
    mesh.addVertex(V3); // Index 3
    mesh.addColor(C3);  // Color associated with Index 3

    mesh.addVertex(V4); // Index 4
    mesh.addColor(C4);  // Color associated with Index 4

    mesh.addVertex(V5); // Index 5
    mesh.addColor(C5);  // Color associated with Index 5

    // If we just leave the mesh as above without adding any indices, we will
    // get triangle T0 and T1.
    //
    // But we want to construct 4 triangles from the vertices and colors above.

    // Create Triangle T0:
    //
    //      [V1]
    //      /  \
    //     / T0 \
    //   [V0]---[V2]
    //
    //  This triangle is made from index { 0, 1, 2 }.
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(2);

    // Create Triangle T2:
    //
    //      [V1]----[V3]
    //         \ T2 /
    //          \  /
    //          [V2]
    //
    //  This triangle is made from index { 1, 2, 3 }.
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(3);

    // Create Triangle T3:
    //
    //              [V3]
    //              /  \
    //             / T3 \
    //          [V2]----[V4]
    //
    //  This triangle is made from index { 2, 3, 4 }.
    mesh.addIndex(2);
    mesh.addIndex(3);
    mesh.addIndex(4);

    // Create Triangle T1:
    //
    //              [V3]----[V5]
    //                 \ T1 /
    //                  \  /
    //                  [V4]
    //
    //  This triangle is made from index { 3, 4, 5}.
    mesh.addIndex(3);
    mesh.addIndex(4);
    mesh.addIndex(5);

    // NOTE: The order of the indices must come in groups of three when using
    // OF_PRIMITIVE_TRIANGLES. Each group of three will be interpreted as a
    // single triangle. It does NOT matter what the order you add the vertices
    // for any given triangle. For instance, you could also create triangle T1
    // as:
    //
    // mesh.addIndex(3);
    // mesh.addIndex(4);
    // mesh.addIndex(5);
    //
    // ... or ...
    //
    // mesh.addIndex(4);
    // mesh.addIndex(5);
    // mesh.addIndex(3);
    //
    // ... or ...
    //
    // mesh.addIndex(5);
    // mesh.addIndex(4);
    // mesh.addIndex(3);
    //
    // etc.

    // NOTE: If indices are NOT used (as in previous examples), then this would
    // be equivalent to just setting the indices to match the number of
    // vertices, e.g.
    //
    // mesh.addIndex(0);
    // mesh.addIndex(1);
    // mesh.addIndex(2);
    // mesh.addIndex(3);
    // mesh.addIndex(4);
    // mesh.addIndex(5);

}


void ofApp::draw()
{
    // Draw the mesh.
    mesh.draw();
}
