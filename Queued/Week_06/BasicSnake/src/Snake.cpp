#include "Snake.h"


void Snake::update()
{
    if (isDead == false)
    {
        // Do we need to move the current head into the history?
        if (targetBodyLength > 0)
        {
            body.push_back(head);
        }

        // Do we need to remove any pieces from the history?
        if (body.size() > targetBodyLength)
        {
            // Remove the oldest snake piece.
            body.erase(body.begin());
        }

        // Now update the positions based on the current direction.
        if (direction == RIGHT)
        {
            head.column++;
        }
        else if (direction == LEFT)
        {
            head.column--;
        }
        else if (direction == UP)
        {
            head.row--;
        }
        else if (direction == DOWN)
        {
            head.row++;
        }
    }
}
