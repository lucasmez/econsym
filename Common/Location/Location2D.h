#ifndef LOCATION_2D_H
#define LOCATION_2D_H

#include <Common/Location/ILocation.h>

/**
 * @note   Check for overflow when calculating distance.
 */
struct Position2D {
    size_t x;
    size_t y;
};

class Location2D: public ILocation {
    protected:
        Position2D position;
        
    public:
        virtual size_t getDistance(const ILocation&) const override;

};

#endif