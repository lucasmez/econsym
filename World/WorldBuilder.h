#ifndef _WORLD_BUILDER_H_
#define _WORLD_BUILDER_H_

#include <World/World.h>
#include <Good/GoodsManager.h>

class WorldBuilder {
    private:
        GoodsManager* gm;
        size_t width;
        size_t height;

    public:
        WorldBuilder() = default;
        void setGoodsManager(GoodsManager* gm);
        void setDimensions(size_t width, size_t height);
        World build();
        
};

#endif