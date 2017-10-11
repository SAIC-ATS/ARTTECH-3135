#pragma once


#include "ofMain.h"
#include "Particle.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void audioIn(ofSoundBuffer& input);

    void makeNewParticle(float x, float y);

    std::vector<float> left;
    std::vector<float> right;
    std::vector<float> volHistory;

    int bufferCounter;
    int drawCounter;

    float smoothedVol;
    float scaledVol;

    ofSoundStream soundStream;

    std::vector<Particle> particles;

    std::vector<ofTexture> textures;

};
