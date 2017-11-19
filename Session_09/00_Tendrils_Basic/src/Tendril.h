#pragma once


#include "ofConstants.h"
#include "TendrilSegment.h"


/// \brief A tendril modeled as a collection of end-to-end TendrilSegments.
class Tendril
{
public:
    /// \brief The start position
    glm::vec3 position;
    
    /// \brief The collection of segments.
    std::vector<TendrilSegment> segments;

};
