#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void draw();

	/// \brief Our single value 0-255 for representing brightness.
	int brightness = 0;

	/// \brief  If this is true, then we are increasing in brightness,
	/// otherwise decreasing.
	bool isBrightnessIncreasing = true;

};
