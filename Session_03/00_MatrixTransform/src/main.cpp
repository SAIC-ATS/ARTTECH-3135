#include "ofApp.h"


int main()
{
    ofSetupOpenGL(512, 512, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}

