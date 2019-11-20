#pragma once


#include "ofMain.h"
#include "Particle.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    void makeParticleAt(float x, float y);

    glm::vec2 findPositionForNewParticle();

    std::vector<Particle> particles;
    
    ofTexture texture;
    
    std::vector<ofPolyline> textPolylines;

    ofRectangle textBoundingBox;

};

