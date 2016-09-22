#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void setup()
	{
		ofSetWindowShape(512, 512); // Set the initial window size.
		ofBackground(0); // Set the background to 0 (black).
	}

	void draw()
	{
		// Set the drawing color to white.
		ofSetColor(255);

		// Draw vertical lines every 5 pixels while 'x' is less than the window width.
		for (int x = 0; x < ofGetWidth(); x += 5)
		{
			ofDrawLine(x, 0, x, ofGetHeight());
		}

		// Draw horizontal lines every 5 pixels while 'y' is less than the window height.
		for (int y = 0; y < ofGetHeight(); y += 5)
		{
			ofDrawLine(0, y, ofGetWidth(), y);
		}

	}

};


int main()
{
	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.width = 1024;
	settings.height = 768;
	ofCreateWindow(settings);
	ofRunApp(std::make_shared<ofApp>());
}
