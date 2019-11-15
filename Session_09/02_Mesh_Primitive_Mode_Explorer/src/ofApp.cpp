#include "ofApp.h"


std::string ofApp::makeInfoString() const
{
    std::stringstream ss;
    
    int width = 25;
    
    ss << std::setw(width) << "-INFO- " << std::endl; // new line
    ss << std::setw(width) << "Primitive Mode: " << getPrimitiveModeString(currentPrimitiveMode) << std::endl;
    ss << std::setw(width) << "# Points : " << polyline.size() << std::endl;
    ss << std::endl;
    ss << std::setw(width) << "-COMMANDS- " << std::endl; // new line
    ss << std::setw(width) << "Clear Points: " << "c" << std::endl;
    ss << std::setw(width) << "Primitive Mode: " << "p" << std::endl;
    ss << std::setw(width) << "Toggle Mesh Wire: " << "w" << std::endl;
    ss << std::setw(width) << "Toggle Mesh Fill: " << "m" << std::endl;
    ss << std::setw(width) << "Toggle Mesh Points: " << "k" << std::endl;
    ss << std::setw(width) << "Toggle Poly: " << "u" << std::endl;
    ss << std::setw(width) << "Toggle Poly Tans: " << "t" << std::endl;
    ss << std::setw(width) << "Toggle Poly Norms: " << "n" << std::endl;
    ss << std::setw(width) << "Toggle Poly Curves: " << "s" << std::endl;
    ss << std::setw(width) << "Toggle Vert Indices: " << "i" << std::endl;
    
    return ss.str();
}


std::string ofApp::getPrimitiveModeString(ofPrimitiveMode mode) const
{
    switch (currentPrimitiveMode)
    {
        case OF_PRIMITIVE_TRIANGLES:
            return "OF_PRIMITIVE_TRIANGLES";
        case OF_PRIMITIVE_TRIANGLE_STRIP:
            return "OF_PRIMITIVE_TRIANGLE_STRIP";
        case OF_PRIMITIVE_TRIANGLE_FAN:
            return "OF_PRIMITIVE_TRIANGLE_FAN";
        case OF_PRIMITIVE_LINES:
            return "OF_PRIMITIVE_LINES";
        case OF_PRIMITIVE_LINE_STRIP:
            return "OF_PRIMITIVE_LINE_STRIP";
        case OF_PRIMITIVE_LINE_LOOP:
            return "OF_PRIMITIVE_LINE_LOOP";
        case OF_PRIMITIVE_POINTS:
            return "OF_PRIMITIVE_POINTS";
#ifndef TARGET_OPENGLES
        case OF_PRIMITIVE_LINES_ADJACENCY:
            return "OF_PRIMITIVE_LINES_ADJACENCY";
        case OF_PRIMITIVE_LINE_STRIP_ADJACENCY:
            return "OF_PRIMITIVE_LINE_STRIP_ADJACENCY";
        case OF_PRIMITIVE_TRIANGLES_ADJACENCY:
            return "OF_PRIMITIVE_TRIANGLES_ADJACENCY";
        case OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY:
            return "OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY";
        case OF_PRIMITIVE_PATCHES:
            return "OF_PRIMITIVE_PATCHES";
#endif
    }
}


void ofApp::setup()
{
}


