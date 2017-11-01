#pragma once


#include "ofMain.h"
#include "Particle.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    
    std::vector<Particle> particles;
    
    Particle mouseParticle;

    ofSoundPlayer soundPlayer;
    
    ofImage myImage;

    ofTexture tex1;
    ofTexture tex2;
    ofTexture tex3;
    ofTexture tex4;
    ofTexture mouseTex;
    
    int randomColor;
    int numParticles = 200;
};
