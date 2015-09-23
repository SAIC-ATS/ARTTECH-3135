#line 1 "BallsWithClassVector"

#include "ofMain.h"
#include "Ball.h" // Include the definition of the ball class.


class ofApp: public ofBaseApp
{
public:

#line 2 "BallsWithClassVector"

std::vector<Ball> myCollectionOfBalls;

void setup() {
	// put your setup code here, to run once:
	ofBackground(0);
	
	for (int i = 0;  i < 500; i++)
    {
        Ball aBallInstance;
    	aBallInstance.x = ofGetWidth() / 2;
	    aBallInstance.y = ofGetHeight() / 2;
	    aBallInstance.vx = ofRandom(-5, 5);
	    aBallInstance.vy = ofRandom(-5, 5);
        aBallInstance.r = ofRandom(2, 5);
        aBallInstance.color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    
        myCollectionOfBalls.push_back(aBallInstance); // add the ball to the collection.
    }
}


void update() {
    
    for (int i = 0; i < myCollectionOfBalls.size(); i++)
    {
        myCollectionOfBalls[i].update();
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

