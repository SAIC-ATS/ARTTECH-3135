#pragma once


#include "ofMain.h"


class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    // Update the current state and change it if needed.
    void updateState();
    
    // Render the current state on the screen in some meaningful way.
    void drawState();
    
    // An "enumeration" that specifies a limited / finite set of possible states.
    enum State
    {
        STATE_RED,
        STATE_YELLOW,
        STATE_GREEN
    };
    
    // This keeps track of the current state of the finite state machine.
    State currentState = STATE_GREEN;
    
    // This is the time of the next transition.
    // We will set this transition time, whenever we enter a new state.
    // For example, if we are entering the RED state, we will set this time
    // to the currentTime + the RED duration.
    uint64_t nextTransitionTime = 0;
    
};
