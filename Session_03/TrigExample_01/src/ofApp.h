#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void setup() override;
	void update() override;
	void draw() override;
	void keyPressed(int key) override;

	float angle; // Angle in radians.
	float angularVelocity; // Angular velocity in radians / unit time.

	float radius; // Radius => hypotenuse

	float x0; // X origin
	float y0; // Y origin

	float x1; // X => adjacent
	float y1; // Y => opposite

};
