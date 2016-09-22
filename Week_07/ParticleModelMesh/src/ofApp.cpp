#include "ofApp.h"


void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(0, 0);

    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.
    
    model.loadModel("astroBoy_walk.dae", true);
    model.setPosition(0, -350, 0);
    model.setScale(1, -1, 1);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
}


void ofApp::update()
{
    model.update();

    ofMesh& front = doubleBuffer[currentBuffer];
    ofMesh& back = doubleBuffer[currentBuffer^1];

    // Set the current front buffer.
    front = model.getCurrentAnimatedMesh(2);

    m0 = model.getCurrentAnimatedMesh(0);
    m1 = model.getCurrentAnimatedMesh(1);
    m3 = model.getCurrentAnimatedMesh(3);

    for (auto& v : m0.getVertices()) v *= 2000;
    for (auto& v : m1.getVertices()) v *= 2000;
    for (auto& v : m3.getVertices()) v *= 2000;

    std::vector<ofVec3f>& frontPoints = front.getVertices();

    // Manually scale the vertices to our coordinate space.
    for (auto& v : frontPoints) v *= 2000;

    // Init arrays if it is the first time.
    if (firstTime)
    {
        doubleBuffer[currentBuffer] = front;
        doubleBuffer[currentBuffer^1] = front;
        velocities.resize(front.getVertices().size());
        firstTime = false;
    }

    std::vector<ofVec3f>& backPoints = back.getVertices();

    // Swap buffers for next time.
    currentBuffer ^= 1;

    // Calculate velocities for each position.
    for (std::size_t i = 0; i < frontPoints.size(); ++i)
    {
        velocities[i] = frontPoints[i] - backPoints[i];

        if (velocities[i].lengthSquared() > 70)
        {
            particles.push_back(SimpleParticle(frontPoints[i], velocities[i]));
        }
    }

    // Add particles to a mesh for drawing.
    particleMesh.clear();
    particleMesh.setMode(OF_PRIMITIVE_LINES);

    uint64_t now = ofGetElapsedTimeMillis();

    auto iter = particles.begin();

    while (iter != particles.end())
    {
        uint64_t age = now - iter->born;

        float speed = iter->velocity.lengthSquared();

        if (speed < .5 || age > 3000 || iter->y < -150)
        {
            iter = particles.erase(iter);
        }
        else
        {
            iter->lastPosition = *iter;

            iter->velocity += ofVec3f(0, -0.3, 0); // Gravity
            iter->velocity *= 0.96; // Drag.
            *iter += iter->velocity; // Move the position by the velocity.

            particleMesh.addVertex(iter->lastPosition);
            particleMesh.addVertex(*iter);
            particleMesh.addColor(ofColor::yellow.getLerped(ofColor(255, 0, 0, 0),
                                                            ofMap(speed, 0, 50, 0, 1, true)));
            particleMesh.addColor(ofColor(255, 255, 0, 50));

            ++iter;
        }
    }
}


void ofApp::draw()
{
    ofSetColor(255);

    ofEnableDepthTest();
    cam.begin();

    ofPushMatrix();
    m0.draw(OF_MESH_POINTS);
    m1.draw(OF_MESH_POINTS);
    m3.draw(OF_MESH_POINTS);
    doubleBuffer[currentBuffer].draw(OF_MESH_POINTS);
    particleMesh.draw(OF_MESH_POINTS);

    ofPopMatrix();

    cam.end();
    ofDisableDepthTest();

}


