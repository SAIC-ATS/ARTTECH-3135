#include "ofApp.h"


int main()
{
    ofGLWindowSettings settings;
    // 770 x 775 is the size of our Mondrian image.
    settings.width = 770;
    settings.height = 775;
    ofCreateWindow(settings);
    return ofRunApp(std::make_shared<ofApp>());
}
