#include "ofApp.h"

// Questions: autoadjust thing?

void ofApp::setup()
{
    dataFont.load("consolas.ttf", 18, true, true, true);

    // Testing redirects and https.
    std::string url = "testData.json";
    
//    // Create a client.
//    ofxHTTP::Client client;
//    
//    // Create a request.
//    ofxHTTP::GetRequest request(url);
//    
//    // Create a context.
//    ofxHTTP::Context context;
    
    grabber.setup(640, 480);
    tracker.setup();
    squarePix.set(255);
    
    squarePix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGBA);
    grayscalePixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    backgroundPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    frameToShowPixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGBA);
    frameToShowTexture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGBA);
    backgroundTexture.allocate(grabber.getWidth(), grabber.getHeight(), GL_RGBA);
    
//    gui.setup();
//    gui.add(threshold.set("Threshold", 55, 0, 100));
//    gui.add(erosionIterations.set("Erosion Iterations",0, 0, 30));
//    gui.add(dilationIterations.set("Dilation Iterations", 0, 0, 30));
    
    ofNoFill();
    ofBackground(255);
}

void ofApp::update()
{
    textSpeed = sin(ofGetFrameNum()/1000)*100;

    makeSquareCounter++;
    grabber.update();
    
    if(go && makeSquareCounter>20)
    {
        makePastSquare();
        makeSquareCounter = 0;
    }
    
    if (grabber.isFrameNew())
    {
        tracker.update(grabber);
//        ofxCv::threshold(frameToShowPixels, frameToShowPixels, threshold, cv::invert);
//        ofxCv::erode(frameToShowPixels, frameToShowPixels, erosionIterations);
//        ofxCv::dilate(frameToShowPixels, frameToShowPixels, dilationIterations);
        
//                                  *****Background Subtraction Start*****

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
        
        grayscaleTexture.loadData(grayscalePixels);
        backgroundTexture.loadData(backgroundPixels);
        frameToShowTexture.loadData(frameToShowPixels);

//                                  *****Background Subtraction End*****

//                                          *****Blur Start*****
        if(go)
        {
            for(auto it = pastSquareVector.begin(); it < pastSquareVector.end(); ++it)
            {
                ofRectangle blurredPastSquare = it->first;
                ofTexture &blurredPastSquareTexture = it->second.first;
                ofPixels &blurredSquarePix = it->second.second;

                //Mirror for smoother/reflecting pastSquareTextures
//                ofPixels flippedPastSquarePixels = blurredSquarePix;
//                flippedPastSquarePixels.mirror(true, false);
                
                for (int x = 0; x < blurredPastSquare.width; x++)
                {
                    for (int y = 0; y < blurredPastSquare.height; y++)
                    {
                        // Get the color to the right from the LAST set pixels saved in the pastSquareTexture
                        ofColor lastColorToTheRight = blurredSquarePix.getColor(x + 1, y);
                        // Get a copy of the current color from the camera.
                        ofColor currentColor = grabber.getPixels().getColor(blurredPastSquare.getMinX() + x, blurredPastSquare.getMinY() + y);
                        
                        // Blend the two colors (lower will favor the last, higher
                        // the current live camera color.
                        ofColor blended = lastColorToTheRight.getLerped(currentColor, 0.005);
                        
                        blurredSquarePix.setColor(x, y, blended);
                    }
                }
                
                blurredPastSquareTexture.loadData(blurredSquarePix);
             }
        }
//                                          *****Blur End*****
    }
}

