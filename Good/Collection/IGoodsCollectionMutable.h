#ifndef _I_GOODS_COLLECTION_MUTABLE_H
#define _I_GOODS_COLLECTION_MUTABLE_H

#include <Good/Collection/IGoodsCollection.h>
#include <Good/Type/GoodType.h>
#include <Good/Common.h>

class IGoodsCollectionMutable: public IGoodsCollection {

    public:
        virtual ~IGoodsCollectionMutable() {};

        /**
         * @brief  Adds a certain quantity of a good type to collection
         * @note implementation of this method is not required by the derived class.
         * @retval None
         */
        virtual void add(const GoodType*, num_goods) = 0;

        /**
         * @brief  Removes the specified quantity of the specific good from the collection.
         * @note implementation of this method is not required by the derived class.
         * @retval whether the good was present in the list in the specified quantity and was sucesfully removed.
         */
        virtual bool remove(const GoodType*, num_goods) = 0;
        
        /**
         * @brief  Transfers an amount of a certain good from this collection to destination collection
         * if this collection contains at least the transfer amount of the required good.
         * @note implementation of this method is not required by the derived class.
         * @param  IGoodsCollection&: destination collection
         * @retval wether the transfer was sucesfull
         */
        virtual bool transfer(const GoodType*, num_goods, IGoodsCollectionMutable&) = 0;
};

#endif