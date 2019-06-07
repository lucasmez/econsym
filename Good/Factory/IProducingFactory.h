#ifndef _I_PRODUCING_FACTORY_H
#define _I_PRODUCING_FACTORY_H

#include <Good/Factory/IGoodFactory.h>
#include <Good/Type/IProducedGoodType.h>
#include <Good/Collection/IGoodsCollectionMutable.h>

class IProducingFactory: public IGoodFactory {
    public:

        /**
         * @brief  Produces and adds a good to a goods collection using 
         * ingredients from same goods collection. Searches for the ingredients
         * in the collection.
         * @param  IProducedGoodType*: good type to produce.
         * @param  IGoodsCollectionMutable&: destination and source collection.
         * @retval Whether the good was successfully produced
         */
        virtual bool produce(const IProducedGoodType*, IGoodsCollectionMutable&) const = 0;

        /**
         * @brief  Produces and adds a good to a destination goods collection using 
         * ingredients from the source goods collection. Searches for the ingredients
         * in the source collection.
         * @param  IProducedGoodType*: good type to produce.
         * @param  IGoodsCollectionMutable&: destination collection.
         * @param  IGoodsCollectionMutable&: source collection.
         * @retval Whether the good was successfully produced
         */
        virtual bool produce(const IProducedGoodType*, IGoodsCollectionMutable&, IGoodsCollectionMutable&) const = 0;
};

#endif
