#include "ofApp.h"


void ofApp::setup()
{
    // Set up our grabber.
    grabber.setup(320, 240);

    // Allocate our working pixels.
    // We match the values of the grabber.
    pixels.allocate(grabber.getWidth(),
                    grabber.getHeight(),
                    grabber.getPixelFormat());

    // Set the values to black 0.
    pixels.set(0);

    // Load the data into the texture.
    texture.loadData(pixels);

    // Allocate our working pixels.
    // We mach the SIZE of the grabber, but we only want grayscale to create
    // time map.
    timeMapPixels.allocate(grabber.getWidth(),
                           grabber.getHeight(),
                           OF_PIXELS_GRAY); // Note that we use 1-channel grayscal here!

    // Set the values to black 0.
    pixels.set(0);

    // Load the data into the texture.
    timeMapTexture.loadData(timeMapPixels);

}

void ofApp::update()
{
    grabber.update();

    if (grabber.isFrameNew())
    {
        if (isBuffering)
        {
            // 0. Save the current frame in our buffer!
            pixelBuffer.push_back(grabber.getPixels());

            // 1. Delete older frames if we have too many buffered.
            while (pixelBuffer.size() > maxBufferSize)
            {
                // This is how we delete the FIRST (oldest) frame from our buffer.
                pixelBuffer.erase(pixelBuffer.begin());
            }
        }

        // 2. Make a "time" map. This map (which could be any grayscale pixel
        // mask) will determine how "deep" we go into the past (i.e. the buffer)
        // for each x / y position.
        //
        // In our mask, which has values from 0 - 255 for each pixel, a value of
        // 0 means that we choose the most recent buffer frame to get our pixel.
        // A value of 255 means we get our oldest frame.  Thus, depending on
        // what the value of the `maxBufferSize`, you will be able to go further
        // "back" in time through the buffer.
        //
        // Here we create a mask that is simply the distance of each pixel from
        // the cursor.

        int mouseX = ofGetMouseX();
        int mouseY = ofGetMouseY();

        // std::min will take two numbers and give you back the smaller of the
        // two numbers. std::max, will take the same, but give you back the
        // larger of the two.
        int maximumDimension = std::min(grabber.getWidth(), grabber.getHeight());

        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                if (useLinearGradient)
                {
                    // The x-distance from the mouse to pixel x/y.
                    float distance = ofDist(mouseX, y, x, y);

                    // Map distance to grayscale.
                    int grayscaleValue = ofMap(distance, 0, grabber.getWidth(), 0, 255, true);

                    // Set our time map values.
                    timeMapPixels.setColor(x, y, ofColor(grayscaleValue));
                }
                else
                {
                    // The distance from the mouse to pixel x/y.
                    float distance = ofDist(mouseX, mouseY, x, y);

                    // Map distance to grayscale.
                    int grayscaleValue = ofMap(distance, 0, maximumDimension, 0, 255, true);

                    // Set our time map values.
                    timeMapPixels.setColor(x, y, ofColor(grayscaleValue));
                }
            }
        }

        timeMapTexture.loadData(timeMapPixels);

        // 3. Now that we have the updated time map, we will dive into our
        // and pick out "historical" pixels based on our map.

        for (int x = 0; x < grabber.getWidth(); x++)
        {
            for (int y = 0; y < grabber.getHeight(); y++)
            {
                // First, we get the current value of the "time map" and we
                // map it to the buffer index (this goes from 0 for an empty
                // buffer to pixelBuffer.size() for a full buffer).
                //
                // Remember the buffer keeps adding new frames and removing the
                // oldest frames.

                // This value will range between 0 - 255.
                int value = timeMapPixels.getColor(x, y).getBrightness();

                // Next we map it.
                std::size_t pixelBufferIndex = ofMap(value, 0, 255, 0, pixelBuffer.size() - 1, true);

                // Now we get the color of x/y pixels at the frame from the
                // pixel buffer that we just figured out above (pixelBufferIndex).

                // When we call pixelBuffer[pixelBufferIndex], we are asking for
                // the ofPixels inside of the pixelBuffer at the index == pixelBufferIndex.

                ofColor colorFromTheBuffer = pixelBuffer[pixelBufferIndex].getColor(x, y);

                // Now save it in our current pixels array to display!
                pixels.setColor(x, y, colorFromTheBuffer);

            }
        }

        texture.loadData(pixels);

    }

}

void ofApp::draw()
{
    ofBackground(0);

    texture.draw(0, 0);
    ofDrawBitmapStringHighlight("The time-warped image.", 20, 20);
    grabber.draw(320, 0);
    ofDrawBitmapStringHighlight("The raw grabber image.", 320 + 20, 20);
    timeMapTexture.draw(0, 240);
    ofDrawBitmapStringHighlight("The time map.", 20, 20 + 240);

    // This is a nicer way to create long strings for display.
    std::stringstream ss;
    ss << "- / = to change max buffered frames" << std::endl;
    ss << "#max buffered frames = " << maxBufferSize << std::endl;
    ss << "#buffered frames = " << pixelBuffer.size()<< std::endl;
    ss << "t to toggle gradientType" << std::endl;
    ss << "p to pause" << std::endl;
    ss << "using linear = " << useLinearGradient << " using circular = " << !useLinearGradient << std::endl;
    ss << "is buffering? = " << isBuffering;
    ofDrawBitmapStringHighlight(ss.str(), 20 + 320, 20 + 240);
}


void ofApp::keyPressed(int key)
{
    if (key == '-')
    {
        maxBufferSize -= 1;
    }
    else if (key == '=')
    {
        maxBufferSize += 1;
    }
    else if (key == 't')
    {
        useLinearGradient = !useLinearGradient;
    }
    else if (key == ' ')
    {
        isBuffering = !isBuffering;
    }

    // Make sure there is always one buffer.
    if (maxBufferSize <= 0)
    {
        maxBufferSize = 1;
    }
}
