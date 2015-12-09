#include "ofApp.h"


void ofApp::setup()
{
    model.loadModel("astroBoy_walk.dae", true);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();

    camera.setPosition(100, 100, 100);

    rotationOffset = 0;

    alpha = 0.9;
}


void ofApp::update()
{
    model.update();
    updateCamera();
}


void ofApp::draw()
{
    ofBackgroundGradient(ofColor::wheat, ofColor::black);
    camera.begin();

    ofSetColor(255, 40);
    ofDrawAxis(50);

    ofMesh mesh = model.getCurrentAnimatedMesh(0);

    ofPushMatrix();
    ofScale(100, 100, 100);
    mesh.drawWireframe();

    model.getCurrentAnimatedMesh(0).drawFaces();
    model.getCurrentAnimatedMesh(1).drawWireframe();
    model.getCurrentAnimatedMesh(2).drawWireframe();
    model.getCurrentAnimatedMesh(3).drawWireframe();

    ofPopMatrix();

    camera.end();

}


void ofApp::updateCamera()
{
    ofxAssimpAnimation& animation = model.getAnimation(0);

    ofMesh mesh = model.getCurrentAnimatedMesh(0);

    ofVec3f modelCentroid = mesh.getCentroid();

    modelCentroid *= 100.0; // Scale everything by 100.

    smoothedModelCentroid = modelCentroid * (1 - alpha) + modelCentroid * alpha;

    ofVec3f cameraPosition = camera.getPosition();

    // Rotate around the z-axis based on animation position.

//    animation.get

    rotationOffset = 1;

    cameraPosition.rotate(rotationOffset, ofVec3f(0, 1, 0));

    cameraPosition.y = smoothedModelCentroid.y;

    camera.setPosition(cameraPosition);
    camera.lookAt(smoothedModelCentroid);


}
