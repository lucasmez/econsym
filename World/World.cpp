#include <World/World.h>

WorldBuilder World::create() {
    return WorldBuilder();
}

World::World(size_t width, size_t height, GoodsManager* gm) {
    this->gm = gm;

    width = fmin(width, (int)sqrt(SIZE_MAX-1));
    height = fmin(height, (int)sqrt(SIZE_MAX-1));

    this->map.reserve(height);
    for (auto& v: this->map) {
        v.reserve(width);
    }
}