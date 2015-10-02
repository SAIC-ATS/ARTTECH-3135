#line 1 "ParticleSystemWithClass"

#include "ofMain.h"
#include "BaseParticle.h"


class ofApp: public ofBaseApp
{
public:

#line 2 "ParticleSystemWithClass"

std::vector<BaseParticle> particles;

void setup() {
    ofSetWindowShape(800, 800);
    for (int i = 0; i < 100; i++)
    {
        BaseParticle particle;
        particle.position.x = ofRandomWidth();
        particle.position.y = ofRandomHeight();
        particle.velocity.x = ofRandom(-10, 10);
        particle.velocity.y = ofRandom(-10, 10);
        particle.drag = ofRandom(0.1, 0.99);

        particles.push_back(particle);
    }
}


void update() {
    for (int i = 0; i < particles.size(); i++)
    {
        particles[i].update();
    }
}


void draw() {
    ofBackground(0);
    for (int i = 0; i < particles.size(); i++)
    {
        particles[i].draw();
    }
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

