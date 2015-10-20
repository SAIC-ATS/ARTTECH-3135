#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void draw();

	/// \brief Our single value 0-255 for representing brightness.
	int brightness = 0;

};
