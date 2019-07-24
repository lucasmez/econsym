#ifndef _SPIRAL_ITERATOR_H
#define _SPIRAL_ITERATOR_H

#include <iterator>
#include <utility>
#include <cmath>
#include <World/Map/Map.h>

template <typename C, typename T, typename Size>
class SpiralIterator
{
    private:
        C* v;
        Size xCenter, yCenter;
        Size x, y;
        Size numCols, numRows;

        Size curLevel = 0;
        Size maxLevel = 0;
        Size numSteps = 0;
        Size topWallXBound = 0;
        Size leftWallYBound = 0;
        Size rightWallYBound = 0;
        Size bottomWallXBound = 0;
        std::pair<Size, Size> lastValue;

        std::pair<Size, Size> getNextPosition() {
            // Already ended
            if (x == SpiralIterator::endValue.first && y == SpiralIterator::endValue.second) 
                return std::pair<Size, Size> {x,y};

            // Advance Level
            if (numSteps == 0) {
                curLevel++;

                // Ending condition
                if (curLevel > maxLevel) {
                    x = SpiralIterator::endValue.first;
                    y = SpiralIterator::endValue.second;
                    return endValue;
                }

                topWallXBound = xCenter - curLevel;
                leftWallYBound = yCenter - curLevel;
                rightWallYBound = yCenter + curLevel;
                bottomWallXBound = xCenter + curLevel;

                numSteps = 8 * curLevel;
                y = rightWallYBound;

                // Return first value
                if (x >= 0 && x < numRows && y >= 0 && y < numCols) {
                    numSteps--;
                    return std::pair<Size, Size> {x, y};
                }
            }

            do {
                // Somewhere in the left wall
                if (y == leftWallYBound) {
                    // bottom-left corner
                    if (x == bottomWallXBound) y++;
                    //  top-left corner OR left wall, no corner
                    else x++;
                }

                // Somewhere in the right side
                else if (y == rightWallYBound) {
                    // top-right corner
                    if (x == topWallXBound) y--;
                    // bottom-right corner OR  right wall, no corner
                    else x--;
                }

                // On the top wall, no corner
                else if (x == topWallXBound) y--;

                // On the bottom wall, no corner
                else if (x == bottomWallXBound) y++;

                numSteps--;
            } while (numSteps > 0 && (x < 0 || x >= numRows || y < 0 || y >= numCols));

            if (x < 0 || x >= numRows || y < 0 || y >= numCols) {
                return lastValue;
            }

            lastValue = std::pair<Size, Size>{x, y};
            return std::pair<Size, Size>{x, y};
        }

    public:
        const static std::pair<Size, Size> endValue;

        using interator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;


        // Using default copy/move constructors and destructor.
        SpiralIterator() : v{nullptr}, xCenter{0}, yCenter{0}, x{0}, y{0} {}
        SpiralIterator(C *v, Size x, Size y) : v{v}, xCenter{x}, yCenter{y}, x{x}, y{y} {
            numRows = v->size();
            numCols = (*v)[0].size();
            maxLevel = std::max(
                std::max(x, numRows-1-x),
                std::max(y, numCols-1-y)
            );
        }
        SpiralIterator(C* v, std::pair<Size, Size> init): SpiralIterator {v, init.first, init.second } {}

        bool operator==(const SpiralIterator &rhs) const
        {
            return x == rhs.x && y == rhs.y;
        }

        bool operator!=(const SpiralIterator &rhs) const
        {
            return x != rhs.x || y != rhs.y;
        }

        reference operator*()
        {
            return (*v)[x][y];
        }

        const reference operator*() const
        {
            return (*v)[x][y];
        }

        pointer operator->()
        {
            return &((*v)[x][y]);
        }

        const pointer operator->() const
        {
            return &((*v)[x][y]);
        }

        SpiralIterator &operator++()
        {
            std::pair<Size, Size> indexes = getNextPosition();
            x = indexes.first;
            y = indexes.second;
            return *this;
        }

        SpiralIterator operator++(int)
        {
            SpiralIterator copy{*this};
            std::pair<Size, Size> indexes = getNextPosition();
            x = indexes.first;
            y = indexes.second;
            return copy;
        }
};

template <typename C, typename T, typename Size>
const std::pair<Size, Size> SpiralIterator<C,T,Size>::endValue = {-1, -1};

#endif
