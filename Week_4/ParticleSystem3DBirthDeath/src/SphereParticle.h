#line 1 "SphereParticle"

#include "ofMain.h"
#include "BaseParticle.h"


#line 2 "SphereParticle"
#pragma once




class SphereParticle: public BaseParticle {
public:
	virtual void draw() {
        ofFill();
        ofSetColor(255, 255, 0, 127);
        ofDrawSphere(position, 40);
	}
	
};


class CubeParticle: public BaseParticle {
public:
	virtual void draw() {
        ofFill();
        
        float normalizedAge = ofMap(getAge(), 0, maximumAge, 1, 0);
        
        ofSetColor(255, 255, 255, 255 * normalizedAge);
        
        ofPushMatrix();
        ofTranslate(position);
        
        // float angle = 
        // ofQuaternion quat;
        
        // quat.makeRotate(velocity, ofPoint::zero());//position);
        
        float angle = position.angle(velocity);
        
        ofPoint direction = position - velocity;
        
        // position.getAngle(
        
        // quat.getRotate(angle, direction);
        
        ofRotate(angle, direction.x, direction.y, direction.z);
        
        ofDrawCone(0, 0, 0, 40 * normalizedAge, 60 * normalizedAge);
        
        ofPopMatrix();
	}
	
};


