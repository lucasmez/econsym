#ifndef _GOODS_COLLECTION_H
#define _GOODS_COLLECTION_H

#include <map>
#include <Good/Common.h>
#include <Good/Type/GoodType.h>
#include <Good/Collection/IGoodsCollectionMutable.h>

class GoodsHoldings: public IGoodsCollectionMutable {
    friend class GoodFactory;
    
    private:
        std::map<const GoodType*, num_goods> holdings;

    protected:
        /**
         * @note This method is protected because only GoodFactory should be 
         * able to remove elements from the collection.
         */
        virtual void add(const GoodType* goodType, num_goods quantity) override;

        /**
         * @note This method is protected because only GoodFactory should be 
         * able to remove elements from the collection.
         */
        virtual bool remove(const GoodType*, num_goods) override;

    public:
        GoodsHoldings() = default;
        virtual ~GoodsHoldings() = default;

        virtual num_goods count(const GoodType*) const override;
        virtual bool transfer(const GoodType*,num_goods, IGoodsCollectionMutable&) override;
        virtual bool contains(const GoodType*, num_goods) const override;
        virtual bool containedIn(const IGoodsCollection&) const override;
        virtual std::string str() const override;
};


#endif