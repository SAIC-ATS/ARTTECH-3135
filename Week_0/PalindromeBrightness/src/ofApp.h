#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void draw();

	/// Our single value 0-255 for representing brightness.
	int brightness = 0;

	/// If this is true, then we are increasing in brightness,
	/// otherwise decreasing.
	bool isBrightnessIncreasing = true;

};
