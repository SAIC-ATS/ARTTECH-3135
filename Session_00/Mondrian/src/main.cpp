#include "ofApp.h"


int main()
{
    ofWindowSettings settings;
    // 770 x 775 is the size of our Mondrian image.
    settings.setSize(770, 775);
    ofCreateWindow(settings);
    return ofRunApp(std::make_shared<ofApp>());
}
