#line 1 "SphereParticle"

#include "ofMain.h"
#include "BaseParticle.h"


#line 2 "SphereParticle"
#pragma once




class SphereParticle: public BaseParticle {
public:
	virtual void draw() {
	    
        // Calculate the normalized age.  This will be used to scale quantities.
        float normalizedAge = getNormalizedAge();

        float sphereRadius = 40;
        float alpha = 180;

        if (normalizedAge > 0.95)
        {
            sphereRadius = ofMap(normalizedAge, 1, 0.95, 1, 40, true);
            alpha = ofMap(normalizedAge, 1, 0.95, 0, 180, true);
        }
        else if (normalizedAge < 0.05)
        {
            sphereRadius = ofMap(normalizedAge, 0.05, 0, 40, 60, true);
            alpha = ofMap(normalizedAge, 0.05, 0, 180, 200, true);

        }

        ofFill();
        ofSetColor(0, 0, 255, alpha);
        ofDrawSphere(position, sphereRadius);
	}
	
};


class CubeParticle: public BaseParticle {
public:
	virtual void draw() {
	    
        // Calculate the normalized speed.  This will be used to scale quantities.
        float normalizedSpeed = ofNormalize(velocity.length(), 0, 10);
    
        // Calculate the normalized age.  This will be used to scale quantities.
        float normalizedAge = ofMap(getAge(), 0, maximumAge, 1, 0);
        
        // Set the alpha color based on the normalized age.
        ofSetColor(255, 255, 255, 255 * normalizedAge);
    
        // Our velocity tells us what direction the particle is moving in. To
        // use it in our angle calculations, we convert our velocity direction 
        // to a "unit" vector by getting its normalized version, which means 
        // that our direction now has a magnitude (length in 3d) of one.
        ofVec3f direction = velocity.getNormalized();

        // Next we decide which was is the "up" direction. For openFrameworks
        // this is usually the "y" axis, so we create a "unit" vector in the 
        // "y" direction.
        ofVec3f upDirection(0, 1, 0);
    
        // In order to construct our rotation, we must determine the angle
        // between our `upVector` and our `direction` vector. This angle 
        // represents the angular displacement on a surface defined by two 
        // vectors, our `upDirection` and our `direction`.
        float rotationAngle = upDirection.angle(direction);
        
        // To use this rotation angle with our 3D transforms we must determine 
        // the axis about which the angle between the vectors was measured.
        // For us it is an axis that is "normal" to the plane defined by our two
        // vectors, which also means it's orthogonal to our two vectors.  To 
        // find the orthogonal vector between to existing vectors, we calculate
        // the vector "cross" product.
        ofVec3f rotationAxis = upDirection.getCrossed(direction);
        
        // Push a new matrix frame onto the stack.
        ofPushMatrix();
        
        // Translate the new frame to the particle's position.
        ofTranslate(position);
        
        // We now rotate using the rotation angle and axis calculated above.
        ofRotate(rotationAngle, rotationAxis.x, rotationAxis.y, rotationAxis.z);
        
        // Use the normalized speed to scale the cone. The y-value is negative 
        // because the cone was drawn upside down originally.
        ofScale(normalizedSpeed, -normalizedSpeed, normalizedSpeed);
        
        // Draw the cone or another object.
        ofDrawCone(0, 0, 0, 10, 30);

        // Pop our current matrix frame off of the stack.
        ofPopMatrix();
        
	}
	
};


