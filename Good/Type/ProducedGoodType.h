#ifndef _PRODUCED_GOOD_TYPE_H_
#define _PRODUCED_GOOD_TYPE_H_

#include <Good/Type/IProducedGoodType.h>
#include <Good/Collection/GoodRecipe.h>
#include <Good/Common.h>

class ProducedGoodType: public IProducedGoodType {
    protected:
        GoodRecipe recipe;
        producing_time productionTime;

    public:
        const static std::string typeName;

        ProducedGoodType(std::string);
        ProducedGoodType(std::string, const GoodRecipe&);
        ProducedGoodType(std::string, const GoodRecipe&, producing_time);
        virtual ~ProducedGoodType() = default;

        virtual const GoodRecipe getRecipe() const override;
        virtual void setRecipe(const GoodRecipe& recipe) override;
        virtual void setRecipe(const Ingredients& ingredients);
        virtual producing_time getProductionTime() const override;
        virtual std::string str() const override;
};

#endif