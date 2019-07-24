#ifndef _WORLD_H_
#define _WORLD_H_

#include <cmath>
#include <climits>
#include <vector>
// #include <World/WorldBuilder.h>
#include <World/Map/Map.h>
#include <Good/GoodsManager.h>

class World {
    protected:
        GoodsManager* gm;

    public:
        World(size_t width, size_t height, GoodsManager* gm);

        // static WorldBuilder create();
};

#endif