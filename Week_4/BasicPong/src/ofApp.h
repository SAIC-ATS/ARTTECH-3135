#pragma once


#include "ofMain.h"


class ofApp: public ofBaseApp
{
public:
	void setup();
	void draw();

	void keyPressed(int key);

	void updatePosition();
	void checkForCollisions();
	void resetBall();
	void resetPaddles();
	void serveBall();

	void drawField();
	void drawBall();
	void drawPaddles();

	void drawScore();

	void ballHitTopWall();
	void ballHitBottomWall();
	void ballHitRightPaddle();
	void ballHitLeftPaddle();

	void leftPlayerScored();
	void rightPlayerScored();
	void rightPaddleUp();
	void rightPaddleDown();

	void leftPaddleUp();
	void leftPaddleDown();

	
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
	// Usually velocity is expressed in units of LENGTH / TIME (e.g. miles /
	// hour, meters / second, etc).  The tricky part is our "time unit" is not a
	// consistent like seconds or milliseconds, but rather it is the duration of
	// the draw loop, or the refresh rate.  So, therefore the units of our
	// "velocity" is actually "pixels / draw loop".  Since the duration of
	// the draw loop can be changed (i.e. the refresh rate of the screen),
	// changing the refresh rate will change the "speed" of the ball.  Many
	// physics engines do not tie their velocity to frame rate, but use an
	// absolute timer so that their units might be something like "pixels /
	// second" or "pixels / millisecond".
	float ballVelocityX = 0;
	float ballVelocityY = 0;

};
