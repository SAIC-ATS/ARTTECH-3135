#include "PTSLoader.h"


ofMesh PTSLoader::load(const std::string& filename)
{
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);

    // Load the text data into a file.
    ofBuffer buffer = ofBufferFromFile(filename);

    std::size_t numberOfPoints = 0;
    std::size_t lineNumber = 0;
    
    std::ifstream file(ofToDataPath(filename, true));
    std::string line;

    while (std::getline(file, line))
    {
        // Trim any white spaces off the front and end of the line.
        line = ofTrim(line);
        
        if (lineNumber == 0)
        {
            // Process the point count.
            numberOfPoints = ofTo<std::size_t>(line);
        }
        else
        {
            // Process a line of point + color.
            std::vector<std::string> tokens = ofSplitString(line, " ");
            
            if (tokens.empty())
            {
                ofLogError("PTSLoader::load") << "There was an unexpected number of points in this line: " << line;
            }
            
            if (tokens.size() > 2)
            {
                std::cout << "Processing line number: " << lineNumber << std::endl;
                // Have position
                glm::vec3 position =
                {
                    ofToFloat(tokens[0]),
                    ofToFloat(tokens[1]),
                    ofToFloat(tokens[2])
                };
                
                mesh.addVertex(position);
            }
            
            if (tokens.size() > 5)
            {
                // We skip the "reflectivity".
                
                // Have color.
                ofColor color(
                              ofToFloat(tokens[4]),
                              ofToFloat(tokens[5]),
                              ofToFloat(tokens[6])
                              );

                mesh.addColor(color);
            }
        }
        
        lineNumber++;
    }
    
//    if (numberOfPoints != lineNumber)
//    {
//        ofLogError("PTSLoader::load") << "There was a mismatch in the number of points: " << numberOfPoints << " vs. " << lineNumber;
//    }

    return mesh;
}



