#include "ofApp.h"


void ofApp::setup()
{
    bool myBool = true;
    
    if (myBool == true)
    {
        std::cout << "hello" << std::endl;
    }
    else
    {
        std::cout << "blah" << std::endl;
    }

    bool myOtherBool = (myBool && false) || true;
    
    if (myOtherBool)
    {
        std::cout << "hello 2" << std::endl;
    }
    else
    {
        std::cout << "blah 2" << std::endl;
    }

    
    
    ofMap(
    
    
}
