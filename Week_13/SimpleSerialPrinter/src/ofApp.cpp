#include "ofApp.h"


void ofApp::setup()
{
    serial.setup("/dev/tty.KeySerial1", 115200);
}


void ofApp::update()
{
}


void ofApp::draw()
{
}


void ofApp::keyPressed(int key)
{
    if (key == 'p')
    {
        std::string message = "Hello\n";
        serial.writeBytes(message);
    }
    else if (key == 'm')
    {
        std::string message = "                     ";
        serial.writeBytes(message);
        serial.writeByte((char)219);
        serial.writeByte('\n');
    }


}
