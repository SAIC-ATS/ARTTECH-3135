#include "Blob.h"

Blob::Blob() {
//    x = mouseX;
//    y= mouse 
    
}

Blob::~Blob() {
    //    x = mouseX;
    //    y= mouse
    
}

void Blob::grow() {
    if(a > 0){
        width += growthRate;
        height += growthRate;
        a -= fade;
        hue += hueChange;
    }
    
    else {

        growthRate = 0;
        height = 0;
        width = 0;
        fade = 0;
    }
};

void Blob::move(){
    x+=ofRandom(-5,5);
    y+=ofRandom(-5,5);
};
