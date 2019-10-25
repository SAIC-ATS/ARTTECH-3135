#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(1280, 720);
    finder.setup("haarcascade_frontalface_default.xml");
    
    enterSound.load("350428__benjaminharveydesign__trumpet-fanfare.aiff");
    leaveSound.load("73581__benboncan__sad-trombone.wav");
}


void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        finder.findHaarObjects(grabber.getPixels());

        bool didFindFace = false;
        
        for (std::size_t i = 0; i < finder.blobs.size(); i++)
        {
            if (finder.blobs[i].area > 256 * 256)
            {
                didFindFace = true;
                break;
            }
        }
        
        
        if (didFindFace)
        {
            std::cout << "Face found!" << std::endl;
            
            // There ARE tracked faces in this block.
            
            if (currentState == TRACKING)
            {
                // we already know about this face, and are tracking it.
            }
            else if (currentState == NOT_TRACKING)
            {
                // There is a face now, but we aren't tracking so,
                // it must be a new face. This is the first time we are seeing it.
                leaveSound.stop();
                enterSound.play();
                
                currentState = TRACKING;
            }
            
            // there are faces
        }
        else
        {
            std::cout << "NO Face found!" << std::endl;

            // There are no tracked faces in this code block.
            if (currentState == TRACKING)
            {
                // Last time we saw a face, but now we don't so we lost the track.
                enterSound.stop();
                leaveSound.play();

                currentState = NOT_TRACKING;

            }
            else if (currentState == NOT_TRACKING)
            {
                // We still don't see any faces.
            }
        }
    }
}


void ofApp::draw()
{
    grabber.draw(0, 0);
    finder.draw(0, 0);
}

