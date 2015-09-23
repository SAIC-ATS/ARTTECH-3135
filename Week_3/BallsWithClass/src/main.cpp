#line 1 "BallsWithClass"

#include "ofMain.h"
#include "Ball.h" // Include the definition of the ball class.


class ofApp: public ofBaseApp
{
public:

#line 2 "BallsWithClass"

Ball myBall0; // initantiating our ball class.

void setup() {
	// put your setup code here, to run once:
	ofBackground(0);
	
	myBall0.x = ofGetWidth() / 2;
	myBall0.y = ofGetHeight() / 2;
	myBall0.vx = 2;
	myBall0.vy = 2;
}


void update() {
    myBall0.update();
}


void draw() {
	myBall0.draw();
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

