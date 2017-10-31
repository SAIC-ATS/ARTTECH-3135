#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofEnableDepthTest();

    // The width, height and depth of our bounding cube.
    boundingSize = { 2000, 500, 1000 };

    int numParticles = 100;

    for (int i = 0; i < numParticles; i++)
    {
        Particle p;

        // Set initial positions.
        p.position.x = 0;
        p.position.y = 0;
        p.position.z = 0;

        // Set initial velocities.
        p.velocity.x = ofRandom(-5, 5);
        p.velocity.y = ofRandom(-5, 5);
        p.velocity.z = ofRandom(-5, 5);

        // Set inital accelerations.
        p.acceleration.x = 0;
        p.acceleration.y = 0;
        p.acceleration.z = 0;

        // Set angular velocity.
        p.angularVelocity.x = ofRandom(-2, 2);
        p.angularVelocity.y = ofRandom(-2, 2);
        p.angularVelocity.z = ofRandom(-2, 2);

        // Set radius.
        p.radius = ofRandom(10, 50);

        // Set color.
        p.color = ofColor::fromHsb(ofRandom(255), 255, 255);

        // Add a copy to our vector.
        particles.push_back(p);
    }
}


void ofApp::update()
{
    // Range for --
    for (Particle& p: particles)
    {
        p.update();

//        // Check to see if our position in inside our bounding cube.
//        if (p.position.x >  boundingSize.x / 2 ||
//            p.position.x < -boundingSize.x / 2 ||
//            p.position.y >  boundingSize.y / 2 ||
//            p.position.y < -boundingSize.y / 2 ||
//            p.position.z >  boundingSize.z / 2 ||
//            p.position.z < -boundingSize.z / 2)
//        {
//            p.position = { 0, 0, 0 };
//        }

        // Check to see if our position in inside our bounding cube.
        // Check x
        if (p.position.x + p.radius >  boundingSize.x / 2)
        {
            p.velocity.x *= -1;
            p.position.x = boundingSize.x / 2 - p.radius;
        }
        else if (p.position.x - p.radius < -boundingSize.x / 2)
        {
            p.velocity.x *= -1;
            p.position.x = - boundingSize.x / 2 + p.radius;
        }

        // Check Y
        if (p.position.y + p.radius >  boundingSize.y / 2)
        {
            p.velocity.y *= -1;
            p.position.y = boundingSize.y / 2 - p.radius;
        }
        else if (p.position.y - p.radius < -boundingSize.y / 2)
        {
            p.velocity.y *= -1;
            p.position.y = - boundingSize.y / 2 + p.radius;
        }

        // Check z
        if (p.position.z + p.radius >  boundingSize.z / 2)
        {
            p.velocity.z *= -1;
            p.position.z = boundingSize.z / 2 - p.radius;
        }
        else if (p.position.z - p.radius < -boundingSize.z / 2)
        {
            p.velocity.z *= -1;
            p.position.z = - boundingSize.z / 2 + p.radius;
        }
    }
}


void ofApp::draw()
{
    cam.begin();

    for (Particle& p: particles)
    {
        p.draw();
    }

    ofNoFill();
    ofSetColor(ofColor::gray);

    // Assumed to be at the origin { 0, 0, 0 }
    ofDrawBox(boundingSize.x, boundingSize.y, boundingSize.z);

    cam.end();

}
