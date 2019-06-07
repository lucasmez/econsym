#ifndef _GOODS_MANAGER_H_
#define _GOODS_MANAGER_H_

#include <vector>
#include <Good/Factory/GoodFactory.h>
#include <Good/Type/GoodType.h>
#include <Good/Common.h>

class GoodsManager {
    private:
        std::vector<GoodType*> types;

    public:
        GoodsManager() = default;

        GoodType* getGoodType(good_id id) const;
        GoodType* getGoodType(const std::string& name) const;

        template <typename GType>
        GType* createGoodType(std::string name) {
            GType* newType = new GType {name};
            types.push_back(newType);
            return newType;
        }

        template <typename FactoryType>
        FactoryType createGoodFactory() const {
            FactoryType newFactory {};
            return newFactory;
        }

        template <typename FactoryType>
        FactoryType createGoodFactory(const GoodType* goodType) const {
            FactoryType newFactory {};
            newFactory.setType(goodType);
            return newFactory;
        }

        template <typename FactoryType>
        FactoryType createGoodFactory(good_id id) const {
            GoodType* goodType = getGoodType(id);
            return createGoodFactory<FactoryType>(goodType);
        }

        virtual ~GoodsManager();

};

#endif