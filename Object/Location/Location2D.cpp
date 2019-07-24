#include "./Location2D.h"

Location2D::Location2D(size_t x, size_t y) {
    position.x = x;
    position.y = y;
}

size_t Location2D::getDistance(const ILocation &dest) const {
    // sqrt((dest.position.x * dest.position.x))
    return 1;
}

Position2D Location2D::getPosition() const {
    return position;
}