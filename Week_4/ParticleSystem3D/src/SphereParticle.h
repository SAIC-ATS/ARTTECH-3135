#line 1 "SphereParticle"

#include "ofMain.h"


#line 1 "SphereParticle"
class SphereParticle: public BaseParticle {
public:
	virtual void draw() {
        ofFill();
        ofSetColor(ofColor::yellow);
        ofDrawSphere(position, 40);
	}
	
};

