#ifndef _GOODS_COLLECTION_H
#define _GOODS_COLLECTION_H

#include <map>
#include <Good/Common.h>
#include <Good/Type/IGoodType.h>
#include <Good/Collection/IGoodsCollectionMutable.h>

class GoodsHoldings: public IGoodsCollectionMutable {
    friend class IGoodFactory;
    
    private:
        std::map<const IGoodType*, num_goods> holdings;

    protected:
        /**
         * @note This method is protected because only IGoodFactory should be 
         * able to remove elements from the collection.
         */
        virtual void add(const IGoodType* goodType, num_goods quantity) override;

        /**
         * @note This method is protected because only IGoodFactory should be 
         * able to remove elements from the collection.
         */
        virtual bool remove(const IGoodType*, num_goods) override;

    public:
        GoodsHoldings() = default;
        virtual ~GoodsHoldings() = default;

        virtual num_goods count(const IGoodType*) const override;
        virtual bool transfer(const IGoodType*,num_goods, IGoodsCollectionMutable&) override;
        virtual bool contains(const IGoodType*, num_goods) const override;
        virtual bool containedIn(const IGoodsCollection&) const override;
        virtual std::string str() const override;
};


#endif