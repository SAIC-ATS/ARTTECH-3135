#pragma once


#include "ofMain.h"


// Our application class.  We can call it whatever we like, but here we choose
// ofApp because lots of other examples do.
//
// ofBaseApp is the "base" class that we build from.  It provides all of the
// basic functionality that is important to a program, like pointer events,
// keyboard events and a program loop that keeps drawing.
class ofApp: public ofBaseApp
{
public:
    // We override the draw function provided by ofBaseApp.
	void draw() override;

	// Our only variable -- a single value 0 - 255 for representing brightness.
	int brightness = 0;

};
