#pragma once 

#include "ofMain.h"

class Blob {
private:
    float growthRate = 5;

public:
    Blob();
    ~Blob();
    float width = 5;
    float height = 5;
    
    float x;
    float y;
    int hue = 0;
    int hueChange = 10;
    int a = 100;
    float fade = 5;
    
    void grow();
    void move();
};
