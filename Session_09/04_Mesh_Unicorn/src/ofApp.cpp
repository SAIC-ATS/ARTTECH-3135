#include "ofApp.h"


void ofApp::setup()
{
    ofEnableAlphaBlending();

    image.load("image.png");
    alphaImage.load("image_a.png");

}


void ofApp::draw()
{
    ofBackgroundGradient(ofColor::white, ofColor::black);

    // clear out my mesh
    mesh.clear();

    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.enableColors();

    for(std::size_t i = 0; i < polyline.size(); ++i)
    {
        glm::vec3 currentPoint = polyline[i];

        glm::vec3 normalPoint = polyline.getNormalAtIndex(i);

        float distance = 0;

        if (i > 0)
        {
            distance = glm::distance(currentPoint, polyline[i-1]);
        }

        float strokeWidth = ofMap(distance, 0, 100, 100, 255,true);
        float alpha = ofMap(distance, 0, 100, 200, 255, true);

        mesh.addVertex(currentPoint + (normalPoint * strokeWidth));
        mesh.addColor(ofColor(255, alpha));

        mesh.addVertex(currentPoint - (normalPoint * strokeWidth));
        mesh.addColor(ofColor(255, alpha));
        
        float imageWidth = image.getWidth();
        float imageHeight = image.getHeight();

#ifdef TARGET_OPENGLES
        imageWidth = 1;
        imageHeight = 1;
#endif

        float currentTextureY = ofMap(i, 0, polyline.size(), 0, imageHeight);

        glm::vec2 textureCoordinate0 = glm::vec2(0,currentTextureY);
        glm::vec2 textureCoordinate1 = glm::vec2(imageWidth,currentTextureY);

        mesh.addTexCoord(textureCoordinate0);
        mesh.addTexCoord(textureCoordinate1);
    }

    if (useAlphaImage)
    {
        alphaImage.bind();
    }
    else
    {
        image.bind();
    }

    mesh.draw();

    if (useAlphaImage)
    {
        alphaImage.unbind();
    }
    else
    {
        image.unbind();
    }


    if (drawVertexIndicies)
    {
        for (std::size_t i = 0; i < polyline.size(); ++i)
        {
            ofDrawBitmapStringHighlight(ofToString(i), polyline[i]);

        }
    }

    ofDrawBitmapStringHighlight("Drag mouse.\n(c) to clear\n(space) fullscreen\n(a) alpha-corn", 20,20);
}


void ofApp::keyPressed(int key)
{
    if ('c' == key)
    {
        polyline.clear();
    }
    else if ('i' == key)
    {
        drawVertexIndicies = !drawVertexIndicies;
    }
    else if ('a' == key)
    {
        useAlphaImage = !useAlphaImage;
    }
    else if (' ' == key)
    {
        ofToggleFullscreen();
    }
}


void ofApp::mouseDragged(int x, int y, int button)
{
    polyline.addVertex(x, y);

    while(polyline.size() > maxPoints)
    {
        polyline.getVertices().erase(polyline.getVertices().begin()); // remove oldest
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    polyline.addVertex(x, y);

    while (polyline.size() > maxPoints)
    {
        polyline.getVertices().erase(polyline.getVertices().begin()); // remove oldest
    }
}

