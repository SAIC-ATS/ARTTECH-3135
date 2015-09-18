#line 1 "BasicPong"

#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:

#line 1 "BasicPong"
// Scores for the two players.
int scoreLeft = 0;
int scoreRight = 0;

// Paddles are represented with the ofRectangle class.
// Remember that the x / y position is the upper left corner, so sometimes
// when setting the x / y position, you need to take the width / height into 
// account.
ofRectangle paddleLeft;
ofRectangle paddleRight;

// Like the paddles, the ball is represented with an ofRectangle, so remember
// that the x / y position represents the uper left corner.
ofRectangle ball;

// The ball velocity in the x / y direction.
// Usually velocity is expressed in units of LENGTH / TIME (e.g. miles / hour, 
// meters / second, etc).  The tricky part is our "time unit" is not a 
// consistent like seconds or milliseconds, but rather it is the duration of the 
// draw loop, or the refresh rate.  So, therefore the units of our "velocity" 
// is actually "pixels / draw loop".  Since the duration of
// the draw loop can be changed (i.e. the refresh rate of the screen), changing
// the refresh rate will change the "speed" of the ball.  Many physics engines
// do not tie their velocity to frame rate, but use an absolute timer so that
// their units might be something like "pixels / second" or 
// "pixels / millisecond".
float ballVelocityX = 0;
float ballVelocityY = 0;

// Setup is where we set up our application, initialize variables, etc.
void setup() {
    ofSetWindowShape(1280, 480);
    ofBackground(0); // Set the background to black.
    
    // Call the functions that resets the game.
    resetPaddles();
    resetBall();
    serveBall();
}

// Draw is called by openFrameworks automatically on a timer associated with
// the refresh rate of the monitor, or the frame rate specified by 
// `ofSetFrameRate(...)` and mediated by `ofSetVerticalSync(...)`.
void draw() {
	updatePosition(); // Call the function that updates the ball position.
	checkForCollisions(); // Call the function that checks for collisions.
	drawField(); // Call the function that draws the field.
	drawBall(); // Call the function that draws the ball.
	drawPaddles(); // Call the function that draws the paddles.
	drawScore();  // Call the function that draws the scores.
}


// The key press function is called automatically by openFrameworks when key
// presses are detected.  This usually happens in a sequence before the draw
// loop.
void keyPressed(int key) 
{
    switch (key)
    {
        case 'q':
            leftPaddleUp();
            break;
        case 'a':
            leftPaddleDown();
            break;
        case 'p':
            rightPaddleUp();
            break;
        case 'l':        
            rightPaddleDown();
            break;
    }
}


// A function to update the position of the ball.
void updatePosition() {
    ball.x += ballVelocityX;
    ball.y += ballVelocityY;
}


// A function to Check for ball collisions.
// The order in which we check for collisions is important.
// The fact that this is an if else if statement means that we can only send 
// send one event (call one function) per call to checkForCollisions().
void checkForCollisions() {
    if (ball.getBottom() > ofGetHeight()) // Check the bottom wall.
    {
        ballHitBottomWall();
    }
    else if (ball.getTop() < 0)  // Check the top wall.
    {
        ballHitTopWall();
    }
    else if (ball.getRight() > ofGetWidth()) // Check the right boundary.
    {
        leftPlayerScored();
    }
    else if (ball.getLeft() < 0) // Check the left boundary.
    {
        rightPlayerScored();
    }
    else if (ball.getLeft() < paddleLeft.getRight() && // Make sure the x dimension is correct. 
             ball.getRight() > paddleLeft.getRight() && // Make sure the x dimension is correct.
             ball.getBottom() > paddleLeft.getTop() && // Make sure that the top is in the right place.
             ball.getTop() < paddleLeft.getBottom()) // Make sure the bottom is in the right place.
    {
        ballHitLeftPaddle();
    }
    else if (ball.getRight() > paddleRight.getLeft() && // Make sure the x dimension is correct. 
             ball.getLeft() < paddleRight.getLeft() && // Make sure the x dimension is correct.
             ball.getBottom() > paddleRight.getTop() && // Make sure that the top is in the right place.
             ball.getTop() < paddleRight.getBottom()) // Make sure the bottom is in the right place.
    {
        ballHitRightPaddle();
    }
    else 
    {
        // No interesting collisions, so keep going.   
    }
}


