#pragma once


#include "ofMain.h"
#include "BaseParticle.h"


class SphereParticle: public BaseParticle
{
public:
	virtual void draw()
	{
        ofFill();
        ofSetColor(ofColor::yellow);
        ofDrawSphere(position, 40);
	}
	
};

