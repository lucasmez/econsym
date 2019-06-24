
#ifndef _I_LOCATION_H
#define _I_LOCATION_H

#include <cstddef>

class ILocation {
    public:
        virtual size_t getDistance(const ILocation&) const = 0;
};

#endif