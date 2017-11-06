#include "ofApp.h"


void ofApp::setup()
{
    std::cout << "int #bits " << sizeof(int) * 8 << " lowest: " << std::numeric_limits<int>::lowest() << " max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "unsigned int #bits " << sizeof(unsigned int) * 8 << " lowest: " << std::numeric_limits<unsigned int>::lowest() << " max: " << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout << "std::size_t #bits " << sizeof(std::size_t) * 8 << " lowest: " << std::numeric_limits<std::size_t>::lowest() << " max: " << std::numeric_limits<std::size_t>::max() << std::endl;
    std::cout << "uint64_t #bits " << sizeof(uint64_t) * 8 << " lowest: " << std::numeric_limits<uint64_t>::lowest() << " max: " << std::numeric_limits<uint64_t>::max() << std::endl;

    std::cout << "uint8_t #bits " << sizeof(uint8_t) * 8 << " lowest: " << (int)std::numeric_limits<uint8_t>::lowest() << " max: " << (int)std::numeric_limits<uint8_t>::max() << std::endl;

}
