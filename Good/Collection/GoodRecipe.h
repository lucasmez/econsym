#ifndef _GOOD_RECIPE_H
#define _GOOD_RECIPE_H

#include <map>
#include <Good/Common.h>
#include <Good/Type/GoodType.h>
#include <Good/Collection/IGoodsCollection.h>

typedef std::map<const GoodType*, num_goods> Ingredients;

class GoodRecipe: public IGoodsCollection {
    private:
        Ingredients ingredients;

    public:
        GoodRecipe();
        GoodRecipe(const Ingredients& ingredients);
        virtual ~GoodRecipe() = default;

        const Ingredients& getIngredients() const;
        virtual num_goods count(const GoodType*) const override;
        virtual bool contains(const GoodType*, num_goods) const override;
        virtual bool containedIn(const IGoodsCollection&) const override;
        virtual std::string str() const override;
};


#endif