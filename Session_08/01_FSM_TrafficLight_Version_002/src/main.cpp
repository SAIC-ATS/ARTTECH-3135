#include "ofApp.h"


int main()
{
    ofSetupOpenGL(70, 170, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
