#ifndef _I_GOOD_FACTORY_H_
#define _I_GOOD_FACTORY_H_

#include <string>
#include <Good/Type/GoodType.h>
#include <Good/Collection/IGoodsCollectionMutable.h>
#include <Good/Common.h>

class IGoodFactory {
    public:
        IGoodFactory() = default;
        virtual ~IGoodFactory() = 0;

        virtual void spawn(const GoodType*, IGoodsCollectionMutable& destinationCol) const;
        virtual void spawn(const GoodType*, num_goods, IGoodsCollectionMutable& destinationCol) const;
        virtual bool destroy(const GoodType*, num_goods, IGoodsCollectionMutable& col) const;
};

#endif
