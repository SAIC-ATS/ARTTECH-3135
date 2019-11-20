#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(80);
    
    ofLoadImage(texture, "brush.png");

    ofTrueTypeFont font;
    font.load(OF_TTF_SANS, 600, true, true, true);

    std::vector<ofPath> textPaths = font.getStringAsPoints("Hi", true, false);

    glm::vec2 textPosition = glm::vec2(100, 650);

    // Initialize the bounding box.
    textBoundingBox.setPosition(textPosition.x,
                                textPosition.y);

    for (auto path: textPaths)
    {
        path.translate(textPosition);
        for (auto p: path.getOutline())
        {
            textBoundingBox.growToInclude(p.getBoundingBox());
            textPolylines.push_back(p);
        }
    }
}


void ofApp::update()
{
    while (particles.size() < 1500)
    {
        glm::vec2 p = findPositionForNewParticle();
        makeParticleAt(p.x, p.y);
    }


    for (auto& p: particles)
        p.update();

    // This line will remove dead particles.
    ofRemove(particles, [](Particle p) { return p.isDead(); });

}


void ofApp::draw()
{
    ofSetColor(100, 80);
    for (auto p: textPolylines)
        p.draw();

    ofEnableBlendMode(OF_BLENDMODE_ADD);

    for (auto& p: particles)
        p.draw();

    ofDisableBlendMode();

    ofDrawBitmapStringHighlight(ofToString(particles.size()), 20, 20);
}


glm::vec2 ofApp::findPositionForNewParticle()
{
    glm::vec2 p;

    bool isInside = false;

    // This could go on forever, but is unlikely.
    while (!isInside)
    {
        // Guess a random point inside our bounding box.
        p = {
            ofRandom(textBoundingBox.getMinX(), textBoundingBox.getMaxX()),
            ofRandom(textBoundingBox.getMinY(), textBoundingBox.getMaxY()),
        };

        // Now see if that point is inside of our shapes?
        // If it is, then jump out of the for loop and while loop.
        for (auto polyline: textPolylines)
        {
            // Is the point inside a polyline?
            if (polyline.inside(p.x, p.y))
            {
                isInside = true;
                break;
            }
        }
    }

    return p;
}


void ofApp::makeParticleAt(float x, float y)
{
    // Create a particle.
    Particle p;

    // Initialize its values.
    p.setup();
    
    // Overwrite the position with the new position x, y.
    p.position.x = x;
    p.position.y = y;

    p.velocity.x = ofRandom(-1, 1);
    p.velocity.y = ofRandom(-1, 1);

    p.acceleration.y = 0.01;

    p.size = ofRandom(30, 50);

    p.ageAtDeath = ofRandom(10, 100);

    // Creates a reference inside the particle to
    // the texture I loaded in setup().
    p.texture = texture;

    // Add the newly created particle to the particles vector.
    particles.push_back(p);
}
