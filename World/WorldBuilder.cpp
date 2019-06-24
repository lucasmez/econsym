#include <World/WorldBuilder.h>

void WorldBuilder::setGoodsManager(GoodsManager* gm) {
    this->gm = gm;
}

void WorldBuilder::setDimensions(size_t width, size_t height) {
    this->width = width;
    this-> height = height;
}

World WorldBuilder::build() {
    World world {this->width, this->height, this->gm};
    return world;
}