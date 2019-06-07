#ifndef _GOOD_FACTORY_H_
#define _GOOD_FACTORY_H_

#include <string>
#include <Good/Type/GoodType.h>
#include <Good/Collection/IGoodsCollectionMutable.h>
#include <Good/Common.h>

class GoodFactory {
    protected:
        const GoodType* inPipeline;

    public:
        GoodFactory();
        virtual ~GoodFactory() = default;

        void spawn(IGoodsCollectionMutable& destinationCol) const;
        void spawn(num_goods, IGoodsCollectionMutable& destinationCol) const;
        void spawn(const GoodType*, IGoodsCollectionMutable& destinationCol) const;
        void spawn(const GoodType*, num_goods, IGoodsCollectionMutable& destinationCol) const;
        bool destroy(const GoodType*, num_goods, IGoodsCollectionMutable& col) const;
        void setType(const GoodType*);
};

#endif
