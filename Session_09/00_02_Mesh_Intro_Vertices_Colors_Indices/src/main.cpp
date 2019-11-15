#include "ofApp.h"


int main()
{
    ofSetupOpenGL(325, 175, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
