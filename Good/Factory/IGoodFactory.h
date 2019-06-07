#ifndef _I_GOOD_FACTORY_H_
#define _I_GOOD_FACTORY_H_

#include <string>
#include <Good/Type/IGoodType.h>
#include <Good/Collection/IGoodsCollectionMutable.h>
#include <Good/Common.h>

class IGoodFactory {
    public:
        IGoodFactory() = default;
        virtual ~IGoodFactory() = 0;

        virtual void spawn(const IGoodType*, IGoodsCollectionMutable& destinationCol) const;
        virtual void spawn(const IGoodType*, num_goods, IGoodsCollectionMutable& destinationCol) const;
        virtual bool destroy(const IGoodType*, num_goods, IGoodsCollectionMutable& col) const;
};

#endif
