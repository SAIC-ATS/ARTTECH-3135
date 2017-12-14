#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(320, 240);
    pixels.allocate(320, 240, OF_PIXELS_RGB);
    // Set all of the pixels to black.
    //pixels.setColor(ofColor::black);
    //texture.loadData(pixels);
    pixels.set(255);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    /*
    
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        // This is where we can modify the pixels.
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                // Get the color at the current pixel from the grabber.
                ofColor color = grabber.getPixels().getColor(x ,y);
                
                // By default, we will just use the pixel from the camera.
                ofColor colorToUse = color;
                
                // Set pixels based on a few tests.
                // We do these tests for each pixels because we are iterating
                // through all of the pixels.
                float brightness = color.getBrightness();
                
                if (brightness > 127)
                {
                    colorToUse = ofColor::indianRed;
                }
                else if (x > grabber.getWidth() / 2)
                {
                    colorToUse.invert();
                }
                else if (y > grabber.getHeight() / 2)
                {
                    // Set the r channel to zero!
                    colorToUse.r = 0;
                }
                
                // Now we send our color into our pixels.
                pixels.setColor(x, y, colorToUse);
                
            }
        }
        
        texture.loadData(pixels);
    }
     
     */
    
    /*
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                // For each pixel column, except the last one ...
                if (x < grabber.getWidth() - 1)
                {
                    // Get the color to the right from the LAST pixels saved.
                    ofColor lastColorToTheRight = pixels.getColor(x + 1, y);
                    // Get a copy of the current color from the camera.
                    ofColor currentColor = grabber.getPixels().getColor(x, y);
                    
                    // Blend the two colors (0.01 will favor the last, closer to
                    // 1 will favor the current live camera color.
                    ofColor blended = lastColorToTheRight.getLerped(currentColor, 0.01);
                    
                    pixels.setColor(x, y, blended);
                }
                else
                {
                    // Otherwise, just save the raw pixel in the last row
                    // (because otherwise we couldn't access x + 1 because it
                    // wouldn't exist).
                    pixels.setColor(x, y, grabber.getPixels().getColor(x, y));
                }
            }
        }
        
    }
    
    texture.loadData(pixels);
*/
    

    grabber.update();
    
    if(grabber.isFrameNew()){
        for(int x = 0; x < grabber.getWidth(); x++){
            for (int y = 0; y < grabber.getHeight(); y++){
                ofColor color = grabber.getPixels().getColor(x ,y);
                
                // By default, we will just use the pixel from the camera.
                ofColor colorToUse = color;
                
                // Set pixels based on a few tests.
                // We do these tests for each pixels because we are iterating
                // through all of the pixels.
                float brightness = color.getBrightness();
                
                if(brightness > 100){
                    // For each pixel column, except the last one ...
                    if (x < grabber.getWidth() - 1)
                    {
                        // Get the color to the right from the LAST pixels saved.
                        ofColor lastColorToTheRight = pixels.getColor(x, y + 2);
                        // Get a copy of the current color from the camera.
                        ofColor currentColor = grabber.getPixels().getColor(x, y);
                        
                        // Blend the two colors (0.01 will favor the last, closer to
                        // 1 will favor the current live camera color.
                        ofColor blended = lastColorToTheRight.getLerped(currentColor, 0.05);
                        
                        pixels.setColor(x, y, blended);
                    }
 
                    else if(brightness < 200){
                        
                             colorToUse.invert();
                    }
                    else
                    {
                        // Otherwise, just save the raw pixel in the last row
                        // (because otherwise we couldn't access x + 1 because it
                        // wouldn't exist).
                        pixels.setColor(x, y, grabber.getPixels().getColor(x, y));
                    }
                    int time = ceil(ofGetElapsedTimef());
                    
                    if(time % 2 == 0){
                        
                        colorToUse.set(ofRandom(255), ofRandom(255), ofRandom(255));
                    }

                    
                }
                

        }
    }
  }
     texture.loadData(pixels);

    /*
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                // Here we use perlin noise to figure out how to offset our pixels.
                // This is 1-D noise.
                float theNoise = ofNoise((x + mouseX) * scale);
                
                int xDisplace = x + grabber.getWidth() * theNoise;
                int yDisplace = y; // None.
                
                // We "wrap" the values to make sure they are accessing
                // legitimate pixel x / y values.  This is kind of like doing a
                // modulo, but takes care of negative numbersÊand floating
                // point as well.
                xDisplace = ofWrap(xDisplace, 0, grabber.getWidth());
                yDisplace = ofWrap(yDisplace, 0, grabber.getHeight());
                
                // So when we set our color, we don't get the color from
                // the x, y position in the grabber, we get it from somewhere
                // a position determined by the perlin noise field.
                ofColor theDisplacedColorFromTheGrabber = grabber.getPixels().getColor(xDisplace, yDisplace);
                
                // Save that color to our pixels!
                pixels.setColor(x, y, theDisplacedColorFromTheGrabber);
            }
        }
    }
    
    texture.loadData(pixels);
     */

}

//--------------------------------------------------------------
void ofApp::draw(){
    grabber.draw(0, 0);
    texture.draw(320, 0);
    
    /*
    
    int time = ceil(ofGetElapsedTimef());
    
    ofPushMatrix();
    ofTranslate(pixels.getWidth(), 0, 0);
    ofScale(-1, 1, 1);
    
    if(time % 4 == 0){
    
    for(int x = 0; x < grabber.getWidth(); x++){
        for (int y = 0; y < grabber.getHeight(); y++){

            ofColor pixelColor = pixels.getColor(x, y);
            
            float brightness = pixelColor.getBrightness();
            
            float width = ofMap(brightness, 0, 255, 2, 40);
            
            if (x < grabber.getWidth() - 1){
                
                ofColor lastColorToTheRight = pixels.getColor(x + 2, y);
                // Get a copy of the current color from the camera.
                ofColor currentColor = grabber.getPixels().getColor(x, y);
                
                ofDrawRectangle(x, y, width, width);
            }
            
        }
    }
    }
    
    */
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
    
    if(key =='r'){
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    }
    
    
    

  }

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------

