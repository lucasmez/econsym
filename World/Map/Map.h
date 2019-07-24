#ifndef _MAP_H
#define _MAP_H

#include <vector>
#include <World/Map/Square.h>
#include <Common/Iterators/SpiralIterator.h>

typedef std::vector<std::vector<Square>> Grid;
typedef long long grid_size;

class Map {
    public:
        Grid grid;

    public:
        Map(size_t rows, size_t cols) {
            grid.reserve(rows);
            for (size_t i = 0; i < grid.capacity(); i++) {
                std::vector<Square> v {};
                v.reserve(cols);
                for (size_t j = 0; j < v.capacity(); j++ ) {
                    v.emplace_back(i, j);
                }
                grid.push_back(v);
            }
        }

        //=====================
        // Iterators
        //=====================
        using spiral_iterator = SpiralIterator<Grid, Square, grid_size>;

        spiral_iterator spiral_begin(grid_size centerX, grid_size centerY) {
            return spiral_iterator { &grid, centerX, centerY };
        }
        spiral_iterator spiral_end() {
            return spiral_iterator { &grid, SpiralIterator<Grid, Square, grid_size>::endValue };
        }

};

#endif