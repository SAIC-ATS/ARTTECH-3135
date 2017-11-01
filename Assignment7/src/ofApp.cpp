#include "ofApp.h"


void ofApp::setup()
{
    grabber.setup(640, 480);
	finder.setup("haarcascade_frontalface_default.xml");
    
    grayscalePixels.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_GRAY);
    
    soundPlayer.loadSound("mawp.mp3");
}


void ofApp::update()
{
    grabber.update();
    
    if (grabber.isFrameNew())
    {
        finder.findHaarObjects(grabber.getPixels());
        
        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                if (grabber.getPixels().getColor(x, y).getBrightness() > threshold)
                {
                    grayscalePixels.setColor(x, y, ofColor(0));
                }
                else
                {
                    grayscalePixels.setColor(x, y, ofColor(255));
                }
            }
        }
        
        grayscaleTexture.loadData(grayscalePixels);
    }
    
}


void ofApp::draw()
{
    ofNoFill();

    grabber.draw(0, 0);
//    grayscaleTexture.draw(0, 0);

	for(unsigned int i = 0; i < finder.blobs.size(); i++)
    {
        // Ignore small "faces".
        if (finder.blobs[i].boundingRect.getArea() > 150 * 150)
        {
            ofRectangle rect = finder.blobs[i].boundingRect;
            
            //Nose variables
            float xNose = rect.getCenter().x;
            float yNose = rect.getCenter().y;

            //Mouth variables
            float yMouth = rect.getCenter().y + 0.24 * rect.getHeight();

            //Eye variables
            float yEye = rect.getCenter().y - 0.11 * rect.getHeight();
            float xEyeOffset = 0.18 * rect.getWidth();
            float xEyeRight = xNose + xEyeOffset;
            float xEyeLeft  = xNose - xEyeOffset;
//            ofDrawRectangle(finder.blobs[i].boundingRect);
            
            //Head
             
            //Googly-Eyes
            ofPushStyle();
            ofFill();
            ofSetColor(255);
            ofDrawCircle(xEyeLeft, yEye+10, 25);
            ofDrawCircle(xEyeRight, yEye+10, 25);
            ofSetColor(0);
            ofDrawCircle(xEyeLeft-5 + std::sin(ofGetFrameNum()*1.5)*3, yEye+10 + std::sin(ofGetFrameNum())*10, 10);
            ofDrawCircle(xEyeRight+5 - std::sin(ofGetFrameNum()*1.5)*3, yEye+10 + std::cos(ofGetFrameNum())*10, 10);

            ofNoFill();
            ofPopStyle();

            //Mouth
            ofPushStyle();
            ofFill();
            ofSetColor(0);
            
            ofRectangle mouthRect(xNose-35, yMouth+10, 70, 20);
            int whitePix;
            
            for(int x = mouthRect.getMinX(); x < mouthRect.getMaxX(); x++)
            {
                for(int y = mouthRect.getMinY(); y < mouthRect.getMaxY(); y++)
                {
                    int brightnessOfGrayscale = grayscalePixels.getColor(x, y).getBrightness();
                    
                    if(brightnessOfGrayscale > 0)
                    {
                        whitePix++;
                    }
                    else
                    {
                        whitePix--;
                    }
                }
            }
            
            if(whitePix > mouthRect.getArea()/3)
            {
                ofDrawEllipse(xNose, yMouth+20, 2*whitePix/mouthRect.height, 40);
//                soundPlayer.setSpeed(1);
                if(!soundPlayer.isPlaying())
                {
                    soundPlayer.play();
                }
            }
            else
            {
                ofSetLineWidth(4);
                ofDrawLine(xNose-60, yMouth+20, xNose+60, yMouth+20);
            }
            ofPopStyle();
        }
    }
}

void ofApp::mousePressed(int x, int y, int button)
{
    cout<<grayscalePixels.getColor(x, y).getBrightness()<<endl;
}


