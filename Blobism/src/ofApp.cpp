#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//use for ps fp?
//compare face (identification?): https://www.faceplusplus.com/face-compare-sdk/
    // --> used with cameras outside exhibition room to take images/surveil people
    //     and insert them into their composition when viewing the piece
//Affectiva: emotion analysis and facial gesturing
//Google: features and logo identification
//Watson: not sure what exactly is unique about it but seems

//make sure osc is being sent from affdex
//make sure osc is sent/recieved from desktop obj-c app
//network monitoring to see if packets are being sent from affdex
//send a shitton and see if they spike
//look at permissions in affdex: maybe something is disabling network communication?
//first thing: use xcode obj-c template to test osc library

void ofApp::setup()
{
    ofSetVerticalSync(true);

    receiver.setup(PORT);
    dataFont.load("consolas.ttf", 10, true, true, true);
        
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
    gui.add(erosionIterations.set("Erosion Iterations",0, 0, 30));
    gui.add(dilationIterations.set("Dilation Iterations", 0, 0, 30));
    gui.add(invert.set("Invert", true));
    gui.add(pastSquareMax.set("Max num PastSquares", 25, 0, 50));
    gui.add(pastSquareSpawnInterval.set("PastSquare spawn interval", 20, 0, 100));
    gui.add(bgSubtractionEnabled.set("BG Subtraction enabled", false));
    gui.add(contoursVisible.set("Contours visible", false));
    
    ofNoFill();
    ofBackground(255);
    
    setupKinect();
    
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
        if(bgSubtractionEnabled)
        {
            captureBG();
        }
        contourFinder.setMinAreaRadius(minArea);
        contourFinder.setMaxAreaRadius(maxArea);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(binaryPixels);
        
        grayscaleTexture.loadData(grayscalePixels);
        binaryTexture.loadData(binaryPixels);
        backgroundTexture.loadData(backgroundPixels);
    }
    
    if(go && makeSquareCounter>pastSquareSpawnInterval && tracker.getInstances().size() > 0)
    {
        PastSquare newSquare = PastSquare(grabber, frameToShowPixels, pastSquareCount, bgCaptured, tracker);
        pastSquareVector.push_back(newSquare);
        
        //Make some text for testing
        dataText = testText[(int)ofRandom(0,testText.size())];
        std::pair<string, ofRectangle> dataPair = std::make_pair(dataText, ofRectangle(newSquare.pastSquare.getMinX(), newSquare.pastSquare.getMinY()+50, newSquare.pastSquare.width, newSquare.pastSquare.height));
        textVector.push_back(dataPair);
        
        pastSquareCount++;
        makeSquareCounter = 0;
    }
}

