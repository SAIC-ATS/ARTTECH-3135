#include "ParticleCube.h"



ParticleCube::ParticleCube()
{
}


ParticleCube::~ParticleCube()
{
}


void ParticleCube::draw()
{
    ofPushMatrix();
    ofTranslate(position); // Move the the position.
    ofRotateX(angle.x); // Rotate along x-axis.
    ofRotateY(angle.y); // Rotate along y-axis.
    ofRotateZ(angle.z); // Rotate along z-axis.
    ofDrawBox(0, 0, 0, 30);
    ofPopMatrix();
}
