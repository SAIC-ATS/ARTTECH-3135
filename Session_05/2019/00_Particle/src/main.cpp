#include "ofApp.h"


int main()
{
    ofSetupOpenGL(200, 1024, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}

