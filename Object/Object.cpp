#include <Object/Object.h>

Object::Object(size_t x, size_t y) {
    Location2D loc {x, y};
    location = loc;
}

const Location2D& Object::getLocation() const {
    return location;
}

size_t Object::getEuclideanDistance(const Object&) const {
    return 1;
}