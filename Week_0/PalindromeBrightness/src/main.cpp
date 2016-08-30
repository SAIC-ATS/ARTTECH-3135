#include "ofApp.h"


int main()
{
    ofGLWindowSettings settings;
    settings.width = 500;
    settings.height = 500;
    ofCreateWindow(settings);
    return ofRunApp(std::make_shared<ofApp>());
}
