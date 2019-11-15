#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);

    ofSpherePrimitive sphere(10, 64);
    meshSphere = sphere.getMesh();
    vboMeshSphere = sphere.getMesh();

    noiseStep = { 0.001, 0.001, 0.001 };
}


void ofApp::draw()
{
    noiseOffset += noiseStep;

    cam.begin();

    ofEnableDepthTest();

    float width = 1000;
    float height = 1000;
    float depth = 1000;
    float stepSize = 100;
    std::size_t numMeshes = 0;

    for (float x = - width / 2; x < width / 2; x += stepSize)
    {
        for (float y = - height / 2; y < height / 2; y += stepSize)
        {
            for (float z = - depth / 2; z < depth / 2; z += stepSize)
            {
                glm::vec3 position(x, y, z);

                ofPushMatrix();
                ofTranslate(position);

                glm::vec3 noisePosition = position / 100 + noiseOffset;

                float scale = 10 * ofNoise(noisePosition);

                ofScale(scale, scale, scale);

                float h = ofMap(x, - width / 2, width / 2, 0, 255);
                float s = ofMap(y, - height / 2, height / 2, 0, 255);
                float b = ofMap(z, - depth / 2, depth / 2, 0, 255);

                ofColor color = ofColor::fromHsb(h, s, b);

                ofSetColor(color);

                if (drawVboMesh)
                {
                    vboMeshSphere.draw();
                }
                else
                {
                    meshSphere.draw();
                }

                ofPopMatrix();

                numMeshes++;
            }
        }
    }

    ofDisableDepthTest();

    cam.end();

    std::stringstream ss;
    ss << "FPS: " << ofGetFrameRate() << std::endl;
    ss << "Num Meshes: " << numMeshes << std::endl;
    ss << "Using " << (drawVboMesh ? "ofVboMesh (fast)" : "ofMesh (slow)") << std::endl;
    ss << std::endl;
    ss << "Press (Spacebar) to Toggle" << std::endl;
    ss << "Use Mouse to Move Camera";
    ofDrawBitmapStringHighlight(ss.str(), 40, 40);

}


void ofApp::keyPressed(int key)
{
    drawVboMesh = !drawVboMesh;
}
