#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cstddef>
#include <Common/Location/Location2D.h>

class Object {
    protected:
        Location2D location;

    public:
        virtual const ILocation& getLocation() const;
        virtual size_t getEuclideanDistance(const Object&) const;
};


#endif // _OBJECT_H_
