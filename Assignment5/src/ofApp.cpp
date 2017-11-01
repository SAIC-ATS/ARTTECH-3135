#include "ofApp.h"

void ofApp::setup()
{
    ofBackground(0);
    
    tex1.setAnchorPoint(tex1.getWidth()/2, tex1.getHeight()/2);
    tex2.setAnchorPoint(tex2.getWidth()/2, tex2.getHeight()/2);
    tex3.setAnchorPoint(tex3.getWidth()/2, tex3.getHeight()/2);
    tex3.setAnchorPoint(tex4.getWidth()/2, tex4.getHeight()/2);
    
    ofLoadImage(tex1, "s1.png");
    ofLoadImage(tex2, "s2.png");
    ofLoadImage(tex3, "s3.png");
    ofLoadImage(tex4, "s4.png");
    
    std::vector<ofTexture> textures = { tex1, tex2, tex3, tex4 };
    
    soundPlayer.setSpeed(ofRandom(0.1, 10));
    soundPlayer.loadSound("bwahhh.mp3");
    
    randomColor = ofRandom(255);

    for (int i = 0; i < numParticles; i++)
    {
        Particle p = *new Particle(ofRandom(50), *new glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0));
        
        p.angularVelocity.x = 0;
        p.angularVelocity.y = 0;
        p.angularVelocity.z = ofRandom(-1, 1);
                
        // Set color.
        p.color = ofColor::fromHsb(randomColor, 150, 100);
        
        p.myTex = textures[ofRandom(0, textures.size())];

        // Add a copy to our vector.
        particles.push_back(p);
    }
}

//Look at Christopher's Particle_Simple_Texture(?) for deflection mechanics
void ofApp::update()
{
    mouseParticle = *new Particle(5000, glm::vec3(ofGetMouseX(), ofGetMouseY(), 0));

    for (Particle& p: particles)
    {
        p.attract(mouseParticle);
        p.update();
        
        if(glm::distance(p.pos, mouseParticle.pos) < 10)
        {
            soundPlayer.setSpeed(ofRandom(0.1, 10));
            
//            glm::vec3 distance = glm::distance(p.pos, mouseParticle.pos);
//            glm::vec3 deflection = ofNormalize(distance, 0, 1) * -1;
            
            soundPlayer.setVolume(ofRandom(0.1, 0.3));

            soundPlayer.play();
            
            p.pos = glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
        }
    }
}

void ofApp::draw()
{
    ofSetColor(0,0,0,10);

    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofEnableBlendMode(OF_BLENDMODE_ADD);

    for (Particle& p: particles)
    {
        p.draw();
    }
    
    ofDrawBitmapString("click to change colors and reset blobs", ofGetWidth()/3, ofGetHeight()-100);
}

void ofApp::mousePressed(int x, int y, int button)
{
    int randomInt = ofRandom(255);
    for(Particle& p: particles)
    {
        randomColor = ofRandom(randomInt);
        p.color = ofColor::fromHsb(randomColor, 150, 100);
        p.pos = glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    }
}
