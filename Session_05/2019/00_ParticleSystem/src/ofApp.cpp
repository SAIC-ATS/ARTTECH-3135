#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    
    ofLoadImage(texture, "brush.png");
    
}


void ofApp::update()
{
    for (int i = 0; i < 5; i++)
    {
        makeParticleAt(ofGetMouseX(), ofGetMouseY());
    }
    
    
    for (std::size_t i = 0; i < particles.size(); i++)
    {
        particles[i].update();

//        if (particles[i].position.y + particles[i].size > ofGetHeight())
//        {
//            // Send the velocity in the opposite direction.
//            particles[i].velocity.y *= -1;
//
//            // Steal a little velocity -- make it 80% of what it was before it
//            // "hit" the wall.
//            // particles[i].velocity.y *= 0.8;
//
//            // Make sure the particle doesn't get stuck on the wrong
//            // side of the wall.
//            particles[i].position.y = ofGetHeight() - particles[i].size;
//        }
    }
    
    // This line will remove dead particles.
    ofRemove(particles, [](Particle p) { return p.isDead(); });
    
    // A C++ way.
    // particles.erase(std::remove_if(particles.begin(), particles.end(), [](Particle p) { return p.isDead(); }), particles.end());
    
    // Another C++ way.
    //    auto iter = particles.begin();
    //
    //    while (iter != particles.end())
    //    {
    //        if (iter->isDead())
    //        {
    //            iter = particles.erase(iter);
    //        }
    //        else
    //        {
    //            ++iter;
    //        }
    //    }
    
    

}


void ofApp::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    for (std::size_t i = 0; i < particles.size(); i++)
    {
        particles[i].draw();
    }
    
    ofDisableBlendMode();
    
    ofDrawBitmapStringHighlight(ofToString(particles.size()), 20, 20);
}


void ofApp::mousePressed(int x, int y, int button)
{
    makeParticleAt(x, y);
}


void ofApp::makeParticleAt(float x, float y)
{
    // Create a particle.
    Particle p;
    
    // Initialize its values.
    p.setup();
    
    // Overwrite the position with the new position x, y.
    p.position.x = x;
    p.position.y = y;

    p.velocity.x = ofRandom(-5, 5);
    p.velocity.y = ofRandom(-5, 0);

    p.size = ofRandom(40, 80);
    
    // Creates a reference inside the particle to
    // the texture I loaded in setup().
    p.texture = texture;
    
    
    // Add the newly created particle to the particles vector.
    particles.push_back(p);
}
