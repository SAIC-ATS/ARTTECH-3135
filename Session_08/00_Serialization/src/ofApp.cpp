#include "ofApp.h"


void ofApp::setup()
{
    ofSetBackgroundColor(80); // A slightly darker background.

    ofFileDialogResult result = ofSystemLoadDialog("Choose a json file");
    
    if (result.bSuccess)
    {
         ofJson currentPolylineJson = ofLoadJson(result.getPath());
        
        // Iterate through the entries in the json object.
        for (std::size_t i = 0; i < currentPolylineJson.size(); i++)
        {
            // Get the next entry from the json object.
            ofJson positionJson = currentPolylineJson[i];
            
            // Create an empty position.
            glm::vec3 position;
            
            // Extract the position data from the json element.
            position.x = positionJson["x"];
            position.y = positionJson["y"];
            position.z = positionJson["z"];
            
            // Add the glm::vec3 position to our _actual_ current polyline.
            currentPolyline.push_back(position);
        }
    }
    
}


void ofApp::update()
{
}


void ofApp::draw()
{
    for (std::size_t i = 0; i < currentPolyline.size(); i++)
    {
        // 1) Get the current position from the polyline.
        glm::vec3 currentPoint = currentPolyline[i];
        
        ofSetColor(ofColor::red);
        ofNoFill();
        
        // 2) Use that position to draw a circle.
        ofDrawCircle(currentPoint, 10);
    }

    
// Alternative rendering idea.
//
//    // Create an openFrameworks polyline.
//    ofPolyline polyline;
//
//    // Add our vertices to it.
//    polyline.addVertices(currentPolyline);
//
//    // Draw the openFrameworks polyline.
//    polyline.draw();
    
}


void ofApp::keyPressed(int key)
{
    if (key == 'p')
    {
        // Save a picture of the current frame.
        // This will save an image to the bin/data folder.
        ofSaveFrame();
    }
    else if (key == 'j')
    {
        // Save the current polyline as a json object.
        
        // ofJson is an alias for nlohman::json
        //
        // typedef nlohman::json ofJson;
        //
        // For more information go here: https://github.com/nlohmann/json

        ofJson currentPolylineJson = nlohmann::json::array();
        
        for (std::size_t i = 0; i < currentPolyline.size(); i++)
        {
            // Save each of the glm::vec3 as a single json object.
            ofJson positionJson;
            
            // Set the json variables to the values of the current position.
            positionJson["x"] = currentPolyline[i].x;
            positionJson["y"] = currentPolyline[i].y;
            positionJson["z"] = currentPolyline[i].z;
 
            // Add the current position json to the current polyline json.
            currentPolylineJson.push_back(positionJson);
        }
        
        // Save the current polyline as json to disk.
        
        ofFileDialogResult result = ofSystemSaveDialog("current_polyline.json", "Please name your json file");
        
        if (result.bSuccess)
        {
            ofSaveJson(result.getPath(), currentPolylineJson);
        }
        
        // ofSaveJson(ofGetTimestampString() + "_current_polyline.json", currentPolylineJson);
    }
    
}


void ofApp::mouseDragged(int x, int y, int button)
{
    // When a mouse is dragged, it means that a button is being
    // held down while the mouse is moving.
    
    // 1) Create a point at the current position of the mouse.
    glm::vec3 currentPoint = { x, y, 0 };
    
    // 2) Add the point to our current polyline.
    currentPolyline.push_back(currentPoint);
}


void ofApp::mousePressed(int x, int y, int button)
{
    // When the button is pressed, begin creating a new line.
    // 1) Clear the vector to make sure there are no points
    //    remaining inside it.
    currentPolyline.clear();
    
    // 2) Create a point at the current position of the mouse.
    glm::vec3 currentPoint = { x, y, 0 };
    
    // 3) Add the point to our current polyline.
    currentPolyline.push_back(currentPoint);
}


void ofApp::mouseReleased(int x, int y, int button)
{
    // 1) Create a point at the current position of the mouse.
    glm::vec3 currentPoint = { x, y, 0 };
    
    // 2) Add the point to our current polyline.
    currentPolyline.push_back(currentPoint);
}
