#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cstddef>
#include <Object/Location/Location2D.h>

class Object {
    protected:
        Location2D location;

    public:
        Object() = default;
        Object(size_t x, size_t y);

        virtual const Location2D& getLocation() const;
        virtual size_t getEuclideanDistance(const Object&) const;
};


#endif // _OBJECT_H_
