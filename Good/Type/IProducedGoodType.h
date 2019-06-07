#ifndef _I_PRODUCED_GOOD_TYPE_H_
#define _I_PRODUCED_GOOD_TYPE_H_

#include <vector>
#include <string>
// #include <Good/Type/GoodType.h>
#include <Good/Collection/GoodRecipe.h>
// #include <Good/Common.h>

class IProducedGoodType {
    public:
        virtual ~IProducedGoodType() {}
        virtual const GoodRecipe getRecipe() const = 0;
        virtual void setRecipe(const GoodRecipe&) = 0;
        virtual void setRecipe(const Ingredients& ingredients) = 0;
};

#endif