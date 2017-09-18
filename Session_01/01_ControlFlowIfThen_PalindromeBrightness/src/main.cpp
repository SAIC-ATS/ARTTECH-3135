#include "ofApp.h"


int main()
{
    ofGLWindowSettings settings;
    settings.width = 512;
    settings.height = 512;
    ofCreateWindow(settings);
    return ofRunApp(std::make_shared<ofApp>());
}
