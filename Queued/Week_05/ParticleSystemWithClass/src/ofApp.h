#pragma once


#include "ofMain.h"
#include "BaseParticle.h"


class ofApp: public ofBaseApp
{
public:
	void setup()
	{
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


	void update()
	{
		for (int i = 0; i < particles.size(); i++)
		{
			particles[i].update();
		}
	}


	void draw()
	{
		ofBackground(0);

		for (int i = 0; i < particles.size(); i++)
		{
			particles[i].draw();
		}
	}
	
	std::vector<BaseParticle> particles;

};