void ofApp::draw()
{
//    gui.draw();

    frameToShowTexture.draw(320, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    backgroundTexture.draw(0, 480, grabber.getWidth()/2, grabber.getHeight()/2);
    
    ofDrawBitmapStringHighlight("click to pause, r to reset", ofGetWidth()/2-100, ofGetHeight()-20);
    ofDrawBitmapStringHighlight(std::to_string(ofGetMouseX()) + ", " + std::to_string(ofGetMouseY()), ofGetMouseX(), ofGetMouseY());

    for(auto it = pastSquareVector.begin(); it < pastSquareVector.end(); ++it)
    {
        //Draw pastSquareTexture at pastSquare coordinates
        it->second.first.draw(it->first.x, it->first.y);
    }
//                  *****Archaic html/json parsing start*****
//
//    ofPushStyle();
//    ofSetColor(255,0,0);
//    
//    for(Json::ArrayIndex a = 0; a < json.size(); a++){
//        for (int i = 0; i < json[a].size(); i++)
//        {
//            std::string dataVal = json[a][i]["value"][0].asString();
//            for(int j = 0; j < json[a][i]["validValues"].size(); j++)
//            {
//                if (json[a][i]["validValues"][j]["value"].asString() == dataVal
//                   && json[a][i]["validValues"][j]["text"].asString() != "True"
//                   && json[a][i]["validValues"][j]["text"].asString() != "False"
//                   && json[a][i]["validValues"][j]["text"].asString() != "Purchased")
//                {
//                    dataVal = json[a][i]["validValues"][j]["text"].asString();
//                }
//                else if (json[a][i]["validValues"][j]["text"].asString() == "True"
//                         || json[a][i]["validValues"][j]["text"].asString() == "False"
//                         || json[a][i]["validValues"][j]["text"].asString() == "Purchased"
//                         )
//                {
//                    dataVal = json[a][i]["name"].asString() + ": " + json[a][i]["validValues"][j]["text"].asString();
//                }
//            }
//            
//            if (a > 0)
//            {
//                dataFont.drawString(dataVal, 50, json[a-1].size() * 24 + i * 24 + 40 + textSpeed);
//            }
//            else
//            {
//                dataFont.drawString(dataVal, 50, i * 24 + 40 + textSpeed);
//            }
//        }
//    }
//    
//    ofPopStyle();
//                  *****Archaic html/json parsing end*****

    tracker.drawDebug();
    tracker.drawDebugPose();
}

void ofApp::keyPressed(int key)
{
    if(key == 'r')
    {
        pastSquareVector.clear();
    }
}

void ofApp::mousePressed(int x, int y, int button)
{
    //Click to stop/start pastSquare generation
    go = !go;
}

void ofApp::makePastSquare()
{
    //Assign random values for dimensions of pastSquare
    int dimX = ofRandom(20, 200);
    int dimY = ofRandom(20, 200);
    
    //Create new ofRectangle pastSquare
    auto pastSquare = ofRectangle((int)ofRandom(640-dimX), (int)ofRandom(480-dimY), dimX, dimY);
    
    //Set squarePix to current grabber pixels
    squarePix = grabber.getPixels();
    
    //Set squarePix to 4 channels (i.e. RGBA)
    squarePix.setNumChannels(4);
    
    if(bgCaptured){
        //Set BG pixel in subsection to white/transparent
        for(int x = pastSquare.getMinX(); x <= pastSquare.getMaxX(); x++)
        {
            for(int y = pastSquare.getMinY(); y <= pastSquare.getMaxY(); y++)
            {
                if(frameToShowPixels.getColor(x, y).getBrightness() < 1)
                {
                    squarePix.setColor(x, y, ofColor(200,200,200,10));
                }
            }
        }
    }
    
    //Get the subsection pixels from the full camera image by cropping the full image to pastSquare's dimensions
    squarePix.crop(pastSquare.x, pastSquare.y, dimX, dimY);
    
    ofTexture pastSquareTexture;
    
    // Allocate space for texture (if necessary?)
    pastSquareTexture.allocate(pastSquare.width, pastSquare.height, GL_RGBA);
    
    //Assign the pixels to texture
    pastSquareTexture.loadData(squarePix);
    
    //Assign texture and pixels to texturePair
    auto texturePair = std::make_pair(pastSquareTexture, squarePix);
    //Assign ofRectangle and texturePair to pair and push to vector
    auto mainPair = std::make_pair(pastSquare, texturePair);
    pastSquareVector.push_back(mainPair);
}


