#include "ofApp.h"


void ofApp::setup()
{
    ofSetBackgroundAuto(false);
}


void ofApp::update()
{
    curvePosition += 0.01;

    if (curvePosition > 1)
    {
        curvePosition = 0;
    }

    if (paths.size() > 0)
    {
        lastPenPosition = penPosition;
        penPosition = paths[0].getPointAtPercent(curvePosition);

        penPosition.x += ofRandom(-10, 10);
        penPosition.y += ofRandom(-10, 10);
    }

}


void ofApp::draw()
{
    for (auto& polyline: paths)
    {
//        polyline.draw();

        for (auto& point: polyline.getVertices())
        {
//            ofDrawEllipse(point, 20, 20);

//            drawTangle(point.x, point.y);

        }
    }

    ofSetColor(255, 80);
    ofDrawLine(penPosition, lastPenPosition);

}


void ofApp::mousePressed(int x, int y, int button)
{
    ofBackground(0);
    paths.push_back(ofPolyline());
    paths.back().addVertex(x, y);
}

void ofApp::mouseDragged(int x, int y, int button)
{
    paths.back().addVertex(x, y);
}


void ofApp::mouseReleased(int x, int y, int button)
{
    ofBackground(0);

    // ?
    ofPolyline lastLine = paths.back();
    paths.pop_back();
    ofPolyline resampledLine = lastLine.getResampledBySpacing(40);
    paths.push_back(resampledLine);
}

void ofApp::keyPressed(int key)
{
    if (key == 'c')
    {
        paths.clear();
    }
}


void ofApp::drawTangle(float x, float y)
{
    ofPolyline line;

    for (int i = 0; i < 25; i++)
    {
        float newX = x + ofRandom(-100, 100);
        float newY = y + ofRandom(-100, 100);
        line.curveTo(ofPoint(newX, newY));
    }

    line.draw();
}



