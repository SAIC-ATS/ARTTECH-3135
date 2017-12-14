#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    // Create some defaul window settings.
    ofGLWindowSettings settings;
    
    // Set the width of the initial window.
    settings.width = 640;
    
    // Set the height of the initial window.
    settings.height = 240;
    
    // Create a window with the ofGLWindowSettings.
    ofCreateWindow(settings);
    
    // Create the application instance.
    auto app = std::make_shared<ofApp>();
    
    // Run the app that was just created. When it is finished running, the
    // program will return an exit "code". The operating system can use this
    // code to determine if the program ran into any problems while it was
    // running.
    int result = ofRunApp(app);
    
    // The program is now complete and we return the result code to the calling
    // process, which is normally owned by the operating system.
    return result;

}
