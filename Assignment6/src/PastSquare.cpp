//#include "PastSquare.h"
//
//PastSquare::PastSquare(){
//    
//}
//
//PastSquare::~PastSquare(){
//    
//}
//
//void PastSquare::setup(){
//    pastSquareTexture.allocate(640, 480, GL_RGBA);
//}
//
//void PastSquare::update() {
//    
//}
//
//void PastSquare::draw(){
//}
//
//void PastSquare::makePastSquare(ofVideoGrabber grabber, std::vector<std::pair<ofRectangle, ofTexture>> pastSquareTextures)
//{
//    //Calculate dimensions
//    dimX = ofRandom(20, 200);
//    dimY = ofRandom(20, 200);
//    
//    //Create new ofRectangle pastSquare
//    pastSquare = ofRectangle(ofRandom(640), ofRandom(480), dimX, dimY);
//    
//    //Get the subsection pixels from the full camera image
//    squarePix = grabber.getPixels();
//    squarePix.crop(pastSquare.x, pastSquare.y, dimX, dimY);
//    
//    //Assign the pixels to a texture
//    pastSquareTexture.loadData(squarePix);
//    
//    //Assign ofRectangle and ofTextures to pair and push to vector
//    myPair = std::make_pair(pastSquare, pastSquareTexture);
//    pastSquareTextures.push_back(myPair);
//    
//    //Pause
//    ofSleepMillis(350);
//}
