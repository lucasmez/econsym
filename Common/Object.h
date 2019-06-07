#include <cstddef>

#ifndef _OBJECT_H_
#define _OBJECT_H_

typedef struct Coords {
    size_t x;
    size_t y;
} Coords;

class Object {
protected:
    Coords coordinates;
public:
    virtual Coords getCoordinates() const;
    virtual size_t getEuclideanDistance(const Object&) const;
};


#endif // _OBJECT_H_
