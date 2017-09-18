#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    void keyPressed(int key) override;

    std::size_t currentWordIndex = 0;
    std::vector<std::string> words;
};
