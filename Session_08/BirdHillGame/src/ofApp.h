#pragma once


#include "ofMain.h"


class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    
    // Update the current state and change it if needed.
    void updateState();
    
    // Render the current state on the screen in some meaningful way.
    void drawState();
    
    // An "enumeration" that specifies a limited / finite set of possible states.
    enum State
    {
        STATE_START,
        STATE_PLAYING,
        STATE_END
    };
    
    // This keeps track of the current state of the finite state machine.
    State currentState = STATE_START;
    
    // This is the position of the ball.
    float yPosition = 0;
    
};
