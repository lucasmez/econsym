#ifndef _PRODUCED_GOOD_TYPE_H_
#define _PRODUCED_GOOD_TYPE_H_

#include <Good/Type/GoodType.h>
#include <Good/Type/IProducedGoodType.h>
#include <Good/Collection/GoodRecipe.h>
#include <Good/Common.h>

class ProducedGoodType: public GoodType, public IProducedGoodType {
    protected:
        GoodRecipe recipe;
        producing_time producingTime;

    public:
        ProducedGoodType(std::string);
        ProducedGoodType(std::string, const GoodRecipe&);
        ProducedGoodType(std::string, const GoodRecipe&, producing_time);
        virtual ~ProducedGoodType() = default;

        virtual const GoodRecipe getRecipe() const override;
        virtual void setRecipe(const GoodRecipe& recipe) override;
        virtual void setRecipe(const Ingredients& ingredients);
        virtual std::string str() const override;
};

#endif