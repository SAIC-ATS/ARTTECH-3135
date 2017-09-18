#include "Ball.h"


void Ball::update()
{
    velocity = velocity + acceleration;

    velocity *= drag;

    position = position + velocity;

    // Check the x bounds.

    if (position.x > ofGetWidth())
    {
        position.x = ofGetWidth();
        velocity.x *= -1;
    }

    if (position.x < 0)
    {
        position.x = 0;
        velocity.x *= -1;
    }

    if (position.y > ofGetHeight())
    {
        position.y = ofGetHeight();
        velocity.y *= -1;
    }

    if (position.y < 0)
    {
        position.y = 0;
        velocity.y *= -1;
    }
}

void Ball::draw()
{
    ofDrawEllipse(position, width, height);
}
