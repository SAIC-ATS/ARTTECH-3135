#include "ofApp.h"


void ofApp::setup()
{
//    // Variables - a piece of memory with a name.
//
//    int a = 4;
//    int b = 5;
//    int c = 10;
//
//    // a plus b plus c equals sum
//
//    int sum = a + b + c;
//
//    // Operator is something that acts on a variable.
//
//    // = -> assignment operator
//    // + -> addition operator
//    // * -> multiplication operator
//    // / -> division
//    // % -> modulo "remainder division"
//
//    // Some operators are "more important" than others.
//    int x = a + (b * c); // 50 + 4 = 54
//    int y = (a + b) * c; // 9 * 10 = 90
//
//    // Operators also work on non-numerical types.
//
//    std::string myFirstName = "Christopher";
//    std::string myLastName = "Baker";
//
    int myAge = 41;
    bool doIFeelLikeImOver40 = false;
    float todaysTemp = 20.0;

//    std::string myFullNameAndAge = myFirstName + " " + myLastName + " is " + ofToString(myAge);
//    std::cout << myFullNameAndAge << std::endl;
//    std::cout << myFirstName << " " << myLastName << " is " << myAge << std::endl;
//
    // Must have its pair!
    // ( ) Parentheses
    // { } Curly Braces or Curly Brackets
    // - define code blocks
    // [ ] Square Brackets

    // && - boolean / logical AND
    // || - boolean / logical OR


//    if (myAge < 40)
//    {
//        std::cout << "Still a kid at heart!" << std::endl;
//    }
//    else if (myAge < 30)
//    {
//        std::cout << "Getting older!" << std::endl;
//    }
//    else
//    {
//        std::cout << "Well ..." << std::endl;
//    }

        if (myAge < 40 || doIFeelLikeImOver40 == false)
        {
            std::cout << "Still a kid at heart!" << std::endl;
        }
        else
        {
            std::cout << "Well ..." << std::endl;
        }


//    ofGetMousePressed(0)
//    ofGetMousePressed(1)
//    ofGetMousePressed(2)


//
//
//
//    if ((myAge < 40 || doIFeelLikeImOver40 == false) && todaysTemp < 37)
//    {
//        std::cout << "Still a kid at heart!" << std::endl;
//    }
//    else
//    {
//        std::cout << "Well ..." << std::endl;
//    }

    //
//    while ((myAge < 40 || doIFeelLikeImOver40 == false) && todaysTemp < 37)
//    {
//        std::cout << "Still a kid at heart!" << std::endl;
//        todaysTemp = todaysTemp + 1;
//    }

//    int i = 0;
//    while (i < 10)
//    {
//        std::cout << i << std::endl;
//        i++;
//    }
//
//    do
//    {
//        std::cout << i << std::endl;
//        i++;
//    } while (i < 10);
//
//    for (int i = 0; i < 10; i++)
//    {
//        std::cout << i << std::endl;
//    }
//
//
//    cout << "---------------" << endl;
//
//    while (false)
//    {
//        std::cout << "You'll never see me!" << std::endl;
//    }
//
//
//    do
//    {
//        std::cout << "This printed!" << std::endl;
//    }
//    while (false);
//
//    // Range-for
//    std::string myString = "Hello World!";
//
//    for (char c: myString)
//    {
//        std::cout << c << std::endl;
//    }
//
//    //
//
//    for (int i = 0; i < myString.size(); i++)
//    {
//        std::cout << myString[i] << std::endl;
//    }
}
