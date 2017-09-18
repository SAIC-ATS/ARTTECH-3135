#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    int i = 5 % 2;

    std::cout << i << std::endl;


    for (int i = 0; i < 10; i++)
    {
        if (( i % 2 ) == 0)
        {
            // i is even.
            std::cout << i << " is even." << std::endl;
        }
        else
        {
            // i is odd.
            std::cout << i << " is odd." << std::endl;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        if (( i % 3 ) == 0)
        {
            // i is even.
            std::cout << i << " is a multiple of three." << std::endl;
        }
        else
        {
            // i is odd.
            std::cout << i << " is not a multiple of three." << std::endl;
        }
    }

    // as a replace
    for (int i = 0; i < 100; i++)
    {
        std::cout << i << " -> " << (i % 15) << std::endl;
    }

}
