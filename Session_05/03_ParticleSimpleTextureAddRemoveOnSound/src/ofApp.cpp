#include "ofApp.h"


void ofApp::setup()
{
    int bufferSize = 256;
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(bufferSize, 0.0);

    bufferCounter = 0;
    drawCounter = 0;
    smoothedVol = 0;
    scaledVol = 0;

    auto devices = soundStream.getMatchingDevices("default");

    ofSoundStreamSettings settings;

    if (!devices.empty()) {
        settings.setInDevice(devices[0]);
    }

    settings.setInListener(this);
    settings.sampleRate = 44100;
    settings.numOutputChannels = 0;
    settings.numInputChannels = 2;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);

    ofBackground(0);

    ofTexture tex0;
    ofTexture tex1;
    ofTexture tex2;
    ofTexture tex3;

    ofLoadImage(tex0, "s1.png");
    ofLoadImage(tex1, "s2.png");
    ofLoadImage(tex2, "s3.png");
    ofLoadImage(tex3, "s4.png");

    textures = { tex0, tex1, tex2, tex3 };
}


void ofApp::update()
{
    int numParticlesToGenerate = ofMap(smoothedVol, 0.1, 0.3, 0, 100, true);

    for (int i = 0; i < numParticlesToGenerate; i++)
    {
        makeNewParticle(ofGetWidth() / 2, ofGetHeight());
    }

    ofRectangle screenRect(0, 0, ofGetWidth(), ofGetHeight());

    // Get an iterator that points to the first element in our vector.
    auto iter = particles.begin();

    // Iterate through all particles.
    while (iter != particles.end())
    {
        iter->update();

        // Is the current particle on the screen?
        if (screenRect.inside(iter->position) == false)
        {
            iter = particles.erase(iter);
        }
        else
        {
            iter++;
        }
    }
}


void ofApp::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    for (Particle& p: particles)
    {
        p.draw();
    }

    ofSetColor(255);
    ofDrawBitmapString("Num Particles: " + ofToString(particles.size()), 14, 14);
    ofDrawBitmapString("Volume: " + ofToString(smoothedVol), 14, 28);

}


void ofApp::audioIn(ofSoundBuffer& input)
{
    float curVol = 0.0;
    int numCounted = 0;

    for (int i = 0; i < input.getNumFrames(); i++)
    {
        left[i] = input[i * 2 ] * 0.5;
        right[i] = input[i * 2 +1 ] * 0.5;

        curVol += left[i] * left[i];
        curVol += right [i] * right [i];
        numCounted += 2;

    }

    curVol /= (float) numCounted;
    curVol = sqrt (curVol);

    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;

    bufferCounter++;
}

void ofApp::makeNewParticle(float x, float y)
{
    Particle p;
    // Set initial positions.
    p.position.x = x;
    p.position.y = y;
    p.position.z = 0;

    // Set initial velocities.
    p.velocity.x = ofRandom(-2, 2);
    p.velocity.y = ofRandom(-5, 5);
    p.velocity.z = 0;

    // Set inital accelerations.
    p.acceleration.x = 0;
    p.acceleration.y = -0.1;
    p.acceleration.z = 0;

    // Set angular velocity.
    p.angularVelocity.x = 0;
    p.angularVelocity.y = 0;
    p.angularVelocity.z = ofRandom(-2, 2);

    // Set color.
    p.color = ofColor(ofRandom(180, 200), 100);

    // Assign a texture.
    std::size_t randomTextureIndex = ofRandom(0, textures.size());

    p.texture = textures[randomTextureIndex];

    // Add a copy to our vector.
    particles.push_back(p);

}


