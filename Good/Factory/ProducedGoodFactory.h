#ifndef _PRODUCED_GOOD_FACTORY_H
#define _PRODUCED_GOOD_FACTORY_H

#include <Good/Factory/IGoodFactory.h>
#include <Good/Factory/IProducingFactory.h>
#include <Good/Collection/IGoodsCollectionMutable.h>

class ProducedGoodFactory: public IProducingFactory {
    public:
        ProducedGoodFactory() = default;
        virtual ~ProducedGoodFactory() = default;

        virtual bool produce(const IProducedGoodType*, IGoodsCollectionMutable&) const override;
        virtual bool produce(const IProducedGoodType*, IGoodsCollectionMutable& dest, IGoodsCollectionMutable& source) const override;
};

#endif