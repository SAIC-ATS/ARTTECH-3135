#include "ofApp.h"


int main()
{
    ofSetupOpenGL(200, 480, OF_WINDOW);
    return ofRunApp(std::make_shared<ofApp>());
}
