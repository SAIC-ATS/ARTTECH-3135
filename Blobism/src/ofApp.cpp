#include "ofApp.h"

//use this for poetic systems fp? emotion determines selections of fragments of poetry?

void ofApp::setup()
{
    receiver.setup(PORT);
    dataFont.load("consolas.ttf", 12, true, true, true);
        
    grabber.setup(640, 480);
    tracker.setup();
    
    grayscalePixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    backgroundPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    binaryPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    frameToShowPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGBA);
    frameToShowTexture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGBA);
    binaryTexture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGBA);
    backgroundTexture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGBA);

    
    gui.setup();
    gui.add(threshold.set("Threshold", 55, 0, 100));
    gui.add(erosionIterations.set("Erosion Iterations",0, 0, 30));
    gui.add(dilationIterations.set("Dilation Iterations", 0, 0, 30));
    gui.add(invert.set("Invert", true));
    gui.add(pastSquareMax.set("Max num PastSquares", 25, 0, 50));
    gui.add(pastSquareSpawnRate.set("PastSquare spawn rate", 20, 0, 100));

    
    ofNoFill();
    ofBackground(255);
    
    current_msg_string = 0;
}

void ofApp::update()
{
    handleOscMsgs();
    
    makeSquareCounter++;
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        tracker.update(grabber);
        
        ofxCv::convertColor(grabber, binaryPixels, CV_RGB2GRAY);
        ofxCv::threshold(binaryPixels, binaryPixels, threshold, invert);
        ofxCv::erode(binaryPixels, binaryPixels, erosionIterations);
        ofxCv::dilate(binaryPixels, binaryPixels, dilationIterations);
        
        //BG Subtraction
        captureBG();
        
        contourFinder.findContours(binaryPixels);
        grayscaleTexture.loadData(grayscalePixels);
        binaryTexture.loadData(binaryPixels);
        backgroundTexture.loadData(backgroundPixels);
    }
    
    if(go && makeSquareCounter>pastSquareSpawnRate && tracker.getInstances().size() > 0)
    {
        PastSquare newSquare = PastSquare(grabber, frameToShowPixels, pastSquareCount, bgCaptured, tracker);
        pastSquareVector.push_back(newSquare);
        
        dataText = testText[(int)ofRandom(0,testText.size()+1)];
        std::pair<string, ofRectangle> dataPair = std::make_pair(dataText, ofRectangle(newSquare.pastSquare.getMinX(), newSquare.pastSquare.getMinY()+50, newSquare.pastSquare.width, newSquare.pastSquare.height));
        textVector.push_back(dataPair);
        
        pastSquareCount++;
        makeSquareCounter = 0;
    }
}

void ofApp::draw()
{
    gui.draw();
    
    backgroundTexture.draw(320, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    binaryTexture.draw(0, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    
    drawText();
    drawPastSquares();
    
    tracker.drawDebug();
    tracker.drawDebugPose();
}

void ofApp::keyPressed(int key)
{
    if(key == 'r')
    {
        pastSquareVector.clear();
    }
    
    if(key == 'p')
    {
        ofImage img;
        img.setFromPixels(grabber.getPixels());
        img.save("snapshot.jpg", OF_IMAGE_QUALITY_BEST);
        
//        string command = "python " + ofToDataPath("google_vision_api.py", true);
//        system(command.c_str());
    }
}

void ofApp::mousePressed(int x, int y, int button)
{
    go = !go;
}

void ofApp::handleOscMsgs()
{
    // hide old messages
//    for(int i = 0; i < NUM_MSG_STRINGS; i++){
//        if(timers[i] < ofGetElapsedTimef()){
//            msg_strings[i] = "";
//        }
//    }
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        cout<<"u got mail!"<<std::endl;
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        string msg_string;
        msg_string = m.getAddress();
        msg_string += ":";
        for(int i = 0; i < m.getNumArgs(); i++){
            // get the argument type
            msg_string += " ";
            msg_string += m.getArgTypeName(i);
            msg_string += ":";
            // display the argument - make sure we get the right type
            if(m.getArgType(i) == OFXOSC_TYPE_INT32){
                msg_string += ofToString(m.getArgAsInt32(i));
            }
            else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
                msg_string += ofToString(m.getArgAsFloat(i));
            }
            else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
                msg_string += m.getArgAsString(i);
                cout << msg_string << std::endl;
            }
            else{
                msg_string += "unknown";
            }
        }
        // add to the list of strings to display
        msg_strings[current_msg_string] = msg_string;
        timers[current_msg_string] = ofGetElapsedTimef() + 5.0f;
        current_msg_string = (current_msg_string + 1) % NUM_MSG_STRINGS;
        // clear the next line
        msg_strings[current_msg_string] = "";
    }
}

void ofApp::drawPastSquares(){
    for(auto it = pastSquareVector.begin(); it < pastSquareVector.end(); ++it)
    {
        if(pastSquareMax + it->pastSquareIndex < pastSquareCount)
        {
            pastSquareVector.erase(it);
        }
        else
        {
            it->draw(go, grabber);
        }
    }
}

void ofApp::captureBG()
{
// Make the grayscale image from the fresh camera image.
    for (int x = 0; x < grabber.getWidth(); x++)
    {
        for (int y = 0; y < grabber.getHeight(); y++)
        {
            grayscalePixels.setColor(x, y, grabber.getPixels().getColor(x, y).getBrightness());
        }
    }
    // If the spacebar is pressed, save that image as the background image.
    if (ofGetKeyPressed(' ') == true)
    {
        bgCaptured = true;
        backgroundPixels = grayscalePixels;
    }
    // Subtract the background from the camera grayscale and create the foreground.
    for (int x = 0; x < grabber.getWidth(); x++)
    {
        for (int y = 0; y < grabber.getHeight(); y++)
        {
            int brightnessOfGrayscale = grayscalePixels.getColor(x, y).getBrightness();
            int brightnessOfBackground = backgroundPixels.getColor(x, y).getBrightness();
            int absDiff = std::abs(brightnessOfBackground - brightnessOfGrayscale);
                    
            ofColor color;
                    
            //Change this to adjust sensitivity to pixel changes
            if (absDiff > 10)
            {
                color = grabber.getPixels().getColor(x, y);
            }
            else
            {
                color = ofColor(0);
            }
            frameToShowPixels.setColor(x, y, color);
        }
    }
}

void ofApp::drawText(){
    ofPushStyle();
    ofSetColor(0);
    for(auto it = textVector.begin(); it < textVector.end(); ++it)
    {
        dataFont.drawString(it->first, it->second.getMinX(), it->second.getMinY());
    }
    ofPopStyle();
}