void ofApp::draw()
{
    ofBackgroundGradient(ofColor::white,ofColor::black);
    
    std::string infoString = makeInfoString();
    
    ofDrawBitmapStringHighlight(infoString, 20, 20);
    
    if(drawPoly)
    {
        polyline.draw();
    }
    
    // clear out my mesh
    mesh.clear();
    
    mesh.setMode(currentPrimitiveMode);
    mesh.enableColors();
    
    for (std::size_t i = 0; i < polyline.size(); ++i)
    {
        auto currentPoint = polyline[i];
        
        mesh.addVertex(currentPoint);
        
        // ofFloatColor uses values of 0-1.
        float map = ofMap(i, 0, polyline.size(), 1, 0); // calculate a value mapped to position
        
        ofFloatColor color(255, map, 0, map);
        
        mesh.addColor(color);
        
        if (drawVertexIndicies)
        {
            ofDrawBitmapStringHighlight(ofToString(i),currentPoint);
        }
        
        if (drawPolyNormals)
        {
            auto normal = polyline.getNormalAtIndex(i);
            normal *= 20.0;
            
            ofPushStyle();
            ofSetColor(255,255,0);
            ofDrawLine(currentPoint, currentPoint + normal);
            
            ofSetColor(255,0,0);
            ofDrawLine(currentPoint, currentPoint - normal);
            
            ofPopStyle();
        }
        
        if (drawPolyTangents)
        {
            auto tangent = polyline.getTangentAtIndex(i);
            tangent *= 20.0;
            
            ofPushStyle();
            ofSetColor(0,255,0);
            ofDrawLine(currentPoint, currentPoint + tangent);
            
            ofSetColor(0,255,255);
            ofDrawLine(currentPoint, currentPoint - tangent);
            
            ofPopStyle();
        }
    }
    
    if (drawPolyCurves)
    {
        ofPushStyle();
        ofNoFill();
        ofSetColor(253,122,2);
        ofBeginShape();
        for(std::size_t i = 0; i < polyline.size(); ++i)
        {
            auto currentPoint = polyline[i];
            if(i == 0 || i == polyline.size() - 1)
            {
                ofCurveVertex(currentPoint.x,currentPoint.y);
            }
            ofCurveVertex(currentPoint.x,currentPoint.y);
        }
        ofEndShape();
        ofPopStyle();
    }
    
    if (drawMeshPoints)
    {
        mesh.draw(OF_MESH_POINTS);
    }
    
    if (drawMeshFill)
    {
        mesh.draw(OF_MESH_FILL);
    }
    
    if (drawMeshWireframe)
    {
        mesh.draw(OF_MESH_WIREFRAME);
    }

}

void ofApp::keyPressed(int key)
{
    if ('p' == key)
    {
        switch (currentPrimitiveMode)
        {
            case OF_PRIMITIVE_TRIANGLES:
                currentPrimitiveMode = OF_PRIMITIVE_TRIANGLE_STRIP;
                break;
            case OF_PRIMITIVE_TRIANGLE_STRIP:
                currentPrimitiveMode = OF_PRIMITIVE_TRIANGLE_FAN;
                break;
            case OF_PRIMITIVE_TRIANGLE_FAN:
                currentPrimitiveMode = OF_PRIMITIVE_LINES;
                break;
            case OF_PRIMITIVE_LINES:
                currentPrimitiveMode = OF_PRIMITIVE_LINE_STRIP;
                break;
            case OF_PRIMITIVE_LINE_STRIP:
                currentPrimitiveMode = OF_PRIMITIVE_LINE_LOOP;
                break;
            case OF_PRIMITIVE_LINE_LOOP:
                currentPrimitiveMode = OF_PRIMITIVE_POINTS;
                break;
            case OF_PRIMITIVE_POINTS:
                currentPrimitiveMode = OF_PRIMITIVE_LINES_ADJACENCY;
                break;
            case OF_PRIMITIVE_LINES_ADJACENCY:
                currentPrimitiveMode = OF_PRIMITIVE_LINE_STRIP_ADJACENCY;
                break;
            case OF_PRIMITIVE_LINE_STRIP_ADJACENCY:
                currentPrimitiveMode = OF_PRIMITIVE_TRIANGLES_ADJACENCY;
                break;
            case OF_PRIMITIVE_TRIANGLES_ADJACENCY:
                currentPrimitiveMode = OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY;
                break;
            case OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY:
                currentPrimitiveMode = OF_PRIMITIVE_PATCHES;
                break;
            case OF_PRIMITIVE_PATCHES:
                currentPrimitiveMode = OF_PRIMITIVE_TRIANGLES;
                break;
        }
    }
    else if ('c' == key)
    {
        polyline.clear();
    }
    else if ('w' == key)
    {
        drawMeshWireframe = !drawMeshWireframe;
    }
    else if ('m' == key)
    {
        drawMeshFill = !drawMeshFill;
    }
    else if ('k' == key)
    {
        drawMeshPoints = !drawMeshPoints;
    }
    else if ('f' == key)
    {
        drawMeshFill = !drawMeshFill;
    }
    else if ('u' == key)
    {
        drawPoly = !drawPoly;
    }
    else if ('t' == key)
    {
        drawPolyTangents = !drawPolyTangents;
    }
    else if ('n' == key)
    {
        drawPolyNormals = !drawPolyNormals;
    }
    else if ('s' == key)
    {
        drawPolyCurves = !drawPolyCurves;
    }
    else if ('i' == key)
    {
        drawVertexIndicies = !drawVertexIndicies;
    }
}


void ofApp::mousePressed(int x, int y, int button)
{
    polyline.addVertex({ x, y, 0 });
}
