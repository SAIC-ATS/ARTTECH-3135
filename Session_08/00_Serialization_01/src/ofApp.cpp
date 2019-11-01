#include "ofApp.h"


void ofApp::setup()
{
    ofColor color = ofColor::red;
    
    ofJson json;
    
    json["color"]["r"] = color.r;
    json["color"]["g"] = color.g;
    json["color"]["b"] = color.b;
    json["color"]["a"] = color.a;

    json["the_value_of_pi"] = 3.14;
    
    std:vector<float> myFloats = { 1.1, 2.2, 3.3 };
    
    json["my_floats"] = myFloats;
    
    // Save the json as text to the disk.
    ofSaveJson("my_json.json", json);
    
    // View the contents of the json file.
    std::cout << json.dump(4) << std::endl;
    
    // Load the saved json from the disk.
    ofJson loadedJson = ofLoadJson("my_json.json");
    
    ofColor myLoadedColor;
    
    myLoadedColor.r = loadedJson["color"]["r"];
    myLoadedColor.g = loadedJson["color"]["g"];
    myLoadedColor.b = loadedJson["color"]["b"];
    myLoadedColor.a = loadedJson["color"]["a"];

    float myLoadedValueOfPi = loadedJson["the_value_of_pi"];
    
    ofSetBackgroundColor(myLoadedColor);
    
}
