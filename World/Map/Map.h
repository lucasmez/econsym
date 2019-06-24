#ifndef _MAP_H
#define _MAP_H

template <typename T>
class Map {
    protected:
        std::vector<std::vector<T>> grid;

    public:
        Map() = default;

        static WorldBuilder create();
};

#endif