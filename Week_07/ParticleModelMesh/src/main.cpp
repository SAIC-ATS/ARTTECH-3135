#include "ofApp.h"


int main()
{
	ofSetupOpenGL(1024, 768, OF_WINDOW);
    ofRunApp(std::make_shared<ofApp>());
}
