#pragma once


/// \brief A Tendril segment.
///
/// A TendrilSegment is modeled as line with a length and a direction defined
/// by angles with respect to the TendrilSegment that comes before it -- its
/// "parent" segment.
class TendrilSegment
{
public:
    /// \brief The segment length measured from the end of the parent segment.
    float length = 10;
    
    /// \brief The angle that this segment leaves from its parent segment.
    ///
    /// The is the angle about the z-axis.
    ///
    /// The angle is defined in radians.
    float angle = 0;
    
};


