#line 1 "BallsWithClassVectorVec"

#include "ofMain.h"
#include "Ball.h" // Include the definition of the ball class.


class ofApp: public ofBaseApp
{
public:

#line 2 "BallsWithClassVectorVec"

std::vector<Ball> myCollectionOfBalls;

void setup() {
	// put your setup code here, to run once:
	ofBackground(0);
	
	for (int i = 0;  i < 5000; i++)
    {
        Ball aBallInstance;
    	aBallInstance.position = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    	aBallInstance.velocity = ofPoint(ofRandom(-5, 5), ofRandom(-5, 5), 0);

        aBallInstance.r = ofRandom(2, 5);
        aBallInstance.color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    
        myCollectionOfBalls.push_back(aBallInstance); // add the ball to the collection.
    }
}


void update() {
    ofPoint previousMouse(ofGetPreviousMouseX(), ofGetPreviousMouseY());
    ofPoint currentMouse(ofGetMouseX(), ofGetMouseY());
    
    ofPoint mouseVelocity = currentMouse - previousMouse;
    
    for (int i = 0; i < myCollectionOfBalls.size(); i++)
    {
        myCollectionOfBalls[i].update();
        
        if (ofGetMousePressed() == true)
        {
            float distance = currentMouse.distance(myCollectionOfBalls[i].position);
                        
            float scaledMouseVelocityX = ofMap(distance, 0, ofGetWidth(), mouseVelocity.x / 4.0, mouseVelocity.x / 32.0);
            float scaledMouseVelocityY = ofMap(distance, 0, ofGetHeight(), mouseVelocity.y / 4.0, mouseVelocity.y / 32.0);
            
            ofPoint scaledMouseVelocity(scaledMouseVelocityX, scaledMouseVelocityY);
            
            myCollectionOfBalls[i].velocity += scaledMouseVelocity; 
        }
        
        if (myCollectionOfBalls[i].position.x > ofGetWidth() || myCollectionOfBalls[i].position.x < 0)
        {
            myCollectionOfBalls[i].velocity.x *= -1.0;
        }
        else if (myCollectionOfBalls[i].position.x > ofGetHeight() || myCollectionOfBalls[i].position.y < 0)
        {
            myCollectionOfBalls[i].velocity.y *= -1.0;
        }
    }
}


void draw() {
    
    for (int i = 0; i < myCollectionOfBalls.size(); i++)
    {
        myCollectionOfBalls[i].draw();
    }
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

