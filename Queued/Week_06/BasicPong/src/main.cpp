#include "ofApp.h"


int main()
{
	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.width = 1024;
	settings.height = 768;
	ofCreateWindow(settings);
	return ofRunApp(std::make_shared<ofApp>());
}
