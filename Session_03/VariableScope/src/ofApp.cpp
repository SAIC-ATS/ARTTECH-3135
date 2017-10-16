#include "ofApp.h"


int myGlobal = 8; // This is a "global" variable.


void ofApp::setup()
{

    ofDrawAxis();

    int myVariable = 88; // be careful not to override the variable by name ...
    std::cout << myVariable << std::endl;

//    int myA = 0; // is limited to the "scope" of the function ofApp::setup()
//
//    std::cout << myA << std::endl;
//
//    if (myA == 0)
//    {
//        int myB = 1;
//
//    }
//    else
//    {
//        std::cout << myC << std::endl;
//        std::cout << myA << std::endl;
////        std::cout << myB << std::endl; // Can't access the scope of myB ...
//    }


    for (int i = 0; i < 10; i++)
    {
        std::cout << i << std::endl;
    }

//    std::cout << i << std::endl;

}


void ofApp::draw()
{
    std::cout << myVariable << std::endl;


   // std::cout << myA << std::endl;
}


void ofApp::keyPressed(int key)
{
    std::cout << myC << std::endl;
}
