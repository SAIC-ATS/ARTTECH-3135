#include "ofApp.h"


// This is the "main" function. It is the entry point to the program. Every
// computer program has a starting point, and this is it!
int main()
{
    // Create some defaul window settings.
    ofGLWindowSettings settings;

    // Set the size of the initial window.
    settings.setWidth(640, 480);

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