void resetBall()
{
    ball.setFromCenter(ofGetWidth() / 2.0, ofGetHeight() / 2.0, 20, 20);
}


void resetPaddles() {
    paddleLeft.setFromCenter(40, ofGetHeight() / 2.0, 20, 100);
    paddleRight.setFromCenter(ofGetWidth() - 40, ofGetHeight() / 2.0, 20, 100);
}


void serveBall()
{
    ball.setFromCenter(ofGetWidth() / 2.0, ofGetHeight() / 2.0, 20, 20);

    ballVelocityX = ofRandom(1, 10);

    // To avoid tiny velocities, 
    if (ofRandom(0, 1) > 0.5) {
        ballVelocityX *= -1;   
    }

    ballVelocityY = ofRandom(1, 10);

    if (ofRandom(0, 1) > 0.5) {
        ballVelocityY *= -1;   
    }
}


void drawField() {
    // Draw a vertical line in the middle of the field.
    ofSetColor(127);
    ofLine(ofGetWidth() / 2, 0, ofGetWidth() / 2, ofGetHeight());
}

void drawBall() {
	ofSetColor(255); // Draw w/ a white color.
    ofNoFill(); // Fill in the shape.
    // Order of operations - BODMAS
    ofRect(ball);
}

void drawPaddles() {
    ofSetColor(255);
    ofNoFill();
    ofRect(paddleLeft);
    ofRect(paddleRight);
}

void drawScore() {
    ofDrawBitmapString(ofToString(scoreLeft), 100, 50);   
    ofDrawBitmapString(ofToString(scoreRight), ofGetWidth() - 100, 50);   
}

void ballHitTopWall()
{
    // Bounce ball in +y direction.   
    ballVelocityY = ballVelocityY * -1.0;
    ball.y = 0;
}

void ballHitBottomWall()
{
    // Bounce ball in -y direction.
    ballVelocityY = ballVelocityY * -1.0;
    ball.y = ofGetHeight() - ball.height;
}

void ballHitRightPaddle()
{
    ballVelocityX = ballVelocityX * -1.0; // Reverse the X velocity.
    ball.x = paddleRight.getLeft() - ball.width;
}

void ballHitLeftPaddle()
{
    ballVelocityX = ballVelocityX * -1.0; // Reverse the X velocity.
    ball.x = paddleLeft.getRight();
}

void leftPlayerScored()
{
    scoreLeft++; // add one to the right player's score.
    resetBall();
    serveBall();
}

void rightPlayerScored()
{
    scoreRight++; // add one to the left player's score. 
    resetBall();
    serveBall();
}

void rightPaddleUp()
{
    paddleRight.y -= 20;
    
    // Make sure paddle doesn't go off screen.
    if (paddleRight.getTop() < 0)
    {
        paddleRight.y = 0;   
    }
}

void rightPaddleDown()
{
    paddleRight.y += 20;

    // Make sure paddle doesn't go off screen.
    if (paddleRight.getBottom() > ofGetHeight())
    {
        paddleRight.y = ofGetHeight() - paddleRight.height;
    }
}

void leftPaddleUp()
{
    paddleLeft.y -= 20;
    
    // Make sure paddle doesn't go off screen.
    if (paddleLeft.getTop() < 0)
    {
        paddleLeft.y = 0;   
    }
}

void leftPaddleDown()
{
    paddleLeft.y += 20;
    
        // Make sure paddle doesn't go off screen.
    if (paddleLeft.getBottom() > ofGetHeight())
    {
        paddleLeft.y = ofGetHeight() - paddleLeft.height;
    }
}


};

int main()
{
    ofSetupOpenGL(320, 240, OF_WINDOW);
    ofRunApp(new ofApp());
}