void ofApp::draw()
{
    backgroundTexture.draw(320, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    binaryTexture.draw(0, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    
    ofPushStyle();
        ofSetColor(0);
        if(contoursVisible)
        {
            contourFinder.draw();
        }
        drawText();
    ofPopStyle();
    
    drawPastSquares();
    
    tracker.drawDebug();
    tracker.drawDebugPose();
    
    gui.draw();
}

void ofApp::keyPressed(int key)
{
    if(key == 'r')
    {
        pastSquareVector.clear();
        textVector.clear();
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
    for(auto it = textVector.begin(); it < textVector.end(); ++it)
    {
        dataFont.drawString(it->first, it->second.getMinX(), it->second.getMinY());
    }
}

void ofApp::setupKinect(){
#ifdef _USE_VIDEO
    
    // Load a video.
    depthVidPlayer.load("testVidDepth.mp4");
    depthVidPlayer.play();
    depthVidPlayer.setLoopState(OF_LOOP_NORMAL);
    depthVidPlayer.setVolume(0);
    
    ofPoint center;
    center.x = ofGetWidth()/2 - depthVidPlayer.getWidth()/2;
    center.y = ofGetHeight()/2 - depthVidPlayer.getHeight()/2;
    
    // Anchor the video to the center.
    depthVidPlayer.setAnchorPoint(center.x, center.y);
    
#else
    
    // Check if we have a Kinect device connected.
    ofxKinectV2 tmp;
    vector <ofxKinectV2::KinectDeviceInfo> deviceList = tmp.getDeviceList();
    
    if (deviceList.size() > 0) {
        cout << "Success: Kinect found.";
    } else {
        cout << "Failure: Kinect not found.";
        return;
    }
    
    kinectGroup.setup("Kinect");
    
    // Setup Kinect. [Assumption] Only a single Kinect will be
    // connected to the system.
    kinect = new ofxKinectV2();
    kinect->open(deviceList[0].serial);
    kinectGroup.add(kinect->params);
    
    gui.add(&kinectGroup);
    
#endif
    
    // openCv GUI.
    cvGroup.setup("openCv");
    cvGroup.add(minArea.setup("Min area", 10, 1, 100));
    cvGroup.add(maxArea.setup("Max area", 200, 1, 500));
    cvGroup.add(threshold.setup("Threshold", 128, 0, 255));
    
    // Add the groups to main GUI.
    gui.add(&cvGroup);
    
    // Restore the GUI from XML file.
    gui.loadFromFile("kinectCv.xml");
}

void ofApp::updateKinect(){
    // Clear the polyline.
    newPoly.clear();
    
    // Set contourFinder with sliders to get the right value for contour finding.
    contourFinder.setMinAreaRadius(minArea);
    contourFinder.setMaxAreaRadius(maxArea);
    contourFinder.setThreshold(threshold);
    
    // Depth image matrix that we will pass to Contour finder.
    Mat depthImgMat;
    
    float widthOffset = 0;
    float heightOffset = 0;
    
#ifdef _USE_VIDEO
    
    // Video player related logic.
    depthVidPlayer.update();
    // Do video related things.
    if (depthVidPlayer.isFrameNew()) {
        ofPixels depthPixels = depthVidPlayer.getPixels();
        texDepth.loadData(depthPixels);
        depthImgMat = toCv(depthPixels);
        
        // Offset distances to center the polyline.
        widthOffset = ofGetWidth()/2 - depthPixels.getWidth()/2;
        heightOffset = ofGetHeight()/2 - depthPixels.getHeight()/2;
        
        // Find contours.
        contourFinder.findContours(depthImgMat);
        updatePolyline(widthOffset, heightOffset);
    }
    
#else
    
    // Kinect related logic.
    if (kinect != nullptr) {
        // Update Kinect.
        kinect->update();
        // Only do work when Kinect captures a new frame.
        if (kinect->isFrameNew()) {
            // Depth and RGB image from the Kinect.
            // TODO: If not using RGB image, comment that out.
            texDepth.loadData(kinect->getDepthPixels());
            texRGB.loadData(kinect->getRgbPixels());
            
            // Depth pixels.
            ofPixels depthPixels = kinect->getDepthPixels();
            // Convert depth pixels into OpenGL Mat data type. This is required for
            // ofxCv to process the depth pixels and find countours.
            depthImgMat = toCv(depthPixels);
            
            // Offset distances to center the polyline.
            widthOffset = ofGetWidth()/2 - depthPixels.getWidth()/2;
            heightOffset = ofGetHeight()/2 - depthPixels.getHeight()/2;
            
            // Find contours.
            contourFinder.findContours(depthImgMat);
            updatePolyline(widthOffset, heightOffset);
        }
    }
    
#endif
}

void ofApp::updatePolyline(float widthOffset, float heightOffset) {
    vector <ofPolyline> polylines = contourFinder.getPolylines();
    
    // Translate algorithm for each vertex of the polyline.
    if (polylines.size() > 0) {
        // Then a person is here.
        vector<glm::vec3> vertices = polylines[0].getVertices();
        
        // Add the offset distances to each vertex of the polyline to
        // center it on the screen.
        for (int i = 0; i < vertices.size(); i++) {
            vertices[i].x += widthOffset;
            vertices[i].y += heightOffset;
        }
        
        // Create a new polyline with updated vertices.
        newPoly.addVertices(vertices);
        
        // Get a smooth version of the polyline.
        newPoly = newPoly.getSmoothed(2);
    }
    else
    {
        // No contours.
    }
}
