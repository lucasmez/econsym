#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <Object/Object.h>
#include <Object/Location/Location2D.h>
#include <Good/Collection/GoodsHoldings.h>

class Square: public Object {
    protected:
        GoodsHoldings goods;

    public:
        Square() = default;
        Square(size_t x, size_t y): Object(x, y) {}
};

#endif
