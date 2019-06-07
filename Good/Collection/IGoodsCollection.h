#ifndef _I_GOODS_COLLECTION_H
#define _I_GOODS_COLLECTION_H

#include <Common/IPrintable.h>
#include <Good/Type/IGoodType.h>
#include <Good/Common.h>

class IGoodsCollection: public IPrintable {

    public:
        virtual ~IGoodsCollection() {};

        /**
         * @brief  Returns the quantity of a specific good without removing it from the collection.
         * @note   
         * @retval How much of the good the collection contains.
         */
        virtual num_goods count(const IGoodType*) const = 0;

        /**
         * @brief  Determies whether the collection has at least the specified number of the specified good.
         * @param  IGoodType*: good to check
         */
        virtual bool contains(const IGoodType*, num_goods) const = 0;

        /**
         * @brief  Determines whether this collection is a subset of the passed collection.
         * Collection A is a subset of B if, for every good in A, B has the same amount or more
         * of the good amount in A.
         * @param IGoodsCollection&: Collection to check whether it contains this collection.
         */
        virtual bool containedIn(const IGoodsCollection&) const = 0;
};

#endif